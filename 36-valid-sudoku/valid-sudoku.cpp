bool rowFunct(vector<vector<char>> & board, int row, int col){
    unordered_map<char,bool> map;
    for(int i=0;i<9;i++){
        char ch = board[row][i];
        if(ch=='.'){
            continue;
        }
        if(map[ch]){
            return false;
        }
        else{
            map[ch] = true;
        }
    }
    return true;
}


bool colFunct(vector<vector<char>> & board, int row, int col){
    unordered_map<char,bool> map;
    for(int i=0;i<9;i++){
        char ch = board[i][col];
        if(ch=='.'){
            continue;
        }
        if(map[ch]){
            return false;
        }
        else{
            map[ch] = true;
        }
    }
    return true;
}

bool matFunct(vector<vector<char>> & board, int row, int col){
    unordered_map<char,bool> map;
    row = (row/3)*3;
    col = (col/3)*3;

    for(int i=row;i<row+3;i++){
        for(int j=col;j<col+3;j++){
            char ch = board[i][j];
            if(ch=='.'){
            continue;
        }
            if(map[ch]){
                return false;
            }
            else{
                map[ch] = true;
            }
        }
    }
    return true;
}
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                bool row = true;
                bool col = true;
                bool mat = true;
                if(board[i][j] != '.'){
                    row = rowFunct(board, i, j);
                    col = colFunct(board, i, j);
                    mat = matFunct(board, i ,j);
                }
                
                if(!(row && col && mat)){
                    return false;
                }
            }
        }
        return true;
    }
};