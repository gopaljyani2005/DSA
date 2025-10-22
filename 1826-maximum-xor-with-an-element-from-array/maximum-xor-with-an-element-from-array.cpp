vector<int> numToBinary(int num){
    vector<int> bin;
    while(num){
        bin.push_back(num%2);
        num = num/2;
    }
    int i = bin.size();
    while(i<32){
        bin.push_back(0);
        i++;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

class TrieNode{
    public:
    int data;
    TrieNode * children[2];
    int mini;
    TrieNode(int data){
        this->data = data;
        this->children[0] = NULL;
        this->children[1] = NULL;
        this->mini = INT_MAX;
    }
};


void insertTrie(int num, TrieNode * root){
    vector<int> bin = numToBinary(num);
    TrieNode* temp = root;
    for(int i=0;i<32;i++){
        if(temp->children[bin[i]]==NULL){
            TrieNode * node = new TrieNode(bin[i]);
            temp->children[bin[i]] = node;
        }
        temp = temp->children[bin[i]];
        temp->mini = min(temp->mini, num);
    }
    return ;
}


int elementXOR(int x, int m, TrieNode * root){
    TrieNode * temp = root;
    vector<int> xbin = numToBinary(x);
    int ans = 0;
    int i = 0;
    while(i<32){
        if(xbin[i]==0 && temp->children[1]!=NULL && temp->children[1]->mini<=m){
            ans = ans + pow(2, 31-i);
            temp = temp->children[1];
        }
        else if(xbin[i]==0 && temp->children[0]!=NULL && temp->children[0]->mini<=m){
            temp = temp->children[0];
        }
        else if(xbin[i]==1 && temp->children[0]!=NULL && temp->children[0]->mini<=m){
            ans = ans + pow(2, 31-i);
            temp = temp->children[0];
        }
        else if(xbin[i]==1 && temp->children[1]!=NULL && temp->children[1]->mini<=m){
            temp = temp->children[1];
        }
        else{
            return -1;
        }
        i++;
    }
    return ans;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        TrieNode * root = new TrieNode(0);
        for(int i=0;i<size;i++){
            insertTrie(nums[i], root);
        }

        int m = queries.size();
        vector<int> answer(m, -1);
        for(int i=0;i<m;i++){
            answer[i] = elementXOR(queries[i][0], queries[i][1], root);
        }
        return answer;
    }
};