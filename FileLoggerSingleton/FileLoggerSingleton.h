#pragma once

#include <string>
#include <iostream>
#include <fstream>


class FileLoggerSingleton {
    private:
        std::ofstream logOut;
        
        FileLoggerSingleton();
        
        FileLoggerSingleton(const FileLoggerSingleton& other) = delete;
        FileLoggerSingleton(const FileLoggerSingleton&& other) = delete;
        FileLoggerSingleton& operator=(const FileLoggerSingleton& other) = delete;
        FileLoggerSingleton& operator=(const FileLoggerSingleton&& other) = delete;
        
        void __fastcall OpenLogFile(const std::string& fileName);
        void CloseLogFile();
        
        std::string GetCurDateTime();
        
    public:
        ~FileLoggerSingleton();
        
        static FileLoggerSingleton& instance();
        
        static void setLogFile(const std::string& fileName);
        
        enum ConsoleColor {
            CC_Black = 0,
            CC_Blue,
            CC_Green,
            CC_Cyan,
            CC_Red,
            CC_Magenta,
            CC_Brown,
            CC_LightGray,
            CC_DarkGray,
            CC_LightBlue,
            CC_LightGreen,
            CC_LightCyan,
            CC_LightRed,
            CC_LightMagenta,
            CC_Yellow,
            CC_White,
        };
        
        void ClrScr();
        
        void __fastcall GotoXY(double x, double y);
        
        uint16_t GetMaxX();
        uint16_t GetMaxY();
        
        void SetColor(ConsoleColor color);
        
        void __fastcall WriteToLog(const std::string& str);
        void __fastcall WriteToLog(const std::string& str, int n);
        void __fastcall WriteToLog(const std::string& str, double d);
};
