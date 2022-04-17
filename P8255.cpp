

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Code {
	
	long long _numX;
	long long _numZ;
	
};

using namespace std;

vector<Code> _myList;
vector<long long> _resList;

void CparseIn () {
	
	int maxi = 0;
	Code solo;

	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> solo._numX >> solo._numZ;
		
		_myList.push_back(solo);
	}
	
}

long long GenNumY (long long numX, long long numZ) {
	
	/*
	n = gcd(numX, numY);
	x = pn, y = qn, z = pq*n^3;
	p⊥q, p^2⊥q;
	n^2 = gcd(p^2*n^2, q*n^2) = gcd(x^2, z/x)
	n = √gcd(x^2, z/x)
	y = qn = pq*n^3/pn/n = z/x/n = z/x/ √gcd(x^2, z/x);
	 */
	
	long long gcdNum = sqrt(__gcd(numX * numX, numZ / numX));
	long long res = 0;
	
	res = numZ / numX / gcdNum;
	
	if (numX * res * __gcd(numX, res) != numZ) {
		return -1;
	} 
	
	return res;
	
}

void Core () {
	
	for (int i = 0; i < _myList.size(); i++) {
		long long curInt = GenNumY(_myList[i]._numX, _myList[i]._numZ);
		
		_resList.push_back(curInt);
	}	
	
}

void CwriteOut () {
	
	for (int i = 0; i < _resList.size(); i++) {
		cout << _resList[i] << '\n';
	}
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
