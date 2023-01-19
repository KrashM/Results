// Топ е задачата!
// 24т.
#include<iostream>

//работи и при отрицателни идентификационни номера, затова не съм направила проверка за firstElfFirstSection,firstElfSecondSection, ... 
bool sectionsOverlap(int firstElfFirstSection, int firstElfLastSection, int secondElfFirstSection, int secondElfLastSection)
{
    if( (firstElfFirstSection <= secondElfFirstSection && firstElfLastSection >= secondElfLastSection) ||
        (secondElfFirstSection <= firstElfFirstSection && secondElfLastSection >= firstElfLastSection) )
        return true;
    
    return false;
}

int main()
{
    int pairs;

    // Вместо да вкарваме всеки път ново,
    // по-скоро се иска да прекъснем програмата.
    do
    {
        std::cin>>pairs;
    } 
    while (pairs<1);

    int firstElfFirstSection, firstElfLastSection;
    int secondElfFirstSection, secondElfLastSection;
    int overlaps=0;

    for(int i=0; i<pairs; i++)
    {
        std::cin>>firstElfFirstSection>>firstElfLastSection;
        std::cin>>secondElfFirstSection>>secondElfLastSection;
        // Можеше само да провериш за грешни интервали примерно 5 3.
        if( sectionsOverlap(firstElfFirstSection, firstElfLastSection, secondElfFirstSection, secondElfLastSection) ) overlaps++;
    }

    if(overlaps == 0) std::cout<<"There aren't any overlapsing pairs.";
    else if(overlaps == 1) std::cout<<"There is 1 overlapsing pair.";
    else std::cout<<"There are "<< overlaps <<" overlapsing pairs.";

    return 0;
}