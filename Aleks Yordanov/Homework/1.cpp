// Overall е много добре.
// Минимални забележки, главно върху "clean code" семантиките.
// 25т.
#include <iostream>
const size_t ALL_VALUES = 13;
/*
void change(double ch)
{
	int n_ch = ch * 100;
	std::cout << "Here is your change:\n";
	short lv100 = n_ch / 10000;
	n_ch %= 10000;
	short lv50 = n_ch / 5000;
	n_ch %= 5000;
	short lv20 = n_ch / 2000;
	n_ch %= 2000;
	short lv10 = n_ch / 1000;
	n_ch %= 1000;
	short lv5 = n_ch / 500;
	n_ch %= 500;
	short lv2 = n_ch / 200;
	n_ch %= 200;
	short lv1 = n_ch / 100;
	n_ch %= 100;
	short st50 = n_ch / 50;
	n_ch %= 50;
	short st20 = n_ch / 20;
	n_ch %= 20;
	short st10 = n_ch / 10;
	n_ch %= 10;
	short st5 = n_ch / 5;
	n_ch %= 5;
	short st2 = n_ch / 2;
	n_ch %= 2;
	short st1 = n_ch / 1;
	if (lv100 > 0) std::cout << lv100 << " - 100 lv\n";
	if (lv50 > 0) std::cout << lv50 << " - 50 lv\n";
    if (lv20 > 0) std::cout << lv20 << " - 20 lv\n";
    if (lv10 > 0) std::cout << lv10 << " - 10 lv\n";
    if (lv5 > 0) std::cout << lv5 << " - 5 lv\n";
    if (lv2 > 0) std::cout << lv2 << " - 2 lv\n";
    if (lv1 > 0) std::cout << lv1 << " - 1 lv\n";
    if (st50 > 0) std::cout << st50 << " - 50 st\n";
    if (st20 > 0) std::cout << st20 << " - 20 st\n";
    if (st10 > 0) std::cout << st10 << " - 10 st\n";
    if (st5 > 0) std::cout << st5 << " - 5 st\n";
    if (st2 > 0) std::cout << st2 << " - 2 st\n";
    if (st1 > 0) std::cout << st1 << " - 1 st\n";
}
*/

// В случая нямаш проблем, защото стойностите са малки,
// но на функция с тип short подаваш стойност с тип int.
//помощна функция, изчисляваща колко броя от всеки вид и намаляваща рестото
int decrease(int& amount,short value)
{
    int res=amount/value;
    amount%=value;
    return res;
}

void change2(double sum)
{
    int new_sum=sum*100; //превръщаме сумата в стотинки
    int arr[ALL_VALUES]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000}; //масив от всички видове стотинки и банкноти, обърнати в стотинки
    // Тази логика е ок, но можеш направо да си ги печаташ,
	// вместо да ги пазиш в масив.
	int res[ALL_VALUES]={0,}; // масив, където съхраняваме броя от всеки вид стотинка или банкнота

	for (int i = ALL_VALUES - 1; i > 0; --i)
    {
        res[i]=decrease(new_sum,arr[i]);       //пълним масива с броя за всеки вид стотинка или банкнота
    }

	for (int i =  ALL_VALUES-1; i>0; --i)
    {
        if(res[i]>0)
        {
            if(i<=5)                                             //извеждаме на екрана само полойителните стойности  
                std::cout<< res[i]<<" - "<<arr[i]<<" st \n";
			else
                std::cout<< res[i]<<" - "<<arr[i]/100 << " lv \n";   
        }
    }
}

// Името на тази функция не мисля, че е много коректно!
void output()
{
	double bill;
	std::cout << "Bill: ";
	std::cin >> bill;
	// Последната проверка не знам дали винаги няма да ти е вярна.
	// Това идва от начина по, който C++ пази числата в паметта.
	// Няма да навлизам в подробности, но като цяло дори и да въведеш
	// 2.50, то ще ти го репрезентира примерно като -> 2.5000000023.
	if (!std::cin || bill < 0 || (bill*100)-(int)(bill*100)>0)          //валидация на сметката
	{
		std::cerr << "Invalid bill!";
		return ;
	}

	double payment;
	std::cout << "Payment: ";
	std::cin >> payment;               
	if (!std::cin || payment < 0 || (payment*100)-(int)(payment*100)>0)    //валидация на платежната сума   
	{
		std::cerr << "Invalid payment amount!";
		return ;
	}

	double diff;
	if (bill > payment)
	{
		std::cout << "Money is not enough!";   
		return ;
	}
	// else-овете са ти излишни, тъй като правиш return в if-овете.
	else if (bill == payment)
	{
		std::cout << "Alright.";    
		return ;
	}
	else
	{
		diff = payment - bill;
		std::cout << "Here is your change:\n";
		change2(diff);              //пресмятане на ресто и извеждане на екрана

	}
}

int main()
{
	output();
	return 0;
}
