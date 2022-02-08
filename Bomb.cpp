
#include <iostream>

#include "Bomb.h"
#include "FileLoggerSingleton/LoggerSingleton.h"


void Bomb::Draw() const {
    LoggerSingleton::instance().SetColor(CC_LightMagenta);
    LoggerSingleton::instance().GotoXY(x, y);
    std::cout << "*";
}