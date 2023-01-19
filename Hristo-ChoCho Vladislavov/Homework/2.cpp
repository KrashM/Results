// Overall добре разписана.
// Имам обаче забележки.
// 1. Моля те не бутай толкова неща в main-а. Прави си функции.
// 2. Липсват валидации.
// 3. Малки логически грешки от които се чупи задачата. (рекурсията и дължината)
// 18т.
#include <iostream>

//I have all the functions after the main one
int oneNumber(int num, int pos);

int numberLength(int uno);

bool checkIt(int uno);

int* newArray(int size);


int main() {

    int n;

    std::cin >> n;

    // Нямаш валидация за n < 0.

    int *unos = newArray(n);

    //Checking for too much memory
    if(!unos) {

      std::cout << "Memory problem!" << std::endl;
      return 1;

    }

    // Валидацията можеше да я изкараш във функция.
    //Inputting the Uno cards
    for (int i = 0; i < n; i++) {
      std::cin >> unos[i];
      if (checkIt(unos[i]) == true) { // == true е ненужно
        std::cout << "Incorrect input" << std::endl;
        return 0; // Memory leak.
      }
    }

    // Сортировката можеше да си я изведеш в отделна функция.
    //Variables just for easier understanding of the code
    int buff, type1, type2;

    //Sorting the Uno cards
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {

        type1 = oneNumber(unos[i], 4) * 10 + oneNumber(unos[i], 5);
        type2 = oneNumber(unos[j], 4) * 10 + oneNumber(unos[j], 5);

        if(type1 > type2 || (type1 == type2 && oneNumber(unos[i], 1) < oneNumber(unos[j], 1))) {
          buff = unos[i];
          unos[i] = unos[j];
          unos[j] = buff;
        }
      }
    }

    // Принта също можеше в отделна функция да се реализира.
    //Variables just for easier understanding of the code
    int color, type;

    //Printing the exact names of the uno cards
    for (int i = 0; i < n; i++) {

      color = oneNumber(unos[i], 1);
      type = oneNumber(unos[i], 4) * 10 + oneNumber(unos[i], 5);

      std::cout << "(";

      switch (color) {

        //All colors besides black
        case 1: std::cout << "YELLOW "; break;
        case 2: std::cout << "GREEN "; break;
        case 3: std::cout << "BLUE "; break;
        case 4: std::cout << "RED "; break;
        case 5:

        //Black is a bit different
          switch (type) {

            case 13: std::cout << "CHANGE COLOR) "; break;
            case 14: std::cout << "+4) "; break;

            //If it is black it does not need the rest specifications
            continue;

          }

      }

      //We type out the numbers after the colors
      if(type < 10) std::cout << type << ") ";
      else {

        //Now we have the cards that are not numbers
        switch (type) {

          case 10: std::cout << "+2) "; break;
          case 11: std::cout << "REVERSE) "; break;
          case 12: std::cout << "STOP) "; break;

        }
      }
    }

    std::cout << std::endl;

    //Clearing out the dynamic memory that has been allocated
    delete[] unos;

    return 0;
}

// Gives us a certain character of the ABCDEF number
int oneNumber(int num, int pos) {

  // От if-а не връщаш никакъв резултат.
  if(pos < 6) {

    num /= 10;
    pos++;
    // Трябва ти return пред извикването на функцията.
    oneNumber(num, pos);
    // Тези 3 реда можеше да ги напишеш като това.
    // oneNumber(num / 10, pos + 1);

  }else return num % 10;

}

//Checks how long the number is
int numberLength(int uno) {

  int length = 0;

  // Това не е много правилно условие.
  // Ако имам числото 123450, ще ти върне 0.
  while(uno % 10 != 0) {

    length++;
    uno /= 10;

  }

  return length;

}

//Checks all the possible incorrect inputs
bool checkIt(int uno) {

  int color = oneNumber(uno, 1);
  int type = oneNumber(uno, 4) * 10 + oneNumber(uno, 5);

  //If the number is of the ABCDEF type
  if(numberLength(uno) != 6) {
    return true;
  }

  //If it is a normal color uno card
  if(color > 5 || color < 1) {
    return true;
  }

  //If it is a normal type uno card
  if(type > 14) {
    return true;
  }

  //If it is a valid non-black uno card
  // Тука по-скоро вместо 10 ти трябваше 0.
  if(color == 5 && type >= 10 && type <= 12) {
    return true;
  }

  //If it is a valid black uno card
  if(color != 5 && type > 12) {
    return true;
  }

  return false;

}

//Here we allocate dynamic memory for an array
int* newArray(int size) {

    int* res = new (std::nothrow) int[size];

    // Същият коментар, както на първа задача.
    if (!res) {
        return NULL;
    }

    return res;
}
