

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 1e4 + 9;
const int MAXM = 1e7 + 9;

int _time = 0;
int _maxi = 0;
vector<int> _timeList;
vector<int> _weightList;
long long _dpArray[MAXM];

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
		for (int m = _timeList[i]; m < _time + 1; m++) {
    		_dpArray[m] = max(_dpArray[m - _timeList[i]] + _weightList[i], _dpArray[m]);
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
