#include "LoggerSingleton.h"


LoggerSingleton::LoggerSingleton() : lineCounter(0) {
    
}

std::string LoggerSingleton::addLineIndex(const std::string& str) {
    ++lineCounter;
    return std::string(" #") + std::to_string(lineCounter) + " " + str;
}

LoggerSingleton::~LoggerSingleton() {
}

LoggerSingleton& LoggerSingleton::instance() {
    static LoggerSingleton instance;
    return instance;
}

void LoggerSingleton::setLogFile(const std::string& fileName) {
    FileLoggerSingleton::instance().setLogFile(fileName);
}

void LoggerSingleton::ClrScr() {
    FileLoggerSingleton::instance().ClrScr();
}

void __fastcall LoggerSingleton::GotoXY(double x, double y) {
    FileLoggerSingleton::instance().GotoXY(x, y);
}

uint16_t LoggerSingleton::GetMaxX() {
    return FileLoggerSingleton::instance().GetMaxX();
}

uint16_t LoggerSingleton::GetMaxY() {
    return FileLoggerSingleton::instance().GetMaxY();
}

void LoggerSingleton::SetColor(ConsoleColor color) {
    FileLoggerSingleton::instance().SetColor(color);
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str) {
    FileLoggerSingleton::instance().WriteToLog(addLineIndex(str));
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str, int n) {
    FileLoggerSingleton::instance().WriteToLog(addLineIndex(str), n);
}

void __fastcall LoggerSingleton::WriteToLog(const std::string& str, double d) {
    FileLoggerSingleton::instance().WriteToLog(addLineIndex(str), d);
}
