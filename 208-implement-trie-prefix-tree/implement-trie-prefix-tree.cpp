class TrieNode {
    public:
    char data;
    TrieNode * children[26];
    bool isTerminal;

    TrieNode (char data){
        this->data = data;
        for(int i=0;i<26;i++){
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode * root;
    Trie() {
        this->root = new TrieNode('*');
    }
    
    void insert(string word) {
        TrieNode * temp = this->root;
        int size = word.size();
        for(int i=0;i<size;i++){
            int index = word[i] - 'a';
            if(temp->children[index]==NULL){
                TrieNode * node = new TrieNode(word[i]);
                temp->children[index] = node;
            }
            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        int size = word.size();
        TrieNode * temp = root;
        for(int i=0;i<size;i++){
            int index = word[i] - 'a';
            if(temp->children[index]==NULL){
                return false;
            }
            else{
                temp = temp->children[index];
                if(i == size-1){
                    return temp->isTerminal;
                }
            }
        }
        return false;
    }
    
    bool startsWith(string word) {
        int size = word.size();
        TrieNode * temp = root;
        for(int i=0;i<size;i++){
            int index = word[i] - 'a';
            if(temp->children[index]==NULL){
                return false;
            }
            else{
                temp = temp->children[index];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */