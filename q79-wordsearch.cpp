// Program to check if a word exists in a 2d Matrix

class Solution { 
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m,n;
        m = board.size();
        n = board[0].size();
        if(m == 0|| n == 0){
            return false;
        }
        if( word.length()==0){
            return true;
        }
           
        for (int i = 0; i<m;i++){
            for(int j = 0;j< n;j++){
                if (word[0] == board[i][j]){
                    if (exist_helper(board,i,j,0,word)){
                        return true;
                    }
                }
            }
        }
        return false;
        
        
    }
    //Takes in board,word, current length of word, and index of current letter
    bool exist_helper(vector<vector<char>>& board, int i, int j, int len, string word){
        //Base Case
        if(len == word.length()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()){
            return false;
        }
        if(board[i][j] != word[len] || board[i][j] == '*'){
            return false;
        }
        
        // Mark the used characters as *
        board[i][j] = '*';
        
        //check for the neighbours
        bool result = (exist_helper(board,i,j-1,len+1,word)|| 
                       exist_helper(board,i,j+1,len+1,word)||
                       exist_helper(board,i-1,j,len+1,word)||
                       exist_helper(board,i+1,j,len+1,word));
    
        if (result) return true;
        // Mark the character unused
        board[i][j] = word[len];
        return false;
        
        
        
    }
};