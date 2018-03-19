//#ifndef ENEMYTANK_H
//#define ENEMYTANK_H
//#include "Field.h"
//#include <windows.h>
//#include "AllyBullet.h"
//
//class EnemyTank
//{
//    public:
//        EnemyTank(int, Field*, int);
//        virtual ~EnemyTank();
//        //void drawTank(int, int);
//        void drawTank(int, int);
//        void redrawPrevious(int, int, int, int, int, int);
//        bool canDraw(int, int);
//
//        int tankCoordinates_[2] = {-1,-1};
//        void checkKeyPress();
//
//    protected:
//
//    public:
//        enum DIRECTION {UP, DOWN, LEFT, RIGHT, NONE};
//        volatile DIRECTION currentDirection_;
//        volatile DIRECTION newDirection_;
//        struct bullet{
//        int x;
//        int y;
//        DIRECTION d;
//        };
//        bullet shoot();
//        void drawBullet(bullet);
//
//        private:
//        Field* field_;
//        const static int tankHeight_ = 2;
//        const static int tankWidth_ = 3;
//        CursorController * cursorController_;
//        AllyBullet * allyBullet_;
//
//
//
//        int tankUP_[tankHeight_][tankWidth_]={
//        {0,1,0},
//        {1,1,1}
//        };
//        int tankDOWN_[tankHeight_][tankWidth_]={
//        {1,1,1},
//        {0,1,0}
//        };
//        int tankLEFT_[tankWidth_][tankHeight_]={
//        {0,1},
//        {1,1},
//        {0,1}
//        };
//        int tankRIGHT_[tankWidth_][tankHeight_]={
//        {1,0},
//        {1,1},
//        {1,0}
//        };
//        int healthPoints_;
//};
//
//#endif // ENEMYTANK_H
