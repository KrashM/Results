// Overall екстра само може да се спести малко писане.
// Плюс желателно е да си поизчистиш main-а малко.
// 23т.
#include <iostream>
#include <cstring>

#define MAX 1024

using std::cin;
using std::cout;
using std::endl;


struct Card {
	int value;
	int color;
};

enum Colors // Бонус точка за enum-а
{
	YELLOW = 1,
	GREEN = 2,
	BLUE = 3,
	RED = 4,
	BLACK = 5
};


//enum SortingValuesOfColors {
//	SORT_YELLOW = 5,
//	SORT_GREEN = 4,
//	SORT_BLUE = 3,
//	SORT_RED = 2,
//	SORT_BLACK = 1
//};


void GetColor(int x, char* ch) {
	switch (x) {
	case 1:
		strcpy(ch, "YELLOW");
		break;
	case 2:
		strcpy(ch, "GREEN");
		break;
	case 3:
		strcpy(ch, "BLUE");
		break;
	case 4:
		strcpy(ch, "RED");
		break;
	case 5:
		strcpy(ch, "BLACK");
		break;
	}
}

int main() {

	int n;
	cin >> n;

	// Валидация за n.

	// �������� ������ ����� � ����� �� ����� �� �� ����� �� �� ������� �� ��������� (� �������, ��� �����) ��-�����.
	Card cards[MAX]; // Динамичен масив трябва да е.


	for (int i = 0; i < n; i++)
	{
		Card card;
		char number[MAX];
		char value[2];

		cin >> number;

		// print with color
		switch (number[0]) {
		case '1':
			value[0] = number[3];
			value[1] = number[4];

			card.value = atoi(value);
			card.color = YELLOW;

			cards[i] = card;
			break;

		case '2':
			value[0] = number[3];
			value[1] = number[4];

			card.value = atoi(value);
			card.color = GREEN;

			cards[i] = card;
			break;

		case '3':
			value[0] = number[3];
			value[1] = number[4];

			card.value = atoi(value);
			card.color = BLUE;

			cards[i] = card;
			break;

		case '4':
			value[0] = number[3];
			value[1] = number[4];

			card.value = atoi(value);
			card.color = RED;

			cards[i] = card;
			break;

		case '5':
			value[0] = number[3];
			value[1] = number[4];

			card.value = atoi(value);
			card.color = BLACK;

			cards[i] = card;
			break;

        // �� ����������� �� ����� ��������� ��� ���� �� �� ���������
        // (���� ����� �� default ���� ������ �� ����������� ����������� ����� �� ������� �����.
		}
	}

	//bubble sort
	Card temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cards[j].value < cards[i].value) {

				temp = cards[i];
				cards[i] = cards[j];
				cards[j] = temp;
			}

			else if (cards[j].value == cards[i].value) {

				char first[MAX];
				char second[MAX];
				GetColor(cards[i].color, first);
				GetColor(cards[j].color, second);


				// change colors in sorting order (�� �� �� ��������� ��� �� ����� ����� ������� �� ������� �� ����)

				// ���� ������� � �� ������ ���� bubble sort � bubble sort-a, �� ������ ���������� ����� n^4 � ��� �� �� ����
				// �� �� � ���� ������� � ����� ��������� but yeah
				if (cards[j].color == 1) cards[j].color = 5;
				else if (cards[j].color == 2) cards[j].color = 4;
				else if (cards[j].color == 4) cards[j].color = 2;
				else if (cards[j].color == 5) cards[j].color = 1;

				if (cards[i].color == 1) cards[i].color = 5;
				else if (cards[i].color == 2) cards[i].color = 4;
				else if (cards[i].color == 4) cards[i].color = 2;
				else if (cards[i].color == 5) cards[i].color = 1;

				if (cards[j].color < cards[i].color) {

					temp = cards[i];
					cards[i] = cards[j];
					cards[j] = temp;
				}


				// ���� ���� ��� ��������� ����������� �� ����, ������� ������ ���������� �� ��������� ��
				// enum-a, �� �� ����� �� ���������� ������� �� ������� ��-�����.
				if (cards[j].color == 5) cards[j].color = 1;
				else if (cards[j].color == 4) cards[j].color = 2;
				else if (cards[j].color == 2) cards[j].color = 4;
				else if (cards[j].color == 1) cards[j].color = 5;

				if (cards[i].color == 5) cards[i].color = 1;
				else if (cards[i].color == 4) cards[i].color = 2;
				else if (cards[i].color == 2) cards[i].color = 4;
				else if (cards[i].color == 1) cards[i].color = 5;

				/*
				�������� �� sorting order-a ��� �� �� �� ����� ���� ����� �����
                (�� �������� � ������ reverse sorting order �� default-��� ����� � ����� �� �������)
				SORT_YELLOW = 5,
				SORT_GREEN = 4,
				SORT_BLUE = 3,
				SORT_RED = 2,
				SORT_BLACK = 1*/
			}
		}
	}

	//print
	cout << "\n";
	cout << "\n";
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
	    // ��� ������� ����� �� �������.
		char ch[MAX];
		GetColor(cards[i].color, ch);

		// strcmp ����� 0 �� true � 1 �� false, ������ ������ ���������� ! �� �� ������ ������
		if (!std::strcmp(ch, "BLACK")) {
			if (cards[i].value == 13)
				cout << "(CHANGE COLOR)" << " ";
			else if (cards[i].value == 14)
				cout << "(+4)" << " ";
			// �� ������� �������� �� �������� ��������� � black color, ������ �� ������� �� ���������.
		}
		else {
			if (cards[i].value == 11)
				cout << "(" << ch << " REVERSE" << ")" << " ";
			else if (cards[i].value == 12)
				cout << "(" << ch << "STOP" << ")" << " ";
			else {
				cout << "(" << ch << " " << cards[i].value << ")" << " ";
			}
		}
	}

	cout << "\n";

	return 0;
}

