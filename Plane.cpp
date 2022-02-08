
#include <iostream>

#include "Plane.h"
#include "FileLoggerSingletone/FileLoggerSingletone.h"


void Plane::Draw() const {
    FileLoggerSingletone::instance().SetColor(FileLoggerSingletone::instance().CC_LightBlue);
    FileLoggerSingletone::instance().GotoXY(x, y);
    std::cout << "=========>";
    FileLoggerSingletone::instance().GotoXY(x - 2, y - 1);
    std::cout << "===";
    FileLoggerSingletone::instance().GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    FileLoggerSingletone::instance().GotoXY(x + 3, y + 1);
    std::cout << "////";
}
