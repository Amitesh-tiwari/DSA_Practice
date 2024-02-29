Problem statement
You are given a list/array of strings which denotes the contacts that exist in your phone directory. 
The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. 
One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.

//code

class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool isEnd;
        TrieNode(){
            isEnd = false;
        }

        ~TrieNode(){
            for(unordered_map<char, TrieNode*> :: iterator i = children.begin(); i!= children.end();i++)
            {
                delete i->second;
            }
        }
};

void insertContact(string &str, TrieNode* root){
    int n = str.length();
    TrieNode* itr = root;

    for(int i=0;i<n;i++){
        TrieNode* next = itr->children[str[i]];

        if(next ==  NULL){
            next = new TrieNode();
            itr->children[str[i]] = next;
        }

        itr = next;
        if(i == n-1){
            itr -> isEnd = true;
        }
    }
}

void viewSuggestionsHelp(TrieNode* curr, string prefix,vector<string> &temp){
    if(curr->isEnd){
        temp.push_back(prefix);
    }

    for(char c = 'a';c <='z';c++){
        TrieNode* next = curr->children[c];

        if(next != NULL){
            viewSuggestionsHelp(next,prefix + (char)c,temp);
        }
    }
}

vector<vector<string>> viewSuggestions(string &str, TrieNode* root){
    TrieNode* prev = root;
    string prefix = "";
    int n = str.length();

    vector<vector<string>> result;

    for(int i=0;i<n;i++){
        prefix.append(1,(char)str[i]);

        char lastCharacter = prefix[i];
        TrieNode* curr = prev->children[lastCharacter];

        if(curr == NULL){
            i++;
            break;
        }

        vector<string> temp;
        viewSuggestionsHelp(curr,prefix,temp);
        result.push_back(temp);
        temp.clear();

        prev = curr;
    }

    delete root;
    return result;
}

void insertContactList(vector<string> &contactList,TrieNode* root){
    int n = contactList.size();

    for(int i=0;i<n;i++){
        insertContact(contactList[i],root);
    }
}


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    TrieNode* root = new TrieNode();
    insertContactList(contactList,root);

    return viewSuggestions(queryStr,root);
    

}