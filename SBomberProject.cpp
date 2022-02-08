
#include <conio.h>

#include "SBomber.h"
#include "FileLoggerSingleton/LoggerSingleton.h"

//========================================================================================================================

int main(void)
{
    LoggerSingleton::instance().setLogFile("log.txt");
    
    SBomber game;
    
    do {
        game.TimeStart();
        
        if (_kbhit())
            game.ProcessKBHit();
        
        LoggerSingleton::instance().ClrScr();
        
        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();
        
        game.TimeFinish();
        
    } while (!game.GetExitFlag());
    
    return 0;
}
