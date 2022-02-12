#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

#include "DeleteDynamicObjectCommand.h"
#include "DeleteStaticObjectCommand.h"
#include "DropBombCommand.h"
#include "DropBombDecoratorCommand.h"


class SBomber
{
    public:
        SBomber();
        ~SBomber();
        
        inline bool GetExitFlag() const { return exitFlag; }
        
        void ProcessKBHit();
        void TimeStart();
        void TimeFinish();
        
        void DrawFrame();
        void MoveObjects();
        void CheckObjects();
        
    private:
        void CheckPlaneAndLevelGUI();
        void CheckBombsAndGround();
        void __fastcall CheckDestoyableObjects(Bomb* pBomb);
        
        void CommandExecuter(Command* command);
        
        Ground* FindGround() const;
        Plane* FindPlane() const;
        LevelGUI* FindLevelGUI() const;
        std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
        std::vector<Bomb*> FindAllBombs() const;
        
        std::vector<DynamicObject*> vecDynamicObj;
        std::vector<GameObject*> vecStaticObj;
        
        bool exitFlag;
        
        uint64_t startTime;
        uint64_t finishTime;
        uint64_t passedTime;
        uint64_t deltaTime;
        uint64_t fps;
        
        uint16_t bombsNumber;
        uint16_t score;
};