#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

// task 1 functions

bool is_number(string s)
{
	bool check_dot = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			if (check_dot == false)
			{
				return false;
			}
			check_dot = false;
		}
		else
		{
			if (s[i] < '0' || s[i]> '9')
			{
				return false;
			}
		}
	}
	return true;
}

// task 2 functions

string common(string stra, string strb)
{
	string newstr;
	for (int i = 0; i < stra.length(); i++)
	{
		if (strb.find(stra[i]) != -1)
		{
			newstr = newstr + stra[i];
		}
	}
	return newstr;
}

// task 3 functions

double** read_mat(string filename, int* size)
{
	ifstream read(filename);
	if (!read)
	{
		cout << "cant open this file!" << endl;
		exit(1);
	}
	read >> *size;
	double** mat = new double* [*size];
	for (int i = 0; i < *size; i++)
	{
		mat[i] = new double[*size];
		for (int j = 0; j < *size; j++)
		{
			read >> mat[i][j];
		}
	}
	read.close();
	return mat;
}

// task 4 functions

double* smallernum(double** arr, int size, double num, int* newsize)
{
	double* ary = new double;
	*newsize = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] < num)
			{
				ary[*newsize] = arr[i][j];
				*newsize++;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return ary;
}





int main()
{
	// this program present the menu of the task, the program reads the user's selection and
	// sends it to the selected task

	int task_number; // the number of task that the user select
	cout << "menu: \n";
	cout << "\n";
	cout << "0. exit \n";
	cout << "1.	For check if given string is number \n";
	cout << "2. For find common string \n";
	cout << "3. Read and print matrix from given file \n";
	cout << "4. Print array with smaller numbers \n";
	cout << "please select the number of task you want to check \n";
	cin >> task_number;
	return 0;

	while (task_number != 0)
	{
		switch (task_number)
		{

		case 1:
		{
			string num;
			cout << "please enter a number" << endl;
			cin >> num;
			cout << is_number(num);
		}
		break;

		case 2:
		{
			string a = "a!69gbo";
			string b = "%alic";
			cout << "a= " << a << endl;
			cout << "b= " << b << endl;
			cout << "the common chars are:" << common(a, b) << endl;
		}
		break;

		case 3:
		{
			int size;
			string filename;
			double** arr = read_mat(filename, &size);
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; i < size; j++)
				{
					cout << setw(6) << arr[i][j];
				}
				cout << endl;
			}
		}
		break;

		case 4:
		{
			string file_name = "numbers.txt";
			double num;
			int newsize;
			cout << "choice a number: ";
			cin >> num;
			double* ary;
			ary = smallernum(read_mat(file_name, &size), size, num, &newsize);
			cout << "new_size = " << newsize << ", new_array = {";
			for (int i = 0; i < newsize; i++)
			{
				cout << ary[i];
				if (i != newsize - 1)
				{
					cout << ", ";
				}
			}
			cout << "}";
			delete[] ary;
		}
		break;
		}
		cout << "menu: \n";
		cout << "\n";
		cout << "0. exit \n";
		cout << "1.	For check if given string is number \n";
		cout << "2. For find common string \n";
		cout << "3. Read and print matrix from given file \n";
		cout << "4. Print array with smaller numbers \n";
		cout << "please select the number of task you want to check \n";
		cin >> task_number;
	}
	cout << "thank you and goodbye";

	return 0;
}