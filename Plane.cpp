
#include <iostream>

#include "Plane.h"
#include "FileLoggerSingleton/LoggerSingleton.h"


void Plane::Draw() const {
    LoggerSingleton::instance().SetColor(CC_LightBlue);
    LoggerSingleton::instance().GotoXY(x, y);
    std::cout << "=========>";
    LoggerSingleton::instance().GotoXY(x - 2, y - 1);
    std::cout << "===";
    LoggerSingleton::instance().GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    LoggerSingleton::instance().GotoXY(x + 3, y + 1);
    std::cout << "////";
}
