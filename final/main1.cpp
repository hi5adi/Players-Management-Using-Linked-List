#include <iostream>
#include <fstream>
#include "LinkedList.cpp"
#include "Player.h"
using namespace std;

int main() {
    LinkedList<Player> playerList;
    
    playerList.readFromFile("players.txt");
    
    int choice;
    do {
        cout << "--------------------------------------" << endl;
        cout << "Player List Management Menu:" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Display Players" << endl;
        cout << "2. Insert Player" << endl;
        cout << "3. Delete Player" << endl;
        cout << "4. Top 3 Players by Jersey" << endl;
        cout << "5. Top 3 Players by Runs" << endl;
        cout << "6. Update Player Details" << endl;
        cout << "0. Exit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Players in the list:" << endl;
                playerList.display();
                break;
            case 2:
			{
			    int jersynum, run, wicket, totalmatch;
			    char name[30];
			
			    cout << "\n\033[1;36mEnter details for the new player:\033[0m";
			    
			    cout << "\n\033[1;32mEnter Jersey Number: \033[0m";
			    cin >> jersynum;
			
			    cout << "\033[1;32mEnter Name: \033[0m";
			    cin.ignore();  // Ignore any newline character left in the buffer
			    cin.getline(name, 30);
			
			    cout << "\033[1;32mEnter Runs: \033[0m";
			    cin >> run;
			
			    cout << "\033[1;32mEnter Wickets: \033[0m";
			    cin >> wicket;
			
			    cout << "\033[1;32mEnter Total Matches: \033[0m";
			    cin >> totalmatch;
			
			    Player newPlayer(jersynum, name, run, wicket, totalmatch);
			    int position;
			    
			    cout << "\033[1;36mEnter position to insert: \033[0m";
			    cin >> position;
			    
			    playerList.insertPos(newPlayer, position);
			    break;
			}
            case 3: {
                int jersey;
                cout << "Enter jersey number of the player to delete: ";
                cin >> jersey;
                playerList.deletePos(playerList.searchElement(jersey));
                break;
            }
            case 4:
                playerList.getTop3ByJersey();
                break;
            case 5:
                playerList.getTop3ByRuns();
                break;
            case 6: {
                int jersey, newRuns, newWickets, newMatches;
                cout << "Enter jersey number of the player to update: ";
                cin >> jersey;
                cout << "Enter new runs: ";
                cin >> newRuns;
                cout << "Enter new wickets: ";
                cin >> newWickets;
                cout << "Enter new matches: ";
                cin >> newMatches;
                playerList.updatePlayer(jersey, newRuns, newWickets, newMatches);
                break;
            }
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    playerList.writeToFile("players.txt");

    return 0;
}
