// Като цяло съм доволен.
// 21т.
#include <iostream>
#define MAX 100 // Не ти е казан макс в условието.


using std::cin;
using std::cout;
using std::endl;


struct Section {
	int start, end;
};

int main() {

	int overlapCounter = 0;

	Section arr[MAX]{}; // Трябва да е динамичен.

	int n;
	cin >> n;

	// Нямаш валидация за n < 0.


	// ��������� �������� ������ � �� �������� � �����
	for (size_t i = 0; i < n * 2; i += 2)
	{
		Section first_curr_section;
		Section second_curr_section;

		cin >> first_curr_section.start;
		cin >> first_curr_section.end;

		cin >> second_curr_section.start;
		cin >> second_curr_section.end;

		arr[i] = first_curr_section;
		arr[i + 1] = second_curr_section;
	}

	// Можеше да си провериш входовете за отрицателни числа или грешни интервали(5-3).



	// ������ �������� �� ������ � ����������� ������� ���� � ��� ������ � ���������


	// � ��������� � ����� ������ �� 2-8,3-7 ���� ������������ �� ������, �� ����������� � �������� ����� �� � �������
	// ����������/������ ������ ���� ���� �� �� ����, �� �� ����������� ������, ������ ������ ��� (������������� �������� ��
	// ������) ��� �� �� ��� � ������ �� �������� ��������� - ������ ��������� >=/<= ������ ������ >/<.
	int index = 0;
	for (size_t index = 0; index < n * 2; index += 2)
	{
			// second section is fully in first 
		if (arr[index].start < arr[index + 1].start && arr[index].end > arr[index + 1].end)
			overlapCounter++;

		// first section is fully in second
		else if (arr[index + 1].start < arr[index].start && arr[index + 1].end > arr[index].end)
			overlapCounter++;

		// first.start == second.start and reverse
		else if (arr[index].start == arr[index + 1].start && arr[index].end > arr[index + 1].end)
			overlapCounter++;
		else if (arr[index + 1].start == arr[index].start && arr[index + 1].end > arr[index].end)
			overlapCounter++;

		//first.end == second.end and reverse
		else if (arr[index].start < arr[index + 1].start && arr[index].end == arr[index + 1].end)
			overlapCounter++;
		else if (arr[index + 1].start < arr[index].start && arr[index + 1].end == arr[index].end)
			overlapCounter++;

		// duplicates
		else if (arr[index].start == arr[index + 1].start && arr[index].end == arr[index + 1].end) {
			overlapCounter++;
		}
	}

	if (overlapCounter == 0)
		cout << "Ne se pripokriwat dvoiki." << endl;
	else if (overlapCounter == 1)
		cout << "Pripokriva se " << overlapCounter << " dvoika." << endl;
	else
		cout << "Pripokrivat se " << overlapCounter << " dvoiki." << endl;

}
