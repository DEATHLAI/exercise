#include <iostream>

int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0){
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >=0 && col < cols
			&& getDigitSum(row) + getDigitSum(col) <= threshold
			&& !visited[row * cols + col])
		return true;
	return false;
}

int movingCountCore(int threshold, int rows, int cols, 
					int row, int col, bool* visited)
{
	int count = 0;
	int position = row * cols + col;
	if (check(threshold, rows, cols, row, col, visited)){
		visited[position] = true;

		count = 1 + movingCountCore(threshold, rows, cols, 
									row - 1, col, visited)
				  + movingCountCore(threshold, rows, cols,
						  			row, col - 1, visited)
				  + movingCountCore(threshold, rows, cols,
						  			row + 1, col, visited)
				  + movingCountCore(threshold, rows, cols,
						  			row, col + 1, visited);
	}

	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows < 1 || cols < 1)
		return 0;

	bool* visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; ++i)
		visited[i] = false;

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;
	return count;
}

int main()
{
	int threshold, rows, cols;
	std::cin >> threshold >> rows >> cols;
	std::cout << movingCount(threshold, rows, cols) << std::endl;

	return 0;
}
