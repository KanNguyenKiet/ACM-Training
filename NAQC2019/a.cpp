#include <bits/stdc++.h>

using namespace std;

int n;
bool a[300];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n;
	for (int i = 0; i < n; ++i) {
		char v;
		cin >> v;
		a['A' + i] = v == 'T';
	}


	char c;
	stack<bool> st;
	while (cin >> c) {
		if (c == '-') {
			auto v = st.top();
			st.pop();
			st.push(!v);
		}
		else if (c == '*') {
			auto u = st.top();
			st.pop();
			auto v = st.top();
			st.pop();

			st.push(u && v);
		}
		else if (c == '+') {
			auto u = st.top();
			st.pop();
			auto v = st.top();
			st.pop();

			st.push(u || v);
		}
		else {
			st.push(a[c]);
		}
	}

	if (st.top())
		cout << "T\n";
	else 
		cout << "F\n";
}
