
#include <iostream>

#include "Tank.h"
#include "FileLoggerSingleton/LoggerSingleton.h"


bool Tank::isInside(double x1, double x2) const
{
    const double XBeg = x + 2;
    const double XEnd = x + width - 1;
    
    if (x1 < XBeg && x2 > XEnd)
        return true;
    
    if (x1 > XBeg && x1 < XEnd)
        return true;
    
    if (x2 > XBeg && x2 < XEnd)
        return true;
    
    return false;
}

void Tank::Draw() const
{
    LoggerSingleton::instance().SetColor(CC_Brown);
    LoggerSingleton::instance().GotoXY(x, y - 3);
    std::cout << "    #####";
    LoggerSingleton::instance().GotoXY(x-2, y - 2);
    std::cout << "#######   #";
    LoggerSingleton::instance().GotoXY(x, y - 1);
    std::cout << "    #####";
    LoggerSingleton::instance().GotoXY(x,y);
    std::cout << " ###########";
}