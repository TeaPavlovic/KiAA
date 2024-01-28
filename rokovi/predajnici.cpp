//jul 2021
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int velicina(int n) {
    return pow(2, ceil(log2(n)));
}

vector<int> napraviStablo(int n, vector<int>& niz) {
    vector<int> stablo(2*n);
    copy(niz.begin(), niz.end(), stablo.begin() + n);
    for(int i = n-1; i>0; i--) {
        stablo[i] = max(stablo[2*i], stablo[2*i+1]);
    }
    return stablo;
}

int upit(int l, int d, int n, vector<int>& stablo) {
    int maks = numeric_limits<int>::min();
    for(l+=n, d+=n; l<=d; l/=2, d/= 2) {
        if(l%2 == 1) maks = max(maks, stablo[l++]);
        if(d%2 == 0) maks = max(maks, stablo[d--]);
    }
    return maks;
}

int main() {
    int n;
    cin >> n;

    vector<int> niz(n);
    for(int i=0; i<n; i++) {
        cin >> niz[i];
    }

    int sn = velicina(n);
    vector<int> stablo = napraviStablo(sn, niz);

    vector<int> jacina(n);
    for(int i=0; i<n; i++) {
        if(i-niz[i] < 0)
            jacina[i] = upit(0, i + niz[i], sn, stablo);
        else if(i+niz[i] >= n)
            jacina[i] = upit(i - niz[i], n-1, sn, stablo);
        else jacina[i] = upit(i - niz[i], i + niz[i], sn, stablo);
    }
    for(int d : jacina) {
        cout << d << ' ';
    }
    cout << '\n';
}