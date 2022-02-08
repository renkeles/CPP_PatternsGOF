
#include <iostream>

#include "Bomb.h"
#include "FileLoggerSingleton/FileLoggerSingleton.h"


void Bomb::Draw() const {
    FileLoggerSingleton::instance().SetColor(FileLoggerSingleton::instance().CC_LightMagenta);
    FileLoggerSingleton::instance().GotoXY(x, y);
    std::cout << "*";
}