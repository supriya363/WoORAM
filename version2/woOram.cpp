#include <iostream>
#include "woOram.h"

using namespace std;

void WoOram :: write(int address, int new_data)
{
    assert( address >= 0 && address <= wooram->N);
    int i = write_access_counter;
    int N = wooram->N;
    int M = wooram->M;
        /*
            1. Write to holding Area
            2. Update Position Map
            3. Refresh N/M Main Area Blocks
            4. Increment Counter
        */
    // cout<<"Write to Physical Block -> "<<i<<endl;
    int new_address = N + (i%M);
    wooram->physical_storage[new_address] = encrypt(new_data);  //Step 1
    wooram->set_pos(address, new_address);                      //Step 2

    //Step 3
    int start = i*(N/M)%N;
    int end = (i+1)*(N/M)%N;
    if (end == 0) end = N;
    for(int addr=start; addr<end; addr++)
    {
        // cout<<"Write(Refresh) to Physical Block -> "<<addr<<endl;
        int new_address = wooram->get_pos(addr);
        int latest_data = decrypt(wooram->physical_storage[new_address]);
        wooram->physical_storage[addr] = encrypt(latest_data);
        wooram->set_pos(addr, addr);         
    }

    write_access_counter = (write_access_counter + 1)%N; //Step 4
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