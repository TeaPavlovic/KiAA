#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int velicina(int n) {
    return pow(2, ceil(log2(n)));
}

vector<int> napraviStablo(vector<int>& niz, int n) {
    vector<int> stablo(2*n);
    copy(begin(niz), end(niz), begin(stablo) + n);

    for(int k = n-1; k>0; k--) {
        stablo[k] = min(stablo[2*k], stablo[2*k+1]);
    }
    return stablo;
}

void postavi(int i, int x, vector<int> stablo, int n) {
    stablo[i += n] = x;

    for(i /= 2; i>0; i /= 2) {
        stablo[i] = min(stablo[i*2], stablo[i*2+1]);
    }
}

int upit(int l, int d, vector<int>& stablo, int n) {
    int najmanji = numeric_limits<int>::max();

    for(l+=n, d+=n; l<=d; l/=2, d/=2) {
         if(l % 2 == 1) 
            najmanji = min(najmanji, stablo[l++]);
        if(d % 2 == 0)
            najmanji = min(najmanji, stablo[d--]);
    }
    return najmanji;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int sn = velicina(n);

    vector<int> stablo = napraviStablo(v, sn);

    while(true) {
        string komanda;
		cin >> komanda;

		if(komanda == "postavi") {
			int i, x;
			cin >> i >> x;

			postavi(i, x, stablo, sn);
		}
		else {
			int l, d;
			cin >> l >> d;
			cout << upit(l, d, stablo, sn) << '\n';
		}
    }
}