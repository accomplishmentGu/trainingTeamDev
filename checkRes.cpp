

#include <bits/stdc++.h>

using namespace std;

int main () {
    
	int T = 0; //对拍 T 组，可以调。
	cin >> T;
    
	for (int test = 1; test <= T; test++) {
		//下面所有的文件名都可以换成自己的
		system("./gen.exe > testin"); //通过生成器 gen.exe 生成数据输出到 testin
		system("./source.exe < testin > outfile"); //运行需要对拍的程序 source.exe，输入 testin，输出到 outfile
		system("./bruteforce.exe < testin > ansfile"); //运行暴力程序 bruteforces.exe，输入 testin，输出到 ansfile
        
		if (system("cmp outfile ansfile")) {
			cerr << "Wrong Answer on test #" << test << "!!!\n";
			return 0;
		}
	}
    
	cerr << "OK passed " << T << " test(s)\n";
    
	return 0;
    
}
