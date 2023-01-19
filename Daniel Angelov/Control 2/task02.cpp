// 10т.
#include <iostream> 

using std::cout; 
using std::cin; 


bool is_trion (unsigned int n, int arr [], size_t size);
void input_array (int arr [], size_t size);

int main ()
{
    // Много малък капацитет си му сложил.
    // Прави го поне 100.
    const unsigned int ARRAY_SIZE = 4;
    unsigned int n; 
    int arr [ARRAY_SIZE];
    cin >> n; 
    // Не си проверяваш n >= ARRAY_SIZE.

    // Тук трябва да подаваш n за размер не ARRAY_SIZE.
    // Иначе ти се обезсмисля n.
    input_array (arr,ARRAY_SIZE);

    cout << std::boolalpha << is_trion(n,arr,ARRAY_SIZE);
    

    return 0; 
}

void input_array (int arr [], size_t size)
{
    for (size_t i = 0; i < size; i++ )
    {
        cin >> arr [i];
    }

}

bool is_trion (unsigned int n, int arr [], size_t size)
{
    bool flag = false;
    // Това е извън масива!!
    // Имаш масив от 4 клетки(индекси от 0 до 3), а се опитваш да достъпиш клетка номер 5.
    // Каква е целта на това n?!?
    arr [size + 1] = n;
    // Отново излизаш извън масива с това size + 1.
    for (unsigned int i = 0; i < size + 1; ++i)
    {
        // Тук стига да намериш една тройка поредни числа от редицата, твърдиш че цялата става такава.
        // Това не е вярно.
        // Плюс това i + 1 и i + 2 ти излизат от масива при крайните стойности.
        if (arr [i] >= arr [i+1] && arr [i+1] <= arr [i+2])
            flag = true;
        if (arr [i] <= arr [i+1] && arr [i+1] >= arr [i+2])
            flag = true;
        
    }

    return flag;
}

