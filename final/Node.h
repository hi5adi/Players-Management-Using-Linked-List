template <class T>
class Node {

    T data;
    Node<T>* next;
public:
    Node(T);
    T getData();
    Node<T>* getNext();
    void setData(T);
    void setNext(Node<T>*);
};