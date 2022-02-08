#include "FileLoggerSingleton.h"

#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <chrono>

//==============================================================================================

FileLoggerSingleton::FileLoggerSingleton() {
    
}

FileLoggerSingleton::~FileLoggerSingleton()
{
    instance().CloseLogFile();
}

//==============================================================================================

void __fastcall FileLoggerSingleton::OpenLogFile(const std::string& FN) {
    logOut.open(FN, std::ios_base::out);
}

void FileLoggerSingleton::CloseLogFile() {
    if (logOut.is_open())
        logOut.close();
}

std::string FileLoggerSingleton::GetCurDateTime() {
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

//==============================================================================================

FileLoggerSingleton& FileLoggerSingleton::instance() {
    static FileLoggerSingleton instance;
    return instance;
}

void FileLoggerSingleton::setLogFile(const std::string& fileName) {
    instance().CloseLogFile();
    instance().OpenLogFile(fileName);
}

//==============================================================================================

void FileLoggerSingleton::ClrScr() {
    system("cls");
}

void __fastcall FileLoggerSingleton::GotoXY(double x, double y) {
    const COORD cc = { short(x), short(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cc);
}

uint16_t FileLoggerSingleton::GetMaxX() {
    HANDLE hWndConsole;
    if ((hWndConsole = GetStdHandle(-12))) {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
            return consoleInfo.srWindow.Right;
            //int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1; // WHAT IS THIS??
        }
    }
    
    return 0;
}

uint16_t FileLoggerSingleton::GetMaxY() {
    HANDLE hWndConsole;
    if ((hWndConsole = GetStdHandle(-12))) {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            return consoleInfo.srWindow.Bottom;
    }
    
    return 0;
}

void FileLoggerSingleton::SetColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color); // color =  (WORD)((BackgroundColor << 4) | TextColor))
}

void __fastcall FileLoggerSingleton::WriteToLog(const std::string& str) {
    if (logOut.is_open())
        logOut << GetCurDateTime() << " - " << str << std::endl;
}

void __fastcall FileLoggerSingleton::WriteToLog(const std::string& str, int n) {
    if (logOut.is_open())
        logOut << GetCurDateTime() << " - " << str << n << std::endl;
}

void __fastcall FileLoggerSingleton::WriteToLog(const std::string& str, double d) {
    if (logOut.is_open())
        logOut << GetCurDateTime() << " - " << str << d << std::endl;
}
