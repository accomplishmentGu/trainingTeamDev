

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;

int _time = 0;
int _maxi = 0;
vector<int> _timeList;
int _dpArray[90009];

void CparseIn () {
	
	int time = 0;

	cin >> _maxi;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> time;
		
		_time += time;
		_timeList.push_back(time);
	}
	
	_time /= 2;
	
} 

void Core () {
	
	_dpArray[0] = 1;
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = _time; m > _timeList[i - 1] - 1; m--) {
			_dpArray[m] = (_dpArray[m] + _dpArray[m - _timeList[i - 1]]) % mod;
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpArray[_time] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
