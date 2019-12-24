// Written by Hasan Albinsaid <hasanalbinsaid@hotmail.com>
#ifndef FUNGSI_H
#define FUNGSI_H
#include <vector>
using namespace std;


class ECC{
    public:
        vector<int> mul_poly_bin(vector<int> &a, vector<int> &b);
        vector<vector<int>> primitive_poly_table_bin(int GF,vector<int> &primitive_poly);
};

#endif // FUNGSI_H
