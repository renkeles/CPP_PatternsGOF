
#include <conio.h>

#include "SBomber.h"
#include "FileLoggerSingleton/FileLoggerSingleton.h"

//========================================================================================================================

int main(void)
{
    FileLoggerSingleton::instance().setLogFile("log.txt");
    
    SBomber game;
    
    do {
        game.TimeStart();
        
        if (_kbhit())
            game.ProcessKBHit();
        
        FileLoggerSingleton::instance().ClrScr();
        
        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();
        
        game.TimeFinish();
        
    } while (!game.GetExitFlag());
    
    return 0;
}
