#include "Field.h"
#include "stdio.h"
#include "EnemyTank.h"
#include "CursorController.h"
#include <windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>

Field::Field(int level, int enemiesCount, int totalKills, int defeats)
{
    //ctor
    level_=level;
    enemiesCount_=enemiesCount;
    previousEnemiesCount_=enemiesCount_+1;
    health_=getMaxHealth();
    previousHealth_=health_+1;
    enemiesKilled_=0;
    totalKills_= totalKills;
    defeats=defeats;
    drawField();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
}

Field::~Field()
{
    //dtor
}

int Field::getEnemiesCount()
{
    return enemiesCount_;
}

void Field::drawLevel(int level)
{
    switch(level)
    {
    case 0:
    {
        for (int i=0; i<15; i++)
        {
            for (int j=0; j<30; j++)
            {
                cursorController_->drawAtPlace(j, i+2, level0_[i][j]);
            }
            printf("\n");
        }
    }
    break;
    case 1:
    {
        for (int i=0; i<15; i++)
        {
            for (int j=0; j<30; j++)
            {
                cursorController_->drawAtPlace(j, i+2, level1_[i][j]);
            }
            printf("\n");
        }

    }
    break;
    case 2:
    {
        for (int i=0; i<15; i++)
        {
            for (int j=0; j<30; j++)
            {
                cursorController_->drawAtPlace(j, i+2, level2_[i][j]);
            }
            printf("\n");
        }
    }

    break;
    }
}

void Field::drawEnemiesLeft()
{
    cursorController_->drawAtPlace(40,8, "Enemies left: ");
    cursorController_->drawAtPlace(60,8, enemiesCount_);
}

void Field::drawKills()
{
    cursorController_->drawAtPlace(40,9, "Enemies killed: ");
    cursorController_->drawAtPlace(60,9, enemiesKilled_);
}

void Field::drawTotalKills()
{
    cursorController_->drawAtPlace(40, 13, "Total kills: ");
    cursorController_->drawAtPlace(60, 13, totalKills_);
    previousEnemiesCount_=enemiesCount_;
}

void Field::drawDefeats()
{
    cursorController_->drawAtPlace(40, 14, "Defeats: ");
    cursorController_->drawAtPlace(60, 14, defeats_);
}


void Field::drawHealth()
{
    cursorController_->drawAtPlace(40,6, "Health: ");
    for(int i=0; i<health_; i++)
    {
        cursorController_->drawAtPlace(60 + i*4,6, "(o)");
    }
}

void Field::drawHelp()
{
}

void Field::drawDisclaimer()
{

}

void Field::drawTime()
{
    int mins = 0;
    int secs = 0;
    int hrs = 0;
    cursorController_->drawAtPlace(40,3, "Time spent: ");
    cursorController_->drawAtPlace(57,3, "h");
    cursorController_->drawAtPlace(58,3, "h");
    cursorController_->drawAtPlace(59,3, ":");
    cursorController_->drawAtPlace(62,3, "m");
    cursorController_->drawAtPlace(63,3, "m");
    cursorController_->drawAtPlace(64,3, ":");
    cursorController_->drawAtPlace(67,3,"s");
    cursorController_->drawAtPlace(68,3,"s");
    while(true)
    {
        cursorController_->drawAtPlace(55,3, hrs/10);
        cursorController_->drawAtPlace(56,3, hrs%10);
        cursorController_->drawAtPlace(60,3, mins/10);
        cursorController_->drawAtPlace(61,3, mins%10);
        cursorController_->drawAtPlace(65,3, secs/10);
        cursorController_->drawAtPlace(66,3, secs%10);
        Sleep(1000);
        secs+=1;
        if(secs%60==0)
        {
            mins+=1;
            if(mins%60==0)
            {
                hrs+=1;
                mins=0;
            }
            secs=0;
        }
    }
}

int Field::getMaxHealth()
{
    return 3;
}

int Field::getTotalKills()
{
    return this->totalKills_;
}

int Field::getTotalDefeats()
{
    return this->defeats_;
}

void Field::drawHeader()
{
    cursorController_->drawAtPlace(0, 0, "*************************************** CRAZY TANKS *********************************************");
    cursorController_->drawAtPlace(0, 1, "I haven't finished the task, so the only tank is the one we control. It's able to shoot and move.");
}

void Field::drawField()
{
    drawHeader();      //++++++++++
    drawLevel(level_);    //++++++++++
    //drawTime();        //
    drawHealth();      //++++++++++
    drawEnemiesLeft(); //++++++++++
    drawKills();       //++++++++++
    drawDefeats();    //+++++++++
    drawTotalKills();  //++++++++++
    drawHelp();        //
    drawDisclaimer();  //
}


int Field::getLevel()
{
    return this->level_;
}

bool Field::isEmpty(int x, int y, int level)
{
    switch(level_)
    {
    case 0:
    {
        if (strcmp(level0_[y][x], " ")==0)
        {
            return true;
        }
        else
            return false;
    }
    break;
    case 1:
    {
        if (strcmp(level1_[y][x], " ")==0)
        {
            return true;
        }
        else
            return false;
    }
    break;
    case 2:
    {
        if (strcmp(level2_[y][x], " ")==0)
        {
            return true;
        }
        else
            return false;
    }
    break;
    }
}
