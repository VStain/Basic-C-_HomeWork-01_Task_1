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

void record1(std::ofstream &File_Record, int arr[], int size_arr)
{
	File_Record << size_arr << endl;
	for (int i = 1; i < size_arr; ++i)
	{
		File_Record << arr[i] << " ";
		if (i == size_arr - 1)
		{
			File_Record << arr[0];
		}
	}
	File_Record << endl;
}

void record2(std::ofstream& File_Record, int arr[], int size_arr)
{
	File_Record << size_arr << endl;
	for (int i = 0; i < size_arr - 1; ++i)
	{
		if (i == 0)
		{
		   File_Record << arr[size_arr-1] << " ";
		}
		File_Record << arr[i] << " ";
	}
	File_Record << endl;
}

/*void record(std::ofstream &File_Record, int arr[], int size_arr)
{
	File_Record << size_arr << endl;
	for (int i = 0; i < size_arr; ++i)
	{
		File_Record << arr[i] << " ";
	}
	File_Record << endl;
}*/

/*int create_arr(std::ifstream& File_to_Use, string str)
{
	File_to_Use >> str;
	int Size_1 = stoi(str);
	int* Arr_1 = new int[Size_1];

	for (int i = 0; i < Size_1 && !File_to_Use.eof(); ++i)
	{
		File_to_Use >> Arr_1[i];
	}
	return Size_1 & Arr_1;
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

		//print(Arr_1, Size_1);
		
		record2(File_Record, Arr_2, Size_2);
		record1(File_Record, Arr_1, Size_1);


		delete[] Arr_1;
		Arr_1 = nullptr;
		delete[] Arr_2;
		Arr_2 = nullptr;

		cout << "Запись выполнена успешно. " << endl;
	}
	else
	{
		cout << "Файл не найден." << endl;
	}
}