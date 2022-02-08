
#include <iostream>

#include "House.h"
#include "FileLoggerSingleton/FileLoggerSingleton.h"


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
    FileLoggerSingleton::instance().SetColor(FileLoggerSingleton::instance().CC_Yellow);
    FileLoggerSingleton::instance().GotoXY(x, y - 5);
    std::cout << "  ########  ";
    FileLoggerSingleton::instance().GotoXY(x, y - 4);
    std::cout << "##        ##";
    FileLoggerSingleton::instance().GotoXY(x, y - 3);
    std::cout << "############";
    FileLoggerSingleton::instance().GotoXY(x, y - 2);
    std::cout << "#          #";
    FileLoggerSingleton::instance().GotoXY(x, y - 1);
    std::cout << "#          #";
    FileLoggerSingleton::instance().GotoXY(x, y);
    std::cout << "############";
}