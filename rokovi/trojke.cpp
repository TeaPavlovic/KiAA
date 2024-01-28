#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_M = 1e6;

int euklid(int a, int b, int& x, int& y) {
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    while(r2 > 0) {
        int q = r1 / r2;
        tie(r1, r2) = make_pair(r2, r1 - q*r2);
        tie(x1, x2) = make_pair(x2, x1 - q*x2);
        tie(y1, y2) = make_pair(y2, y1 - q*y2);
    }

    x = x1;
    y = y1;

    return r1;
}

void eratosten(vector<int>& delioci) {
    int n = delioci.size();
    for(int i=1; i <= n; i++) {
            for(int j=i; j<=n; j+=i) {
                delioci[j]++;
            }
    }
}

int main() {
    int q;
    cin >> q;

    vector<int> delioci(MAX_M+1, 0);
    eratosten(delioci);

    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x, y;
        int nzdTmp = euklid(a, b, x, y);
        int nzd = euklid(nzdTmp, c, x, y);
        cout << delioci[nzd] << '\n';
    }
    return 0;
}