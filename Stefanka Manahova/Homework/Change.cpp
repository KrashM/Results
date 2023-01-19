// Just perfect!!
// 25т.
#include <iostream>

using std::cout;
using std::cin;
using std::size_t;

int main() {
    /*създаваме масив, в който запазваме стойностите на 
    възможните банкноти и монети в стотинки*/
    const unsigned int currency[] = {10000, 5000, 2000, 1000, 500,
                                     200, 100, 50, 20, 10, 5, 2, 1};
    const size_t size = 13;
 
    const double EPS = 0.00001;
    double price;
    double moneyGiven;

    /*валидираме дали въведените числа са 
    положителни*/
    do {    
        cin >> price >> moneyGiven;
    } while (price <= 0 || moneyGiven <= 0);
    
    /*създаваме две променливи от тип int, за да работим
    със стотинки (използваме EPS заради 
    особеностите на запазването на числа от тип double)*/
    // Между другото не ти трябва да добавяш EPS
    // Това идва от самата репрезентация на числата в паметта
    // и схемата по която се превръщат в десетични такива.
    // С две думи ако въведеш 12 то винаги ще е > 12 а не по-малко.
    unsigned int priceInSt = (price + EPS) * 100;
    unsigned int stotinkiGiven = (moneyGiven + EPS) * 100;

    /*проверяваме дали са дадени по-малко пари*/
    if (stotinkiGiven < priceInSt) {
        cout << "Money is not enough" << '\n';
    }

    /*проверяваме дали парите са точно*/
    else if (stotinkiGiven == priceInSt) {
        cout << "Alright";
    }

    /*в случай, че трябва да се върне ресто:*/
    else {
        unsigned int change = stotinkiGiven - priceInSt;

        /*в count ще запазваме броя на всеки вид банкнота/монета,
        след което ще го използваме за следващата и т.н*/
        unsigned int count = 0;

        cout << "Here is your change: " << '\n';

        /*обхождаме масива, като започваме от 100-те лв,
        и смятаме колко най-много банкноти/монети от всеки вид
        можем да дадем, което се реализира чрез делене с остатък*/
        for (size_t i = 0; i < size; i++)
        {
           count = change / currency[i];

           /*намаляваме рестото, което остава да върнем*/
           change = change % currency[i];

           if (count != 0) {
            /*ако работим с банкнота, трябва да преобразуваме 
            стойността в левове*/
               if (currency[i] >= 100) {
                   cout << count << " - " << currency[i] / 100 << " lv" << '\n';
               }
               else {
                    cout << count << " - " << currency[i]<< " st" << '\n';
               }
           }
        }
    }

    return 0;
}