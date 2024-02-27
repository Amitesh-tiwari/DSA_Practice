Trie data structure is defined as a Tree based data structure that is used for storing some collection of strings and performing efficient search operations on them. 
The word Trie is derived from reTRIEval, which means finding something or obtaining it. 

Trie follows some property that If two strings have a common prefix then they will have the same ancestor in the trie. 
A trie can be used to sort a collection of strings alphabetically as well as search whether a string with a given prefix is present in the trie or not.



#include<iostream>
using namespace std;

class TrieNode{ 
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode( char ch )
    {
        data = ch;
        for(int i=0;i<26;i++){
            children[i] == NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('/0');
    }

    void insertUtils(TrieNode* root, string word){

        if(word.length == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root ->children[index] != NULL){
            //present hain trie m word
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode*(word[0]);
            root ->children[index] = child;
        }
        //Recursion
        insertUtils(child,word.substr(1));

    }

    void insertWord(stirng word){
         insertUtils(root,word);
    }

    bool searchUtil(TrieNode* root, string word){

         if(word.length == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root ->children[index] != NULL){
            //present hain trie m word
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }
        //Recursion
       return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }

};

int main(){

    Trie *t = new Trie();

    t->insertWord("abcd");

    cout<<"Present or not" <<t->searchWord("abcd");
    
    return 0;
}