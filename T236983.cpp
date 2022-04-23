

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long _volume = 0;
vector<long long> _volumeList;
long long _res = 0;

void CparseIn () {
	
	int maxi = 0;
	long long curInt = 0;
	
	cin >> maxi >> _volume;
	
	for (int i = 0; i < maxi; i++) {
		cin >> curInt;
		
		_volumeList.push_back(curInt);
	}
	
} 

void Core () {
	
	for (int i = _volumeList.size() - 1; i > -1; i--) {
		if (_volume - _volumeList[i] > -1) {
			_res += _volumeList[i];
			_volume -= _volumeList[i];
		}	
	} 
	
}

void CwriteOut () {
	
	cout << _res << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
