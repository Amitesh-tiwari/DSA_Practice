You have been given a text message. You have to return the Run-length Encoding of the given message.

Run-length encoding is a fast and simple method of encoding strings. 
The basic idea is to represent repeated successive characters as the character and a single count.
For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".

//code

#include <bits/stdc++.h> 
string encode(string &message)
{
    int n = message.size(),i;
    string encodedmsg = "";
    for(i=0;i<n;i++){

        char curChar = message[i];
        int charFreq = 1;
        while(i+1 <n &&message[i+1]== curChar){
            i++;
            charFreq++;
        }

        encodedmsg.push_back(curChar);
        encodedmsg.append(to_string(charFreq));
    }

    return encodedmsg;
}