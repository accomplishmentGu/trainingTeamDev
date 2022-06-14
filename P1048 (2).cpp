

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _time = 0;
int _maxi = 0;
vector<int> _timeList;
vector<int> _weightList;
int _dpMap[109][10009];

void CparseIn () {
	
	int time = 0;
	int weight = 0;
	
	cin >> _time >> _maxi;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> time >> weight;
		
		_timeList.push_back(time);
		_weightList.push_back(weight);
	}
	
}

void Core () {
	
	for (int i = 0; i < _maxi; i++) {
		for (int m = 0; m < _time + 1; m++) {
			_dpMap[i + 1][m + _timeList[i]] = max(_dpMap[i + 1][m + _timeList[i]], _dpMap[i][m] + _weightList[i]);
			_dpMap[i + 1][m] = max(_dpMap[i + 1][m], _dpMap[i][m]);
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpMap[_maxi][_time] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
