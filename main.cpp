#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Field.h"
#include <thread>
#include "AllyTank.h"
#include "AllyBullet.h"

using namespace std;

int main()
{
    CursorController * cursorController = new CursorController();
    cursorController->hideCursor();
    srand(time(NULL));
    int level = rand() % 3;
    int enemiesCount = rand()%4 +1;
    Field * field1 = new Field(level, enemiesCount, 0, 0);
    AllyTank * allyTank1 = new AllyTank(field1);
    std::thread t1([field1] {field1->drawTime();});
    std::thread t2([allyTank1] {allyTank1->checkKeyPress();});
    t2.join();
    t1.join();
    delete allyTank1;
    delete field1;
    return 0;
}
