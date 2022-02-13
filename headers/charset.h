#ifndef CHARSET_H_INCLUDED
#define CHARSET_H_INCLUDED

#include <string>
#include "board.h"
using namespace std;

enum CATEGORY { UPPERCASE_CONSONANTS, UPPERCASE_VOWELS, LOWERCASE_CONSONANTS, LOWERCASE_VOWELS, SYMBOLS, NUMBERS };

class Charset
{
    private:
    Board *m_board;
    int m_permutation, m_row;
    wchar_t m_column;

    wchar_t m_uppercaseConsonants[21] = {L'B', L'C', L'Ç', L'D', L'F', L'G', L'Ğ', L'H', L'J', L'K', L'L', L'M', L'N', L'P', L'R', L'S', L'Ş', L'T', L'V', L'Y', L'Z'};
    wchar_t m_uppercaseVowels[8] = {L'A', L'E', L'I', L'İ', L'O', L'Ö', L'U', L'Ü'};
    wchar_t m_lowercaseConsonants[21] = {L'b', L'c', L'ç', L'd', L'f', L'g', L'ğ', L'h', L'j', L'k', L'l', L'm', L'n', L'p', L'r', L's', L'ş', L't', L'v', L'y', L'z'};
    wchar_t m_lowercaseVowels[8] = {L'a', L'e', L'ı', L'i', L'o', L'ö', L'u', L'ü'};
    wchar_t m_symbols[30] = {L'+', L'-', L'*', L'/', L'.', L',', L'?', L'!', L';',L':',
                           L'^', L'\'', L'\"', L'%', L'\\', L'(', L')', L'[', L']', L'{',
                           L'}', L'=', L'_', L'&', L'|', L'<', L'>', L'$', L'£', L'#'};
    wchar_t m_numbers[10] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9'};

    int FindCategory(wchar_t charToFindCategory);
    int GetShiftingAmount(int category);
    wchar_t ShiftChar(int category, wchar_t charToShift, int shiftingAmount);

    public:
    Charset(int _permutation, int _row, wchar_t _column, Board* _board);
    int SetShiftingAmounts();
    wstring Encrypt(wstring stringToEncrypt);
    wstring Decrypt(wstring stringToDecrypt);
};

#endif