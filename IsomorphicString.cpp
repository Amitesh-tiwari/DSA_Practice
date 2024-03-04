You have been given two strings, 'str1' and 'str2'.



Your task is to return true if the given two strings are isomorphic to each other, 
else return false.



Note :
Two strings are isomorphic if a one-to-one mapping is possible for every character 
of the first string ‘str1’ to every character of the second string ‘str2’ while preserving the order of the characters.

All occurrences of every character in the first string ‘str1’ 
should map to the same character in the second string, ‘str2’.

//code

#define MAX_CHARS 26

bool areIsomorphic(string &str1, string &str2)
{
    int m = str1.length();
    int n = str2.length();

    if(m != n){
        return false;
    }

    bool marked[MAX_CHARS] = {false};

    int hash[MAX_CHARS];
    memset(hash,-1,sizeof(hash));

    for(int i=0;i<n;i++){
        if(hash[str1[i]-'a'] == -1){
            if(marked[str2[i]-'a'] == true){
                return false;
            }

            marked[str2[i]- 'a'] = true;
            hash[str1[i] -'a'] = str2[i];
        }

        else if(hash[str1[i] - 'a']!= str2[i]){
            return false;
        }
    }
    return true;
}