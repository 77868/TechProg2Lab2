#include "firstTask.h"
#include <iostream>
#include <limits>
#include "keeper.h"
void firstTaskMain()
{
  keeper mainKeeper;
  char choice = 0;
  while (true)
  {
    mainKeeper.show();
    std::cout << std::endl
              << "выберите действие:" << std::endl
              << "1 - добавить объект" << std::endl
              << "2 - удалить объект" << std::endl
              << "3 - поиск маршрута" << std::endl
              << "4 - отредактировать информацию об маршруте" << std::endl
              << "5 - выйти" << std::endl;
    choice = 0;
    std::cin >> choice;
    if (!std::cin.good())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (choice)
    {
    case '1':
      mainKeeper.tryAddItem();
      break;
    case '2':
      mainKeeper.tryRemoveItem();
      break;
    case '3':
      mainKeeper.tryGetItemInfo();
      break;
    case '4':
      mainKeeper.tryEditItem();
      break;
    case '5':
      return;
    }
  }
}