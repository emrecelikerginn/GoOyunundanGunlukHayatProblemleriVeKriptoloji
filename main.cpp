#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include "headers/board.h"
#include "headers/charset.h"
#include "headers/coordsys.h"
using namespace std;

#define ClearScreen system("cls"); wcout << L"┌─────────────────────────────────────────────────────┐\n│ Go Oyunundan Günlük Hayat Problemleri ve Kriptoloji │\n└─────────────────────────────────────────────────────┘\n\n"

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    system("color b");
    
    try
    {
        int choice;

        do
        {
            ClearScreen;
            wcout << L"1) Şifrele\n";
            wcout << L"2) Şifre Çöz\n";
            wcout << L"3) Koordinatlara Bak\n\n";
            wcout << L"Yapmak İstediğiniz İşlemi Seçin : ";
            wcin >> choice;
        }
        while (choice != 1 && choice != 2 && choice != 3);

        if (choice == 1 || choice == 2)
        {
            wstring stringInput, seed;
            int permutation, row;
            wchar_t column;

            ClearScreen;
            wcout << L"Kullanmak İstediğiniz Go Tahtası : ";
            wcin >> seed;

            wcout << L"123456'nın Permütasyonu : ";
            wcin >> permutation;
            wcout << L"Satır Numarası : ";
            wcin >> row;
            wcout << L"Sütun Harfi : ";
            wcin >> column;

            Board board(seed);
            Charset charset(permutation, row, column, &board);

            wcin.clear();
            wcin.sync();

            if (choice == 1)
            {
                ClearScreen;
                wcout << L"Şifrelemek İstediğiniz Metin : \n";

                getline(wcin, stringInput);
                wcout << L"\nŞifrelenmiş Metin : \n" << charset.Encrypt(stringInput);
            }
            else if (choice == 2)
            {
                ClearScreen;
                wcout << L"Çözmek İstediğiniz Metin : \n";

                getline(wcin, stringInput);
                wcout << L"\nÇözülmüş Metin : \n" << charset.Decrypt(stringInput);
            }

            wcout << L"\n\nProgramı Kapatmak İçin Herhangi Bir Tuşa Basın.";
        }
        else if (choice == 3)
        {
            int numberOfPoints, x, y, counter = 1;
            CoordinateSystem coordsys;

            ClearScreen;
            wcout << L"Girilecek Nokta Sayısı : ";
            wcin >> numberOfPoints;

            for (int i = 0; i < numberOfPoints; i++)
            {
                wcout << (i+1) << L". Nokta : ";
                wcin >> x >> y;
                coordsys.SetCoord(x, y);
            }

            ClearScreen;
            wcout << L"Sonuçlar:\n";

            int *result = coordsys.GetResults();

            for (int i = 1; i < *result; i+=2)
            {
                wcout << counter << L". Nokta : " << *(result + i) << " " << *(result + (i+1)) << "\n";
                counter++;
            }

            wcout << L"\nProgramı Kapatmak İçin Herhangi Bir Tuşa Basın.";
        }
    }
    catch(...)
    {
        ClearScreen;
        wcout << L"Bir Hata Meydana Geldi.\nProgramı Kapatmak İçin Herhangi Bir Tuşa Basın.";
    }

    getch();
    return 0;
}