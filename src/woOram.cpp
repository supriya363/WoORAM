#include <iostream>
#include "woOram.h"

using namespace std;

void WoOram :: write(int address, int new_data)
{
    wooram->main_area[address] = new_data;

}

int WoOram :: read(int address)
{
    int data = wooram->main_area[address];
    return data;
}