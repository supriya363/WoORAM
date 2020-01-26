#ifndef WOORAM_H
#define WOORAM_H
#define STORAGE_SIZE 10
#include <bits/stdc++.h>

using namespace std;

class WoOramDataStore
{
    public:
    int N = STORAGE_SIZE/2;
    vector<int> main_area = vector<int>(N);
    vector<int> holding_area = vector<int>(N);
    map<int, int> position_map;
    void display_main_area();
    void display_holding_area();
    int get_pos(int);
};


class WoOram
{
    private: 
    int write_access_counter = 0;
    WoOramDataStore *wooram = new WoOramDataStore;

    public:
    void write(int, int);
    int read(int);
};

#endif