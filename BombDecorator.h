#pragma once

#include "Bomb.h"
#include <string>
#include <iostream>
#include "FileLoggerSingleton/FileLoggerSingleton.h"


class BombDecorator : public Bomb {
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
        
        virtual void SetPos(double nx, double ny) {
            pBomb->SetPos(nx, ny);
        }
        
        virtual double GetY() const {
            return pBomb->GetY();
        }
        
        virtual double GetX() const {
            return pBomb->GetX();
        }
        
        virtual void SetWidth(uint16_t widthN) {
            pBomb->SetWidth(widthN);
        }
        
        virtual uint16_t GetWidth() const {
            return pBomb->GetWidth();
        }
};
