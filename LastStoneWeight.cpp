We have a collection of 'N' stones, each stone has a positive integer weight.

On each turn, we choose the two heaviest stones and smash them together. 
Suppose the stones have weights 'x' and 'y' with 'x' <= 'y'. 
The result of this smash will be:

1. If 'x' == 'y', both stones are totally destroyed;

2. If 'x' != 'y', the stone of weight 'x' is totally destroyed, 
and the stone of weight 'y' has a new weight equal to 'y - x'.

In the end, there is at most 1 stone left. 
Return the weight of this stone or 0 if there are no stones left


#include<queue>

int weightOfLastStone(int arr[], int n)
{
   priority_queue<int> pq;
   for(int i =0;i<n;i++){
       pq.push(arr[i]);
   }
   while(pq.size() > 1){
       int x = pq.top();
       pq.pop();

       int y = pq.top();
       pq.pop();

       if(x-y > 0){
           pq.push(x-y);
       }
   }

   if(pq.size() == 0){
       return 0;
   }

   return pq.top();
}