// 25т.
#include <iostream>


using std::size_t;



void PositiveIntegerCheck (int &n) {
    while (n < 1) {
        std::cout << "Please enter a correct number:";
        std::cin >> n;
    }
}




bool Compare(int num1, int color1, int num2, int color2) {
    if (num1 != num2) {
        return num1 < num2;
    } else {
        return color1 > color2;
    }
}





void Swap(int *numbers, int *colors, const int n ) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (Compare(numbers[i], colors[i], numbers[j], colors[j])) {
                int tempColor = colors[i];
                colors[i] = colors[j];
                colors[j] = tempColor;
                int tempNum = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tempNum;
            }
        }
    }
}




void PrintUno(const int *numbers, const int *colors,const size_t n) {
    for (int i = 0; i < n; i++) {
        if (colors[i] == 5) {
            if (numbers[i] == 13) std::cout << "(CHANGE COLOR)" << " ";
            else std::cout << "(+4)" << " ";
        } else {
            switch (colors[i]) {
                case 1:
                    std::cout << "(YELLOW ";
                    break;

                case 2:
                    std::cout << "(GREEN ";
                    break;

                case 3:
                    std::cout << "(BLUE ";
                    break;

                case 4:
                    std::cout << "(RED ";
                    break;
            }
            if (numbers[i] > 9) {
                switch (numbers[i]) {
                    case 10:
                        std::cout << "+2) ";
                        break;

                    case 11:
                        std::cout << "REVERSE) ";
                        break;

                    case 12:
                        std::cout << "STOP) ";
                        break;
                }
            } else std::cout << numbers[i] << ") ";
        }
    }
}




int main() {
    int n;
    std::cin >> n;

    PositiveIntegerCheck(n);
    int colors[n]; // Не можем да декларираме статичен масив с променлив размер.
    int numbers[n]; // Не можем да декларираме статичен масив с променлив размер.
    for (int i = 0; i < n; i++) {
        int card;
        std::cin >> card;
        card /=10;
        int color = card / 10000;
        int num = card % 100;

        if ((color < 1 || color > 5 || (color == 5 && (num < 13 || num > 14))) ||
            (color < 5 && (num < 0 || num > 12))) {
            std::cout << "WRONG INPUT: " << card;
            return 0;
        }

        numbers[i] = num;
        colors[i] = color;
    }

    Swap(numbers, colors, n);
    PrintUno(numbers, colors, n);
    return 0;
}
// Тази задача беше голяма играчка. Все да пипна нещо и нещо друго спираше да работи. Сега поне изглежда изчистена,
// че по-рано не се четеше. Като цяло ми отне МНОГО повече време да я напиша, отколкото очаквах.