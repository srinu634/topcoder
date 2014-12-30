#include<vector>
#include<string>
#include<iostream>
using namespace std;

class TheKingsArmyDiv2 {

public:
int getNumber(vector<string> state){ 
	int i,j,r,c;
	

	int flag = 0;
	
	r = state.size();
	c = state[0].size();
	
	cout<<r<<" "<<c<<endl;
	
	
	for(i=0;i<r;i++)
		for(j=0;j<c-1;j++)
			if( state[i][j] == state[i][j+1] && state[i][j] == 'H' )
				return 0;
			else if( state[i][j] == 'H' || state[i][j+1] =='H')
				flag = 1;
	
	for(i=0;i<c;i++)
		for(j=0;j<r-1;j++)
				if( state[j][i] == state[j+1][i] && state[j][i] == 'H' )
				return 0;
			else if( state[j][i] == 'H' || state[j+1][i] =='H')
				flag = 1;
	
	if(flag==1)
		return 1;
	return 2;
	
	

}//getNumber



}; //class