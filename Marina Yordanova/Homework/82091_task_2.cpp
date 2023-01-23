// Overall е супер задачата.
// Минимални проблеми с валидациите.
// 25т.
#include <iostream>

void inputElvesLength(std::size_t &count)
{
    const std::size_t MAX = 100;
    // size_t няма как да е < 0. И 0 също е валидно.
    while (count <= 0 || count > MAX)
    {
        std::cout << "\nEnter the number of elves: ";
        std::cin >> count;
    }
}

void inputSuppliesLength(std::size_t &count)
{
    const std::size_t MAX = 20;
    // Същият коментар и тук.
    while (count <= 0 || count > MAX)
    {
        std::cout << "\nEnter the number of supplies: ";
        std::cin >> count;
    }
}

std::size_t inputSupplies(std::size_t size)
{
    std::size_t total = 0, current = 0, count = 0;
    while (count < size)
    {
        // Този while не ти трябва.
        // 0 е валидно и няма как да е < 0!
        // Така, че е излишно.
        while (current <= 0)
        {
            std::cin >> current;
        }
        count++;
        total += current;
        current = 0;
    }

    return total;
}

void inputElves(std::size_t size)
{
    std::size_t current = 0, max = 0, maxElfNum;
    for (std::size_t i = 0; i < size; i++)
    {
        std::size_t currentElfSupplies = 0;
        inputSuppliesLength(currentElfSupplies);
        current = inputSupplies(currentElfSupplies);
        if (current > max)
        {
            max = current;
            maxElfNum = i + 1;
        }
    }
    std::cout << "\n-----------------------------------------------------------";
    std::cout << "\nElf number " << maxElfNum << " carries the most - " << max;
    std::cout << "\n-----------------------------------------------------------";
}

int main()
{
    std::size_t elvesCount = 0;
    inputElvesLength(elvesCount);
    inputElves(elvesCount);
    return 0;
}