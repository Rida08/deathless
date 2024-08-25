#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using ll = long long;
using namespace std;

int n, k, an=0;

const int N = 10;
int p[N];
bool used[N];

void bt(int fz) {
	if (p[n] != 0) {
		int s = 0;
		for (int i = 1; i <= n; ++i) {
			if (p[i]==i) {
				s++;
			}
		}
		if (s == k) {
			an++;
		}
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		p[fz] = i;
		used[i] = 1;
		bt(fz+1);
		used[i] = 0;
		p[fz] = 0;
	}
}

int main() {
	cin >> n >> k;
	bt(1);
	cout << an;
}
