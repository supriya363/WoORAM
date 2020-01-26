#include "woOram.h"

using namespace std;

void WoOramDataStore::display_main_area()
{
    for(int i=0; i<N; i++)
        cout<<"Address : "<<i<<", Data : "<<physical_storage[i]<<endl;
}

void WoOramDataStore::display_holding_area()
{
    for(int i=N; i<2*N; i++)
        cout<<"Address : "<<i<<", Data : "<<physical_storage[i]<<endl;
}

int WoOramDataStore::get_pos(int logical_address)
{
    try
    {
        int physical_address = position_map.at(logical_address);
        return physical_address;
    }
    catch(const std::exception& e)
    {
        cout<<"Logical Address "<<logical_address<<" does not have any data\n"<<endl;
        return logical_address;
    }
    
    
}

void WoOramDataStore::set_pos(int logical_address, int physical_address)
{
    position_map[logical_address] = physical_address;
}