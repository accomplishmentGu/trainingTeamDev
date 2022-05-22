

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int _maxi = 0;
int _time = 0;
vector<int> _timeList;
int _dpArray[5009];
int _resArray[5009];

void CparseIn () {
	
	int time = 0;
	int weight = 0;
	
	cin >> _maxi >> _time;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> time;
		
		_timeList.push_back(time);
	}
	
} 

void Core () {
	
	_dpArray[0] = 1;
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = _time; m > _timeList[i - 1] - 1; m--) {
			_dpArray[m] = (_dpArray[m] + _dpArray[m - _timeList[i - 1]]) % 10;
		}
	}
	
	for (int i = 1; i < _maxi + 1; i++) {
		memcpy(_resArray, _dpArray, sizeof(_resArray));
		
		for (int m = _timeList[i - 1]; m < _time + 1; m++) {
            _resArray[m] = (_resArray[m] - _resArray[m - _timeList[i - 1]] + 10) % 10;
    	}
    	
        for (int m = 1; m < _time + 1; m++) {
        	cout << _resArray[m];
		}
		
		cout << '\n';
	}
	
}

void CwriteOut () {
	
	// nothing
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
