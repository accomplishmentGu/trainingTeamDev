

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _maxi = 0;
vector<int> _volumeList;
bool _dpArray[509];
int _res = 0;

void CparseIn () {
	
	int curInt = 0;
	int max = 0;
	
	cin >> _maxi;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> curInt;
		
		if (curInt > max) {
			max = curInt;
			_volumeList.push_back(1);
			
			continue;
		}
		
		_volumeList[_volumeList.size() - 1]++;
	}
	
}

void Core () {
	
	_dpArray[0] = true;
	
	for (int i = 0; i < _volumeList.size(); i++) {
		for (int m = _maxi / 2; m > _volumeList[i] - 1; m--) {
			_dpArray[m] = _dpArray[m] || _dpArray[m - _volumeList[i]];
		}
	}
	
	for (int m = _maxi / 2; m > -1; m--) {
		if (_dpArray[m]) {
			_res = abs(m - (_maxi - m));
			return;
		}
	}
	
}

void CwriteOut () {
	
	cout << _res << '\n';
	
}

int main () {
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;;
	
} 
