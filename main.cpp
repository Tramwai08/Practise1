#include<iostream>

using namespace std;

class Array
{
	int* arr;
	int kol;
public:

	Array()
	{
		cin >> kol;
		arr = new int[kol];
		set();
	}

	Array(const Array& old)
	{
		kol = old.kol;
		arr = new int[kol];
		for (int i = 0; i < kol; i++)
			arr[i] = old.arr[i];
	}

	~Array()
	{
		delete[]arr;
	}


	void print()
	{
		for (int i = 0; i < kol; i++)
			cout << arr[i] << "  ";
		cout << endl;
	}

	void set()
	{

		for (int i = 0; i < kol; i++)
			arr[i] = rand() % 100;
	}


	void sort()
	{
		int temp;
		for (int i = 0; i < kol; i++)
		{
			temp = arr[i];
			for (int j = i; j < kol; j++)
				if (temp > arr[j])
				{
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
		}
	}
	int max()
	{
		sort();
		return arr[kol - 1];
	}
	int min()
	{
		sort();
		return arr[0];
	}
};

int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите размерность массива ";
	Array array;
	cout << "Ваш массив" << endl;
	array.print();
	cout << "Отсортированый массив \n";
	array.sort();
	array.print();
	cout << "Максимальное значение " << array.max() << "\nМинимальное значение " << array.min() << endl;

	return 0;
}