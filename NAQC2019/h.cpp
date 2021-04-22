#include <bits/stdc++.h>

using namespace std;

const int maxN = 500 + 10;


int n;
int a[maxN][maxN];
int f[maxN][maxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		cin >> a[i][j];

	int res = 0;
	for (int len = 1; len <= n; ++len) {
		for (int i = 0; i < n; ++i) {
			int j = (i + len - 1) % n;
			int u = (i + 1)%n;
			int v = (u + len - 3) % n;
			f[i][j] = a[i][j];
			if (len - 2 > 0)
				f[i][j] += f[u][v];


			for (int m = (i + 1)%n; m != j; m = (m + 1)%n) {
				f[i][j] = max(f[i][j], f[i][m] + f[(m + 1)%n][j]);
			}

			res = max(res, f[i][j]);
		}

	}
	cout << res << "\n";
}
