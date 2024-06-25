#ifndef LFG_HEADER_H
#define LFG_HEADER_H

#include <vector>
using namespace std;

enum computation_type{L, F, G};

void calculate_accesses(int, int, vector<vector<int>> &, computation_type);
void display_accesses(int, int, vector<vector<int>> &, computation_type);

#endif