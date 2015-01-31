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
#define ALICE true
#define BOB FALSE

using namespace std;

class OrderedNim {
    public:
    string winner(vector<int> layout) {
        string alice="Alice";
        string bob="Bob";
        int i,j;
        bool winner; //true:ALice , false:bob

        winner=ALICE;
        i=0;

      while(i<layout.size() ){

            if(layout[i]==0){
                i++;
            continue;
            }
            if(i!=layout.size()-1)
                layout[i] = layout[i]>1?1:0;
            else{
                    layout[i]=0; //Take all from the last heap
                    break;
            }

        winner^=true;

      }

        if(winner==ALICE)
            return alice;
        else
            return bob;

    }
};