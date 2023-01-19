// 5т.
#include <iostream> 

bool isHulm(std::size_t n, int array[1000]) {

    bool isHulm = true;
    int maxIndex; // index of the biggest number
    int maxNum = array[0]; // biggest number
    // Гледай типовете на i и n да са едни и същи при сравняването.
    for (int i = 0; i < n; i++) {
        if (array[i] > maxNum) {
            maxNum = array[i];
            maxIndex = i;
        }
    }

    int left[maxIndex], right[n - maxIndex]; 

    // Тук въртим до maxIndex без -1.
    for (int i = 0; i < maxIndex-1; i ++) {
        left[i] = array[i];
    }
    for (int i = maxIndex; i < n; i ++) {
        right[i] = array[maxIndex];
    }

    // Тук трябва да е до -1, заради i + 1.
    for (int i = 0; i < maxIndex; i++) {
        // Изпуснала си равното.
        if (!(left[i+1] > left[i])) {
            isHulm = false;
            break;
        } else isHulm = true;
    }

    for (int i = n - maxIndex; i < n; i++) {
        if (isHulm == false) {
            break;
         } else { // Този else прецаква нещата. Защото ако е хълм първата част ще въртиш само първия if.
             continue;
         }
        if (!(right[i+1] < right[i])) {
            isHulm = false;
            break;
        }
    }

    return isHulm;

}

int main () {
     
     int n;
     std::cout << "Enter n: " << std::endl;
     std::cin >> n;
    //  Нямаш валидация за n. n <= 0 или n > 1000.
     int array[1000];
     
     for (int i = 0; i < n; i++) {
        std::cout << "Enter array[" << i << "]" << std::endl;
        std::cin >> array[i];
     }

    bool result = isHulm(n, array);
    int x;
    if (result == true) {
        x = 1;
        //std::cout << 1;
    } else {
        x = 0;
        //std::cout << 0;
    }
    std::cout << x;

    return 0; 
     

}