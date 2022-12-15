#include "keeper.h"
#include "route.h"
#include <iostream>
#include <limits>
#include <cstring>
 
void keeper::resize()
{
	capacity = 2 * capacity;
	route **tmp = new route *[capacity];
	for (size_t i = 0; i < listLenght; i++)
	{
		tmp[i] = list[i];
	}
	delete[] list;
	list = tmp;
}

void keeper::show()
{
	for (size_t i = 0; i < listLenght; i++)
	{
		std::cout <<i<<") "<< *list[i]<<std::endl;
	}
}
void keeper::tryEditItem()
{
	try
	{
		list[choiseItem()]->edit();
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}
}

int keeper::searchItem()
{
    unsigned int number = UINT32_MAX;
    std::cout<<"Введите номер маршрута: ";
    std::cin>>number;
    if(!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw("Введенно некоректное значение"); 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (size_t i = 0; i < listLenght; i++)
    {
        if(list[i]->getIndex()==number)
        {
            return i;
        }
        throw("Маршрут не найден");
    }
    
}
void keeper::tryGetItemInfo()
{
		try
	{
		list[searchItem()]->getInfo();
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}

}

void keeper::sort()
{
	for (size_t i = 0; i < listLenght-1; i++)
	{
		for (size_t j = i + 1; j < listLenght; j++)
		{
			if (list[i]->getIndex()>list[j]->getIndex())
			{
				auto tmp =list[i];
				list[i]=list[j];
				list[j]=tmp;
			}
		}
	}
	
}

int keeper::choiseItem()
{
    	if (listLenght == 0)
		throw "Список пуст";
	show();
	int choice = -1;
	std::cout <<std::endl<< "Введите индекс выбранного объекта: ";
	std::cin >> choice;
	if(!std::cin.good()){
	std::cin.clear();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (choice < 0 || choice >= listLenght)
		throw("Введенно некоректное значение");
	return choice;
}  
void keeper::tryAddItem()
{
	try
	{
		route *item = new route;
		addItem(item);
        sort();
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}
}
void keeper::addItem(route *item)
{
	if (capacity == listLenght)
		resize();
	list[listLenght++] = item;
}

void keeper::tryRemoveItem()
{
	try
	{
		int itemId = choiseItem();
		removeItem(itemId);
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}
}
void keeper::removeItem(int itemId)
{
	delete list[itemId];
	for (size_t i = itemId; i < listLenght - 1; i++)
	{
		list[i] = list[i + 1];
	}
	list[--listLenght] = nullptr;
}
keeper::keeper():listLenght(0),capacity(1)
{
    list=new route*[capacity];
}
keeper::~keeper()
{
    for (size_t i = 0; i < listLenght; i++)
    {
        delete list[i];
    }
    delete[] list;
}