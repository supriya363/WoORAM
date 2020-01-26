#ifndef WOORAM_H
#define WOORAM_H
#define STORAGE_SIZE 10
#include <bits/stdc++.h>

using namespace std;

class WoOramDataStore
{
    public:
    int N = STORAGE_SIZE/2;
    vector<int> main_area;
    vector<int> holding_area;
    void display_main_area();
    void display_holding_area();
};

#endif