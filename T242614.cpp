

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _maxi = 0;
int _time = 0;
vector<int> _timeList;
vector<int> _weightList;
long long _dpMap[5009][9]; 

void CparseIn () {
	
	int time = 0;
	int weight = 0;
	
	cin >> _maxi >> _time;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> time >> weight;
		
		_timeList.push_back(time);
		_weightList.push_back(weight);
	}
	
}

void Core () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = _time; m > -1; m--) {
			_dpMap[m][1] = max(_dpMap[m][1], (long long) _dpMap[m][0] + _weightList[i - 1]);
			
			if (m > _timeList[i - 1] - 1) {
				_dpMap[m][0] = max(_dpMap[m][0], (long long) _dpMap[m - _timeList[i - 1]][0] + _weightList[i - 1]);
				_dpMap[m][1] = max(_dpMap[m][1], (long long) _dpMap[m - _timeList[i - 1]][1] + _weightList[i - 1]);
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpMap[_time][1] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
