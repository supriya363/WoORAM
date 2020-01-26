#include <iostream>
#include <bits/stdc++.h>
#include "woOram.h"

using namespace std;

int main()
{
    WoOram *w = new WoOram();
    w->write(2,200);
    w->write(1,100);
    w->write(3,300);
    w->write(4,400);
    w->display_storage();
    w->display_position_map();
    w->write(2,2200);
    w->write(1,1100);
    w->display_storage();
    w->display_position_map();
    
    // cout<<w->read(0)<<" "<<w->read(1)<<" "<<w->read(2)<<" "<<w->read(3)<<" "<<w->read(4);
    return 0;
}