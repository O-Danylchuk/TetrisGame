#include "board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Board::clear() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::set(int x, int y, char figure) {
    board[x][y] = figure;
}

char Board::get(int x, int y) {
    return board[x][y];
}

bool Board::isLineFull(int i) {
    for (int j = 0; j < 10; ++j) {
        if (board[i][j] == ' ') {
            return false;
        }
    }
    return true;
}

void Board::updateScore(int score) {
    int linesCleared = 0;
    int score = 0;

    for (int i = 0; i < 20; ++i) { 
        if (isLineFull(i)) { 
            linesCleared++;

            for (int k = i; k > 0; --k) {
                for (int j = 0; j < 10; ++j) {
                    board[k][j] = board[k - 1][j];
                }
            }

            for (int j = 0; j < 10; ++j) {
                board[0][j] = ' ';
            }

            i--;
        }
    }

    switch (linesCleared) {
        case 1:
            score = 100;
            break;
        case 2:
            score = 300;
            break;
        case 3:
            score = 500;
            break;
        case 4:
            score = 800;
            break;
        default:
            score = 0;
            break;
    }
}
