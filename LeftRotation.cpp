A left rotation operation on an array of size  shifts 
each of the array's elements  unit to the left. 
Given an integer, , rotate the array that many steps 
left and return the result.

Function Description

Complete the rotateLeft function in the editor below.

rotateLeft has the following parameters:

int d: the amount to rotate by
int arr[n]: the array to rotate


vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> v;
    for(int i=d;i<arr.size();i++){
        v.push_back(arr[i]);
    }
    for(int i=0;i<d;i++){
        v.push_back(arr[i]);
    }
    return v;
    

}