#pragma once

#include "Bomb.h"
#include <string>
#include <iostream>
#include "FileLoggerSingleton/FileLoggerSingleton.h"


class BombDecorator : public DynamicObject {
    private:
        Bomb* pBomb;
        const char* pic;
        
    public:
        BombDecorator(
            Bomb* pBomb,
            const double speed,
            const char* pic
        )
            :
                pBomb(pBomb),
                pic(pic)
        {
            if (pBomb)
                pBomb->SetSpeed(speed);
        }
        
        ~BombDecorator() {
            delete pBomb;
        }
        
        void Move(uint16_t time) override {
            pBomb->Move(time);
        }
        
        void Draw() const override {
            pBomb->Draw();
            std::cout << pic;
        }
};
