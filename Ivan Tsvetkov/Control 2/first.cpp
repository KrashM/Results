// 30т.


#include <iostream>
#include <cstring>
#define MAX 100


using std::cin;
using std::cout;
using std::endl;

bool leq(char n1[], char n2[]) {

	// Този подход е верен, но работи само за малки числа.
	int firstNumber = atoi(n1); // Яко че знаеш за тази функция!
	int secondNumber = atoi(n2); // Яко че знаеш за тази функция!

	if (firstNumber <= secondNumber)
		return true;
	return false;
}



int main() {
	char n1[100];
	char n2[100];

	cin.getline(n1, 100); // Прост cin работи тук.
	cin.getline(n2, 100); // Прост cin работи тук.

	// Нямаш валидация на числата.
	// Мога да въведа "929h3iu12y397h" и това ще е ок.

	cout << (leq(n1, n2)
		? "First number is smaller or equal to second number."
		: "Second number is smaller than first number.") << endl;

}


