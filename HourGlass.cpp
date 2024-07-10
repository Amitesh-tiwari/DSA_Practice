An hourglass in  is a subset of values with indices falling in this 
pattern in 's graphical representation:

a b c
  d
e f g
There are  hourglasses in . An hourglass sum is the 
sum of an hourglass' values.
 Calculate the hourglass sum for every hourglass in , 
 then print the maximum hourglass sum. The array will 
 always be 6x6.

Example
-9 -9 -9  1 1 1 
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0
The 16 hourglass sums are:  
-63, -34, -9, 12,
-10,   0, 28, 23,   
-27, -11, -2, 10,  
9,  17, 25, 18

int hourglassSum(vector<vector<int>> arr){
    int max_sum = INT_MIN;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + 
            arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + 
            arr[i+2][j+2];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}