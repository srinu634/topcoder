#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#define MAX 10000
using namespace std;

class OkonomiyakiShop {
    public:
    int count(vector<int> osize, int K) {
        int i,j;
        int ans = 0;

       sort(osize.begin(),osize.end());

       for(i=0;i<osize.size();i++)
            for(j=i+1;j<osize.size();j++)
                if( abs(osize[j] - osize[i]) <= K )
                    ans++;

        return ans;
    }
};

