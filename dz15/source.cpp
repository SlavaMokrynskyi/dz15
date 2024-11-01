#include <iostream>
#define SIZE1 10
#define SIZE2 10
using namespace std;


int Max(int* parr1, int* parr2, int size1, int size2)
{
	int index_arr = 0;
	int index = 0;
	int max;
	max = parr1[0];
	for (int i = 0; i < size1; i++)
	{
		if (parr1[i] > max)
		{
			max = parr1[i];
			index_arr = 1;
			index = i;
		}	
	}
	for (int i = 0; i < size2; i++)
	{
		if (parr2[i] > max)
		{
			max = parr2[i];
			index_arr = 2;
			index = i;
		}
	}

	cout << "Max value of 2 arrays is: " << max << endl;
	if (index_arr == 1)
	{
		cout << "This element placed in first arr by " << index << " index" << endl;
	}
	else if (index_arr == 2)
	{
		cout << "This element placed in second arr by " << index << " index" << endl;
	}
	return 0;
}

int Min(int* parr1, int* parr2, int size1, int size2)
{
	int index_arr = 0;
	int index = 0;
	int min;
	min = parr1[0];
	for (int i = 0; i < size1; i++)
	{
		if (parr1[i] < min)
		{
			min = parr1[i];
		}
	}
	for (int i = 0; i < size2; i++)
	{
		if (parr2[i] < min)
		{
			min = parr2[i];
		}
	}

	cout << "Min value of 2 arrays is: " << min << endl;
	if (index_arr == 1)
	{
		cout << "This element placed in first arr by " << index << " index" << endl;
	}
	else if (index_arr == 2)
	{
		cout << "This element placed in second arr by " << index << " index" << endl;
	}
	return 0;
}

int Avg(int* parr1, int* parr2, int size1, int size2)
{
	int sum = 0, count = 0;
	for (int i = 0; i < size1; i++)
	{
		sum += parr1[i];
		count += 1;
	}
	for (int i = 0; i < size2; i++)
	{
		sum += parr2[i];
		count += 1;
	}

	cout << "AVG of 2 arrays is: " << (float)sum / count << endl;
	return 0;
}

void Action(int* parr1, int* parr2,int size1, int size2, int(*function)(int*,int*,int,int))
{
	function(parr1, parr2, size1, size2);
}

char* DeleteSymbolByIndex(char str[], int index, int size)
{
	if (index < 0 || index > size)
	{
		return str;
	}

	char* new_str = new char[size];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			new_str[i] = str[i];
		}
		else if (i == index)
		{
			continue;
		}
		else {
			new_str[i - 1] = str[i];
		}

	}
	new_str[size - 1] = '\0';
	delete[] str;
	return new_str;
}

char* DeleteAllEnteredSymbols(char str[], char symbol, int size)
{
	char* new_str = new char[size];
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (str[i] == symbol)
		{
			continue;
		}
		new_str[j] = str[i];
		j++;
	}

	new_str[j] = '\0';
	delete[] str;
	return new_str;
}

char* InsertSymbolByIndex(char str[],int index,char symbol ,int size)
{
	char* new_str = new char[size + 1];
	
	for (int i = 0; i < index; i++)
	{
		new_str[i] = str[i];
	}
	new_str[index] = symbol;

	for (int i = index + 1; i < size; i++)
	{
		new_str[i] = str[i - 1];
	}

	new_str[size] = '\0';
	delete[] str;
	return new_str;
}

char* ChangeSymbols(char str[], int size)
{
	char* new_str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '.')
		{
			new_str[i] = '!';
		}
		else
		{
			new_str[i] = str[i];
		}
	}
	new_str[size] = '\0';
	delete[] str;
	return new_str;
}

int CountOfEnteredSymbols(char str[], char symbol)
{
	int count = 0, i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == symbol)
		{
			count++;
		}
		i++;
	}
	return count;
}

void CountTypesInStr(char str[])
{
	int i = 0, count_letters = 0, count_nums = 0, count_sym = 0;
	
	while (str[i] != '\0')
	{
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
		{
			count_letters++;
		}
		else if (str[i] > 47 && str[i] < 58)
		{
			count_nums++;
		}
		else
		{
			count_sym++;
		}
		i++;
	}
	cout << "Count of Letters: " << count_letters << endl;
	cout << "Count of Nums: " << count_nums << endl;
	cout << "Count of Symbols: " << count_sym << endl;
}

int main()
{
	int arr1[SIZE1] = { 1,23,5,6,12,67,21,2,312,-193 };
	int arr2[SIZE2] = { 1,1239,348,123,-1234,18239,1233,56,7,99999 };
	int choice;
	int (*pFunction)(int*, int*, int, int) = Max;
	int* parr1 = arr1;
	int* parr2 = arr2;

	do{
		cout << "Chose what you need:\n1)Max\n2)Min\n3)Avg\n(Enter 0 if you wanna close a code) " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			pFunction = Max;
			Action(parr1, parr2, SIZE1, SIZE2, pFunction);
			break;
		case 2:
			pFunction = Min;
			Action(parr1, parr2, SIZE1, SIZE2, pFunction);
			break;
		case 3:
			pFunction = Avg;
			Action(parr1, parr2, SIZE1, SIZE2, pFunction);
			break;
		default:
			break;
		}
	} while (choice != 0);
	
	char* str = new char[100];
	cout << "Enter your string -> ";
	cin.getline(str,100);
	int index = 0;
	cout << "Enter index of symbol that code must delete -> ";
	cin >> index;
	int i = 0;
	int size = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	str = DeleteSymbolByIndex(str, index, size);
	cout << str;


	char sym;
	cout << "Enter what symbol you need to delete -> ";
	cin >> sym;


	str = DeleteAllEnteredSymbols(str, sym, size);
	cout << str;

	str = InsertSymbolByIndex(str, index, sym, size);
	cout << str;

	str = ChangeSymbols(str, size);
	cout << str;

	cout << "Count: " << CountOfEnteredSymbols(str, sym);
	CountTypesInStr(str);

	delete[] str;
}