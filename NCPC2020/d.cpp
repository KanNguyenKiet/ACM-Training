#include <bits/stdc++.h>

#define ll long long

using namespace std;


const int maxN = 2e5 + 100;

int n;
vector<int> child[maxN];
ll h[maxN], l[maxN];

ll need[maxN];

void DFS(int u = 0, ll pn = 0) {
	need[u] = l[u] - h[u];
	pn = max(0ll, pn - l[u]);
	need[u] += pn;

	for (int c: child[u])
		DFS(c, need[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> l[0];
	h[0] = 0;
	n += 1;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p >> l[i] >> h[i];
		child[p].push_back(i);
	}

	DFS();

	cout << *min_element(need, need + n) << "\n";
}
