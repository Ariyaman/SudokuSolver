#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 class Sudoku {
    private: 
        vector<vector<int>> board;
        vector<vector<int>> answer;
    
        bool isValidMove(vector<vector<int>>& board, int row, int col, int number) {
            for (int i = 0; i <= 8; ++i) {
                if (board[row][i] == number)
                return false;
            }
     
            for (int i = 0; i <= 8; ++i) {
                if (board[i][col] == number)
                    return false;
            }
            
            int row_increment = row - (row % 3);
            int col_increment = col - (col % 3);
       
            for (int i = 0; i < 3; i++) {        
                for (int j = 0; j < 3; j++) {
                    if (board[i + row_increment][j + col_increment] == number)
                    {
                        return false;
                    }
                }
            }
     
            return true;
        }
    
        bool find_answer(int row, int col, vector<vector<int>>& temporary_grid) {
            if(row == 9) {
                this->answer = temporary_grid;
                return true;
            }
    
            if(this->board[row][col] != 0)
            {
                if(col==8) {
                    return find_answer(row+1, 0, temporary_grid);
                }
    
                else {
                    return find_answer(row, col+1, temporary_grid);
                }
            }
            
            else {
                for(int i=1;i<=9;++i) {
                    if(isValidMove(temporary_grid, row, col, i)) {
                        temporary_grid[row][col] = i;
                                    
                        if(col==8) {
                            if(find_answer(row+1, 0, temporary_grid))
                            return true;
                        }
        
                        else {
                            if(find_answer(row, col+1, temporary_grid))
                            return true;
                        }
                    }
                    
                    temporary_grid[row][col] = 0;
                }
            }
            
            return false;
        }

    public: 
        Sudoku() {
            board = vector<vector<int>>(9,vector<int>(9,0));
        }
    
        void fill(vector<vector<int>> grid) {
            for(int i=0;i<grid.size();++i) {
                board[grid[i][0]][grid[i][1]] = grid[i][2];
            }
        }
    
        void autogenerate() {
            vector<vector<int>> temporary_grid = this->board;
            
            find_answer(0, 0, temporary_grid);
            
            for(int i=0;i<9;++i) {
                for(int j=0;j<9;++j) {
                    cout<<this->answer[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};


int main() {
    Sudoku s;

    int n;
    cin>>n;

    vector<vector<int>> grid;

    for(int i=0;i<n;++i) {
        int row;
        int col;
        int number;

        cin>>row>>col>>number;

        grid.push_back({row,col,number});
    }

    s.fill(grid);

    s.autogenerate();
    
    return 0;
}