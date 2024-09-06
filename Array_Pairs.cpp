Consider an array of  integers, . Find and print the 
total number of  pairs such that  where .

Input Format

The first line contains an integer, , denoting the number of elements in the array.
The second line consists of  space-separated integers describing the respective values of .

long solve(vector<int> arr) {

    long count = 0;
    unordered_map<int, int> freq;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    for(auto it=freq.begin();it!=freq.end();it++){
        count += (it->second * (it->second - 1))/2;
    }
    return count;
}