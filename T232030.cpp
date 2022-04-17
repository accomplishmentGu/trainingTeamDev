

#include <iostream>
#include <fstream>

using namespace std;

string _myStr = "";
long long _res = 0;

void CparseIn () {
	
	cin >> _myStr;
	
}

void Core () {
	
	long long aNum = 0;
	long long bNum = 0;
	
	for (int i = 0; i < _myStr.length(); i++) {
		if (_myStr[i] == 'a') {
			aNum++;
			continue;
		}
		
		bNum++;
	}
	
	_res = aNum * (aNum + 1) / 2 + bNum * (bNum + 1) / 2;
	
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
