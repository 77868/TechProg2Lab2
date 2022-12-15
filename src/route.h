#pragma once
#include <iostream>
#include <fstream>
class route
{
private:
    unsigned int routeNumber;
    char startDestName[64];
    char endDestName[64];
    char info[128];

public:
    route();
    route(route& original);
    ~route();

    void edit();
    void getInfo();
    unsigned int getIndex();
    friend std::ostream &operator<<(std::ostream &output, route &_route);
};