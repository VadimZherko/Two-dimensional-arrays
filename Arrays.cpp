#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

void fill_array(vector<vector<int>>& array, int);
void print_array(vector<vector<int>>& array, int);
void new_matrix_for_task5(int**&, int);

template <typename T>
void fill_rand_array(vector<vector<T>>&, int);
template <typename T>
void new_matrix(vector<vector<T>>, int, int);
template <typename T>
void print_matrix(vector<vector<T>>, int);
template <typename T>
void fill_rand_matrix(vector<vector<T>>&, int);
template <typename T>
void columns(vector<vector<T>>, int);
template <typename T>
bool even_col(vector<vector<T>>, int, int);
template <typename T>
bool simple_col(vector<vector<T>>, int);
template <typename T>
void sum_diag(vector<vector<T>>, int);
template <typename T>
int sum_row(vector<vector<T>>, int, int);


int max_sum_of_rows(vector<vector<int>>&, int);
int row_sum(vector<int>&, int);
int** create_matrix(int);

int main()
{
	int number_of_task;

	cout << "List of tasks" << endl;
	cout << "Task 1" << endl;
	cout << "Task 2" << endl;
	cout << "Task 3" << endl;
	cout << "Task 4" << endl;
	cout << "Task 5" << endl;

	cin >> number_of_task;
	system("cls");

	switch (number_of_task)
	{
	case 1:
	{
		task1();
		break;
	}
	case 2:
	{
		task2();
		break;
	}
	case 3:
	{
		task3();
		break;
	}
	case 4:
	{
		task4();
		break;
	}
	case 5:
	{
		task5();
		break;
	}
	default:
	{
		cout << "Incorrect input" << endl;
	}
	}
}


void task1()
{
	int size;

	cout << "Input matrix size" << endl;
	cin >> size;

	vector<vector<int>> array(size, vector<int>(size));
	fill_array(array, size);
	print_array(array, size);
}

void fill_array(vector<vector<int>>& array, int size)
{
	int number = 1, j = 0, a;

	for (int i = 0; i <= size && j < size; i++)
	{
		a = j % 2;
		a == 0 ? array[i][j] = number++ : array[i][j] = number--;

		if (i == (size - 1))
		{
			i = -1;
			j++;
			a == 0 ? number = number + size - 1 : number = number + size + 1;
		}
	}
}

void print_array(vector<vector<int>>& array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl << endl;
	}
}

void task2()
{
	int half_size, size;

	cout << "Set matrix block size";
	cin >> half_size;
	size = 2 * half_size;

	vector<vector<int>>array(size, vector<int>(size, 0));
	fill_rand_array(array, size);

	cout << "Initial matrix: " << endl;
	print_matrix(array, size);

	new_matrix(array, size, half_size);
}

template <typename T>
void print_matrix(vector<vector<T>> array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl << endl;
	}
}

template <typename T>
void fill_rand_array(vector<vector<T>>& array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[j][i] = rand();
		}
	}
}

template <typename T>
void new_matrix(vector<vector<T>> array, int size, int half_size)
{
	vector<vector<int>> matrix(size, vector<int>(size, 0));
	//move top left
	for (int i = 0; i < half_size; i++)
	{
		for (int j = 0; j < half_size; j++)
			matrix[i][half_size + j] = array[i][j];
	}
	//move top right
	for (int i = 0; i < half_size; i++)
	{
		for (int j = half_size; j < size; j++)
			matrix[i + half_size][j] = array[i][j];
	}
	//move bottom right
	for (int i = half_size; i < size; i++)
	{
		for (int j = half_size; j < size; j++)
			matrix[i][j - half_size] = array[i][j];
	}
	//move bottom left
	for (int i = half_size; i < size; i++)
	{
		for (int j = 0; j < half_size; j++)
			matrix[i - half_size][j] = array[i][j];
	}

	cout << endl << "New matrix:" << endl;;
	print_matrix(matrix, size);
}

void task3()
{
	int size;

	cout << "Set the matrix size:" << endl;
	cin >> size;

	vector<vector<int>> matrix(size, vector<int>(size, 0));
	fill_rand_matrix(matrix, size);

	cout << "The row with the highest amount is" << max_sum_of_rows(matrix, size);

}

int max_sum_of_rows(vector<vector<int>>& matrix, int size)
{
	int sum, max_sum = 0, j = 0, row = 0;
	for (int i = 0; i < size; i++)
	{
		sum = row_sum(matrix[i], size);
		if (sum > max_sum)
		{
			max_sum = sum;
			row = i;
		}
	}

	return row;
}

int row_sum(vector<int>& array, int size)
{
	int sum = 0;
	for (int j = 0; j < size; j++)
	{
		sum += abs(array[j]);
	}
	return sum;
}

void task4()
{
	int size;

	cout << "Enter array size";
	cin >> size;

	vector<vector<int>> matrix(size, vector<int>(size));

	fill_rand_matrix(matrix, size);
	print_matrix(matrix, size);
	columns(matrix, size);
	sum_diag(matrix, size);
}

template <typename T>
void fill_rand_matrix(vector<vector<T>>& matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[j][i] = -2 + (rand() % (10 - (-2) + 1));
			(matrix[j][i] % 2) == 0 ? matrix[j][i] + 1 : 1 + 1;
		}
	}
}

template <typename T>
void columns(vector<vector<T>> matrix, int size)
{
	vector<int>even_cols(size);
	int even = 0;

	cout << "Columns where all numbers are even:";
	for (int i = 0; i < size; i++)
	{
		if (even_col(matrix, size, i) == true) cout << i << ' ';
	}

	cout << "Columns where all numbers are prime:";
}

template <typename T>
bool even_col(vector<vector<T>> matrix, int size, int col)
{
	int even = 0;

	for (int j = 0; j < size; j++)
	{
		(matrix[j][col] % 2) == 0 ? even++ : even = 0;
		if ((j = size - 1) && even == size) return true;
		else return false;
	}

	return false;
}

template <typename T>
bool simple_col(vector<vector<T>> matrix, int size, int col)
{
	int simple = 0;

	for (int j = 0; j < size; j++)
	{
		matrix[j][col] == 2 || matrix[j][col] == 3 || matrix[j][col] == 5 || matrix[j][col] == 7 ? simple++ : simple = 0;
		if ((j = size - 1) && simple == size) return true;
		else return false;
	}
}

template <typename T>
void sum_diag(vector<vector<T>> matrix, int size)
{
	int  j = 0;

	for (int i = 0; i < size; i++)
	{

		if (matrix[i][j] < 0)
		{
			cout << "Line amount" << i << ' ' << sum_row(matrix, size, i) << endl;
		}
		j++;
	}
}

template <typename T>
int sum_row(vector<vector<T>> matrix, int size, int i)
{
	int sum_row = 0;
	for (int j = 0; j < size; j++)
	{
		sum_row += matrix[i][j];
	}
	return sum_row;
}

void task5()
{
	int size;

	cout << "Enter array size" << endl;
	cin >> size;

	int** matrix = create_matrix(size);
	cout << "Enter array values" << endl;
	new_matrix_for_task5(matrix, size);

}

void new_matrix_for_task5(int**& matrix, int size)
{
	double max = matrix[0][0];
	int raw = 0, col = 0;
	int** new_matrix = create_matrix(size - 1);


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> matrix[i][j];

			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
				raw = i;
				col = j;
			}
		}
	}

	int k = 0, l = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == raw) continue;
		k++;

		for (int j = 0; j < size; j++)
		{
			if (j == col) continue;
			l++;
			new_matrix[k][l] = matrix[i][j];
		}
		l = 0;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << new_matrix[i][j];
		}
	}
}

int** create_matrix(int size)
{
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++) matrix[i] = new int[size];
	return matrix;
}