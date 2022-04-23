

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 9;

int _volume = 0;
vector<int> _volumeList;
int _dpArray[MAXN];

void CparseIn () {
	
	int curInt = 0;
	
	cin >> _volume;
	
	for (int i = 0; i < 3; i++) {
		cin >> curInt;
		
		_volumeList.push_back(curInt);
	}
	
} 

void Core () {
	
	memset(_dpArray, 0x80, sizeof(_dpArray));
	
	_dpArray[0] = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int m = _volumeList[i]; m < _volume + 1; m++) {
    		_dpArray[m] = max(_dpArray[m - _volumeList[i]] + 1, _dpArray[m]);
    	}
	}
	
}

void CwriteOut () {
	
	if (_dpArray[_volume] < 0) {
		cout << -1 << '\n';
		return;
	}
	
	cout << _dpArray[_volume] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
