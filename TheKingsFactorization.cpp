#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAX 1000000
class TheKingsFactorization {
public:
vector<long long> getVector(long long N,  vector<long long> primes) {
	long long i,j;
	long long M,M1=1;
	vector<long long>result;
	M=N;
	
	for(i=2;i<MAX;i++)
		while( M%i==0)
			result.push_back(i), M/=i,M1*=i;
	
	
	if(M==1)
		return result; //Done with all the factors
		
	if( primes[primes.size()-1] < MAX ) { //There can be only one more factor
		result.push_back(M);
		return result; 
	}
	else
	{
	
		M/= primes[primes.size()-1];
		if(M==1) { 
			result.push_back(primes[primes.size()-1]);
			return result;
		}
		if( M < primes[primes.size()-1] ){
			result.push_back(M),result.push_back(primes[primes.size()-1]);
			return result;
		}
		else {
			result.push_back(primes[primes.size()-1]),result.push_back(M);
			return result;
		}
	}
		
	return result;
  


	

}//getVector

}; //class