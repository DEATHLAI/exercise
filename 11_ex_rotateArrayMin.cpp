#include <iostream>
#include <stdexcept>

int rotateArrayMin(int data[], int length)
{
	if (data == nullptr || length <= 0)
		throw std::logic_error("Input error");

	int start = 0, end = length - 1;
	while (end >= start){
		if (end - start <= 1)
			break;

		int middle = ((end - start) >> 1) + start;
		if (data[start] == data[end] && data[start] == data[middle]){
			++start;
			--end;
			continue;
		}
		if (data[middle] >= data[start])
			start = middle;
		if (data[middle] <= data[end]){
			end = middle;

		}
	}

	return data[end];
}

int main()
{
	int a[5] = {1,1,1,1,1};
	std::cout << rotateArrayMin(a,5) << std::endl;
}
