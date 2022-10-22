// Сдвиг массива на заданное число элементов
#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

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

	//3. Десятичное число, введенное с клавиатуры перевести в двоичную систему счисления;
	//4. Десятичное число, введенное с клавиатуры перевести в шестнадцатеричную систему счисления;
	//Алгоритм перевода Dec в Bin и Hex здесь :
	//https://github.com/okovtun/BV_225/blob/master/DataTypes/NumericSystems.pdf
}