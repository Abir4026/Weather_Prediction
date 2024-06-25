#include <iostream>
#include <vector>

#define sizeof_L 5
#define sizeof_F 8
#define sizeof_G 8

enum calculation_type{L, F, G};

using namespace std;

void calculate_accesses(int r, int c, vector<vector<int>> &arr, calculation_type type);
void display_accesses(int r, int c, vector<vector<int>> &arr, calculation_type type);

int main() {

    vector<vector<int>> access_indices_L;
    vector<vector<int>> access_indices_F;
    vector<vector<int>> access_indices_G;
    
    calculate_accesses(2, 2, access_indices_L, L);
    display_accesses(2, 2, access_indices_L, L);
    calculate_accesses(2, 2, access_indices_F, F);
    display_accesses(2, 2, access_indices_F, F);
    calculate_accesses(2, 2, access_indices_G, G);
    display_accesses(2, 2, access_indices_G, G);

    return 0;
}

void calculate_accesses(int r, int c, vector<vector<int>> &arr, calculation_type type)
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

void display_accesses(int r, int c, vector<vector<int>> &arr, calculation_type type)
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