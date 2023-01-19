// 25т.
#include <iostream>
using std::cin;
using std::cout;

void insertArr(int arr[], int n) {
	for (size_t i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void printArr(int arr[], int n) {
	for (size_t i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << std::endl;
}
// Функцията е валидна, но може да се напише малко по-добре
bool trueForAi(int arr[], int n, int ai) {
	for (size_t i = 0; i < ai-1; i++) {
		// Вторият цикъл е безмислен
		// Схемата е следната за масив от сорта на [1, 2, 3, 4, 5, 6, 7, 8, 9], ai = 5
		// С първия цикъл въртиш до 5 включително
		// Втория цикъл също въртиш до 5 включително
		// Реално ти минаваш тези елементи 2 пъти for no reason.
		for (size_t j = i + 1; j < ai; j++) {
			if (arr[i] > arr[j]) return false;
		}
	}
	for (size_t i = ai; i < n - 1; i++) {
		// Същият проблем имаме и тук.
		for (size_t j = ai + 1; j < n; j++) {
			if (arr[i] < arr[j]) return false;
		}
	}
	return true;
}
bool trueForAnyAi(int arr[], int n) {
	// Хубаво е ai и n да са от един и същи тип като ги сравняваме.
	for (size_t ai = 1; ai < n; ai++) {
		// Подаваш size_t ai на функция, която ти иска int.
		// -> губиш информация.
		if (trueForAi(arr, n, ai)) return true;
	}
	return false;
}

int main()
{
	int n;
	int arr[1024];
	cin >> n;
	// Нямаш валидация за n < 0
	insertArr(arr, n);
	printArr(arr, n);
	if (trueForAnyAi(arr,n)) cout << "True";
	else cout << "False";

}
