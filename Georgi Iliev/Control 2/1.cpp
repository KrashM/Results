// 25т.
#include <iostream>
using std::cin;
using std::cout;

int strlenght(const char str[]) {
	int i = 0;
	while (str[i] != '\0') ++i;
	return i;
}

// Подхода е правилен, но ще работи само за малки числа
int convertToNumber(const char str[]) {
	int num = 0;
	for (size_t i = 0; i < (strlenght(str)); i++) {
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}

bool ed(int n) {
	while (n != 0) {
		int newN = n % 10;
		if (newN % 2 != 0) return false;
		n /= 10;
	}
	return true;
}
int main()
{
	char str[1024];
	cin >> str;
	// Няма валидация на входа
	if (ed(convertToNumber(str))) cout << "True";
	else cout << "False";
	return 0;
}
