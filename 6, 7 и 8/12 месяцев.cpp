#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;



int main() {
	ll n, a;
	cin >> n >> a;
	a = a * pow(10, 12 - n);
	bool t = 1;
	while (t) {
		t = 0;
		for (int i = 2; i * i < a; ++i) {
			if (a % i == 0) {
				t = 1;
				i = a;
			}
		}
		a++;
		cout << a;
	}
	cout << a;
}
