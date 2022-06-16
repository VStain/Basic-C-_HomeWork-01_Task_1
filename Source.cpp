#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void print(int arr[], int size_arr)
{
	for (int i = 0; i < size_arr; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*void record(std::ofstream File_Record, int arr[], int size_arr)
{
	for (int i = 0; i < size_arr; ++i)
	{
		File_Record << arr[i] << " ";
	}
}*/

int main()
{
	setlocale(LC_ALL, "Rus");

	string str;
	ifstream File_to_Use ("in.txt");
	ofstream File_Record ("out.txt");

	if (File_to_Use.is_open())
	{
		File_to_Use >> str;
		int Size_1 = stoi(str);
		int* Arr_1 = new int[Size_1];

		for (int i = 0; i < Size_1 && !File_to_Use.eof(); ++i)
		{
			File_to_Use >> Arr_1[i];
		}

		File_to_Use >> str;
		int Size_2 = stoi(str);
		int* Arr_2 = new int[Size_2];

		for (int i = 0; i < Size_2 && !File_to_Use.eof(); ++i)
		{
			File_to_Use >> Arr_2[i];
		}
		
		File_Record << Size_1 << endl;
		for (int i = 0; i < Size_1; ++i)
		{
			File_Record << Arr_1[i] << " ";
		}
		File_Record << endl;

		File_Record << Size_2 << endl;
		for (int i = 0; i < Size_2; ++i)
		{
			File_Record << Arr_2[i] << " ";
		}
		File_Record << endl;

		delete[] Arr_1;
		Arr_1 = nullptr;
		delete[] Arr_2;
		Arr_2 = nullptr;
	}
	else
	{
		cout << "Файл не найден." << endl;
	}
}