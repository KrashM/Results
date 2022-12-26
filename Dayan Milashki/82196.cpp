// 1ва - 30т.
// 2ра - 5т.
// 3та - 0т.
#include <iostream>
#include <cstring>

//2 вариант
/*
bool isItEven(char n[])
{
    int counter = strlen(n);
    for(int i = 0 ; i < counter ; i++)
    {
        // Това работи само защото цифрите в аски таблицата започват с 0(48).
        // Трябва да се направи (n[i] - '0') % 2 - така намираш точната цифра дали е четна.
        if(n[i] % 2 != 0)
        {
            return false;
        }
    }
    return true;
}
*/

bool isItTrue(unsigned n , int arr[])
{
    int maxElement = arr[0];
    int indexOfMaxElement = 0;
    for(int i = 1 ; i < n ; i++)
    {
        // Липсва ти равното.
        if(arr[i] > arr[i - 1])
        {
            maxElement = arr[i];
            indexOfMaxElement = i;
        }
    }
    
    // Намерили сме индекса на максималния елемент, защо не продължим да обикаляме от него нататък?!?
    for(int i = 0 ; i < n ; i++)
    {
        // Първата част ще е вярна, тъй като в предишния цикъл сме ги разгледали тези елементи.
        // Това ще върне true в 99% от случаите още на първата врътка.
        // Без да проверим часта след maxElement-а.
        if((i < indexOfMaxElement && arr[i] < maxElement) || (i > indexOfMaxElement && arr[i] < maxElement))
        {
            return true;
        }
    }
    return false;
}


int main()
{
    // Поне да ги беше отделил в различни файлове XD.
    //Задача 1

    /*
    const int MAX_ARRAY_SIZE = 100;
    char n[MAX_ARRAY_SIZE];

    std::cout << "Enter an array of numbers" << std::endl;;
    std::cin.getline(n , MAX_ARRAY_SIZE); // Няма нужда от getline, може с един обикновен cin.
    // Нямаш валидация за числото.
    
    std::cout << std::boolalpha << isItEven(n); 
    */



   //Задача 2
   const int MAX_ARRAY_SIZE = 100;
   int arr[MAX_ARRAY_SIZE];
   unsigned int n;

   std::cout << "Enter the size of the array" << std::endl;
   std::cin >> n;
    // Нямаш валидация за n >= 100.

   for(int i = 0 ; i < n ; i++)
   {
        std::cin >> arr[i];
   } 

   std::cout << isItTrue(n , arr);










    return 0;
}