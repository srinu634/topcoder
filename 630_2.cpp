#include<cstdio>
#include<set>
#include<algorithm>
#include<map>
#include<iostream>
#include<vector>
#define  pb push_back
using namespace std;

 class PairGameEasy {

    int dp[3003][3003];

    public:

    string able(int a, int b, int c, int d){
        int i,j;


        string yes = "Able to generate";
        string no = "Not able to generate";

        for(i=1;i<=3000;i++)
            for(j=1;j<=3000;j++)
               dp[i][j] = -1;

       dp[c][d] = solve(a,b,c,d);

        if(  dp[c][d] == 1 )
            return yes;
        else
            return no;

    }



     int solve( int a, int b,int c,int d){

        if( a==c && b==d)
            return dp[a][b] = 1;


         if( a > c || b > d)
            return dp[a][b] = 0;



            if ( dp[a][a+b] == -1)  dp[a][a+b] = solve(a,a+b,c,d)  ;
            if ( dp[a+b][b] == -1)  dp[a+b][b] = solve(a+b,b,c,d)  ;


        dp[a][b] = dp[a][a+b] || dp[a+b][b];

        return dp[a][b];
    }

};

