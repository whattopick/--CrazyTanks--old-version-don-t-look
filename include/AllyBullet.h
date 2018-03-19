#ifndef ALLYBULLET_H
#define ALLYBULLET_H
#include "CursorController.h"
#include "Field.h"


class AllyBullet
{
    public:
        AllyBullet(Field*);
        virtual ~AllyBullet();
        void shoot(int, int, int);

    protected:

    public:
        Field* field_;
        int x_;
        int y_;
        int direction_;
    private:
        CursorController * cursorController_;
};

#endif // ALLYBULLET_H
