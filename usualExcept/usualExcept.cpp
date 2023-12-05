#include <iostream>

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
    {
        throw std::invalid_argument("Вы ввели слово запретной длины! До свидания");
    }
    return str.length();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int len = 0;
    std::cout << "Введите запретную длину : ";
    std::cin >> len;

    for (;;)
    {
        std::string word = "";
        std::cout << "Введите слово : ";
        std::cin >> word;

        try
        {
            std::cout << "Длина слова "<< word <<" равна " << function(word, len) << std::endl;
        }
        catch (const std::invalid_argument& except)
        {
            std::cout << except.what() << std::endl;
            break;
        }
    }
}
