#include <iostream>
#include <vector>
#include "lfg_header.h"

void calculate_accesses(int r, int c, vector<vector<int>> &arr, computation_type type)
{
    if(type == L)
    {
        arr.push_back({r, c});
        arr.push_back({r + 1, c});
        arr.push_back({r - 1, c});
        arr.push_back({r, c + 1});
        arr.push_back({r, c - 1});
    }
    else if(type == F)
    {
        arr.push_back({r + 2, c});
        arr.push_back({r + 1, c + 1});
        arr.push_back({r + 1, c});
        arr.push_back({r + 1, c - 1});
        arr.push_back({r, c + 1});
        arr.push_back({r, c});
        arr.push_back({r, c - 1});
        arr.push_back({r -1, c});
    }
    else if(type == G)
    {
        arr.push_back({r + 1, c + 1});
        arr.push_back({r + 1, c});
        arr.push_back({r, c + 2});
        arr.push_back({r, c + 1});
        arr.push_back({r, c});
        arr.push_back({r, c - 1});
        arr.push_back({r - 1, c + 1});
        arr.push_back({r - 1, c});
    }

    return;
}

void display_accesses(int r, int c, vector<vector<int>> &arr, computation_type type)
{
    int arr_size = arr.size() - 1;

    cout << "grid points accessed to calculate ";

    if(type == L)
    {
        cout << "L(" << r << ", " << c << ") : [";
    }
    else if(type == F)
    {
        cout << "F(" << r << ", " << c << ") : [";
    }
    else if(type == G)
    {
        cout << "G(" << r << ", " << c << ") : [";
    }

    for(int i = 0; i < arr_size; i += 1)
    {
        cout << "(" << arr[i][0] << ", " << arr[i][1] << "), "; 
    }

    cout << "(" << arr[arr_size][0] << ", " << arr[arr_size][1] << ")]" << endl; 
    cout << endl;

    return;
}