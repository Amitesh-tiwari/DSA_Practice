There is a collection of input strings and a collection 
of query strings. For each query string, determine how 
many times it occurs in the list of input strings. 
Return an array of the results.

There are  instances of '',  of '' and  of ''. For each 
query, add an element to the return array, .

Function Description

Complete the function matchingStrings in the editor below.
 The function must return an array of integers representing 
 the frequency of occurrence of each query string in 
 stringList.

matchingStrings has the following parameters:

string stringList[n] - an array of strings to search
string queries[q] - an array of query strings

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    vector<int> v;
    for(int i=0;i<queries.size();i++){
        int count = 0;
        for(int j=0;j<strings.size();j++){
            if(queries[i]==strings[j]){
                count++;
            }
        }
        v.push_back(count);
    }
    return v;
}