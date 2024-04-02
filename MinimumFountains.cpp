Problem statement
There is a one-dimensional garden of length 'N'. 
On each of the positions from 0 to 'N', there is a fountain, 
and this fountain’s water can reach up to a certain range as
 explained further. In other words, there are 'N' + 1 fountains 
 located at positions 0, 1, 2, 3, …. 'N' which can be activated 
 in the garden.

You are given an integer 'N' and an array/list 'ARR' of length 'N' + 1,
 where each index of the array denotes the coverage limit of a particular
  fountain.

A fountain at index 'i' can water the area ranging from the position 'i' - 'ARR'['i'] 
to 'i' + 'ARR'['i'].

Your task is to find the minimum number of fountains that have to be activated such 
that the whole garden from position 0 to 'N' has access to
 the water from at least some fountain.

Note:

1. 0-based indexing is used in the array.
2. We only care about the garden from 0 to 'N' only. 
So if i - 'ARR'['i'] < 0 or i + 'ARR'['i'] > 'N', you may ignore the exceeding area.
3. If some fountain covers the garden from position 'A'
to position 'B', it means that the water from this fountain 
will spread to the whole line segment with endpoints 'A' and 'B'.

//code

#include <bits/stdc++.h> 
#include<unordered_map>

int findMinFountains(vector<int> &arr, int n)
{
   
   vector<vector<int>> range(n+1, vector<int> (2,0));
   for(int i =0;i <= n;i++){
       int idxLeft = max(i - arr[i],0);
       int idxRight = min(i + (arr[i]),n);
       range[i][0] = idxLeft;
       range[i][1] = idxRight;
   }

   unordered_map<int,int> maxEnds(range.size());

   for(vector<int> &clip : range){
       maxEnds[clip[0]] = max(maxEnds[clip[0]], clip[1]);
   }

   int currEnds  = -1;
   int isReachable = 0;
   int ans  =0;

   for(int i =0; i <= n; i++){

       if(isReachable >= n || i > isReachable){
           break;
       }

       if(maxEnds.count(i)){
           if( i > currEnds){
               ans++;
               currEnds = isReachable;
           }

           isReachable = max(isReachable, maxEnds[i]);
       }
   }

   if(isReachable >= n){
       return ans;
   }
   else{
       return -1;
   }
}

 