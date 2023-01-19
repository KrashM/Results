// Единственото, за което мога да се заям е, че нямаш валидация на входа.
// Задачата е топ!
// 24т.
#include <iostream>
int main()
{
    int section; 
    std::cout << "Insert how many sections are there: "; std::cin >> section;
    int a, b, c, d, counter = 0;        //a, b, c, d - elements in one section

    std::cout << "Insert all the elements: " << std::endl;

    for (int i = 0; i < section; i++)
    {
        std::cin >> a >> b >> c >> d;
        if ((a <= c && d <= b) || (a >= c && d >= b)) counter++;
    }
    
    std::cout << "There is/are "<< counter << " pair(s) which belong to the same interval";           //припокриват се
}