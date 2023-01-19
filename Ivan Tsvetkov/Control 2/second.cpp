// 30т.
#include <iostream>
#include <cstring>
#define MAX 100


using std::cin;
using std::cout;
using std::endl;

bool checkTrion(int n, int arr[]) {
	bool first_case = true;
	bool second_case = true;

	// first case -> arr[0] < arr[1] > arr[2]...
	int first_state = 0;
	int second_state = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			if (arr[i] <= arr[i + 1]) {
				if (first_state == 0) {
					first_state = 1;

					continue;
				}
				else {
					first_case = false;
					break;
				}
			}
			else if (arr[i] >= arr[i + 1]) {
				if (first_state == 1) {
					first_state = 0;

					continue;
				}
				else {
					first_case = false;
					break;
				}
			}
		}
	}




	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			if (arr[i] >= arr[i + 1]) {
				if (second_state == 0) {
					second_state = 1;

					continue;
				}
				else {
					second_case = false;
					break;
				}
			}
			else if (arr[i] <= arr[i + 1]) {
				if (second_state == 1) {
					second_state = 0;

					continue;
				}
				else {
					second_case = false;
					break;
				}
			}
		}
	}



	if (first_case || second_case)
		return true;
	return false;
}



int main() {
	int n;
	cin >> n;

	// Нямаш проверка за n < 0.

	// Защо само 5 елемента?
	int arr[5];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << (checkTrion(n, arr) ? "Imame redica trion" : "Nqmame redica trion") << endl;

}



