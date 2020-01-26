#include <iostream>
#include <bits/stdc++.h>
#include "woOram.h"

using namespace std;

int main()
{
    WoOram *w = new WoOram();
    w->write(0,100);
    int val = w->read(2);
    return 0;
}