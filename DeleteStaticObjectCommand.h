#pragma once

#include "Command.h"
#include "GameObject.h"
#include <vector>


class DeleteStaticObjectCommand : public Command {
    public:
        DeleteStaticObjectCommand(const GameObject* pObject, std::vector<GameObject*>& vec)
            :
                pObject(pObject),
                vec(vec)
        {}
        
        virtual ~DeleteStaticObjectCommand() {}
        
        void execute() override {
            for (auto it = vec.begin(); it != vec.end(); ++it)
                if (*it == pObject) {
                    delete *it;
                    vec.erase(it);
                    return;
                }
        }
        
    private:
        const GameObject* pObject;
        std::vector<GameObject*>& vec;
};