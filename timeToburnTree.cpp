#include<map>
BinaryTreeNode<int>* createParentMapping(BinaryTreeNode<int>* root, int start,map<BinaryTreeNode<int>*,BinaryTreeNode<int>* > &nodeToParent){

     BinaryTreeNode<int>* res = NULL;
     queue<BinaryTreeNode<int>*> q;
     q.push(root);
     nodeToParent[root] = NULL;

     while(!q.empty()){

        BinaryTreeNode<int>* front = q.front();
        q.pop();

        if(front->data == start){
            res = front;
        }

        if(front->left){
           nodeToParent[front->left] = front;
           q.push(front->left);
        }

        if(front->right){
           nodeToParent[front->right] = front;
           q.push(front->right);
        }

     }
     return res;
 }

int burnTree(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &nodeToParent){

    map<BinaryTreeNode<int>*, bool> visited;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    visited[root] = true;
    int ans = 0;

    while(!q.empty()){
        bool flag = 0;
        int size = q.size();

        for(int i =0;i<size;i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){

                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;

            }


        }
        if(flag == 1){
        ans++;
    }
  }
  return ans;
 }

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>* > nodeToParent;
    BinaryTreeNode<int>* targetNode = createParentMapping(root,start,nodeToParent);
    int ans = burnTree(targetNode,nodeToParent);
    return ans;

}
