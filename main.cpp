// Written by Hasan Albinsaid <hasanalbinsaid@hotmail.com>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<vector>
#include <fungsi.h>

using namespace std;
ECC hasan;

int GF=5;
vector <int> primitive_poly {1,1,1,0,1}; //x^5 = 1 + x + x^2 + x^4

int main()
{
    cout << "     Poly Table    "<<endl;

    cout <<"GF(2^"<<GF<< ") |<LSB- -MSB>" << endl;
    vector<vector<int>> poly_table = hasan.primitive_poly_table_bin(GF,primitive_poly); //Generate representation GF(2^x)
    for (int i=0;i<pow(2,GF);i++){
        if (i<=1) cout << i << "\t| ";
        if (i>1) cout << "a^" << i-1 << "\t| ";
        for (int j=0;j<GF;j++) cout << poly_table[i][j] << " ";
        cout << endl;
    }
    return 0;
}
