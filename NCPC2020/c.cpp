#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
vector<int> a;

void print_step() {
	cout << "yes\n";
	int s = accumulate(a.begin(), a.end(), 0);
	while (s) {
		int i = max_element(a.begin(), a.end()) - a.begin();
		int j = 0;
		while (j == i  || a[j] == 0)
			j += 1;

		a[i] -= 1;
		a[j] -= 1;
		cout << i + 1 << " " << j + 1 << "\n";
		s -= 2;
	}
}

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int s = accumulate(a.begin(), a.end(), 0);
	bool res = (s % 2 == 0) && (*max_element(a.begin(), a.end()) <= s/2);

	if (res)
		print_step();
	else
		cout << "no\n";
}
