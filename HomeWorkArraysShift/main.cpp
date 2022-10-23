// Сдвиг массива на заданное число элементов
#include<iostream>
#include<conio.h>
using namespace std;

//#define ARRAYS_SHIFT
#define BINARY_DECIMAL_HEX
//#define TEST

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef ARRAYS_SHIFT
	cout << "\t*** Домашнее задание: Сдвиг массива на заданное число элементов ***\n\n";
	int shift;
	const int SIZE = 10;
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "\tВведите число, на которое нужно сдвинуть массив (отрицательные числа для сдвига влево, положительные - для сдвига вправо): \n"; cin >> shift;
	
	if (shift > 0)
	{
		if (shift > SIZE) shift %= SIZE;
		shift = SIZE - shift;
	}
	else
	{
		shift = -shift;
		if (shift > SIZE) shift %= SIZE;
	}
	cout << "\tshift = " << shift << endl;
	//Вывод начального массива
	for (int i = 0; i < SIZE; i++)
	{
		cout << '\t' << arr[i];
	}
	cout << endl;
	for (int i = 0; i < shift; i++)
	{
		int temp = arr[0]; //переменная для временного хранения перемещаемой ячейки массива
		for (int i = 0; i < SIZE; i++)
		{
			(i == SIZE - 1) ? arr[i] = temp : arr[i] = arr[i + 1];
		}
	}
	//вывод смещенного массива в консоль
	for (int i = 0; i < SIZE; i++)
	{
		cout << '\t' << arr[i];
	}
	cout << endl;
#endif

#ifdef BINARY_DECIMAL_HEX
	//3. Десятичное число, введенное с клавиатуры перевести в двоичную систему счисления;
	//4. Десятичное число, введенное с клавиатуры перевести в шестнадцатеричную систему счисления;
	//Алгоритм перевода Dec в Bin и Hex здесь :
	//https://github.com/okovtun/BV_225/blob/master/DataTypes/NumericSystems.pdf

	cout << "\t*** Домашнее задание ****\n\tПеревод десятичного числа в двоичное\n";
	const int SIZE = 16;
	int input_dec, base = 0, output = 0, digit = 1;
	bool zero = false; //начальные нули
	int arr[SIZE];
	char arr_out[SIZE];
	cout << "\tВведите десятичное число, которое требуется перевести в другую систему счисления: "; cin >> input_dec;
	cout << "\n\tнажмите \"h\" для перевода в шестнадцатиричную форму, \"o\" для перевода в восьмеричную форму или \"b\" для перевода в двоичную форму: ";
	while (base == 0)
	{
		switch (_getch())
		{
		case 'H':
		case 'h':
		case 'Р':
		case 'р': base = 16; break;
		case 'b':
		case 'B':
		case 'и':
		case 'И': base = 2; break;
		case 'o':
		case 'O':
		case 'щ':
		case 'Щ': base = 8; break;
		default: cout << "К сожалению, вы нажали не ту клавишу. Попробуйте ещё раз.";
		}
	}
	/*do
	{
		output = input_dec % base * digit + output;
		input_dec /= base;
		digit *= 10;
	}
	while (input_dec / base);
	output = input_dec % base * digit + output;*/
	for (int i = SIZE - 1; i >= 0; i--)
	{
		arr[i] = input_dec % base;
		input_dec /= base;
	}
	cout << "\n\t\tРезультат = ";
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == 10) arr_out[i] = 'A';
		else if (arr[i] == 11) arr_out[i] = 'B';
		else if (arr[i] == 12) arr_out[i] = 'C';
		else if (arr[i] == 13) arr_out[i] = 'D';
		else if (arr[i] == 14) arr_out[i] = 'E';
		else if (arr[i] == 15) arr_out[i] = 'F';
		else arr_out[i] = arr[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		if ((int)arr_out[i] != 0) zero = true;
		if (zero)
		{
			if (i % 4 == 0) cout << ' ';
			arr_out[i] > 9 ? cout << arr_out[i] : cout << (int)arr_out[i];
		}
	}
	cout << endl;
#endif // BINARY_DECIMAL_HEX
}