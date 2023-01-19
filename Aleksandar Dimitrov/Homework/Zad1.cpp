// Даже не минава входа на задачата.
// Изглежда добре разписана, обаче не работи.
// 20т.
#include<iostream>

// Човеко, защо с тези магически числа XD
//Validaciq za dali e bukva cifra ili space 
bool validateChar(char c){
    return (c == 32 || (c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

// Отново, защо с магическите числа XD
//Pravene na malki bukvi
char toLower(char c){
    if(int(c) >= 65 && int(c) <= 90)
        return c + 32;
    return c;
}

//Sravnqva stringove
bool Bigger(char str1[], char str2[]){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(toLower(int(str1[i])) > toLower(int(str2[i])))return 1;
        if(toLower(int(str1[i])) < toLower(int(str2[i])))return 0;
        i++;
    }
    return 1;
}

int main(){
    system("clear");
    //Slojih go poneje v primera ima niz s poveche ot 30 elementa
    const int simvoli = 30; // Сложи ги 31 за '\0'.
    int n;
    std::cin>>n;
    if(n < 0 || n > 50){
        std::cout<<"Incorrect Input";
        return 0;
    }

    // На статичен масив не трябва да слагаш променлив размер.
    // Плюс, че само n ти е достатъчен като размер.
    char field [n + 1][simvoli];
    for(int i = 0;i <= n;i++){
        // Ето тук от се бъгва входа, защото това дългото изречение не се побира.
        // От там всичко надолу се прецаква.
        std::cin.getline(field[i], simvoli);
        for(int j = 0; field[i][j] != '\0'; j++){
            if(!validateChar(field[i][j])){
                std::cout<<"Incorrect Input";
                return 0;
            }
        }
    }

    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            if(Bigger(field[i], field[j]))
                std::swap(field[i], field[j]);

                
    for(int i = 1;i <= n;i++){
        std::cout<<std::endl<<field[i];
    }

    return 0;
}