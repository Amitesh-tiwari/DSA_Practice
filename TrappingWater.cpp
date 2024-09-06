Problem statement
You have been given a long type array/list 'arr’ of size
'n'.It represents an elevation map wherein 'arr[i]’ 
denotes the elevation of the 'ith' bar.
Print the total amount of rainwater that can be trapped 
in these elevations.
//code
long long getTrappedWater(long long* arr, int n) {
    long long left[n], right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i = 1; i<n; i++){
        left[i] = max(left[i-1], arr[i]);
    }
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1], arr[i]);
    }
    long long ans = 0;
    for(int i = 0; i<n; i++){
        ans += min(left[i], right[i]) - arr[i];
    }
    return ans;
}