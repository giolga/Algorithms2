#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Trie *children[26];
    bool end_of_word;
};

struct Trie *getNode() {//(void)
    struct Trie *pnode = new Trie;
    pnode->end_of_word = false;

    for(int i = 0; i < 26; i++) {
        pnode->children[i] = NULL;
    }

    return pnode;
}

void insert (struct Trie *root, string s) {
    struct Trie *tempRoot = root;
    for(int i = 0; i < s.size(); i++) {
        //finding index of each character;
        int k = s[i] - 'a';

        if(!tempRoot->children[k]) {//not NULL
            tempRoot->children[k] = getNode();
        }

        tempRoot = tempRoot->children[k];
    }

    tempRoot->end_of_word = true;

}

string search(struct Trie *root, string s) {
    struct Trie *tempRoot = root;
    string ans = "";
    for(int i = 0; i < s.size(); i++) {
        int k = s[i] - 'a';
        if(tempRoot->children[k] == NULL) {
            // return false;
            return "Not found";
        }

        ans += s[i];
        cout << tempRoot->children[k] << " ";
        tempRoot = tempRoot->children[k];
    } 

    // return (tempRoot != NULL && tempRoot->end_of_word);
    return ans;
}

int main() {
    struct Trie *root = getNode();
    insert(root, "bear");
    insert(root, "prefix");
    insert(root, "prompt");
    insert(root, "prefer");
    insert(root, "car");
    insert(root, "card");
    insert(root, "cat");
    insert(root, "beach");
    insert(root, "cardiology");
    
    cout << search(root, "bear") << endl;
    cout << search(root, "bears") << endl;
    cout << search(root, "prefix") << endl;

    return 1;
}