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

using namespace std;

class SortishDiv2 {
    public:

    int getSortedness(vector<int> & v) {
        int i,j;
        int res = 0;
        for(i=v.size()-1 ; i>=0;i--)
            for(j=0;j<i;j++)
                if( v[j] < v[i] )
                    res++;
        return res;
    }


    int ways(int sortedness, vector<int> seq) {
         int ans ,i;
        vector<int>permute;
        vector<int>tempseq;
        ans = 0;

        for( i= 1;i<=seq.size();i++ )
            if( count( seq.begin(),seq.end(),i) == 0 )
                permute.push_back(i);

        cout<<endl<<"seq array is: "<<endl;
        for(i = 0;i<seq.size();i++)
            cout<<seq[i]<<" ";
            cout<<endl;


        cout<<endl<<"Permute array is: "<<endl;
        for(i = 0;i<permute.size();i++)
            cout<<permute[i]<<" ";
            cout<<endl;

            cout<<"sortedness required is: "<<sortedness<<endl;


        do {
            cout<<"Permuting again"<<endl;
            int k=0;
            tempseq.clear();

            for(i=0;i<seq.size();i++)
                if(seq[i] == 0)
                    tempseq.push_back(permute[k++]);
                else
                    tempseq.push_back(  seq[i] );

			cout<<"sortedness found:: "<<getSortedness(tempseq)<<endl;
            if(sortedness == getSortedness(tempseq) )
                ans++;

        } while( next_permutation(permute.begin(),permute.end()) ) ;


        return ans;
    }
};

