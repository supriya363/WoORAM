#include "woOram.h"

using namespace std;

WoOramDataStore::WoOramDataStore()
{
    for(int i=0; i<N; i++)
        position_map[i] = i;
}

void WoOramDataStore::display_main_area()
{
    for(int i=0; i<N; i++)
        cout<<"Address : "<<i<<", Data : "<<physical_storage[i]<<endl;
}

void WoOramDataStore::display_holding_area()
{
    for(int i=N; i<N+M; i++)
        cout<<"Address : "<<i<<", Data : "<<physical_storage[i]<<endl;
}

int WoOramDataStore::get_pos(int logical_address)
{
    int physical_address = position_map[logical_address];
    return physical_address;
}

void WoOramDataStore::set_pos(int logical_address, int physical_address)
{
    position_map[logical_address] = physical_address;
}