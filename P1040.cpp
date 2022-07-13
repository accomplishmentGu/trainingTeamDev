

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int _maxi = 0;
long long _myArray[39];
long long _resMap[39][39];
int _rootMap[39][39];

void CparseIn () {
	
	cin >> _maxi;
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> _myArray[i];
	}
	
}

long long Dfs1 (int left, int right) {
	
	if (left > right) {
		return 1;
	}
	
	if (left == right) {
		return _myArray[left];
	}
	
	if (_resMap[left][right] != -1) {
		return _resMap[left][right];
	}
	
	for (int i = left; i < right + 1; i++) {
		long long cur = Dfs1(left, i - 1) * Dfs1(i + 1, right) + _myArray[i];
		
		if (cur > _resMap[left][right]) {
			_resMap[left][right] = cur;
			_rootMap[left][right] = i;	
		}
	}
	
	return _resMap[left][right];
	
}

void Dfs2 (int left, int right) {
	
	if (left > right) {
		return;
	}
	
	if (left == right) {
		cout << left << ' ';
		
		return;
	}
	
	cout << _rootMap[left][right] << ' ';
	
	Dfs2(left, _rootMap[left][right] - 1);
	Dfs2(_rootMap[left][right] + 1, right);
	
}

void Core () {
	
	memset(_resMap, -1, sizeof(_resMap));
	
}

void CwriteOut () {
	
	cout << Dfs1(1, _maxi) << '\n';
	
	Dfs2(1, _maxi);
	
	cout << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
