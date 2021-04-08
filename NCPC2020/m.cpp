#include<bits/stdc++.h>

using namespace std;

#define ll long long 

void solve() {
	string s;
	cin >> s;
	int a = 0;
	for (char x : s) {
		a += (x == 'S');
	}
	int b = 0;
	cin >> s;
	for (char x : s) {
		b += (x == 'S');
	}
	for (int i = 1; i <= a * b; i++) {
		cout << "S(";
	}
	cout << 0;
	for (int i = 1; i <= a * b; i++) {
		cout << ")";
	}
	cout << endl;
}

int main() {
	solve();
}

