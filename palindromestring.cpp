#include<iostream>
#include<string>
using namespace std;
char toLowerCase(char st){
    if(st >='a'&& st<='z'){
        return st;
    }
    else{
        char temp = st-'A'+'a';
        return temp;
    }
}
int palindrome(char at[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(toLowerCase(at[s])!= toLowerCase(at[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }

    }
    return 1;
}

int main(){
    char t[4];
    cout<<"Enter a string"<<endl;
    cin>>t;
    cout<<"palindrome or not "<<palindrome(t,4)<<endl;
    cout<<"to Lowercase"<<toLowerCase('B');
    return 0;
}