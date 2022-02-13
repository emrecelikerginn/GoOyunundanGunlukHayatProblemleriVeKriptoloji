#include "headers/board.h"

Board::Board(wstring seed)
{
    int y = 0, x = 0, counter;

    for (int i = 0; i < seed.size(); i++)
    {
        if (isdigit(seed[i]))
        {
            if (isdigit(seed[i+1]))
            {
                counter = (static_cast<int>(seed[i]) - 48) * 10 + (static_cast<int>(seed[i+1]) - 48);
                i++;
            }
            else
                counter = static_cast<int>(seed[i]) - 48;
        }
        else if (seed[i] == 'e')
        {
            for (int j = 0; j < counter; j++)
                m_board[y][x++] = STATE::EMPTY;
        }
        else if (seed[i] == 'b')
        {
            for (int j = 0; j < counter; j++)
                m_board[y][x++] = STATE::BLACK;
        }
        else if (seed[i] == 'w')
        {
            for (int j = 0; j < counter; j++)
                m_board[y][x++] = STATE::WHITE;
        }
        else if (seed[i] == '-')
        {
            y++;
            x = 0;
        }
    }
}

int Board::GetColumnOrder(wchar_t column)
{
    wchar_t columnLetters[19] = {L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h', L'i', L'j', 
                                 L'k', L'l', L'm', L'n', L'o', L'p', L'q', L'r', L's'};
    
    for (int i = 0; i < 19; i++)
    {
        if (towlower(column) == columnLetters[i])
            return i;
    }
}

void Board::ShowBoard()
{
    wcout << "\n\n\n";

    for (int y = 0; y < 19; y++)
    {
        for (int x = 0; x < 19; x++)
        {
            if (m_board[y][x] == STATE::EMPTY)
                wcout << ". ";
            else if (m_board[y][x] == STATE::BLACK)
                wcout << "b ";
            else if (m_board[y][x] == STATE::WHITE)
                wcout << "W ";
        }

        wcout << "\n";
    }

    wcout << "\n\n";
}

int Board::GetCountOfStateInColumn(STATE state, wchar_t column)
{
    int counter = 0;

    for (int i = 0; i < 19; i++)
        if (m_board[i][GetColumnOrder(column)] == state)
            counter++;

    return counter;
}

int Board::GetCountOfStateInRow(STATE state, int row)
{
    int counter = 0;

    for (int i = 0; i < 19; i++)
        if (m_board[row-1][i] == state)
            counter++;

    return counter;
}