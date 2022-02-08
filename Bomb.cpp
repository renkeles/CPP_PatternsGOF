
#include <iostream>

#include "Bomb.h"
#include "FileLoggerSingletone/FileLoggerSingletone.h"


void Bomb::Draw() const {
    FileLoggerSingletone::instance().SetColor(FileLoggerSingletone::instance().CC_LightMagenta);
    FileLoggerSingletone::instance().GotoXY(x, y);
    std::cout << "*";
}