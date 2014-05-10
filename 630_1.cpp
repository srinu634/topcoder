#include<cstdio>
#include<set>
#include<algorithm>
#include<map>
#include<iostream>
#include<vector>
#define  pb push_back
using namespace std;

pair < int,int > p;


class CandidatesSelectionEasy{

    vector <int> sort(vector <string> score, int x){
        int i,j;
        vector<int>res;
        vector< pair< int, int > > p;


        for(  i = 0 ; i < score.size(); i++ ){
            char ch;
            ch = score[i][j];
            p.pb( make_pair( (ch-'0') ,i) );
            }
        std::sort(p.begin(),p.end()); //sorts according to b-a 1st and then c-a

        for(i = 0; i  < score.size();i++)
            res.pb( p[i].second );

        return res;
    }

};
