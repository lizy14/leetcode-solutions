class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        height = board.size();
        if(height == 0){
            return false;
        }
        width = board[0].size();
        if(width == 0){
            return false;
        }
        
        for(int x=0; x<width; x++){
            for(int y=0; y<height; y++){
                bool b = exist(board, word.begin(), word.end(), x, y);
                if(b){
                    return true;
                }
            }
        }
        return false;
    }
private:
    typedef string::iterator it;
    int height;
    int width;
    bool exist(vector<vector<char>>& board, it begin, it end, int x, int y){
        if(begin == end){
            return true;
        }
        if(x < 0 || y < 0 || x >= width || y >= height){
            return false;
        }
        char& c = board[y][x];
        if(c != *begin){
            return false;
        }
        char old = c;
        c = '\0';
        
        if(
            exist(board, begin + 1, end, x, y - 1) || 
            exist(board, begin + 1, end, x, y + 1) || 
            exist(board, begin + 1, end, x - 1, y) || 
            exist(board, begin + 1, end, x + 1, y)){
            return true;
        }
        c = old;
        return false;
    }
};
