#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> pre(n + 1, vector<int>(26, -1));
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (i) {
			for (int j = 0; j < 26; j++) {
				pre[i][j] = pre[i - 1][j];
			}
			pre[i][s[i - 1] - 'a'] = i - 1;
			for (int j = 0; j < 26; j++) {
				if (pre[i][j] > pre[i][s[i] - 'a']) {
					res++;
				}
			}
		}
	}
	cout << res;
}

int main() {
	solve();
}
	
