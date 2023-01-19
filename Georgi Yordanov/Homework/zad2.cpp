// Тук имам леки забележки. Задачата си е добре разписана.
// 20т.
#include <iostream>

using std::cin;
using std::cout;

// Collects the number of meals and amount of calories per meal. 
// Returns the elf with the most calories and the amount of calories.

void collectCalories(int* arr, int size) {

    int maxElf = 0, maxCal = 0;

    for(unsigned int i = 0; i < size; i++) {

        // Ако го беше направил unsigned...
        int meals = 0;

        // If the entered number is <= 0, asks again.

        // Това тука нямаше да има нужда от него.
        do {

            cout << "Enter the number of meals: ";
            cin >> meals;

            if(meals <= 0) cout << "Invalid number. \n";

        } while(meals <= 0);

        // Не валидираш дали meals > 20.
        

        for(unsigned int j = 0; j < meals; j++) {

            // Същият проблем тука.
            int cal = 0;

            // If the entered number is <= 0, asks again.

            // Ненужно.
            do {

                cout << "Enter calorie count: ";
                cin >> cal;

                if(cal <= 0) cout << "Invalid number. \n";

            } while(cal <= 0);

            arr[i] += cal;

            if(maxCal < arr[i]) {
                maxCal = arr[i];
                maxElf = i + 1;
            }
        }

    }

    cout << "Elf #" << maxElf << " carries the highest amount of calories: " << maxCal << ".\n";

}

// Makes sure every allocated element is 0.
// Можеше да я кръстиш нещо по-смислено функцията,
// като примерно assign или memset.
void freeMem(int* arr, int size) {

    for(int i = 0; i < size; i++) arr[i] = 0;

}

int main() {

    int n = 0;
    cout << "Enter number of elves: ";
    cin >> n;

    // Валидация за n, няма.

    // Няма nothrow.
    int* calArr = new int[n];

    if(!calArr){

        cout << "Problem while allocating";
        return 1;
    }

    freeMem(calArr, n);
    collectCalories(calArr, n);

    delete[] calArr;

    return 0;
}