#include "FileLoggerSingletone.h"

#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <chrono>

//==============================================================================================

FileLoggerSingletone::FileLoggerSingletone() {
    
}

FileLoggerSingletone::~FileLoggerSingletone()
{
    instance().CloseLogFile();
}

//==============================================================================================

void __fastcall FileLoggerSingletone::OpenLogFile(const std::string& FN) {
    logOut.open(FN, std::ios_base::out);
}

void FileLoggerSingletone::CloseLogFile() {
    if (logOut.is_open())
        logOut.close();
}

std::string FileLoggerSingletone::GetCurDateTime() {
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

//==============================================================================================

FileLoggerSingletone& FileLoggerSingletone::instance() {
    static FileLoggerSingletone instance;
    return instance;
}

void FileLoggerSingletone::setLogFile(const std::string& fileName) {
    instance().CloseLogFile();
    instance().OpenLogFile(fileName);
}

//==============================================================================================

void FileLoggerSingletone::ClrScr() {
    system("cls");
}

void __fastcall FileLoggerSingletone::GotoXY(double x, double y) {
    const COORD cc = { short(x), short(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cc);
}

uint16_t FileLoggerSingletone::GetMaxX() {
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

uint16_t FileLoggerSingletone::GetMaxY() {
    HANDLE hWndConsole;
    if ((hWndConsole = GetStdHandle(-12))) {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            return consoleInfo.srWindow.Bottom;
    }
    
    return 0;
}

void FileLoggerSingletone::SetColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color); // color =  (WORD)((BackgroundColor << 4) | TextColor))
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str) {
    if (logOut.is_open())
        logOut << GetCurDateTime() << " - " << str << std::endl;
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str, int n) {
    if (logOut.is_open())
        logOut << GetCurDateTime() << " - " << str << n << std::endl;
}

void __fastcall FileLoggerSingletone::WriteToLog(const std::string& str, double d) {
    if (logOut.is_open())
        logOut << GetCurDateTime() << " - " << str << d << std::endl;
}
