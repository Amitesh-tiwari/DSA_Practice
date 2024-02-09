#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data" << " "<< value << endl;
    }
};

void InsertAtHead(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp1 = new Node(d);
        tail = temp1;
        temp1->next = temp1;
    }
    else
    {
        // non empty list
        // assuming that the data is present in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found curr is representing the found element
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        //assuming that the list is non empty and the value is 
        // present in the list
        Node* prev = tail;
        Node*curr = prev->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(tail== curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;

    }

}
void print(Node *&tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout<<endl;
}

int main()
{
    Node *tail = NULL;
    InsertAtHead(tail, 3, 5);
    print(tail);
    InsertAtHead(tail, 5, 7);
    print(tail);
    InsertAtHead(tail, 7, 9);
    print(tail);
    InsertAtHead(tail, 5, 6);
    print(tail);
    deleteNode(tail,5);
    print(tail);
    return 0;
}
