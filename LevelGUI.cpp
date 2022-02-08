#include <iostream>
#include <cstring>

#include "LevelGUI.h"
#include "FileLoggerSingleton/FileLoggerSingleton.h"


void LevelGUI::Draw() const {
    FileLoggerSingleton::instance().SetColor(FileLoggerSingleton::instance().CC_White);
    
    FileLoggerSingleton::instance().GotoXY(x, y);
    char* buf = new (std::nothrow) char[width + 1];
    
    if (buf == nullptr)
        return;
    
    memset(buf, '+', width);
    buf[width] = '\0';
    std::cout << buf;
    FileLoggerSingleton::instance().GotoXY(x, y + height);
    std::cout << buf;
    delete [] buf;
    buf = nullptr;
    
    for (size_t i = size_t(y); i < height + y; i++)
    {
        FileLoggerSingleton::instance().GotoXY(x, (double)i);
        std::cout << "+";
        FileLoggerSingleton::instance().GotoXY(x + width - 1, (double)i);
        std::cout << "+";
    }
    
    FileLoggerSingleton::instance().GotoXY(3, 1);
    std::cout << "FramePerSecond: " << static_cast<int>(fps / (passedTime / 1000.0));
    FileLoggerSingleton::instance().GotoXY(25, 1);
    std::cout << "PassedTime: " << static_cast<int>(passedTime / 1000.0) << " sec";
    FileLoggerSingleton::instance().GotoXY(46, 1);
    std::cout << "BombsNum: " << bombsNumber;
    FileLoggerSingleton::instance().GotoXY(62, 1);
    std::cout << "Score: " << score;
}

void __fastcall LevelGUI::SetParam(
    uint64_t passedTimeNew,
    uint64_t fpsNew,
    uint16_t bombsNumberNew,
    int16_t scoreNew
) {
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;
}
