

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double _time = 0;
int _maxi = 0;
vector<double> _timeList;
vector<int> _weightList;
double _dpArray[10009];
int _res = 0;

void CparseIn () {
	
	double time = 0;
	int weight = 0;
	
	cin >> _maxi >> _time;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> time >> weight;
		
		_timeList.push_back(time);
		_weightList.push_back(weight);
	}
	
} 

void Core () {
	
	_dpArray[0] = 1;
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = 10000; m > _weightList[i - 1] - 1; m--) {
			_dpArray[m] = max(_dpArray[m], _dpArray[m - _weightList[i - 1]] * (1 - _timeList[i - 1]));
		}
	}
	
	for (int i = 10000; i > -1; i--) {
		if (_dpArray[i] >= _time) {
			_res = i;
			return;
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
