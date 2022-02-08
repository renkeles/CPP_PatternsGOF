
#include <iostream>

#include "House.h"
#include "FileLoggerSingletone/FileLoggerSingletone.h"


bool House::isInside(double x1, double x2) const {
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

void House::Draw() const {
    FileLoggerSingletone::instance().SetColor(FileLoggerSingletone::instance().CC_Yellow);
    FileLoggerSingletone::instance().GotoXY(x, y - 5);
    std::cout << "  ########  ";
    FileLoggerSingletone::instance().GotoXY(x, y - 4);
    std::cout << "##        ##";
    FileLoggerSingletone::instance().GotoXY(x, y - 3);
    std::cout << "############";
    FileLoggerSingletone::instance().GotoXY(x, y - 2);
    std::cout << "#          #";
    FileLoggerSingletone::instance().GotoXY(x, y - 1);
    std::cout << "#          #";
    FileLoggerSingletone::instance().GotoXY(x, y);
    std::cout << "############";
}