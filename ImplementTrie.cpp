Problem statement
Implement Trie Data Structure to support these operations:

insert(word) - To insert a string "word" in Trie
search(word) - To check if string "word" is present in Trie or not.
startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".


Three type of queries denote these operations:

Type 1: To insert a string "word" in Trie.
1 word

Type 2: To check if the string "word" is present in Trie or not.
2 word

Type 3: To check if there is any string in the Trie that starts with the given prefix string "word".
3 word



/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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

class Trie {

    TrieNode* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtils(TrieNode* root, string word){

        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root ->children[index] != NULL){
            //present hain trie m word
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root ->children[index] = child;
        }
        //Recursion
        insertUtils(child,word.substr(1));

    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtils(root, word);

    }

    bool searchUtil(TrieNode* root, string word){

         if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root,word);

    }

    bool prefixUtil(TrieNode* root, string word){

         if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
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
        
       return prefixUtil(child,word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        return prefixUtil(root,prefix);
    }
};