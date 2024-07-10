Write a program to check queen valid position for 8*8 chess board.
if a,b is a current position of the queen and c,d is the next position of the queen. then the queen is valid if a!=c and b!=d and abs(a-c)!=abs(b-d).
a,b,c,d are user inputs

//code
class Solution {
    public:
    bool isSafe(int a, int b, int c, int d){
        if(a!=c && b!=d && abs(a-c)!=abs(b-d)){
            return true;
        }
        return false;
    }
};