#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;
using ll = long long;

int x, kol = 0, ch=0;
vector<int>an;
string ans = "";

void dt(int i, ll s, ll p) {
	if (p > s + 9 * (x - i)) return;
	if (i == x) {
		if (s == p) {
			kol++;
			if (!ch) {
				for (int l = 0; l < an.size(); ++l) ans+=to_string(an[l]);
				ch = 1;
			}
		}	
		return;
	}
	for (int j = 1; j < 10; ++j) {
		an.push_back(j);
		dt(i+1, s + j, p * j);
		an.pop_back();
	}
}

int main() {
	cin >> x;
	if (x == 1) {
		ch = 1;
		ans="0";
	}
	 dt(0, 0, 1);
	if (x == 1) kol++;
	cout << kol<<" "<<ans;
}
