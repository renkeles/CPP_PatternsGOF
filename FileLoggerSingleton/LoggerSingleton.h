#include "FileLoggerSingleton.h"

#include "string"


class LoggerSingleton
{
    private:
        size_t lineCounter;
        
        LoggerSingleton();
        
        LoggerSingleton(const LoggerSingleton& other) = delete;
        LoggerSingleton(const LoggerSingleton&& other) = delete;
        LoggerSingleton& operator=(const LoggerSingleton& other) = delete;
        LoggerSingleton& operator=(const LoggerSingleton&& other) = delete;
        
        std::string addLineIndex(const std::string& str);
        
    public:
        ~LoggerSingleton();
        
        static LoggerSingleton& instance();
        
        void setLogFile(const std::string& fileName);
        
        void ClrScr();
        
        void __fastcall GotoXY(double x, double y);
        
        uint16_t GetMaxX();
        uint16_t GetMaxY();
        
        void SetColor(ConsoleColor color);
        
        void __fastcall WriteToLog(const std::string& str);
        void __fastcall WriteToLog(const std::string& str, int n);
        void __fastcall WriteToLog(const std::string& str, double d);
};
