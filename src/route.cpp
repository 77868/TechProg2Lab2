#include "route.h"
#include "input.h"
#include <fstream>
#include <iostream>
#include "cstring"
std::ostream &operator<<(std::ostream &output, route &_route)
{
    output << "Маршрут №: " << _route.routeNumber
           << ". Место отправления: " << _route.startDestName
           << ". Место назначения : " << _route.endDestName;
}
unsigned int route::getIndex()
{
    return routeNumber;
}
void route::getInfo()
{
    std::cout << "Маршрут №: " << routeNumber << std::endl
              << "Место отправления: " << startDestName << std::endl
              << "Место назначения: " << endDestName << std::endl
              << "Информация: " << info << std::endl;
}
void route::edit()
{
    char choice = '0';
    std::cout << "Выберите редактируемое поле:" << std::endl
              << "1 - Номер маршрута" << std::endl
              << "2 - название начального пункта" << std::endl
              << "3 - название конечного пункта" << std::endl
              << "4 - информация о маршруте" << std::endl;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (choice)
    {
    case '1':
        getValue(routeNumber, "Введите новый номер маршрута: ");
        break;
    case '2':
        getValue(startDestName, 64, "Введите название начального пункта: ");
        break;
    case '3':
        getValue(endDestName, 64, "Введите название конечного пункта: ");
        break;
    case '4':
        getValue(info,128 ,"Введите новое описание: ");
        break;
    default:
        std::cout << "Введенно некоректное значение: " << std::endl;
    }
}

route::route()
{
    getValue(routeNumber, "Введите номер маршрута: ");
    getValue(startDestName, 64, "Введите название начального пункта:");
    getValue(endDestName, 64, "Введите название конечного пункта: ");
    getValue(info,128, "Опишите маршрут: ");
}

route::route(route &original)
{
    routeNumber = original.routeNumber;
    strcat(startDestName, original.startDestName);
    strcat(endDestName, original.endDestName);
    strcat(info, original.info);
}
route::~route(){};