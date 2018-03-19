#include "AllyTank.h"
#include "Field.h"
#include <windows.h>
#include <conio.h>
#include "AllyBullet.h"
#include <thread>


AllyTank::AllyTank(Field * field)
{
    //ctor
    field_=field;
    currentDirection_=UP;
    newDirection_=NONE;
    cursorController_ = new CursorController();
    tankCoordinates_[0]=(field_->fieldWidth_-tankWidth_)/2;
    tankCoordinates_[1]=field_->fieldHeight_-1-tankHeight_;
    if(canDraw(tankCoordinates_[0], tankCoordinates_[1]))
    {
        drawTank(tankCoordinates_[0], tankCoordinates_[1], false);
    }
    allyBullet_ = new AllyBullet(field_);
}

AllyTank::~AllyTank()
{
    //dtor
}

void AllyTank::checkKeyPress()
{
    int c;
    while(true)
    {
        c=_getch();
        if(c==224)
        {
            c=_getch();

            if(c==72)
            {
                newDirection_=UP;
                if(canDraw(tankCoordinates_[0], tankCoordinates_[1]-1))
                {
                    tankCoordinates_[1]-=1;
                    drawTank(tankCoordinates_[0], tankCoordinates_[1], true);
                    currentDirection_=newDirection_;
                }
            }
            if(c==80)
            {
                newDirection_=DOWN;
                if(canDraw(tankCoordinates_[0], tankCoordinates_[1]+1))
                {
                    tankCoordinates_[1]+=1;
                    drawTank(tankCoordinates_[0], tankCoordinates_[1], true);
                    currentDirection_=newDirection_;
                }
            }
            if(c==75)
            {
                newDirection_=LEFT;
                if(canDraw(tankCoordinates_[0]-1, tankCoordinates_[1]))
                {
                    tankCoordinates_[0]-=1;
                    drawTank(tankCoordinates_[0], tankCoordinates_[1], true);
                    currentDirection_=newDirection_;
                }
            }

            if(c==77)
            {
                newDirection_=RIGHT;
                if(canDraw(tankCoordinates_[0]+1, tankCoordinates_[1]))
                {
                    tankCoordinates_[0]+=1;
                    drawTank(tankCoordinates_[0], tankCoordinates_[1], true);
                    currentDirection_=newDirection_;
                }
            }
        }
        if (c==32)
        {
            allyBullet_->shoot(tankCoordinates_[0], tankCoordinates_[1], currentDirection_);
        }
    }
}


bool AllyTank::canDraw(int x, int y)
{
    bool canDraw=true;
    switch(newDirection_)
    {
    case UP:
    case NONE:
    {
        for(int i=0; i<tankHeight_; i++)
        {
            for(int j=0; j<tankWidth_; j++)
            {
                if((field_->isEmpty(x+j,y+i, field_->getLevel())==false)&&(tankUP_[i][j]==1))
                {
                    canDraw=false;
                    break;
                }
            }
            if(canDraw==false)
            {
                break;
            }
        }
    }
    return canDraw;
    case DOWN:
    {
        for(int i=0; i<tankHeight_; i++)
        {
            for(int j=0; j<tankWidth_; j++)
            {
                if((field_->isEmpty(x+j,y+i, field_->getLevel())==false)&&(tankDOWN_[i][j]==1))
                {
                    canDraw=false;
                    break;
                }
            }
            if(canDraw==false)
            {
                break;
            }
        }
    }
    return canDraw;
    case LEFT:
    {
        for(int i=0; i<tankWidth_; i++)
        {
            for(int j=0; j<tankHeight_; j++)
            {
                if((field_->isEmpty(x+j,y+i, field_->getLevel())==false)&&(tankLEFT_[i][j]==1))
                {
                    canDraw=false;
                    break;
                }
            }
            if(canDraw==false)
            {
                break;
            }
        }
    }
    return canDraw;
    case RIGHT:
    {
        for(int i=0; i<tankWidth_; i++)
        {
            for(int j=0; j<tankHeight_; j++)
            {
                if((field_->isEmpty(x+j,y+i, field_->getLevel())==false)&&(tankRIGHT_[i][j]==1))
                {
                    canDraw=false;
                    break;
                }
            }
            if(canDraw==false)
            {
                break;
            }
        }
    }
    return canDraw;

    }
}

void AllyTank::redrawPrevious(int x, int y, int i, int j, int a, int b)
{
    switch (currentDirection_)
    {
    case UP:
    {
        if(tankUP_[i][j]==1)
        {
            if(newDirection_==LEFT)
            {
                int temp = i;
                i=j;
                j=temp;
            }
            if(field_->isEmpty(x+j+a, y+b+i, field_->getLevel()))
            {
                cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0]+a, y+b+i+field_->fieldLeftCorner_[1], " ");
            }
        }
    }
    break;
    case DOWN:
    {
        if(field_->isEmpty(x+j+a,y+i+b, field_->getLevel()))
        {
            if(newDirection_==LEFT)
            {
                int temp = i;
                i=j;
                j=temp;
            }
            if(newDirection_==RIGHT)
            {
                int temp = i;
                i=j;
                j=temp;
            }
            if(tankDOWN_[i][j]==1)
            {
                if(field_->isEmpty(x+j+a, y+b+i, field_->getLevel()))
                {
                    cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0]+a, y+b+i+field_->fieldLeftCorner_[1], " ");
                }
            }
        }
    }
    break;
    case LEFT:
    {
        if(field_->isEmpty(x+j+a,y+i+b, field_->getLevel()))
        {
            if(tankLEFT_[i][j]==1)
            {
                if(newDirection_==UP)
                {
                    int temp = tankHeight_-i-1;
                    i=j;
                    j=temp;
                }
                if(newDirection_==DOWN)
                {
                    int temp = tankHeight_-i;
                    i=j;
                    j=temp;
                }
                if(field_->isEmpty(x+j+a, y+b+i, field_->getLevel()))
                {
                    cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0]+a, y+b+i+field_->fieldLeftCorner_[1], " ");
                }
            }
        }
    }
    break;
    case RIGHT:
    {
        if(field_->isEmpty(x+j+a,y+i+b, field_->getLevel()))
        {
            if(tankRIGHT_[i][j]==1||tankRIGHT_[i][j]==0)
            {
                if(newDirection_==UP)
                {
                    int temp = i;
                    i=j;
                    j=temp;
                }
                if(newDirection_==DOWN)
                {
                    int temp = i;
                    i=j;
                    j=temp;
                }
                if(field_->isEmpty(x+j+a, y+b+i, field_->getLevel()))
                {
                    cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0]+a, y+b+i+field_->fieldLeftCorner_[1], " ");
                }
            }
        }
    }
    break;
    }
}

void AllyTank::drawTank(int x, int y, bool redraw)
{
    switch(newDirection_)
    {
    case UP:
    case NONE:
    {
        for(int i=0; i<tankHeight_; i++)
        {
            for(int j=0; j<tankWidth_; j++)
            {
                if(redraw==true)
                {
                    redrawPrevious(x, y, i, j, 0, 1);
                }
            }
        }
        for(int i=0; i<tankHeight_; i++)
        {
            for(int j=0; j<tankWidth_; j++)
            {
                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
                {
                    if(tankUP_[i][j]==1)
                    {
                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
                    }
                }
            }
        }
    }
    break;
    case DOWN:
    {
        for(int i=0; i<tankHeight_; i++)
        {
            for(int j=0; j<tankWidth_; j++)
            {
                if(redraw==true)
                {
                    redrawPrevious(x,y,i,j, 0, -1);
                }
            }
        }
        for(int i=0; i<tankHeight_; i++)
        {
            for(int j=0; j<tankWidth_; j++)
            {
                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
                {
                    if(tankDOWN_[i][j]==1)
                    {
                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
                    }
                }
            }
        }
    }
    break;
    case LEFT:
    {
        for(int i=0; i<tankWidth_; i++)
        {
            for(int j=0; j<tankHeight_; j++)
            {
                if(redraw==true)
                {
                    redrawPrevious(x,y,i,j, 1, 0);
                }
            }
        }
        for(int i=0; i<tankWidth_; i++)
        {
            for(int j=0; j<tankHeight_; j++)
            {
                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
                {
                    if(tankLEFT_[i][j]==1)
                    {
                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
                    }
                }
            }
        }
    }
    break;
    case RIGHT:
    {
        for(int i=0; i<tankWidth_; i++)
        {
            for(int j=0; j<tankHeight_; j++)
            {
                if(redraw==true)
                {
                    redrawPrevious(x,y,i,j, -1, 0);
                }
            }
        }
        for(int i=0; i<tankWidth_; i++)
        {
            for(int j=0; j<tankHeight_; j++)
            {
                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
                {
                    if(tankRIGHT_[i][j]==1)
                    {
                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
                    }
                }
            }
        }
    }
    break;

    }
}
