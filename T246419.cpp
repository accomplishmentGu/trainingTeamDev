

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int _maxi = 0;
long long _left = 0;
long long _right = 0;
vector<long long> _myList;
queue<long long> _dpQueue1;
queue<long long> _dpQueue2;
long long _res = 0;

void CparseIn () {
	
	int ignore = 0;
	long long curInt = 0;
	
	cin >> _maxi >> _left >> _right;
	
	cin >> ignore;
	
	for (int i = 1; i < _maxi; i++) {
		cin >> curInt;
		
		_myList.push_back(curInt);
	}
	
}

void Core () {
	
	_dpQueue2.push(0);
	
	for (int i = 0; i < _myList.size(); i++) {
		while (!_dpQueue2.empty() && _dpQueue2.front() < _myList[i] - _left + 1) {
			_dpQueue1.push(_dpQueue2.front());
			_dpQueue2.pop();
		}
		
		while (!_dpQueue1.empty() && _dpQueue1.front() < _myList[i] - _right) {
			_dpQueue1.pop();
		}
		
		if (!_dpQueue1.empty()) {
			_dpQueue2.push(_myList[i]);
			_res = max(_res, _myList[i]);
		}
	}
	
}

void CwriteOut () {
	
	cout << _res << '\n';
	
}

void Clear () {
	
	_myList.clear();
	
	while (!_dpQueue1.empty()) {
		_dpQueue1.pop();
	}
	
	while (!_dpQueue2.empty()) {
		_dpQueue2.pop();
	}
	
	_res = 0;
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int codeNum = 0;
	
	cin >> codeNum;
	
	while (codeNum--) {
		Clear(); 
		CparseIn();
		Core();
		CwriteOut(); 
	}
	
	return 0;
	
} 
