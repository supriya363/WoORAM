#include <iostream>
#include <bits/stdc++.h>
#include "woOram.h"

using namespace std;

void test()
{
    WoOram *w = new WoOram();
    w->write(2,200);
    w->write(1,100);
    w->write(3,300);
    w->write(4,400);
    w->write(2,2200);
    w->write(1,1100);
    w->display_storage();
    w->display_position_map();
    w->write(0,10);
    w->write(3,3300);
    w->write(0,1001);
    w->write(2,2200);
    w->display_storage();
    w->display_position_map();
}

int main()
{
    test();
    return 0;
}