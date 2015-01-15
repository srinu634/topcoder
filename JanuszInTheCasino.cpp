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
#include<map>
#define f first
#define s second
#define mp make_pair
typedef double d;
typedef long long ll;
using namespace std;


class JanuszInTheCasino {
    public:
    map< pair<ll,int> , d> check;
    double findProbability(long long n, int m, int k) {
        pair<ll,int> p;
        if(n==0)
            return 0;
        if(k==0)
            return 1;

       p = {n,k};

        if( check.find(p) == check.end() )
            check[p] = (n%m)*findProbability(n-n/m-1,m,k-1)/m + (m-n%m)*findProbability(n-n/m,m,k-1)/m;

        return check[p];
    }
};

