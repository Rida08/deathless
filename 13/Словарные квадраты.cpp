#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int n, l;
vector<string> a, f;
string an;

void dt(int i, string w) {
    if (w.size()==4) {
        if (w == a[0] || w == a[1] || w == a[2] || w == a[3] || w == a[4] || w == a[5] || w == a[6] || w == a[7]){
            an = w;
        }
        return;
    }
    if (i == 9 || i == -1 || w.size() == 5) return;
    dt(i+1, w+f[i]);
   // dt(i + 1, w);
  //  dt(i - 1, w);
}

int main() {
    cin >> n;
    string x;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> x;
        a.push_back(x);
        f.push_back(to_string((char)x[0]));
    }
    dt(0, "");
    cout << an;
    
}
