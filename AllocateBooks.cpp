Problem statement
You have been given a permutation of ‘N’ integers. A sequence of ‘N’ integers is called a permutation if it contains all integers from 1 to ‘N’ exactly once. Your task is to rearrange the numbers and generate the lexicographically next greater permutation.

To determine which of the two permutations is lexicographically smaller, we compare their first elements of both permutations. If they are equal — compare the second, and so on. If we have two permutations X and Y, then X is lexicographically smaller if X[i] < Y[i], where ‘i’ is the first index in which the permutations X and Y differ.

For example, [2, 1, 3, 4] is lexicographically smaller than [2, 1, 4, 3].

//code
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i = n - 2;
    while (i >= 0 && permutation[i] >= permutation[i + 1])
    {
        i--;
    }
    if (i < 0)
    {
        sort(permutation.begin(), permutation.end());
        return permutation;
    }
    int j = n - 1;
    while (permutation[j] <= permutation[i])
    {
        j--;
    }
    swap(permutation[i], permutation[j]);
    reverse(permutation.begin() + i + 1, permutation.end());
    return permutation;
}