

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int mod = 1e9 + 7;

struct Code {
	
	string _oriStr;
	string _newStr;
	
};

int _maxi = 0;
vector<Code> _myList;
int _resArray[9];
int _myArray[9];

void CparseIn () {
	
	int curInt = 0;
	Code solo;
	
	cin >> _maxi;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> curInt >> curInt;
		cin >> solo._oriStr >> solo._newStr;
		
		_myList.push_back(solo);
	}
	
}

void GenRes (string theStr, int index, string nextStr, string toStr, int cur) {
	
	static int cc = 0;
	string curStr1 = "";
	string curStr2 = "";
	
	if (index == theStr.length()) {
		if (nextStr == toStr) {
			cc++;
			cc %= mod;
		}
		
		return;
	}
	
	curStr1 = nextStr, curStr2 = nextStr;

	if (theStr[index] == '-') {
		curStr1.erase(curStr1.begin());
		curStr2.erase(curStr2.end() - 1);
		GenRes(theStr, index + 1, curStr1, toStr, cur);
		GenRes(theStr, index + 1, curStr2, toStr, cur);
	}
	
	if (theStr[index] != '-') {
		curStr1 += theStr[index];
		GenRes(theStr, index + 1, curStr1, toStr, cur);
	}
	
	_resArray[cur] = cc - _myArray[cur - 1];
	_myArray[cur] = _resArray[cur] + _myArray[cur - 1];
	
}

void Core () {
	
	for (int i = 0; i < _myList.size(); i++) {
		GenRes(_myList[i]._oriStr, 0, "", _myList[i]._newStr, i + 1);
	}
	
}

void CwriteOut () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		cout << _resArray[i] << '\n';
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
