class Solution {
    public:
        bool dfs(vector<vector<char>>& board, string& word,
                     int i, int j, int index) {

                             // Word completely found
                                     if (index == word.size())
                                                 return true;

                                                         // Boundary check
                                                                 if (i < 0 || i >= board.size() ||
                                                                             j < 0 || j >= board[0].size())
                                                                                         return false;

                                                                                                 // Character doesn't match
                                                                                                         if (board[i][j] != word[index])
                                                                                                                     return false;

                                                                                                                             // Mark as visited
                                                                                                                                     char temp = board[i][j];
                                                                                                                                             board[i][j] = '#';

                                                                                                                                                     // Explore 4 directions
                                                                                                                                                             bool found =
                                                                                                                                                                         dfs(board, word, i + 1, j, index + 1) ||
                                                                                                                                                                                     dfs(board, word, i - 1, j, index + 1) ||
                                                                                                                                                                                                 dfs(board, word, i, j + 1, index + 1) ||
                                                                                                                                                                                                             dfs(board, word, i, j - 1, index + 1);

                                                                                                                                                                                                                     // Backtracking
                                                                                                                                                                                                                             board[i][j] = temp;

                                                                                                                                                                                                                                     return found;
                                                                                                                                                                                                                                         }

                                                                                                                                                                                                                                             bool exist(vector<vector<char>>& board, string word) {

                                                                                                                                                                                                                                                     int rows = board.size();
                                                                                                                                                                                                                                                             int cols = board[0].size();

                                                                                                                                                                                                                                                                     for (int i = 0; i < rows; i++) {
                                                                                                                                                                                                                                                                                 for (int j = 0; j < cols; j++) {

                                                                                                                                                                                                                                                                                                 if (board[i][j] == word[0]) {
                                                                                                                                                                                                                                                                                                                     if (dfs(board, word, i, j, 0))
                                                                                                                                                                                                                                                                                                                                             return true;
                                                                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                                                                                                 }

                                                                                                                                                                                                                                                                                                                                                                                         return false;
                                                                                                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                                                                                                             };