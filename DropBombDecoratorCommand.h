#pragma once

#include "FileLoggerSingleton/FileLoggerSingleton.h"
#include "Command.h"
#include "DynamicObject.h"
#include "Plane.h"
#include <vector>
#include "BombDecorator.h"
#include "Ground.h"


class DropBombDecoratorCommand : public Command {
    public:
        DropBombDecoratorCommand(
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
        
        ~DropBombDecoratorCommand() {}
        
        void execute() override {
            if (bombsNumber > 0) {
                FileLoggerSingleton::instance().WriteToLog(std::string(__FUNCTION__) + " was invoked");
                
                double x = pPlane->GetX() + 4;
                double y = pPlane->GetY() + 2;
                
                Bomb* pBomb = new Bomb;
                pBomb->SetDirection(0.3, 1);
                pBomb->SetPos(x, y);
                pBomb->SetWidth(craterSize);
                
                BombDecorator* bombDecorator = new BombDecorator(
                    pBomb,
                    speed,
                    ">"
                );
                
                vec.push_back(bombDecorator);
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
