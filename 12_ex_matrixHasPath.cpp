#include <iostream>
#include <vector>
#include <cstring>
using std::vector;

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
				 const char* str, vector<int>& path, bool* visited);
bool hasPath(const char* matrix, int rows, int columns, const char* str)
{
	 if (matrix == nullptr || rows < 1 || columns < 1 || str == nullptr)
		 return false;

	 bool* visited = new bool[rows * columns];
	 memset(visited, 0, rows * columns);
	 vector<int> path;

	 for (int row = 0; row < rows; ++row)
		 for (int col = 0; col < columns; ++col)
			 if (hasPathCore(matrix, rows, columns, row, col, str, path, visited)){
				 for (auto i : path)
					 std::cout << i << ' ';
				 std::cout << std::endl;
				 delete[] visited;
				 return true;
			 }

	 delete[] visited;
	 return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
				 const char* str, vector<int>& path, bool* visited)
{
	if (str[path.size()] == '\0')
		return true;

	bool hasPath = false;
	int position = row * cols + col;
	if (row >= 0 && row < rows && col >= 0 && col < cols
			&& matrix[position] == str[path.size()] && !visited[position]){
		
		path.push_back(position);
		visited[position] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
							str, path, visited)
				|| hasPathCore(matrix, rows, cols, row - 1, col,
							str, path, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1,
							str, path, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col,
							str, path, visited);

		if (!hasPath){
			path.pop_back();
			visited[position] = false;
		}
	}

	return hasPath;
}

int main()
{
	char a[] = {'a','b','t','g','c','f','c','s','j','d','e','h','\0'};
	char str[10];
	std::cin.getline(str,12);
	std::cout << hasPath(a, 3, 4, str) << std::endl;

	return 0;
}
