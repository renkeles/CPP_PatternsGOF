
#include <iostream>

#include "Plane.h"
#include "FileLoggerSingleton/FileLoggerSingleton.h"


void Plane::Draw() const {
    FileLoggerSingleton::instance().SetColor(FileLoggerSingleton::instance().CC_LightBlue);
    FileLoggerSingleton::instance().GotoXY(x, y);
    std::cout << "=========>";
    FileLoggerSingleton::instance().GotoXY(x - 2, y - 1);
    std::cout << "===";
    FileLoggerSingleton::instance().GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    FileLoggerSingleton::instance().GotoXY(x + 3, y + 1);
    std::cout << "////";
}
