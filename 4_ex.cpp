#include<iostream>

bool find(const int* matrix, int rows, int columns, int number)
{
	bool found = false;

	if (matrix == nullptr || rows <= 0 || columns <= 0)
		return false;

	int row = 0, column = columns - 1;
	while (column >= 0 && row < rows){
		if (number < matrix[row * columns + column])
			--column;
		else if (number > matrix[row * columns + column])
			++row;
		else
			return true;
	}
	
	return found;
}

int main()
{
	int a[2][3] = {{1,2,3},{4,5,6}};
	std::cout << find(&a[0][0], 2, 3, 7) << std::endl;

	return 0;
}
