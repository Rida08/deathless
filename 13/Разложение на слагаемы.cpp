#include <iostream>
#include <vector>
#include <string>



using namespace std;
using ll = long long;

int n;
int sum;
vector<string>ans;
vector<int>an1;

void dt(int i, int s) {
	if (s == n) {
		//ans.push_back(an);
		//for (int i = 0; i < an1.size(); ++i) {
		//	//if (i == an1.size() - 1) cout << an1[i];
		//	/*else*/ cout << to_string(an1[i]) << " + ";
		//}
		return;
	}
	if (s > n) return;
	an1.push_back(i);
	dt(i, s + i);
	dt(i+1, s + i);
	an1.pop_back();
	dt(i+1, s);
}

int main() {
	cin >> n;
	dt(0, 0);
	//for (string i : ans) {
	//	cout << i + "\n";
	//}
}
