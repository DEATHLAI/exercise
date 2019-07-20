#include<iostream>

int countRange(const int* numbers, int length, int start, int end)
{
	int count = 0;

	for (int i = 0; i < length; ++i)
		if (numbers[i] >= start && numbers[i] <= end)
			++count;

	return count;
}

int getDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -2;

	int start = 0;
	int end = length - 1;

	while (end >= start){
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if  (end == start)
			return (count > 1 ? start : -1);

		count > (middle - start + 1) ? end = middle : start = middle + 1;
	}

	return 0;
}

int main()
{
	int a[5] = {0,1,2,4,1};
	std::cout << getDuplication(a, sizeof(a)/sizeof(int)) << std::endl;

	return 0;
}
