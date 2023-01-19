// Като цяло е доста добре задачата.
// Някакви минимални забележки и oversight-ове.
// 22т.
#include <iostream>

int* newArray(int size);

int main() {

  int n;

  std::cin >> n;

  // Нямаш валидация за n < 0.

  int *packages = newArray(n * 4);

  //Checking for too much memory
  if(!packages) {

    std::cout << "Memory problem!" << std::endl;
    return 1;

  }

  //This is our final number
  int count = 0;

  //We input the grid
  for (int i = 1; i <= n * 4; i++) {

    // Ще хвърли грешка при i = n * 4.
    // С тази схема трябва да си заделиш n * 4 + 1 клетки.
    std::cin >> packages[i];

    // Нямаш валидация за некоректни интервали или отрицателни числа.

    //We check each row for inconvenieces
    if(i % 4 == 0) {
      // С един || могат да се обединят също. Или да се изнесе в една булева функция.
      if (packages[i - 3] <= packages[i - 1] && packages[i - 2] >= packages[i]) count++;
      else if (packages[i - 3] >= packages[i - 1] && packages[i - 2] <= packages[i]) count++;
    }
  }

  std::cout << "There are " << count << " inconvenient pairs!" << std::endl;

  delete[] packages;

  return 0;
}

//Here we allocate dynamic memory for an array
int* newArray(int size) {

    int* res = new (std::nothrow) int[size];

    // Това ти е излишно. То ако е станало проблем ще си е nullptr.
    // Тъй че можеш да махнеш целия if и да ти остане само.
    // return res;
    if (!res) {
        return NULL;
    }

    return res;
}
