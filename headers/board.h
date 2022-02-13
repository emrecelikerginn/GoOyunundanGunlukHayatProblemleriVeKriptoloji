#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

enum STATE { EMPTY, BLACK, WHITE };

class Board
{
    private:
    int m_board[19][19];
    int GetColumnOrder(wchar_t column);

    public:
    Board(wstring seed);
    void ShowBoard();
    int GetCountOfStateInColumn(STATE state, wchar_t column);
    int GetCountOfStateInRow(STATE state, int row);
};

#endif