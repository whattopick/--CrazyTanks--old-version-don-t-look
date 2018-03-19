//#include "EnemyTank.h"
//#include <stdlib.h>
//#include <time.h>
//#include "Field.h"
//#include <windows.h>
//#include <conio.h>
//#include "AllyBullet.h"
//
//EnemyTank::EnemyTank(int healthPoints, Field * field, int enemiesCount)
//{
//    healthPoints_=healthPoints;
//    //ctor
//    field_=field;
//    srand(time(NULL));
//    int dir = rand()%4;
//    char c;
//    currentDirection_= DIRECTION (dir);
//    switch (currentDirection_){
//        case UP:{
//        c='u';
//        }
//        break;
//        case DOWN:{
//        c='d';
//        }
//        break;
//        case LEFT:{
//        c='l';
//        }
//        break;
//        case RIGHT:{
//        c='r';
//        }
//        break;
//    }
//    newDirection_=NONE;
//    cursorController_ = new CursorController();
//    switch(field_->getLevel())
//    {
//    case 0:
//    {
//        int counter;
//        int tx;
//        int ty;
//        do
//        {
//            counter = rand()%9;
//            int tx = field_->levelSp0_[counter][0];
//            int ty = field_->levelSp0_[counter][1];
//            if(strcmp(field_->levelAdd0_[ty][tx], " ")==0)
//            {
//                field_->levelAdd0_[ty][tx] = &c;
//                tankCoordinates_[0]=tx;
//                tankCoordinates_[1]=ty;
//            }
//        } while(strcmp(field_->levelAdd0_[ty][tx], " ")==0);
//
//    }
//    break;
//    case 1:
//    {
//    int counter;
//        int tx;
//        int ty;
//        do
//        {
//            counter = rand()%9;
//            int tx = field_->levelSp1_[counter][0];
//            int ty = field_->levelSp1_[counter][1];
//            if(strcmp(field_->levelAdd1_[ty][tx], " ")==0)
//            {
//                field_->levelAdd0_[ty][tx] = &c;
//                tankCoordinates_[0]=tx;
//                tankCoordinates_[1]=ty;
//            }
//        } while(strcmp(field_->levelAdd1_[ty][tx], " ")==0);
//    }
//    break;
//    case 2:
//    {
//    int counter;
//        int tx;
//        int ty;
//        do
//        {
//            counter = rand()%9;
//            int tx = field_->levelSp2_[counter][0];
//            int ty = field_->levelSp2_[counter][1];
//            if(strcmp(field_->levelAdd2_[ty][tx], " ")==0)
//            {
//                field_->levelAdd2_[ty][tx] = &c;
//                tankCoordinates_[0]=tx;
//                tankCoordinates_[1]=ty;
//            }
//        } while(strcmp(field_->levelAdd2_[ty][tx], " ")==0);
//    }
//    break;
//    }
//    //if(canDraw(tankCoordinates_[0], tankCoordinates_[1]))
//    //{
//        drawTank(tankCoordinates_[0], tankCoordinates_[1]);
//    //}
//   // allyBullet_ = new AllyBullet(field_);
//}
//
//EnemyTank::~EnemyTank()
//{
//    //dtor
//}
//
//void EnemyTank::drawTank(int x, int y)
//{
//    //cursorController_->drawAtPlace(x, y, "o");
//    //bool canDraw=true;
//    switch(newDirection_)
//    {
//    case UP:
//    case NONE:
//    {
//        for(int i=0; i<tankHeight_; i++)
//        {
//            for(int j=0; j<tankWidth_; j++)
//            {
//                /*if(redraw==true){
//                    redrawPrevious(x, y, i, j, 0, 1);
//                }*/
//                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
//                {
//                    if(tankUP_[i][j]==1)
//                    {
//                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
//                    }
//                }
//            }
//        }
//        //currentDirection_=newDirection_;
//    }
//    break;
//    case DOWN:
//    {
//        for(int i=0; i<tankHeight_; i++)
//        {
//            for(int j=0; j<tankWidth_; j++)
//            {
//                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
//                {
//                    if(tankDOWN_[i][j]==1)
//                    {
//                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
//                    }
//                }
//            }
//        }
//    }
//    break;
//    case LEFT:
//    {
//        for(int i=0; i<tankWidth_; i++)
//        {
//            for(int j=0; j<tankHeight_; j++)
//            {
//                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
//                {
//                    if(tankLEFT_[i][j]==1)
//                    {
//                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
//                    }
//                }
//            }
//        }
//    }
//    break;
//    case RIGHT:
//    {
//        for(int i=0; i<tankWidth_; i++)
//        {
//            for(int j=0; j<tankHeight_; j++)
//            {
//                if(field_->isEmpty(x+j,y+i, field_->getLevel()))
//                {
//                    if(tankRIGHT_[i][j]==1)
//                    {
//                        cursorController_->drawAtPlace(x+j+field_->fieldLeftCorner_[0], y+i+field_->fieldLeftCorner_[1], "o");
//                    }
//                }
//            }
//        }
//    }
//    break;
//
//    }
//}
