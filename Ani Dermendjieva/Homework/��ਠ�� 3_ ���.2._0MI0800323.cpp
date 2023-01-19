// Умолявам те не блъскай всичко в main-а.
// Трудно става за дебъгване, проверяване и като цяло за четене.
// Валидацията не е коректна, липсва динамичния масив и незнайно защо
// проверяваш ИМЕ на функция?!?
// 15т.
#include <iostream> 

const int SIZE = 1024;

// Това не е реална валидация.
// Първо си правиш картите всички на 0 и от там нататък ти се прецаква задачата.
// Второ теб не те вълнува толкова дали е 6 цифрено, отколкото дали
// са изпълнени условията на картите.
// И трето i <=> count, едно и също нещо => излишно.
bool validInput (int arr[]) {
    int i = 0;
    int count = 0;

    while (arr[i] > 1) {
        arr[i] / 10;
        count++;
        i++;
    }

    if (count != 6) {
        return false;
    } 

    return true;
}

int main () {

    int numberOfCards;
    std::cin >> numberOfCards;

    // Трябваше да го направиш динамичен.
    int arr[SIZE];

    for (int i = 0; i < numberOfCards; i++) {

        std::cin >> arr[i];

        if(arr[i] < 0) {

            std::cout << "Invalid input!";
            return 1;

        }
    }

    // Функция без аргументи?!?
    // Това изобщо не прави това, което си мислиш.
    if (!validInput) {
        std::cout << "Invalid input!";
        return 1;
    }
    
    int firstDigitOfN = 0, fourthDigitOfN = 0, fifthDigitOfN = 0;
    int newNumber = 0;

    int secondArr[SIZE];

    for (int i = 0; i < numberOfCards; i++) {

        firstDigitOfN = arr[i] / 100000;
        int n = arr[i] / 10;
        fifthDigitOfN = n % 10;
        int m = arr[i] / 100;
        fourthDigitOfN = m % 10;

        newNumber = (fourthDigitOfN * 100) + (fifthDigitOfN * 10) + firstDigitOfN;
        
        secondArr[i] = newNumber;
    }   

    // Първо, защо не отдели цялата сортировка в една отделна функция?
    // Второ, защо не ги обедини в едно двата цикъла?
    for(int i = 0; i < numberOfCards - 1; i++){
        for(int j = i + 1; j < numberOfCards; j++){
        
            if(secondArr[i] > secondArr[j]) {
                std::swap(secondArr[i], secondArr[j]);
            }
        }
    }

    for (int i = 0; i < numberOfCards; i++) {
        for (int j = i + 1; j < numberOfCards; j++) {
            
            if ((secondArr[i] / 10) == (secondArr[j] / 10) && (secondArr[i] % 10) < (secondArr[j] % 10)) {
                std::swap(secondArr[i], secondArr[j]);
            }
        }
    }

    // Invalid input-а, трябва да го проверяваш още в началото. Не тук!
    for (int i = 0; i < numberOfCards; i++) {

        int colour = secondArr[i] % 10;
        int value = secondArr[i] / 10;

        switch (colour) {
            case 1:
            if (value == 13) continue;
            else std::cout << "(YELLOW ";

            break;
            case 2:
            if (value == 13) continue;
            else std::cout << "(GREEN ";
            break;

            case 3:
            if (value == 13) continue;
            else std::cout << "(BLUE ";
            break;

            case 4:
            if (value == 13) continue;
            else std::cout << "(RED ";
            break;

            case 5:

                if (value == 13) {
                    std::cout << "(CHANGE COLOUR) ";
                } else if (value == 14)  {
                    std::cout << "(+4) ";
                } else {
                    std::cout << "Invalid input!";
                    return 1;
                }
            
            break;

            default: 
            std::cout << "Invalid input!";
            return 1;

        }
        
        switch (value) {
            case 1:
            std::cout << "1) ";
            break;
            case 2:
            std::cout << "2) ";
            break;
            case 3:
            std::cout << "3) ";
            break;
            case 4:
            std::cout << "4) ";
            break;
            case 5:
            std::cout << "5) ";
            break;
            case 6:
            std::cout << "6) ";
            break;
            case 7:
            std::cout << "7) ";
            break;
            case 8:
            std::cout << "8) ";
            break;
            case 9:
            std::cout << "9) ";
            break;
            case 10:
            std::cout << "+2) ";
            break;
            case 11:
            std::cout << "REVERSE) ";
            break;
            case 12:

                if (colour != 5) {
                    std::cout << "STOP) ";
                } else {
                std::cout << "Invalid input!";
                return 1; 
                } 
            
            break;
            case 13: 
            break;
            case 14: 
                if(colour != 5) {
                    std::cout << "Invalid input!";
                    return 1;
                }
            break;
        
            default: 
            std::cout << "Invalid input!";
            return 1;
        
        }
    }     

    return 0;
    
}