//sept 2020
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int velicina(int n) {
    return pow(2, ceil(log2(n)));
}

vector<int> napraviStablo(int n, vector<int>& niz) {
    vector<int> stablo(2*n);
    copy(niz.begin(), niz.end(), stablo.begin() + n);

    for(int i=n-1; i>0; i--) {
        stablo[i] = stablo[2*i] + stablo[2*i+1];
    }
    return stablo;
}

void izmeni(int i, int x, int n, vector<int>& stablo) {
    int izmena = x - stablo[i+=n];
    stablo[i] = x;
    for(i/=2; i>0; i/=2) {
        stablo[i] += izmena;
    }
}

int suma(int l, int d, int n, vector<int>& stablo) {
    int suma = 0;
    for(l+=n, d+=n; l<=d; l/=2, d/=2) {
        if(l % 2 == 1)
            suma += stablo[l++];
        if(d % 2 == 0)
            suma += stablo[d--];
    }
    return suma;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> niz(n);
    for(int i=0; i<n; i++) 
        cin >> niz[i];
    
    int sn = velicina(n);
    vector<int> stablo = napraviStablo(sn, niz);

    while(q--) {
        int a, b;
        cin >> a >> b;
        int tmp = stablo[a+sn]; //obrati paznju na indekse
        izmeni(a, stablo[b+sn], sn, stablo);
        izmeni(b, tmp, sn, stablo);
        cout << suma(a, b, sn, stablo) << ' ';
    }
    cout << '\n';

    return 0;
}