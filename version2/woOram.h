#ifndef WOORAM_H
#define WOORAM_H
#define STORAGE_SIZE 15
#define NbyM_FACTOR 2/3
#include <bits/stdc++.h>

using namespace std;

class WoOramDataStore
{
    public:
    WoOramDataStore();
    const int N = STORAGE_SIZE * NbyM_FACTOR;
    const int M = STORAGE_SIZE - N;
    vector<int> physical_storage = vector<int>(STORAGE_SIZE);
    vector<int> position_map = vector<int>(N);
    void display_main_area();
    void display_holding_area();
    int get_pos(int);
    void set_pos(int,int);
};


class WoOram
{
    private: 
    int write_access_counter = 0;
    WoOramDataStore *wooram = new WoOramDataStore;
    int encrypt(int);
    int decrypt(int);

    public:
    void write(int, int);
    int read(int);
    void display_storage();
    void display_position_map();
};

#endif