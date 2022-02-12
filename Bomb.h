#pragma once

#include "DynamicObject.h"


class Bomb : public DynamicObject {
    public:
        virtual ~Bomb() {}
        
        static const uint16_t BombCost = 10;
        void Draw() const override;
};

