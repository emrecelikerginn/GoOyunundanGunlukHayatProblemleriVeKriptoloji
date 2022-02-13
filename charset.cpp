#include "headers/charset.h"

Charset::Charset(int _permutation, int _row, wchar_t _column, Board* _board)
{
    m_permutation = _permutation;
    m_row = _row;
    m_column = _column;
    m_board = _board;
}

int Charset::FindCategory(wchar_t charToFindCategory)
{
    for (int i = 0; i < 30; i++)
    {
        if (charToFindCategory == m_uppercaseConsonants[i] && i < 21)
            return CATEGORY::UPPERCASE_CONSONANTS;
        else if (charToFindCategory == m_uppercaseVowels[i] && i < 8)
            return CATEGORY::UPPERCASE_VOWELS;
        else if (charToFindCategory == m_lowercaseConsonants[i] && i < 21)
            return CATEGORY::LOWERCASE_CONSONANTS;
        else if (charToFindCategory == m_lowercaseVowels[i] && i < 8)
            return CATEGORY::LOWERCASE_VOWELS;
        else if (charToFindCategory == m_symbols[i] && i < 30)
            return CATEGORY::SYMBOLS;
        else if (charToFindCategory == m_numbers[i] && i < 10)
            return CATEGORY::NUMBERS;
    }
}

int Charset::GetShiftingAmount(int category)
{
    if (m_permutation % 10 == category + 1)
        return m_board->GetCountOfStateInColumn(STATE::EMPTY, m_column);
    else if ((m_permutation % 100) / 10 == category + 1)
        return m_board->GetCountOfStateInColumn(STATE::WHITE, m_column);
    else if ((m_permutation % 1000) / 100 == category + 1)
        return m_board->GetCountOfStateInColumn(STATE::BLACK, m_column);
    else if ((m_permutation % 10000) / 1000 == category + 1)
        return m_board->GetCountOfStateInRow(STATE::EMPTY, m_row);
    else if ((m_permutation % 100000) / 10000 == category + 1)
        return m_board->GetCountOfStateInRow(STATE::WHITE, m_row);
    else if (m_permutation / 100000 == category + 1)
        return m_board->GetCountOfStateInRow(STATE::BLACK, m_row);
        
}

wchar_t Charset::ShiftChar(int category, wchar_t charToShift, int shiftingAmount)
{
    if (category == CATEGORY::UPPERCASE_CONSONANTS)
    {
        for (int i = 0; i < 21; i++)
        {
            if (charToShift == m_uppercaseConsonants[i])
            {
                if (shiftingAmount > 0)
                    return m_uppercaseConsonants[(shiftingAmount + i) % 21];
                else if (shiftingAmount + i < 0)
                    return m_uppercaseConsonants[shiftingAmount + i + 21];
                else if (shiftingAmount + i >= 0)
                    return m_uppercaseConsonants[shiftingAmount + i];
            }
        }
    }
    else if (category == CATEGORY::UPPERCASE_VOWELS)
    {
        for (int i = 0; i < 8; i++)
        {
            if (charToShift == m_uppercaseVowels[i])
            {
                if (shiftingAmount > 0)
                    return m_uppercaseVowels[(shiftingAmount + i) % 8];
                else if (shiftingAmount + i < 0)
                    return m_uppercaseVowels[shiftingAmount + i + 8];
                else if (shiftingAmount + i >= 0)
                    return m_uppercaseVowels[shiftingAmount + i];
            }
        }
    }
    else if (category == CATEGORY::LOWERCASE_CONSONANTS)
    {
        for (int i = 0; i < 21; i++)
        {
            if (charToShift == m_lowercaseConsonants[i])
            {
                if (shiftingAmount > 0)
                    return m_lowercaseConsonants[(shiftingAmount + i) % 21];
                else if (shiftingAmount + i < 0)
                    return m_lowercaseConsonants[shiftingAmount + i + 21];
                else if (shiftingAmount + i >= 0)
                    return m_lowercaseConsonants[shiftingAmount + i];
            }
        }
    }
    else if (category == CATEGORY::LOWERCASE_VOWELS)
    {
        for (int i = 0; i < 8; i++)
        {
            if (charToShift == m_lowercaseVowels[i])
            {
                if (shiftingAmount > 0)
                    return m_lowercaseVowels[(shiftingAmount + i) % 8];
                else if (shiftingAmount + i < 0)
                    return m_lowercaseVowels[shiftingAmount + i + 8];
                else if (shiftingAmount + i >= 0)
                    return m_lowercaseVowels[shiftingAmount + i];
            }
        }
    }
    else if (category == CATEGORY::SYMBOLS)
    {
        for (int i = 0; i < 30; i++)
        {
            if (charToShift == m_symbols[i])
            {
                if (shiftingAmount > 0)
                    return m_symbols[(shiftingAmount + i) % 30];
                else if (shiftingAmount + i < 0)
                    return m_symbols[shiftingAmount + i + 30];
                else if (shiftingAmount + i >= 0)
                    return m_symbols[shiftingAmount + i];
            }
        }
    }
    else if (category == CATEGORY::NUMBERS)
    {
        for (int i = 0; i < 10; i++)
        {
            if (charToShift == m_numbers[i])
            {
                if (shiftingAmount > 0)
                    return m_numbers[(shiftingAmount + i) % 10];
                else if (shiftingAmount + i < 0)
                    return m_numbers[shiftingAmount + i + 10];
                else if (shiftingAmount + i >= 0)
                    return m_numbers[shiftingAmount + i];
            }
        }
    }
}

wstring Charset::Encrypt(wstring stringToEncrypt)
{
    wstring result = L"";

    for (int i = 0; i < stringToEncrypt.size(); i++)
    {
        if (stringToEncrypt[i] == L' ')
            result += L' ';
        else
            result += ShiftChar(FindCategory(stringToEncrypt[i]), stringToEncrypt[i], GetShiftingAmount(FindCategory(stringToEncrypt[i])));
    }

    return result;
}

wstring Charset::Decrypt(wstring stringToDecrypt)
{
    wstring result = L"";

    for (int i = 0; i < stringToDecrypt.size(); i++)
    {
        
        if (stringToDecrypt[i] == L' ')
            result += L' ';
        else
            result += ShiftChar(FindCategory(stringToDecrypt[i]), stringToDecrypt[i], -GetShiftingAmount(FindCategory(stringToDecrypt[i])));
    }

    return result;
}