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
#define  mp make_pair
#define pb push_back

using namespace std;

class ConnectingCars {
    public:
    long long calc(vector< pair<double,double> > &p,int s,int e) {
        int mid = (e+s)/2;
        cout<<"start , end: "<<" "<<s<<" "<<e<<endl;
        if(s==e)
            return 0;
        if( (e - s + 1)%2 == 1 ){
                    return (mid-1-s+1)*(p[mid].first - p[mid-1].second) + (p[mid+1].first - p[mid].second)*(e - (mid + 1) + 1) + calc(p,s,mid-1) + calc(p,mid+1,e);

        }
        else
        {
            int leftmid = (e+s)/2;
            int rightmid = leftmid + 1;
            int mean = (p[rightmid].first - p[leftmid].second );

            return mean*(e-s+1)/2 + calc(p,s,leftmid) + calc(p,rightmid,e);

        }
}


    long long minimizeCost(vector<int> positions, vector<int> lengths) {
        int i,j;
        vector< pair<double,double> > p;

        for( i = 0; i< positions.size();i++ )
            p.pb( mp(positions[i],positions[i]+lengths[i]) );

        sort(p.begin(),p.end());

        //for(i=0;i<p.size();i++)
          //  cout<<p[i].first<<" "<<p[i].second<<endl;
        return calc(p,0,p.size()-1);
    }
};

