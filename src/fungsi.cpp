// Written by Hasan Albinsaid <hasanalbinsaid@hotmail.com>
#include "fungsi.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> ECC::mul_poly_bin(vector<int> &a, vector<int> &b){
    vector<int> result;
    result.clear();
    for (int i=0;i<(int)a.size()+(int)b.size()-1;i++) result.push_back(0);
    for (int i=0;i<(int)a.size();i++){
        rotate(result.begin(),result.begin()+result.size()-1,result.end());
        for (int j=0;j<(int)b.size();j++){
            result[j]=(result[j]+b[j]*a[(int)a.size()-i-1])%2;
        }
    }
    while(result[(int)result.size()-1]==0)result.pop_back();
    return result;
}

vector<vector<int>> ECC::primitive_poly_table_bin(int GF,vector<int> &primitive_poly){
    vector<vector<int>> matrik;
    vector<int> vect;
    matrik.clear();
    for(int i=0;i<GF;i++) vect.push_back(0); // add 0,0,..,0
    matrik.push_back(vect);
    vect.clear();    vect.push_back(1);    for(int i=1;i<GF;i++) vect.push_back(0); // add 1,0,..,0
    matrik.push_back(vect);
    for (int i=2;i<(int)pow(2,GF);i++){
        vect.clear();
        if (matrik[i-1][GF-1]==1){
            for (int j=0;j<GF;j++){
                if (j==0) vect.push_back((primitive_poly[j]+0)%2);
                if (j>0) vect.push_back((primitive_poly[j]+matrik[i-1][j-1])%2);
            }
        }
        else{
            for (int j=0;j<GF;j++){
                if (j==0) vect.push_back(0);
                if (j>0) vect.push_back(matrik[i-1][j-1]);
            }
        }
        matrik.push_back(vect);
    }
    return matrik;
}
