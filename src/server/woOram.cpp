#include <iostream>
#include "woOram.h"

using namespace std;

class WoOram
{
    private: 
    int write_access_counter = 0;
    WoOramDataStore *wooram = new WoOramDataStore;

    public:
    void write(int, int);
    int read(int);
};

void WoOram:: write(int address, int new_data)
{
    //Todo

}

int read(int address)
{
    //Todo
    return 0;
}