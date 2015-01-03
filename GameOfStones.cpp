#include<vector>
using namespace std;
class  GameOfStones {
public:
int count(vector <int> stones) {
	int i;
	int mean = 0;
	
	vector<int>::iterator it = stones.begin() ;
	
	for( ; it!= stones.end();it++)
		mean += *it;
	
	if ( mean % stones.size() != 0 )
		return -1; //Can't split the stones equally
	vector<int> stones1(stones); 
	
	mean /= stones.size();
	
	for( i = 0 ; i < stones1.size() ; i++ )
		stones1[i] = stones1[i] - mean;
		
	int ans = 0;
	
	for(i=0;i<stones1.size();i++)
		if( stones1[i]%2 != 0) 
			return -1;
		else if(stones1[i] >= 0 )
			ans+=stones1[i];
	return ans/2;

}//count
};//class