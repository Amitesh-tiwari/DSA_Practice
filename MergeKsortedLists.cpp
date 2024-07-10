Given 'k' sorted linked lists, each list is sorted in 
increasing order. 
You need to merge all these lists into one single sorted 
list. 
You need to return the head of the final linked list.

#include<queue>

class compare{
    public:
    bool operator()(const Node* a , const Node* b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){

    int k = listArray.size();
    if(k == 0){
        return NULL;
    }

    priority_queue<Node*, vector<Node*>, compare > minheap;

    for(int i=0;i<k;i++){
        if(listArray[i] != NULL){
            minheap.push(listArray[i]);
        }
    }
    Node* head = NULL;
    Node* tail = NULL;

    while(minheap.size()>0){
        Node* top = minheap.top();
        minheap.pop();

        if(top->next != NULL){
            minheap.push(top->next);
        }

        if(head == NULL){
            head = top;
            tail = top;
        }
        else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

