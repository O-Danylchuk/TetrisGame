#pragma once
#include <iostream>

class Board {
public:
    Board();
    void set(int x, int y, char player);
    void printBoard();
    int updateScore();
    char get(int x, int y);
    void clear();
private:
    char board[10][20];
    bool isLineFull(int i);
};