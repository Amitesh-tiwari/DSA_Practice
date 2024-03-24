Problem statement
A Derangement is a permutation of ‘N’ elements,
 such that no element appears in its original position. 
 For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, 
 because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements 
possible of a set of N elements.

//code

long long int countDerangements(int n) {
    
    if(n  == 1 or n == 2){
        return n-1;
    }

    long long int prevOne = 0;
    long long int prevTwo = 1;

    for(int i = 3;i<= n; i++){
        long long int curr = ( (i - 1) % MOD *(prevOne %MOD + prevTwo %MOD) %MOD)%MOD;
        prevOne = prevTwo;
        prevTwo = curr;
    }

    return prevTwo;
}