

#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 1e4 + 9;
const int mod = 1e9 + 7;

bool _primeArray[MAXN];
long long _dpArray[MAXN];

void CparseIn () {
	
	// nothing
	
}

void Core () {
	
	_dpArray[0] = 1;
	
	for (int i = 2; i < 10001; i++) {
		if (!_primeArray[i]) {
			for (int m = i; m < 10001; m += i) {
				_primeArray[m] = true;
			}
			
			for (int m = i; m < 10001; m++) {
	    		_dpArray[m] = (_dpArray[m] + _dpArray[m - i]) % mod;
	    	}
    	}
	}
	
}

void CwriteOut () {
	
	for (int i = 1; i < 10001; i++) {
		cout << _dpArray[i] << '\n';
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
