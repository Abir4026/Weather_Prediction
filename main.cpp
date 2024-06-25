#include <iostream>
#include <vector>
#include "lfg_header.h"

using namespace std;

int main()
{
    vector<vector<int>> arr;
    // vector<vector<vector<int>>> display_matirx;
    // vector<vector<vector<int>>> display_matirx_transpose;

    for(int c = 2; c <= 4; c += 1)
    {
        for(int r = 2; r <= 4; r += 1)
        {
            calculate_accesses(r, c, arr, L);
            display_accesses(r, c, arr, L);
            arr.clear();
        }

        cout << endl;
        cout << endl;

        for(int r = 2; r <= 4; r += 1)
        {
            calculate_accesses(r, c, arr, F);
            display_accesses(r, c, arr, F);
            arr.clear();
        }

        cout << endl;
        cout << endl;

        for(int r = 2; r <= 4; r += 1)
        {
            calculate_accesses(r, c, arr, G);
            display_accesses(r, c, arr, G);
            arr.clear();
        }

        cout << endl;
        cout << endl;
    }

    return 0;
}