

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int _num = 0;
int _res = 0;

void CparseIn () {
	
	cin >> _maxi >> _num;	
	
}

void Dfs (int cur, int num, int last) {
	
	if (num == _num) {
		if (cur == _maxi) {
			_res++;
		}
		
		return;
	} 
	
	for (int i = last; cur + i * (_num - num) < _maxi + 1; i++) {
		Dfs(cur + i, num + 1, i);
	}
	
}

void Core () {
	
	Dfs(0, 0, 1);
	
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
