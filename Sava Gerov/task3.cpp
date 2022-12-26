// 0т.
#include <iostream>

const unsigned int MAX_CAPACITY = 100;

int main() {  

    unsigned int n, m;
    
    std::cin >> n >> m;
    double ArrayOFns[] {0};

    for (size_t i = 0; i < n; i++)
    {   
        for (size_t j = 0; i < m; j++)
        {
            std::cin >> ArrayOFns[i] >> ArrayOFns[j];
            std::cout << "( " << ArrayOFns[i] << " , " << ArrayOFns[j] << " ) " << " , " ;
        }
    }


    return 0;
}

