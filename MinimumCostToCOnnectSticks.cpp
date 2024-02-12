You are given an array/list ‘ARR’ of ‘N’ positive integers where each element describes the length of the stick. 
You have to connect all sticks into one. At a time, you can join any two sticks by paying a cost of ‘X’ 
and ‘Y’ where ‘X’ is the length of the first stick and ‘Y’ is the length of the second stick and 
the new stick we get will have a length equal to (X+Y). 

You have to find the minimum cost to connect all the sticks into one.

long long int minimumCostToConnectSticks(vector<int> &arr) {
     
     priority_queue<long long,vector<long long>,greater<long long> > minheap;

     for(int i=0;i<arr.size();i++){
          minheap.push(arr[i]);
     }

     long long cost = 0;

     while(minheap.size() > 1){
          long long x = minheap.top();
          minheap.pop();

          long long y = minheap.top();
          minheap.pop();

          long long sum = x+y;
          cost += sum;

          minheap.push(sum);
     }
     return cost;
}