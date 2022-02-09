#pragma once

#include "FileLoggerSingleton/FileLoggerSingleton.h"
#include "Command.h"
#include "DynamicObject.h"
#include "Plane.h"
#include <vector>
#include "Bomb.h"
#include "Ground.h"


class DropBombCommand : public Command {
    public:
        DropBombCommand(
            const Plane* plane,
            std::vector<DynamicObject*>& vec,
            uint16_t& bombsNumber,
            uint16_t& score,
            const double speed,
            const CraterSize craterSize
        )
            :
                pPlane(plane),
                vec(vec),
                bombsNumber(bombsNumber),
                score(score),
                speed(speed),
                craterSize(craterSize)
        {}
        
        ~DropBombCommand() {}
        
        void execute() override {
            if (bombsNumber > 0) {
                FileLoggerSingleton::instance().WriteToLog(std::string(__FUNCTION__) + " was invoked");
                
                double x = pPlane->GetX() + 4;
                double y = pPlane->GetY() + 2;
                
                Bomb* pBomb = new Bomb;
                pBomb->SetDirection(0.3, 1);
                pBomb->SetSpeed(speed);
                pBomb->SetPos(x, y);
                pBomb->SetWidth(craterSize);
                
                vec.push_back(pBomb);
                bombsNumber--;
                score -= Bomb::BombCost;
            }
        }
        
    private:
        const Plane* pPlane;
        std::vector<DynamicObject*>& vec;
        uint16_t& bombsNumber;
        uint16_t& score;
        const double speed;
        const CraterSize craterSize;
};
