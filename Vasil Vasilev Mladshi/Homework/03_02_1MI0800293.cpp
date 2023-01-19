// Като цяло доста добре.
// Малки забележки с динмаичните масиви и тези string-ове.
// 20т.
#include <iostream>
#include <string.h>

using std :: cout;
using std :: cin;
using std :: endl;

struct UnoCard {
    
    char color[100] = "";
    short colorInt;
    char value[100] = "";
    short valueInt;

};

void decideColor (UnoCard &x, short colorCode);
void decideValue (UnoCard &x, char cardValue[], short colorCode);
void setCard (UnoCard &x, short colorCode, char cardValue[]);
void bubbleSort(UnoCard* arr, const int SIZE);
void swap(UnoCard &a, UnoCard &b);

int main() {
    
    int n;
    // char str[1000];
    
    cout << "Please input ammount of cards: ";
    cin >> n;

    if(n > 0){ // Вместо проверката защо просто не връщаш тук?

        int counter = 0, i = 0, colorCode;

        // Тези скоби не знам защо си ги сложил така.
        // Защо пак въвеждаш като string?
        // Нямаш защита от проблеми с паметта.
        char *str = new char((n * 6 + n-1));
        UnoCard * unocards = new UnoCard[n];
        char cardValue[2];

        // UnoCard unocards[125];
        UnoCard currentCard;

        cin.ignore(1024, '\n');
        
        cout <<endl;

        cin.getline(str, (n * 6 + n-1));

        while (str[i] != '\0' && counter < n){

            colorCode = int(str[i] - '0');

            cardValue[0] = str[i + 3];
            cardValue[1] = str[i + 4]; 

            setCard(currentCard, colorCode, cardValue);

            unocards[counter] = currentCard;
            i += 7;
            counter ++;
        }
        bubbleSort(unocards, n);
        
        for (int j = 0; j < n; j++)
        {
            if (unocards[j].colorInt != 5)
            {
                cout << "(" << unocards[j].color << " " << unocards[j].value << ") ";
            }
            else
            {
                cout << "(" << unocards[j].value << ") ";
            }
            
        }

        delete str;
        delete[] unocards;
    }

    return 0;
}

    //function that decides color value





    // for (int j = 0; j < n; j++)
    // {
    //     cout << "This is the color: " << unocards[j].color;
    //     cout << " This is the value: " << unocards[j].value<<endl;    
    // }

    // while (str[counter] != '\0')
    // {
    //     counter++;
    // }
    
    // if (counter == ( n * 6 + n-1))
    // {
    //     cout << "Statement is true.";
    // }
    // else {
    //     cout << "Statement is false.";
    // }

void setCard (UnoCard &x, short colorCode, char cardValue[]){
    decideColor(x, colorCode);
    decideValue(x, cardValue, colorCode);
}

void decideColor (UnoCard &x, short colorCode){
    x.colorInt = colorCode;
    switch (colorCode)
    {
    case 1:
        strcpy(x.color, "YELLOW");
        break;
    case 2:
        strcpy(x.color, "GREEN");
        break;
    case 3:
        strcpy(x.color, "BLUE");
        break;
    case 4:
        strcpy(x.color, "RED");
        break;
    case 5:
        strcpy(x.color, "BLACK");
        break;
    default:
        strcpy(x.color, "INVALID");
        break;
    }
}

void decideValue (UnoCard &x, char cardValue[], short colorCode){

    // Тъй като cardValue е char '0' = 48 и примерно ако имаш 7 => 55
    x.valueInt = cardValue[0] * 10 + cardValue[1];

    if (cardValue[0] == '0')
    {
        x.value[0] = cardValue[1];
    }
    else if(cardValue[0] == '1'){
        switch (cardValue[1])
        {
        case '0':
            strcpy(x.value, "+2");
            break;

        case '1':
            strcpy(x.value, "REVERSE");
            break;

        case '2':

            if(colorCode != 5){
                strcpy(x.value, "STOP");
            }

            else{
                strcpy(x.value, "INVALID");
            }
            break;
        
        case '3':
            strcpy(x.value, "CHANGE COLOR");
            break;

        case '4':

            if (colorCode == 5)
            {
                strcpy(x.value, "+4");
            }
            else {
                strcpy(x.value, "INVALID");
            }
            break;

        default:
            strcpy(x.value, "INVALID");
            break;
        }
    }
    
    
}

void bubbleSort(UnoCard* arr, const int SIZE){

    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = i + 1; j < SIZE; j++) {
            if (arr[i].valueInt != arr[j].valueInt)
            {
                if(arr[i].valueInt > arr[j].valueInt){
                    swap(arr[i], arr[j]);
                }
            }
            else {
                if (arr[i].colorInt < arr[j].colorInt)
                {
                    swap(arr[i], arr[j]);
                }
                
            }
        }
    }
}

void swap(UnoCard &a, UnoCard &b){

    UnoCard temp = a;
    a = b;
    b = temp;

}