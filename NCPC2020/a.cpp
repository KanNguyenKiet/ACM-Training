#include <bits/stdc++.h>

#define ll long long

using namespace std;


const int maxN = 200;

int n;
ll a[maxN];

void print_res() {
	for (int i = 0; i <  n; ++i)
		 cout << a[i] << ' ';
	cout << "\n";
}

ll mini(ll a) {
	if (a < 10)
		return 0;

	string s = to_string(a);
	if (s[0] != '1') {
		s[0] = '1';
		return stoll(s);
	}

	int i = 1;
	while (i < s.size() && s[i] == '0')
		i += 1;
	if (i < s.size())
		s[i] = '0';

	return stoll(s);
}

ll maxi(ll a) {
	if (a < 10)
		return 9;

	string s = to_string(a);
	int i = 0;
	while (i < s.size() && s[i] == '9')
		i += 1;

	if (i < s.size())
		s[i] = '9';

	return stoll(s);
}



int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i + 1 < n; ++i)
		if (maxi(a[i]) > a[i + 1]) {
			a[i] = maxi(a[i]);
			print_res();
			return 0;
		}

	for (int i = n - 1; i - 1 >= 0; --i)
		if (mini(a[i]) < a[i - 1]) {
			a[i] = mini(a[i]);
			print_res();
			return 0;
		}

	cout << "impossible\n";
}
