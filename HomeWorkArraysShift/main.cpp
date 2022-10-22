// ����� ������� �� �������� ����� ���������
#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	cout << "\t*** �������� �������: ����� ������� �� �������� ����� ��������� ***\n\n";
	int shift;
	const int SIZE = 10;
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "\t������� �����, �� ������� ����� �������� ������ (������������� ����� ��� ������ �����, ������������� - ��� ������ ������): \n"; cin >> shift;
	
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
	//����� ���������� �������
	for (int i = 0; i < SIZE; i++)
	{
		cout << '\t' << arr[i];
	}
	cout << endl;
	for (int i = 0; i < shift; i++)
	{
		int temp = arr[0]; //���������� ��� ���������� �������� ������������ ������ �������
		for (int i = 0; i < SIZE; i++)
		{
			(i == SIZE - 1) ? arr[i] = temp : arr[i] = arr[i + 1];
		}
	}
	//����� ���������� ������� � �������
	for (int i = 0; i < SIZE; i++)
	{
		cout << '\t' << arr[i];
	}
	cout << endl;

	//3. ���������� �����, ��������� � ���������� ��������� � �������� ������� ���������;
	//4. ���������� �����, ��������� � ���������� ��������� � ����������������� ������� ���������;
	//�������� �������� Dec � Bin � Hex ����� :
	//https://github.com/okovtun/BV_225/blob/master/DataTypes/NumericSystems.pdf
}