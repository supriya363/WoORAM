#include <iostream>
#include "woOram.h"

using namespace std;

void WoOram :: write(int address, int new_data)
{
    assert( address >= 0 && address <= wooram->N);
    int i = write_access_counter;
    int N = wooram->N;
        /*
            1. Write to holding Area
            2. Update Position Map
            3. Increment Counter
            4. Refresh Main Area if required
        */
    int new_address = N + (i%N);
    wooram->physical_storage[new_address] = encrypt(new_data);  //Step 1
    wooram->set_pos(address, new_address);                      //Step 2
    write_access_counter = (write_access_counter + 1)%N;
    cout<<"Done Writing"<<endl;
    if (write_access_counter == 0)
    {
        for(int addr=0; addr<N; addr++)
        {
            int new_address = wooram->get_pos(addr);
            int latest_data = decrypt(wooram->physical_storage[new_address]);
            wooram->physical_storage[addr] = encrypt(latest_data);
            wooram->set_pos(addr, addr);         
        }
    }
}

int WoOram :: read(int logical_address)
{
    assert( logical_address >= 0 && logical_address <= wooram->N);
    int physical_address = wooram->get_pos(logical_address);
    int data = decrypt(wooram->physical_storage[physical_address]);
    return data;
}

int WoOram :: encrypt(int data)
{
    return data;
}

int WoOram :: decrypt(int data)
{
    return data;
}

void WoOram :: display_storage()
{
    wooram->display_main_area();
    wooram->display_holding_area();
}

void WoOram :: display_position_map()
{
    vector<int> m = wooram->position_map;
    for(int i=0; i<wooram->N; i++)
    {
        cout<<"Logical Address : "<<i<<", Physical Address : "<<m[i]<<endl;
    }
}