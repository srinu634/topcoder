#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define INF 100000
//Shortest path can be calculated by bfs . Floyd warshall will also work as this is a very small graph

class PathGameDiv2 {
public:
int calc(vector <string> board){ 
	int i,j,k;
	int n = board[0].size();
	vector<int>g[1000];
	
	
	if( n == 1 ) {  
		if( board[1][0] == '.' && board[0][0] == '.' )
			return 1;
		else
			return 0;
	}
	
	for(i=0;i<2*n;i++)
		for(j=0;j<2*n;j++)
			g[i].push_back(INF);
			
			
	
	for(i=2;i<2*n;i++)
			if( i%2==0) {
				if( board[1][i/2] == '#' ) continue;
				
				if( board[1][i/2-1]!= '#' )
					 g[i][i-2] = 1, g[i-2][i] = 1;
				if( board[0][i/2] != '#' ) 
					g[i][i+1] = 1, g[i+1][i] = 1;
			}
			else {
				if( board[0][i/2] == '#' ) continue;
				
				if ( board[1][ (i-1)/2 ] != '#' )
					 g[i][i-1] = 1 , g[i-1][i] = 1;
				if( board[0][i/2-1] != '#') 	
					g[i][i-2] = 1, g[i-2][i] = 1;
			}
			
		for(i=0;i<2*n;i++) {
			for(j=0;j<2*n;j++)
				cout<<g[i][j]<<" ";
			cout<<endl;
			}
			
		for(k=0;k<2*n;k++)
			for(i=0;i<2*n;i++)
				for(j=0;j<2*n;j++)
					if( g[i][k] + g[k][j] < g[i][j] )
						g[i][j] =  g[i][k] + g[k][j];
						
		int ans  = min ( g[0][2*n-1] , g[0][2*n-2] );
		ans = min ( ans, g[1][2*n-1] );
		ans = min ( ans,g[1][2*n-2] );
		cout<<endl<<endl;
		for(i=0;i<2*n;i++) {
			for(j=0;j<2*n;j++)
				cout<<g[i][j]<<" ";
			cout<<endl;
			}
		
		int blackcount = 0;
		
		for(i=0;i<2;i++)
			for(j=0;j<n;j++)
				if( board[i][j] == '#' )
					blackcount++;
		
		cout<<ans<<"  "<<blackcount<<endl;
		
		return 2*n - ans - blackcount - 1;
		
		
			
		
		
		
						
	

}//calc



};//class