// Overall добре написана. Можеше да си улесниш живота с малко масиви.
// 24т.
#include<iostream>
#include<cmath>

int main()
{
    float n, k; // Защо не double XD?
    std::cin >> n >> k;
    if (n == k)
    {
        std::cout << "Alright" << '\n';
    }
    else if (n > k)
    {
        std::cout << "Money is not enough" << '\n';
    }
	// Тука трябваше да си направиш и валидация за отрицателни стойности.
    else
    {
        float change = k - n;
		// Мале мале, много трудно е за проследяване това.
		int hundred = change / 100;
		int fifty = (change - (hundred * 100)) / 50;
		int twenty = (change - (hundred * 100) - (fifty * 50)) / 20;
		int ten = (change - (hundred * 100) - (fifty * 50) - (twenty * 20)) / 10;
		int five = (change - (hundred * 100) - (fifty * 50) - (twenty * 20) - (ten * 10)) / 5;
		int two = (change - (hundred * 100) - (fifty * 50) - (twenty * 20) - (ten * 10) - (five * 5)) / 2;
		int one = (change - (hundred * 100) - (fifty * 50) - (twenty * 20) - (ten * 10) - (five * 5) - (two * 2)) / 1;
        change = change - (hundred * 100) - (fifty * 50) - (twenty * 20) - (ten * 10) - (five * 5) - (two * 2) - (one * 1);
		int zeroFifty = round(change*100) / 50;
		int zeroTwenty = round((change - (zeroFifty * 0.50)) * 100)/ 20;
		int zeroTen = round((change - (zeroFifty*0.50) - (zeroTwenty*0.20)) * 100) / 10;
		int zeroFive = round((change -(zeroFifty * 0.50) - (zeroTwenty * 0.20) - (zeroTen * 0.10)) * 100) / 5;
		int zeroTwo = round((change - (zeroFifty * 0.50) - (zeroTwenty * 0.20) - (zeroTen * 0.10) - (zeroFive * 0.05)) * 100)/2;
		int zeroOne = round((change - (zeroFifty*0.50)- (zeroTwenty * 0.20) - (zeroTen*0.10) - (zeroFive * 0.05) - (zeroTwo*0.02)) * 100);

		// Можеше да се избегне това да се пишат 50 if-а.
        if (zeroOne != 0)
		{
			std::cout << zeroOne << " - 1 st" << std::endl;
		}
		if (zeroTwo != 0)
		{
			std::cout << zeroTwo << " - 2 st" << std::endl;
		}
		if (zeroFive != 0)
		{
			std::cout << zeroFive << " - 5 st" << std::endl;
		}
		if (zeroTen != 0)
		{
			std::cout << zeroTen << " - 10 st" << std::endl;
		}
		if (zeroTwenty != 0)
		{
			std::cout << zeroTwenty << " - 20 st" << std::endl;
		}
		if (zeroFifty != 0)
		{
			std::cout << zeroFifty << " - 50 st" << std::endl;
		}
		if (one != 0)
		{
			std::cout << one << " - 1 lv" << std::endl;
		}
		if (two != 0)
		{
			std::cout << two << " - 2 lv" << std::endl;
		}
		if (five != 0)
		{
			std::cout << five << " - 5 lv" << std::endl;
		}
		if (ten != 0)
		{
			std::cout << ten << " - 10 lv" << std::endl;
		}
        if (twenty != 0)
		{
			std::cout << twenty << " - 20 lv" << std::endl;
		}
		if (fifty != 0)
		{
			std::cout << fifty << " - 50 lv" << std::endl;
		}
        if(hundred != 0)
        {
            std::cout << hundred << " - 100 lv" << std::endl;
        }

    }
    return 0;
}