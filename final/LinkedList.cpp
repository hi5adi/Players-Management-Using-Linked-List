#include "LinkedList.h"
#include "Player.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList() : start(nullptr) {}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = start;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
}

template <class T>
void LinkedList<T>::display() {
    if (start == nullptr) {
        cout << "No players in the list." << endl;
        return;
    }
    Node<T>* current = start;
    while (current != nullptr) {
        current->getData().display();
        current = current->getNext();
    }
}

template <class T>
void LinkedList<T>::insertPos(T& data, int pos) {
    Node<T>* temp = new Node<T>(data);
    if (start == nullptr) {
        start = temp;
        return;
    }

    if (pos == 1) {
        temp->setNext(start);
        start = temp;
        return;
    }

    Node<T>* p = start;
    int i = 1;
    while (p->getNext() != nullptr && i < pos - 1) {
        i++;
        p = p->getNext();
    }

    temp->setNext(p->getNext());
    p->setNext(temp);
}

template <class T>
void LinkedList<T>::deletePos(int pos) {
    if (start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node<T>* temp = start;
    if (pos == 1) {
        start = start->getNext();
        delete temp;
        cout << "Player at position " << pos << " deleted." << endl;
    } else {
        for (int i = 1; temp != nullptr && i < pos - 1; ++i) {
            temp = temp->getNext();
        }
        if (temp == nullptr || temp->getNext() == nullptr) {
            cout << "Invalid position." << endl;
        } else {
            Node<T>* nextNode = temp->getNext()->getNext();
            delete temp->getNext();
            temp->setNext(nextNode);
            cout << "Player at position " << pos << " deleted." << endl;
        }
    }
}

template <class T>
void LinkedList<T>::getTop3ByJersey() {
    if (start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // Create an array to store the top 3 players by jersey
    Player top3[3];

    // Initialize the top3 array with the first three players in the list
    Node<T>* p = start;
    for (int i = 0; i < 3 && p != nullptr; ++i) {
        top3[i] = p->getData();
        p = p->getNext();
    }

    // Iterate through the remaining players in the list
    while (p != nullptr) {
        int jersey = p->getData().getJersynum();

        // Find the player with the minimum jersey in the top3 array
        int minIndex = 0;
        for (int i = 1; i < 3; ++i) {
            if (top3[i].getJersynum() < top3[minIndex].getJersynum()) {
                minIndex = i;
            }
        }

        // If the current player has a higher jersey than the minimum in the top3 array, replace it
        if (jersey > top3[minIndex].getJersynum()) {
            top3[minIndex] = p->getData();
        }

        p = p->getNext();
    }

    // Display the top 3 players by jersey
    cout << "\nTop 3 players by jersey:";
    for (int i = 0; i < 3; ++i) {
        top3[i].display(); // Assuming Players class has a display method
    }
}


template <class T>
void LinkedList<T>::getTop3ByRuns() {
    if (start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // Initialize an array to store the top 3 players by runs
    Player top3[3];

    // Initialize the top3 array with the first three players in the list
    Node<T>* p = start;
    for (int i = 0; i < 3 && p != nullptr; ++i) {
        top3[i] = p->getData();
        p = p->getNext();
    }

    // Iterate through the remaining players in the list
    while (p != nullptr) {
        int runs = p->getData().getRun();

        // Find the player with the maximum runs in the top3 array
        int maxIndex = 0;
        for (int i = 1; i < 3; ++i) {
            if (top3[i].getRun() > top3[maxIndex].getRun()) {
                maxIndex = i;
            }
        }

        // If the current player has more runs than the minimum in the top3 array, replace it
        if (runs > top3[maxIndex].getRun()) {
            top3[maxIndex] = p->getData();
        }

        p = p->getNext();
    }

    // Display the top 3 players by runs
    cout << "\nTop 3 players by runs:";
    for (int i = 0; i < 3; ++i) {
        top3[i].display(); // Assuming Player class has a display method
    }
}

template <class T>
int LinkedList<T>::searchElement(int value) {
    Node<T>* p = start;
    int pos = 1;
    while (p != nullptr) {
        if (p->getData().getJersynum() == value)
            return pos;
        p = p->getNext();
        pos++;
    }
    return -1;
}

template <class T>
void LinkedList<T>::updatePlayer(int jerseyNumber, int newRuns, int newWickets, int newMatches) {
    Node<T>* p = start;
    while (p != nullptr) {
        if (p->getData().getJersynum() == jerseyNumber) {
            p->getData().setRun(newRuns);
            p->getData().setWicket(newWickets);
            p->getData().setTotalMatch(newMatches);
            cout << "\nPlayer details updated successfully.";
            return;
        }
        p = p->getNext();
    }
    cout << "\nPlayer not found with Jersey Number: " << jerseyNumber;
}

template <class T>
void LinkedList<T>::readFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }
    int jersey, runs, wickets, matches;
    char playerName[30];
    while (file >> jersey >> playerName >> runs >> wickets >> matches) {
        Player player(jersey, playerName, runs, wickets, matches);
        insertPos(player, 1);
    }
    file.close();
}

template <class T>
void LinkedList<T>::writeToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to create file: " << filename << endl;
        return;
    }
    Node<T>* current = start;
    while (current != nullptr) {
        file << current->getData();
        current = current->getNext();
    }
    file.close();
}
