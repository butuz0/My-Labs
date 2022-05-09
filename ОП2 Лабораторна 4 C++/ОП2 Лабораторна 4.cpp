#include "Header.h"
#include "BoolMatrix.h"

int main()
{
	srand(time(NULL));

	int rows, cols;
	cout << "Enter matrix size (rows, cols): ";
	cin >> rows >> cols;

	cout << "First matrix" << endl;
	BoolMatrix a(rows, cols);
	a.print();

	cout << "Second matrix" << endl;
	BoolMatrix b(rows, cols, create_matrix(rows, cols));
	b.print();

	cout << "Third matrix - conjunction of two previous matrices" << endl;
	BoolMatrix c = a | b;
	c.print();

	cout << "Inversion of third matrix" << endl;
	~c;
	c.print();

	int count = c.count_ones();
	cout << "Amount of ones in third matrix: " << count << endl;
}