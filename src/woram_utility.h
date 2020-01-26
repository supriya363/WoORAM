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