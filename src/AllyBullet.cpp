#include "AllyBullet.h"
#include <conio.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>

AllyBullet::AllyBullet(Field * field)
{
    //ctor
    field_=field;
    cursorController_ = new CursorController();
}

AllyBullet::~AllyBullet()
{
    //dtor
}

void AllyBullet::shoot(int x, int y, int d)
{
    switch(d)
    {
    case 0:
    {
        x=x+1;
        y=y-1;
    }
    break;
    case 1:
    {
        x=x+1;
        y=y+2;
    }
    break;
    case 2:
    {
        x=x-1;
        y=y+1;
    }
    break;
    case 3:
    {
        x=x+2;
        y=y+1;
    }
    break;
    }
    while (field_->isEmpty(x, y, field_->getLevel()))
    {
        cursorController_->drawAtPlace(x+field_->fieldLeftCorner_[0], y+field_->fieldLeftCorner_[1], "*");
        switch(d)
        {
        case 0:
        {
            y-=1;
            Sleep(45);
            cursorController_->drawAtPlace(x+field_->fieldLeftCorner_[0], y+field_->fieldLeftCorner_[1]+1, " ");
        }
        break;
        case 1:
        {
            y+=1;
            Sleep(45);
            cursorController_->drawAtPlace(x+field_->fieldLeftCorner_[0], y+field_->fieldLeftCorner_[1]-1, " ");
        }
        break;
        case 2:
        {
            x-=1;
            Sleep(45);
            cursorController_->drawAtPlace(x+field_->fieldLeftCorner_[0]+1, y+field_->fieldLeftCorner_[1], " ");
        }
        break;
        case 3:
        {
            x+=1;
            Sleep(45);
            cursorController_->drawAtPlace(x+field_->fieldLeftCorner_[0]-1, y+field_->fieldLeftCorner_[1], " ");
        }
        break;

        }
    }
}
