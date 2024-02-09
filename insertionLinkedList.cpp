#include<iostream>
using namespace std;

class Node{
  public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtStartHead(Node*& head,int d){

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node*&tail, int d){
    Node* temp1 = new Node(d);
    tail->next = temp1;
    tail = temp1;
}

void InsertAtPosition(Node *& tail, Node* &head, int position, int d){
    Node* temp = head;
    if(position == 1){
        InsertAtStartHead(head,d);
        return;
    }

    if(temp->next = NULL){
        InsertAtTail(tail,d);
        return;
    }
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;

}
int main(){
    
    Node* node1 = new Node(10);
    cout<<"value is "<< node1 -> data << endl;
    // cout<<"next is "<< node1 ->next << endl;
    Node* head = node1;
    print(head);
    //InsertAtStartHead(head,20);
    Node* tail = node1;
    InsertAtTail(tail,30);
    print(head);
    InsertAtTail(tail,40);
    print(head);
    InsertAtPosition(tail,head,1,50);
    print(head);
    return 0;
}