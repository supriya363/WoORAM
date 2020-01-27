#include <iostream>
#include <bits/stdc++.h>
#include "woOram.h"

using namespace std;

void see_access_pattern()
{
    WoOram *w = new WoOram();
    w->write(2,200);
    w->write(1,100);
    w->write(3,300);
    w->write(4,400);
    w->write(2,2200);
    w->write(1,1100);
    w->write(0,10);
    w->write(3,3300);
    w->write(0,1001);
    w->write(2,2200);
    w->display_storage();
    w->display_position_map();
}

void check_reads(vector<int> &arr, WoOram *w)
{
    for(int i=0; i<STORAGE_SIZE * NbyM_FACTOR; i++)
    {
        int array_value = arr[i];
        int wooram_value = w->read(i);
        assert ( array_value == wooram_value);
    }
}

void test()
{
    vector<int> simple_array(STORAGE_SIZE * NbyM_FACTOR);
    WoOram *w = new WoOram();

    //a series of writes in woram
    w->write(2,200);
    w->write(1,100);
    w->write(3,300);
    w->write(4,400);
    w->write(2,2200);
    w->write(1,1100);
    w->write(0,10);
    w->write(3,3300);
    w->write(0,1001);
    w->write(2,2200);

    //same writes on simple array
    simple_array[2] = 200;
    simple_array[1] = 100;
    simple_array[3] = 300;
    simple_array[4] = 400;
    simple_array[2] = 2200;
    simple_array[1] = 1100;
    simple_array[0] = 10;
    simple_array[3] = 3300;
    simple_array[0] = 1001;
    simple_array[2] = 2200;

    //check if reads are same
    check_reads(simple_array, w);

    //more writes in woram
    w->write(6,600);
    w->write(7,2500);
    w->write(3,27900);
    w->write(0,400);
    w->write(6,11100);

    //same writes on simple array
    simple_array[6] = 600;
    simple_array[7] = 2500;
    simple_array[3] = 27900;
    simple_array[0] = 400;
    simple_array[6] = 11100;

    check_reads(simple_array, w);


    w->write(9,500);
    w->write(9,40);
    w->write(8,200);
    w->write(1,131);
    w->write(6,2280);

    simple_array[9] = 500;
    simple_array[9] = 40;
    simple_array[8] = 200;
    simple_array[1] = 131;
    simple_array[6] = 2280;

    check_reads(simple_array, w);


    cout<<"All assertions passed"<<endl;

}

int main()
{
    // see_access_pattern();
    test();
    return 0;
}