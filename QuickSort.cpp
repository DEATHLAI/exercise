#include <stdexcept>
#include <iostream>
#include <cstdlib>

int RandomInRange(int start, int end)
{
	int range = end - start;
	int val = rand() % range + start;

	return val;
}

void Swap(int* a, int* b)
{
	int iTemp = *a;
	*a = *b;
	*b = iTemp;
}

int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >=length)
		throw std::logic_error("Invalid Parameters");

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
		if (data[index] < data[end]){
			++small;
			if (small != index)
				Swap(&data[small], &data[index]);
		}

	++small;
	Swap(&data[small], &data[end]);

	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;

	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort(data, length, index + 1, end);
}

int main()
{
	int a[7] = {2,1,4,3,6,7,5};
	QuickSort(a,7,0,6);
	for(auto i : a)
		std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}
