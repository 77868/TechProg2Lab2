#include "secondTask.h"
#include "firstTask.h"
#include "iostream"
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Ru");
    std::cout << "Введите номер необходимой задачи: ";
    int choice = 0;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        firstTaskMain();
        break;
    case 2:
        secondTaskMain();
        break;
    default:
        std::cout << "Введены некоректные данные, попрообуйте ещё раз :";
        break;
    }
    return 0;
}
