// Като цяло много добре разписана задача.
// Минимални грешки с динамичната памет и размера на изреченията.
// 23т.
#include <iostream>

char **createArray(int size, const int max_el_size)
{
    char **array = new (std::nothrow) char *[size];

    if (!array)
    {
        std::cout << "Error creating array" << std::endl;
        return nullptr;
    }

    for (std::size_t i = 0; i < size; i++)
    {
        array[i] = new (std::nothrow) char[max_el_size];
        // Тук също ти трябва проверка ако се бъгне оператор new.
        // И ако стане проблем да можеш да си изтриеш паметта.
    }

    return array;
}

void inputArray(char **array, std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
    {
        // Тук също трябва да са 31!
        std::cin.getline(array[i], 30);
    }
}

char toLower(char r)
{
    return (r >= 'A' && r <= 'Z') ? r += 32 : r;
}

int compareInArray(char *str1, char *str2)
{
    char char1 = *str1, char2 = *str2;
    char1 = toLower(char1);
    char2 = toLower(char2);
    if (char1 > char2)
    {
        return 1;
    }
    if (char1 < char2)
    {
        return -1;
    }
    else
    {
        compareInArray(++str1, ++str2);
    }
    return 0;
}

std::size_t strlen(char *array)
{
    std::size_t len = 0;
    while (*array)
    {
        ++array;
        ++len;
    }
    return len;
}
void copyString(char *dest, char *src)
{
    std::size_t len = strlen(src);
    for (std::size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void swap(char *str1, char *str2)
{
    std::size_t n = strlen(str1);
    char tmp[n];
    copyString(tmp, str1);
    copyString(str1, str2);
    copyString(str2, tmp);
}

void orderArray(char **array, std::size_t size)
{
    for (std::size_t i = 0; i < size - 1; i++)
    {
        for (std::size_t j = i + 1; j < size; j++)
        {
            int lexi = compareInArray(array[i], array[j]);
            // По-скоро само при 1 можем да го правим.
            // 0 е когато са равни и не ни трябва,
            // излишно да ги раместваме, ако са равни.
            if (lexi == 0 || lexi == 1)
            {
                swap(array[i], array[j]);
            }
        }
    }
}

void print(char **array, std::size_t size)
{
    std::cout << "\n============ P R I N T I N G ============" << std::endl;
    for (std::size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

void deleteArray(char **array, std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

int main()
{
    const int max = 50;
    std::size_t size = 0;

    // size от 0 и 1 е валидно принципно.
    while (size <= 1 || size > max)
    {
        std::cout << "\nEnter a valid size: ";
        std::cin >> size;
    }

    // 31 Ти трябват заради '\0'.
    // Затова и примера не върви!
    char **words = createArray(size, 30);

    std::cin.ignore();
    inputArray(words, size);
    orderArray(words, size);
    print(words, size);

    deleteArray(words, size);
    return 0;
}
