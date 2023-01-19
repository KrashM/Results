// Отново много добро решение.
// Може само да се промени малко валидацията ад не изисква всеки път ново число,
// а ако срещне грешен вход да приключва програмата.
// 23т.
#include <iostream>

int Check()
{
    int var; 
    int x, y;
    bool check = true;

    do 
    { 
        std::cin >> var; 
        if (var > 99999 && var < 1000000)
        {
            x = var / 100000;
            y = (var / 10) % 100;

            if (x < 1 || x > 5 || y < 0 || y > 14) check = false;
            else check = true;
        }
        else check = false;
    } 
    while ((var <= 99999 || var >= 1000000) && !check);
    return var;
}


const char colour [5][10] = {"Yellow", "Green", "Blue", "Red", "Black"}; 
const char symbols [15][20] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+2", "Reverse", "Stop", "Change Colour", "+4"};


int main ()
{
    // Тук ти трябваше динамичен масив, тъй като ти се въвежда размера.
    const int MAX_SIZE = 10;
    int cards[MAX_SIZE][2];
    int count, temp; 
    std::cout << "Insert the count of the cards: "; std::cin >> count;
    std::cout << "Insert the numbers of the cards: " << std::endl;
    for (int i = 0; i < count; i++)
    {
        // Хммм това не е точно това, което се иска по условие.
        // Но все пак си е валидация.
        temp = Check();
        cards[i][0] = temp / 100000;
        cards[i][1] = (temp / 10) % 100; 
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (cards[i][1] > cards[j][1])
            { 
                std::swap(cards[i][1], cards[j][1]); 
                std::swap(cards[i][0], cards[j][0]); 
            }
            else if ((cards[i][1] == cards[j][1]) && (cards[i][0] < cards[j][0]))
            {
                std::swap(cards[i][1], cards[j][1]); 
                std::swap(cards[i][0], cards[j][0]); 
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (cards[i][0] == 5) std::cout << '(' <<symbols[cards[i][1]] << ')' <<' ';
        else std::cout << '(' <<  colour[cards[i][0] - 1] <<',' << symbols[cards[i][1]] << ')' << ' ';
    }
    return 0;
}