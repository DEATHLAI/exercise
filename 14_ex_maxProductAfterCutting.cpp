#include <iostream>

int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int products[length + 1] = {0, 1, 2, 3};
	int max = 0;

	for (int i = 4; i <= length; ++i){
		max = 0;
		for (int j = 1; j <= i/2; ++j){
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
		}

		products[i] = max;
	}

	max = products[length];

	return max;
}

int main()
{
	int length;
	std::cin >> length;
	std::cout << maxProductAfterCutting_solution1(length) << std::endl;

	return 0;
}
