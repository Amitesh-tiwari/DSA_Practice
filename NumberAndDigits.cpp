Problem statement
You are given a positive number ‘N.’ 
You need to find all the numbers such that the sum of 
digits of those numbers to the number itself is equal to ‘N.’

For example:
You are given ‘N’ as 21, the only number whose sum
 of digits and the number itself equals 
 21 is 15 as 15 + 1 + 5 = 21. Hence the answer is [15].

 //code

#include <bits/stdc++.h> 
#include<algorithm>

int sumOfDigits(int num){
    if(num == 0){
        return 0;
    }
    return num %10 + sumOfDigits(num/10);
}
vector<int> numbersAndDigits(int n) 
{
    vector<int> numList;
    for(int num = 1; num < 1001; ++num){
        int leftVal = n- num;
        int rightVal = n+ num;

        if(leftVal >= 0 && leftVal + sumOfDigits(leftVal) == n){
            numList.push_back(leftVal);
        }

        if(rightVal + sumOfDigits(rightVal) == n && rightVal != leftVal){
            numList.push_back(rightVal);
        }
    }
    sort(numList.begin(), numList.end());
    return numList;
}
