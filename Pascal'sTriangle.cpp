You are given an integer N. Your task is to return a 2-D ArrayList 
containing the pascal’s triangle till the row N.

A Pascal's triangle is a triangular array constructed by summing adjacent elements 
in preceding rows. Pascal's triangle contains the values of the binomial coefficient. 
For example in the figure below.

For example, given integer N= 4 then you have to print.

1  
1 1 
1 2 1 
1 3 3 1

Here for the third row, you will see that the second element 
is the summation of the above two-row elements i.e. 2=1+1, 
and similarly for row three 3 = 1+2 and 3 = 1+2.

//code
/*
	Time Complexity: O(2^N)
	Space complexity: O(N)
	
	Where N denotes the number of Rows.
*/

//Recursive Approach
#include<vector>

long long int calPascal(long long int i, long long int j) {
    if (j == 0 || j == i) {
        return 1;
    } else {
        return calPascal(i - 1, j - 1) + calPascal(i - 1, j);
    }
}

vector < vector < long long int >> printPascal(int n) {
    vector < vector < long long int >> triangle;
    for (int i = 0; i < n; i++) {
        vector < long long int > temp;
        for (int j = 0; j <= i; j++) {
            temp.push_back(calPascal((long long int) i, (long long int) j));
        }
        triangle.push_back(temp);
    }
    return triangle;
}

//optimized approach

#include <bits/stdc++.h>
#include<vector>

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int > > triangle;
    vector<long long int > temp;

    for(int i=1;i<=n;i++){
      long long int rCe = 1;
      temp.clear();
      for(int  j=1;j <= i; j++){
        temp.push_back(rCe);
        rCe = rCe * (i-j)/j;
      }
      triangle.push_back(temp);
    } 
    return triangle;
}

