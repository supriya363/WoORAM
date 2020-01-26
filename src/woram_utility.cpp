#include "woOram.h"

using namespace std;

void WoOramDataStore::display_main_area()
{
    int n = main_area.size();
    for(int i=0; i<n; i++)
        cout<<"Address : "<<i<<", Data : "<<main_area[i]<<endl;
}

void WoOramDataStore::display_holding_area()
{
    int n = holding_area.size();
    for(int i=0; i<n; i++)
        cout<<"Address : "<<i<<", Data : "<<main_area[i]<<endl;
}

int WoOramDataStore::get_pos(int logical_address)
{
    int physical_address = position_map.at(logical_address);
    return physical_address;
}