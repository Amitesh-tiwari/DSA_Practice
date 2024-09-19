You are given an array/list ARR consisting of N integers.
 Your task is to find all the distinct triplets present in
  the array which adds up to a given number K.

An array is said to have a triplet {ARR[i], ARR[j], 
ARR[k]} with sum = 'K' if there exists three indices i, 
j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] 
+ ARR[k] = 'K'.

Note:
1. You can return the list of values in any order. 
For example, if a valid triplet is {1, 2, -3}, then 
{2, -3, 1}, {-3, 2, 1} etc is also valid triplet. 
Also, the ordering of different triplets can be random
 i.e if there are more than one valid triplets, you can
  return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then 
return an empty list, and the output printed for such 
a test case will be "-1".

//code
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++) {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1])) {
            int low = i + 1, high = n - 1, sum = K - arr[i];
            while (low < high) {
                if (arr[low] + arr[high] == sum) {
                    res.push_back({arr[i], arr[low], arr[high]});
                    while (low < high && arr[low] == arr[low + 1]) low++;
                    while (low < high && arr[high] == arr[high - 1]) high--;
                    low++;
                    high--;
                } else if (arr[low] + arr[high] < sum) {
                    low++;
                } else {
                    high--;
                }
            }
        }
    }
    return res;
}