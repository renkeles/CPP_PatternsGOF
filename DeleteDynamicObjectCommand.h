#pragma once

#include "Command.h"
#include "DynamicObject.h"
#include <vector>


class DeleteDynamicObjectCommand : public Command {
    public:
        DeleteDynamicObjectCommand(const DynamicObject* pObject, std::vector<DynamicObject*>& vec)
            :
                pObject(pObject),
                vec(vec)
        {}
        
        virtual ~DeleteDynamicObjectCommand() {}
        
        void execute() override {
            for (auto it = vec.begin(); it != vec.end(); ++it)
                if (*it == pObject) {
                    delete *it;
                    vec.erase(it);
                    return;
                }
        }
        
    private:
        const DynamicObject* pObject;
        std::vector<DynamicObject*>& vec;
};