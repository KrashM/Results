// Топ е задачата!
// 24т.
#include<iostream>

bool validCard(int &card)
{
    if(card<100000 || card>999999) return false;
    
    int firstDigit = card/100000;
    int forthAndFifthDigit = (card/10) %10 + ((card/100)%10)*10;

    if( (firstDigit == 1 || firstDigit == 2 || firstDigit == 3 || firstDigit == 4) && forthAndFifthDigit > 12 ) return false;
    else if( firstDigit == 5 && (forthAndFifthDigit < 13 || forthAndFifthDigit > 14) ) return false;
    else if(firstDigit==0 || firstDigit>5) return false;

    //по условие:        1-yellow, 2-green, 3-blue, 4-red,   5-black
    //по моята програма: 1-black,  2-red,   3-blue, 4-green, 5-yellow, за да може да сортирам после в нарастващ ред картите

    if(firstDigit == 1) firstDigit = 5;
    else if(firstDigit == 2) firstDigit = 4;
    else if(firstDigit == 4) firstDigit = 2;
    else if(firstDigit == 5) firstDigit = 1;

    //запазвам само значещите цифри, като първата цифра (оказващата цвета) я слагам последна
    card = forthAndFifthDigit*10 + firstDigit;
    return true;
}

//insertionSort
void sortCards(int* unoCard, int cardsCount)
{
    for(int i=1; i<cardsCount; i++)
    {
        int x = unoCard[i];
        int j= i-1;
        // Това условие не работи по условието.
        // Там се иска първо ако са различни стойностите по стойността >.
        // После ако са еднакви по цвета <.
        while(j>=0 && unoCard[j]>x)
        {
            unoCard[j+1] = unoCard[j];
            j--;
        }
        unoCard[j+1] = x;
    }
}

void printCards(int* unoCard, int cardsCount)
{
    for(int i=0; i<cardsCount; i++)
    {
        std::cout<<"(";
        if(unoCard[i] % 10 == 2) std::cout<<"RED ";
        if(unoCard[i] % 10 == 3) std::cout<<"BLUE ";
        if(unoCard[i] % 10 == 4) std::cout<<"GREEN ";
        if(unoCard[i] % 10 == 5) std::cout<<"YELLOW ";
        
        unoCard[i] = unoCard[i]/10;

        if(unoCard[i] <= 9) std::cout<<unoCard[i];
        if(unoCard[i] == 10) std::cout<<"+2";
        if(unoCard[i] == 11) std::cout<<"REVERSE";
        if(unoCard[i] == 12) std::cout<<"STOP";
        if(unoCard[i] == 13) std::cout<<"CHANGE COLOR";
        if(unoCard[i] == 14) std::cout<<"+4";
        std::cout<<") ";
    }
}

int main()
{
    int cardsCount;

    // Отново същият коментар за валидацията.
    do
    {
        std::cin>>cardsCount;
    }
    while(cardsCount<1);
    

    int* unoCard = new (std::nothrow) int[cardsCount];
    if (!unoCard)
    {
        std::cout << "Problem while allocating memory for the array!" << std::endl;
        return 1;
    }

    for(int i=0; i<cardsCount; i++)
    {
        std::cin>>unoCard[i];
        if( !validCard(unoCard[i]) )
        {   
            cardsCount--;
            i--;            //ако картата е невалидна я изтривам (като записвам отгоре друга)
        }
    }

    std::cout<<"There are "<<cardsCount<<" valid UNO cards"<<std::endl;

    sortCards(unoCard, cardsCount);
    printCards(unoCard, cardsCount);
   
    delete[] unoCard;

    return 0;
}