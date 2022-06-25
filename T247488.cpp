

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> _myList;
vector<int> _resList1;
vector<int> _resList2; 

void CparseIn () {
	
	int maxi = 0;
	string curStr = "";
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> curStr;
		
		_myList.push_back(curStr);
	}
	
}

void Core () {
	
	for (int i = 0; i < _myList.size(); i++) {
		string solo = _myList[i];
		int index = -1;
		int res1 = 0;
		int res2 = 0;
		
		for (int m = 0; m < solo.length() - 1; m += 2) {
			if (solo[m] != solo[m + 1]) {
				res1++;
				continue; 
			}
			
			if (solo[m] != index) {
				res2++;
				index = solo[m];
			}
		}
		
		res2 = max(res2, 1);
		_resList1.push_back(res1);
		_resList2.push_back(res2);
	}
	
}

void CwriteOut () {
	
	for (int i = 0; i < _resList1.size(); i++) {
		cout << _resList1[i] << ' ' << _resList2[i] << '\n';
	}
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
