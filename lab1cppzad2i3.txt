#include <iostream>

using namespace std;

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
	int memory_test = 1;
	if (iSizeX <= 0 || iSizeY  <= 0)
	{
		if (memory_test == 1) 
		{
			cout << "alokacja nieudana" << endl;
			cout << "\n";
		}

		return false;
	}
	else
	{
		*piTable = new int*[iSizeX];

		for (int i = 0; i < iSizeX; i++) 
		{
			(*piTable)[i] = new int[iSizeY];
		}

		if (memory_test == 1)
		{
			for (int i = 0; i < iSizeX; i++)
			{
				for (int j = 0; j < iSizeY; j++)
				{
					cout << (*piTable)[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}

		return true;
	}
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
	int memory_test = 1;
	if (iSizeX <= 0 || iSizeY <= 0)
	{
		if (memory_test == 1)
		{
			cout << "dealokacja nieudana" << endl;
			cout << "\n";
		}

		return false;
	}
	else
	{
		if (memory_test == 1)
		{
			(*piTable)[0][0] = 2;
			cout << (*piTable)[0][0];
			cout << "\n\n";
		}

		for (int i = 0; i < iSizeX; i++)
		{
			delete[](*piTable)[i];
		}


		if (memory_test == 1)
		{
			for (int i = 0; i < iSizeX; i++)
			{
				for (int j = 0; j < iSizeY; j++)
				{
					cout << (*piTable)[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}

		delete[] *piTable;
		return true;
	}

}
/*
int main()
{
	int **pi_table;
	int iSizeX = 5;
	int iSizeY = 3;
	int iSizeWrong = -4;
	b_alloc_table_2_dim(&pi_table, iSizeX, iSizeY);
	b_alloc_table_2_dim(&pi_table, iSizeWrong, iSizeY);
	b_dealloc_table_2_dim(&pi_table, iSizeX, iSizeY);
	b_dealloc_table_2_dim(&pi_table, iSizeWrong, iSizeY);
}
*/