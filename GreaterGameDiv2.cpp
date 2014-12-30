#include<vector>
#include<iostream>
using namespace std;

class GreaterGameDiv2 {
public:
int calc(vector <int> snuke, vector <int> sothe) {
	int ans = 0;
	for(int i=0;i<snuke.size();i++)
		if( snuke[i] > sothe[i])
			ans++;
	
	return ans;
}//method
}; //classs