class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> isPresent;

        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            isPresent.clear();
            for(int j = 0; j < m; j++){
                isPresent[board[i][j]]++;
                if(board[i][j] != '.' && isPresent[board[i][j]] > 1){
                    // cout << "1 " << i << " " << j;
                    return 0;
                }
            }
        }
        isPresent.clear();
        for(int i = 0; i < m; i++){
            isPresent.clear();
            for(int j = 0; j < n; j++){
                isPresent[board[j][i]]++;
                if(board[j][i] != '.' && isPresent[board[j][i]] > 1){
                    // cout << "2 " << i << " " << j;
                    return 0;
                }
            }
        }
        isPresent.clear();

        for(int r = 0; r < n; r += 3){
            for(int c = 0; c < m; c += 3){
                isPresent.clear();
                for(int i = r; i < r+3; i++){
                    for(int j = c; j < c+3; j++){
                        isPresent[board[j][i]]++;
                        if(board[j][i] != '.' && isPresent[board[j][i]] > 1){
                            // cout << "3 " << i << " " << j;
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};