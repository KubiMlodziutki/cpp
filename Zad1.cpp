﻿#include <iostream>

using namespace std;

void v_alloc_table_fill_34(int iSize)
{
	int memory_test = 1;
	if (iSize <= 0 && memory_test == 1) 
	{
		cout << "Nie mozna zadeklarowac tablicy o rozmiarze " << iSize << endl;
	}

	else 
	{

		int *table = new int[iSize];

		for (int i = 0; i < iSize; i++) 
		{
			*(table + i) = 34; //wartosc moze wystepowac bezposrednio
			cout << *(table + i) << " ";
		}

		delete[] table;
		cout << "\n";
	}
}

/*
int main()
{
	
	v_alloc_table_fill_34(5);
	v_alloc_table_fill_34(-10);
	v_alloc_table_fill_34(0);
}
*/