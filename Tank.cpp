
#include <iostream>

#include "Tank.h"
#include "FileLoggerSingletone/FileLoggerSingletone.h"


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
    FileLoggerSingletone::instance().SetColor(FileLoggerSingletone::CC_Brown);
    FileLoggerSingletone::instance().GotoXY(x, y - 3);
    std::cout << "    #####";
    FileLoggerSingletone::instance().GotoXY(x-2, y - 2);
    std::cout << "#######   #";
    FileLoggerSingletone::instance().GotoXY(x, y - 1);
    std::cout << "    #####";
    FileLoggerSingletone::instance().GotoXY(x,y);
    std::cout << " ###########";
}