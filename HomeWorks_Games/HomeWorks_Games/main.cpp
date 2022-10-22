#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
using namespace std;

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, spase = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
const int SIZE_MENU = 3;
#define LEFT_TOP_DOUBLE_ANGLE       char(201);
#define RIGHT_TOP_DOUBLE_ANGLE      char(187);
#define LEFT_BOTTOM_DOUBLE_ANGLE    char(200);
#define RIGHT_BOTTOM_DOUBLE_ANGLE   char(188);
#define LEFT_TOP_SINGLE_ANGLE       char(218);
#define RIGHT_TOP_SINGLE_ANGLE      char(191);
#define LEFT_BOTTOM_SINGLE_ANGLE    char(192);
#define RIGHT_BOTTOM_SINGLE_ANGLE   char(217);
#define DOUBLE_VERTICAL             char(186);
#define DOUBLE_HORIZONTAL           char(205);
#define SINGLE_VERTICAL             char(179);
#define SINGLE_HORIZONTAL           char(196);

void SetCursor(int x, int y)
{
    COORD myCoords = { x, y };
    SetConsoleCursorPosition(hStdOut, myCoords);
}

int menu();
void Chess();
void Game_2048();

int main()
{
    setlocale(LC_ALL, "RUS");
    int poz = 0;
    poz = menu();
    switch (poz)
    {
    case 0: system("cls"); Chess(); break;
    case 1: system("cls"); Game_2048(); break;
    case 2: system("cls"); cout << endl;
    }
}

int menu()
{
    char menu[SIZE_MENU][17] = {
        "Шахматная доска",
        "   Игра 2048   ",
        "     Выход     "
    };
    int poz = 0, key;

    for (int i = 0; i < SIZE_MENU; i++)
    {
        SetCursor(10, 10 + i);
        cout << menu[i];
    }

    do {
        for (int i = 0; i < SIZE_MENU; i++)
        {
            SetCursor(10, 10 + i);

            if (i == poz)
            {
                SetCursor(7, 10 + i);
                cout << "=> ";
            }
            else
            {
                SetCursor(7, 10 + i);
                cout << "   ";
            }
            cout << menu[i];
            if (i == poz)
            {
                SetCursor(25, 10 + i);
                cout << " <=";
            }
            else
            {
                SetCursor(25, 10 + i);
                cout << "   ";
            }
        }

        key = _getch();
        switch (key)
        {
        case Up: if (--poz < 0) poz = SIZE_MENU - 1; break;
        case Down: if (++poz > SIZE_MENU - 1) poz = 0; break;
        case Enter: return(poz);
        }
    } while (key != esc);
}

void Chess()
{
    setlocale(LC_ALL, "Russian");

    int size_board;
    cout << "Введите размер доски в клетках: "; cin >> size_board;
    size_board++;
    setlocale(LC_ALL, "C");
    for (int i = 0; i < size_board; i++)
    {
        for (int j = 0; j < size_board; j++)
        {
            if (i == 0 && j == 0)                   cout << LEFT_TOP_DOUBLE_ANGLE;
            if (i == 0 && j == size_board)          cout << RIGHT_TOP_DOUBLE_ANGLE;
            if (i == size_board && j == 0)          cout << LEFT_BOTTOM_DOUBLE_ANGLE;
            if (i == size_board && j == size_board) cout << RIGHT_BOTTOM_DOUBLE_ANGLE;
            if (j == 0 || j == size_board)          cout << DOUBLE_VERTICAL;
            if (i == 0 || i == size_board)
            {
                cout << DOUBLE_HORIZONTAL;
                cout << DOUBLE_HORIZONTAL;
            }
        }
        cout << endl;
    }
}

void Game_2048()
{
    cout << "Game_2048";
}