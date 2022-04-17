

#include <iostream>
#include <fstream>

namespace Quick {
	 
	inline long long Read () {
	
		long long theNum = 0;
		char theChar = 0;
		int negative = 0; 
		
		theChar = getchar();
		negative = 1;
		
		while (theChar < '0' || theChar > '9') {
			// if the input must be nonnegative, we can not write
			if (theChar == '-') {
				negative = -1;
			}
			
			theChar = getchar();
		}
		
		theNum = theChar ^ 48; // theChar - 48
		
		while ((theChar = getchar()) > '0' - 1 && theChar < '9' + 1) {
			theNum = (theNum << 3) + (theNum << 1) + (theChar ^ 48);
		}
		
		return theNum * negative;
		
	}
	
	template <typename type>
	inline void RecursionWrite (type theNum) {
		
		if (theNum) {
			RecursionWrite(theNum / 10);
			putchar(theNum % 10 + 48);
		}
		
	}
	
	template <typename type1, typename type2>
	inline void Write (type1 theNum, type2 endChar) {
		
		if (!theNum) {
			putchar('0');
		}
		
		if (theNum < 0) {
			putchar('-');
			theNum *= -1;
		}
		
		if (theNum) {
			RecursionWrite(theNum / 10);
			putchar(theNum % 10 + 48);
		}
		
		putchar(endChar);
		
	}
	
}

using namespace std;
using namespace Quick;

const int MAXN = 5e6 + 9;

int _maxi = 0;
long long _mod = 0;
long long _constant = 0;
long long _myArray[MAXN];
long long _mulArray[MAXN]; // _mulArray[i] = _myArray[1] * _myArray[2] * ... * _myArray[i]
long long _invArray[MAXN]; // inverse of _mulArray[i]
long long _res = 0;

long long QuickPow (long long base, long long index, long long mod) {
	
	long long res = 1;
	
	while (index) {
		if (index & 1) {
			res = (res * base) % mod;
		}
		 
		base = (base * base) % mod;
		index >>= 1;
	}
	
	return res;
	
}

void CparseIn () {
	
	_maxi = Read(), _mod = Read(), _constant = Read();
	
	for (int i = 1; i < _maxi + 1; i++) {
		_myArray[i] = Read();
	}
	
}

void Core () {
	
	long long cur = 1;
	
	_mulArray[0] = 1;
	
	for (int i = 1; i < _maxi + 1; i++) {
		_mulArray[i] = _mulArray[i - 1] * _myArray[i] % _mod;
	}
	
	_invArray[_maxi] = QuickPow(_mulArray[_maxi], _mod - 2, _mod);
	
	for (int i = _maxi - 1; i > -1; i--) {
		_invArray[i] = _invArray[i + 1] * _myArray[i + 1] % _mod; 
	}
	
	for (int i = 1; i < _maxi + 1; i++) {
		cur = cur * _constant % _mod;
		_res = (_res + cur * _invArray[i] % _mod * _mulArray[i - 1]) % _mod;
	}
	
}

void CwriteOut () {
	
	Write(_res, '\n'); 
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 
