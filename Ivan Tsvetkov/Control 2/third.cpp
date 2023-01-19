// 25т.
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Point {
	double X, Y;
};


void findRectangle(int n, Point points[]) {

	// Така занулявайки ги ще работят само за положителни числа за max и само за отрицателни за min.
	// Трябваше да ги сложиш кординатите им да са равни на първата точка от масива.
	Point smallest{ 0, 0 };
	Point biggest{ 0, 0 };

	for (int i = 0; i < n; i++)
	{
		//used to find top left corner
		if (biggest.X < points[i].X) {
			biggest.X = points[i].X;
		}
		if (biggest.Y < points[i].Y) {
			biggest.Y = points[i].Y;
		}

		if (smallest.X > points[i].X)
			smallest.X = points[i].X;

		if (smallest.Y > points[i].Y)
			smallest.Y = points[i].Y;
	}

	cout << smallest.X << endl;
	cout << biggest.Y << endl;
	// Забравил си страните да изпринтиш колко са.
}

int main() {

	int n;
	cin >> n;

	// Липсва ти валидация за n < 2.

	Point arr[100];

	for (int i = 0; i < n; i++)
	{
		Point point;
		cin >> point.X;
		cin >> point.Y;

		arr[i] = point;
	}

	findRectangle(n, arr);


	return 0;
}















