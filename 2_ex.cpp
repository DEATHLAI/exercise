#include<iostream>
#include<cstring>

bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0){
		std::cout << "input error." << std::endl;
		return false;
	}
	
	for (int i = 0;i < length;++i)
		if (numbers[i] < 0 || numbers[i] > length - 1){

			std::cout << i <<  "number error." << std::endl;
			return false; 
		}

	for (int i = 0; i < length; ++i){
		while (numbers[i] != i){
			int itemp = numbers[i];

			if (numbers[i] == numbers[itemp]){
				duplication = &numbers[i];
				return true;
			}

			numbers[i] = numbers[itemp];
			numbers[itemp] = itemp;
		}
	}

	return false;
}

int main()
{
	int a[5] = {0,1,2,4,1};
	int* pTemp = nullptr;
	std::cout << duplicate(a, sizeof(a)/sizeof(int), pTemp) << std::endl;
}
