#include <vector>
#include <string>
using namespace std;

bool checkSubgrid(vector<vector<char>>& board, int rowStart, int colStart) {
    string check = "";

    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (board[i][j] == '.')
                continue;

            if (check.find(board[i][j]) != std::string::npos) {
                return false;
            }

            check += board[i][j];
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    string check = "";

    // check rows
    for (int i = 0; i < 9; i++) {
        check = "";

        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.')
                continue;

            if (check.find(board[i][j]) != std::string::npos) {
                return false;
            }

            check += board[i][j];
        }
    }

    // check cols
    check = "";
    for (int j = 0; j < 9; j++) {
        check = "";

        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.')
                continue;

            if (check.find(board[i][j]) != std::string::npos) {
                return false;
            }

            check += board[i][j];
        }
    }

    // check each subgrid 3x3
    for (int i = 0; i <= 6; i += 3) {
        for (int j = 0; j <= 6; j += 3) {
            if (!checkSubgrid(board, i, j))
                return false;
        }
    }

    return true;
}