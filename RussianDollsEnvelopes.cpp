Problem statement
You are given a set of ‘N’ rectangular envelopes. 
The height and width of each envelope are given by arrays,
 ‘height’ and ‘width’ respectively, each consisting of ‘N’ 
 positive integers. The height, width of the ith envelope is 
 given by ‘height[i]’ and ‘width[i]’ respectively.

You can put one envelope inside another envelope if and only if 
both the height and width of one envelope is strictly greater than 
the height and width of the other envelope.

What is the maximum number of envelopes you can Russian doll? 
(put one inside other)
Note:
Rotation of envelope is not allowed, that is, height and width 
can’t be exchanged

//code

#include<algorithm>
#include<climits>

int LIS(vector<int>& arr, int n){
    vector<int> tail(n);
    tail[0] = arr[0];
    int length = 1;

    for(int i = 1;i<n;i++){

        int j = lower_bound(tail.begin(), tail.begin()+ length, arr[i]) - tail.begin();

        if(j == length){
            tail[length++] = arr[i];
        }
        else{
            tail[j] = arr[i];
        }

    }

    return length;
    
}



int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {

    vector<vector<int>> envelopes(n, vector<int> (2));

    for(int i =0;i<n;i++){
        envelopes[i][0] = height[i];
        envelopes[i][1] = width[i];
    }

    sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2) -> bool{
        if(v1[0] < v2[0] or (v1[0] == v2[0] and v1[1] > v2[1])){
            return true;
        }

        return false;
    });

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        arr[i] = envelopes[i][1];
    }

    return LIS(arr,n);

}