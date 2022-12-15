#include "route.h"

class keeper
{
private:
	route **list;
	unsigned int capacity, listLenght;
	void resize();
	int choiseItem();
	int searchItem();
	void addItem(route *item);
	void removeItem(int itemId);

public:
	void show();
	void tryRemoveItem();
	void tryAddItem();
	void tryGetItemInfo();
	void tryEditItem();
	void sort();

	keeper();
	~keeper();
};