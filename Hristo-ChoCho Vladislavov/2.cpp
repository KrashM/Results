// 30т.
#include <iostream>

bool isItTrion(unsigned int n, int num[]) {

    // Липсват ти равнота навсякъде.
    if(num[0] < num[1]) {

        for(int i = 2; i < n-1; i += 2) {
            if(num[i] > num[i+1]) return false;

        }

        for(int i = 1; i < n-1; i += 2) {

            if(num[i] < num[i+1]) return false;

        }
    }else if(num[0] > num[1]) {
        for(int i = 2; i < n-1; i += 2) {

            if(num[i] < num[i+1]) return false;

        }

        for(int i = 1; i < n-1; i += 2) {

            if(num[i] > num[i+1]) return false;

        }
    }

    return true;

}


int main() {

    int MAX_NUM = 1000;

    unsigned int n;

    std::cin >> n;

    int num[MAX_NUM];

    for(int i = 0; i < n; i++) {
        std::cin >> num[i];
    }

    std::cout << isItTrion(n, num) << std::endl;

    return 0;
}
