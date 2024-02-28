You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings.
 If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. 
Hence, the answer is “cod”.

//code  

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root = new TrieNode(ch); 
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
            root->childCount++;
            root ->children[index] = child;
        }
        //Recursion
        insertUtils(child,word.substr(1));

    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtils(root, word);

    }

    void lcp(string str, string &ans){
        for(int i=0;i<str.length();i++){
            char ch = str[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch -'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal){
                break;
            }

        }
    }

};





string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');
    for(int i=0;i<n;i++){
        t->insert(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    
    t->lcp(first,ans);
    return ans;
}


