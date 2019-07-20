#include<iostream>
#include<cstring>

bool charChange(char* str, int length, char origin, const char* to)
{
	if(str == nullptr || length <= 0)
		return false;

	int count = 0;
	int originalLength = strlen(str);

	for (int i = 0; i < originalLength; ++i)
		if (str[i] == origin)
			++count;
	int newLength = originalLength + count * (strlen(to) - 1);
	if (newLength > length - 1){
		std::cout << "too long" << std::endl;
		return false;
	}

	if (count != 0){
		char* p1 = str + originalLength;
		char* p2 = str + newLength;
		while (p1 >= str){
			if (*p1 != origin){
				*p2 = *p1;
				--p1;
				--p2;
			}
			else {
				--p1;
				p2 = p2 - strlen(to);
				strncpy(p2 + 1, to, strlen(to));
				//std::cout << str << std::endl;
				//std::cin.get();
			}
		}
	}
	return true;
}

int main()
{
	char a[6] = "hello";
	charChange(a, strlen(a), 'h', "yu");
	std::cout << a << std::endl;

	return 0;
}
