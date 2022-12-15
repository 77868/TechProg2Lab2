#include "secondTask.h"
#include <fstream>
#include <iostream>
#include <cstring>

void secondTaskMain()
{
    std::cout << "Введите имя файла: ";
    char inputFileName[128];
    std::cin >> inputFileName;
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        std::cout << "Ошибка при открытии файла";
        return;
    }

    findWords(inputFile);
    inputFile.close();
    return;
}

void findWords(std::ifstream &inputFile)
{
    std::cout << "Результат: " << std::endl;
    char ch;
    bool isWord = false;
    bool prevIsDelim = true;
    bool prevIsVowel = false;
    bool startedWithVowel = false;
    unsigned int wordLen = 0;

    do
    {
        ch = inputFile.get();
        if (prevIsDelim && !isDelim(ch))
        {
            isWord = true;
            if (isVowel(ch))
            {
                startedWithVowel = true;
            }
            prevIsDelim = false;
        }

        if (isDelim(ch))
        {
            if (prevIsVowel && startedWithVowel)
            {
                inputFile.seekg(inputFile.tellg()-wordLen-1);
                for (size_t i = 0; i < wordLen; i++)
                {
                    char tmp=' ';
                    tmp = inputFile.get();
                    std::cout << tmp;
                }
                std::cout << " ";
            }
            wordLen = 0;
            isWord = false;
            prevIsVowel = false;
            startedWithVowel = false;
            prevIsDelim = true;
        }

        if (isWord)
        {
            if (isVowel(ch))
                prevIsVowel = true;
            else
                prevIsVowel = false;
            wordLen++;
        }

    } while (inputFile);
    std::cout<<std::endl;
}
bool isVowel(char ch)
{
    char vowels[] = "AaEeUuIiOo";
    for (size_t i = 0; i < 10; i++)
    {
        if (vowels[i] == ch)
            return true;
    }
    return false;
}
bool isDelim(char ch)
{
    char delimeters[] = {'!', '.', ',', ' ', '?', '-', EOF, '\0', '\n'};
    for (size_t i = 0; i < 9; i++)
    {
        if (delimeters[i] == ch)
            return true;
    }
    return false;
}