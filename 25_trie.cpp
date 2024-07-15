#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
    public:
    char c;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char c){
        this->c=c;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie {

public:
    TrieNode *root;
    public:
    Trie(){
        root=new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
        void insertUtil(TrieNode* root,string s){
        //base case;
        if(s.size()==0){root->isTerminal=true;return;}
        int index=s[0]-'a';
        TrieNode* child;

        //absent
        if(root->children[index]==NULL){
            child=new TrieNode(s[0]);
            root->children[index]=child;}

        //present
        else{child=root->children[index];}

        //recursive case
        insertUtil(child,s.substr(1));
    }
    void insert(string word) {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
       bool searchUtil(TrieNode* root,string s){
        //base case
        if(s.size()==0){return root->isTerminal;}
        int index=s[0]-'a';
        TrieNode* child;
        //absent
        if(root->children[index]!=NULL)
        {child=root->children[index];}
        //present
        else
        {return false;}
        //recursive case
        return searchUtil(child,s.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
           bool startwithUtil(TrieNode* root,string s){
        //base case
        if(s.size()==0){return true;}
        int index=s[0]-'a';
        TrieNode* child;
        //absent
        if(root->children[index]!=NULL)
        {child=root->children[index];}
        //present
        else
        {return false;}
        //recursive case
        return startwithUtil(child,s.substr(1));
    }
    bool startsWith(string prefix) {
        return startwithUtil(root,prefix);
    }
};
// int main() {
// //trie is a tree data structure used for storing strings
// //root node has multiple children, each child represents a character    
// Trie *t=new Trie();
// t->insert("hello");
// t->insert("world");
// t->insert("hell");
// t->insert("he");
// t->search("hello")?cout<<"found\n":cout<<"not found\n";
// t->search("hell")?cout<<"found\n":cout<<"not found\n";
// t->search("hel")?cout<<"found\n":cout<<"not found\n";


// //creating dictionary using trie has advantage over hashmaps as space can be optimized using trie
//     return 0;
// }