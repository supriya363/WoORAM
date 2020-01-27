#include <iostream>
#include <bits/stdc++.h>
#include "woOram.h"

using namespace std;

void see_access_pattern()
{
    WoOram *w = new WoOram();
    w->write(2,200);
    w->write(1,100);
    w->write(3,300);
    w->write(4,400);
    w->write(2,2200);
    w->write(1,1100);
    w->write(0,10);
    w->write(3,3300);
    w->write(0,1001);
    w->write(2,2200);
    w->display_storage();
    w->display_position_map();
}

int main()
{
    see_access_pattern();
    return 0;
}