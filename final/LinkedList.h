#include "Node.cpp"
#include<string>
template <class T>
class LinkedList 
{

    Node<T>* start;
	public:
	    LinkedList();
	    ~LinkedList();
	    void display();
	    void insertPos(T&, int);
	    void deletePos(int);
	    void getTop3ByJersey();
	    void getTop3ByRuns();
	    int searchElement(int);
	    void updatePlayer(int, int, int, int);
	    void readFromFile(const char* filename);
	    void writeToFile(const std::string& filename);
};