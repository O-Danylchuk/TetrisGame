#include <cassert>
#include <iostream>
#include "board.h"

void testSingleLineClear(Board& board) {
    board.clear();  // Clear the board for a fresh test
    // Fill one line
    for (int j = 0; j < 10; ++j) {
        board.set(5, j, 'X');  // Assuming 'X' is a filled cell
    }
    board.printBoard();
    int score = board.updateScore();
    assert(score == 100);
    std::cout << "Single line clear test passed.\n";
    board.printBoard();
}

void testDoubleLineClear(Board& board) {
    board.clear();
    // Fill two lines
    for (int j = 0; j < 10; ++j) {
        board.set(5, j, 'X');
        board.set(6, j, 'X');
    }
    board.printBoard();
    int score = board.updateScore();
    assert(score == 300);
    std::cout << "Double line clear test passed.\n";
    board.printBoard();
}

void testTripleLineClear(Board& board) {
    board.clear();
    // Fill three lines
    for (int j = 0; j < 10; ++j) {
        board.set(5, j, 'X');
        board.set(6, j, 'X');
        board.set(7, j, 'X');
    }
    board.printBoard();

    int score = board.updateScore();
    assert(score == 500);
    std::cout << "Triple line clear test passed.\n";
    board.printBoard();
}

void testTetrisLineClear(Board& board) {
    board.clear();
    // Fill four lines
    for (int j = 0; j < 10; ++j) {
        board.set(5, j, 'X');
        board.set(6, j, 'X');
        board.set(7, j, 'X');
        board.set(8, j, 'X');
    }
    board.printBoard();
    int score = board.updateScore();
    assert(score == 800);
    std::cout << "Tetris line clear test passed.\n";
    board.printBoard();
}

void testNoLineClear(Board& board) {
    board.clear();
    board.printBoard();
    // No filled lines
    int score = board.updateScore();
    assert(score == 0);
    std::cout << "No line clear test passed.\n";
}

int main() {
    Board board;

    testSingleLineClear(board);
    testDoubleLineClear(board);
    testTripleLineClear(board);
    testTetrisLineClear(board);
    testNoLineClear(board);

    std::cout << "All tests passed.\n";
    return 0;
}
