// На задачата и липсват само валидации за overflow.
// Иначе всичко е точно.
// 24т.
#include <iostream> 

using std::cin;
using std::cout; 

const size_t MAX_ELVES = 100; 
const size_t MAX_CANDIES = 20; 

bool validate (int n){
    return n > 0;
}

void input (int arr [], size_t size_of_array){
    for (size_t i = 0; i < size_of_array; ++i)
        cin >> arr [i];
    
}

int calories_per_one_elf (int arr[], size_t size_of_array){
    int sum = 0;
    for (size_t i = 0; i < size_of_array; ++i) 
        sum += arr [i];
    return sum;

}

void max_calories_and_position (int arr [], size_t size_of_array){
    int max = 0, position = 0; 
    for (size_t i = 0; i < size_of_array; ++i){
        if (max < arr[i]){
            max = arr[i];
            position = i + 1;
        }
    }
    cout << "Elf " << position << " carries the most calories - " << max;

}

int main (){

    int number_of_elves;
    cin >> number_of_elves;

    if (!validate(number_of_elves)){ // Ами > 100?
        cout << "Invalid input! ";
        return -1; 
    }
    int arr_sums [MAX_ELVES]; 
    int candies [MAX_CANDIES];

    for (size_t i = 0; i < number_of_elves; ++i){
        int n; 
        cin >> n;
        
        if (!validate (n)){ // Също > 20?
            cout << "Invalid input! ";
            return -1;
        }

        input(candies, n);
        arr_sums [i] = calories_per_one_elf (candies, n);
    }
    max_calories_and_position (arr_sums,number_of_elves);
    

    return 0;
}