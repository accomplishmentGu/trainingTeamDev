

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 9;

int _myArray[MAXN];
long long _resArray[MAXN];
vector<int> _codeList;

void CparseIn () {
	
	int maxi = 0;
	int curInt = 0;
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> curInt;
		_myArray[curInt]++;
	}
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> curInt;
		
		_codeList.push_back(curInt);
	}
	
}

void Core () {
	
	for (long long i = 1; i < 1e6 + 1; i++) {
		if (i * i < 1e6 + 1) {
			_resArray[i * i] += _myArray[i] * (_myArray[i] + 1) / 2;
		}
		
		for (long long m = i + 1; i * m < 1e6 + 1; m++) {
			_resArray[i * m] += _myArray[i] * _myArray[m];
		}
	}
	
	for (int i = 1; i < 1e6 + 1; i++) {
		_resArray[i] += _resArray[i - 1];
	}
	
} 

void CwriteOut () {
	
	for (int i = 0; i < _codeList.size(); i++) {
		cout << _resArray[_codeList[i]] << '\n';
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
