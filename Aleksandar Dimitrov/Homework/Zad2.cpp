// Overall добре разписана задача.
// Само искам да кажа, че не е хубаво да бутаме всичко в main-а.
// 20т.
#include<iostream>

int main(){
    int gnomes, items, calories, sum, max_sum, max_index;
    std::cin>>gnomes;
    
    if(gnomes > 100 || gnomes < 0){
        std::cout<<"Incorrect Input";
        return 0;
    }

    for(int i = 0;i < gnomes;i++){
        sum = 0;
        std::cin>>items;

        if(items > 20 || items < 0){
            std::cout<<"Incorrect Input";
            return 0;
        }
        
        for(int j = 0;j < items;j++){
            // Не трябва ли първо да ги въведеш калориите и тогава да проверяваш.
            if(calories < 0){
                std::cout<<"Incorrect Input";
                return 0;
            }
        
            std::cin>>calories;
            sum += calories;
        }
        
        // С този if слагаш max_index = ??
        // Ако максималният ти е първият ти не му даваш индекс.
        // Реално този if ти е просто излишен.
        if(i == 0){
            max_sum = sum;
        }else{
            if(sum > max_sum){
                max_index = i + 1;
                max_sum = sum;
            }
        }
    }
    std::cout<<"Елф номер "<<max_index<<" носи най - много калории - "<<max_sum;
}