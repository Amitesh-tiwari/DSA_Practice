You are given an array/list NUM of integers.
You are supposed to rearrange the elements of 
NUM such that no two adjacent elements will be the same 
or find out if it not possible.

For example:
Input: arr[] = {1,1,1,2,2,2} 
Output: {1,2,1,2,1,2}

//code

#include <bits/stdc++.h> 
#include<queue>
#include<unordered_map>

class compare{
    public:
    bool operator()(pair<int,int>p1, pair<int,int> p2){
        return p1.second < p2.second;
    }
};
vector<int> rearrange(vector<int>& num)
{

    vector<int> output;
    priority_queue<pair<int,int> , vector<pair<int,int>>, compare> pq;

    int n = num.size();
    unordered_map<int,int> freq;

    for(int i=0;i<n;i++){
        freq[num[i]]++;
    }

    for(auto x: freq){
        pq.push({x.first,x.second});
    }

    pair<int,int>prev{-1,-1};

    while(pq.size()!=0){
        pair<int,int> curr = pq.top();

        pq.pop();

        output.push_back(curr.first);

        if(prev.second > 0){
            pq.push(prev);
        }

        curr.second = curr.second-1;
        prev = curr;
    }

    if(output.size() == num.size()){
        return output;
    }

    return {-2147483648};

}