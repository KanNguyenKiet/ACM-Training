#include <bits/stdc++.h>

using namespace std;

int n;
int a[300];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}


	if (a[n] == n) {
		cout << "good job\n";
		return 0;
	}

	vector<int> res;
	a[0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = a[i - 1] + 1; j < a[i]; ++j)
			res.push_back(j);
	
	for (auto e: res)
		cout << e << "\n";
	cout << "\n";
}
