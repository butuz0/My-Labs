#pragma once
#include "Header.h"
class BoolMatrix
{
private:
	int rows, cols;
	int** matrix;

public:
	BoolMatrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		matrix = new int* [rows];
		matrix = new int* [rows];

		for (int i = 0; i < rows; ++i)
		{
			matrix[i] = new int[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = rand() % 2;
			}
		}
	}
	BoolMatrix(int rows, int cols, int **matrix)
	{
		this->rows = rows;
		this->cols = cols;
		this->matrix = matrix;
	}
	~BoolMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	BoolMatrix& operator|(BoolMatrix& other)
	{
		BoolMatrix& result = *this;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.matrix[i][j] = matrix[i][j] | other.matrix[i][j];
			}
		}
		return result;
	}
	BoolMatrix& operator ~ ()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = !matrix[i][j];
			}
		}
		return *this;
	}

	int get_rows()
	{
		return rows;
	}
	int get_cols()
	{
		return cols;
	}
	int** get_matrix()
	{
		return matrix;
	}

	int count_ones()
	{
		int count = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == 1)
				{
					count++;
				}
			}
		}
		return count;
	}
	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << setw(3) << matrix[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
};