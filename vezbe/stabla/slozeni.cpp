#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int velicina(int n) {
    //ceil - gornje zaokruzivanje
    return pow(2, ceil(log2(n)));
}

vector<int> napraviStablo(vector<int>& niz, int n) {
    vector<int> stablo(2*n);
    copy(niz.begin(), niz.end(), stablo.begin() + n);

    //formiramo "cvorove" stabla
    for(int k = n-1; k > 0; k--) {
        stablo[k] = stablo[2*k] +stablo[2*k+1];
    }
    return stablo;
}

void postavi(int i, int x, vector<int>& stablo, int n) {
    //menjamo vrednost clana niza
    stablo[i += n] = x;
    for(i /= 2; i > 0; i /= 2) {
        stablo[i] = stablo[2*i] + stablo[2*i+1];
    }
}

int upit(int l, int d, vector<int>& stablo, int n) {
    int zbir = 0;
    for(l += n, d += n; l <= d; l /= 2, d /= 2) {
        if(l % 2 == 1) zbir += stablo[l++];
        if(d % 2 == 0) zbir += stablo[d--];
    }
    return zbir;
}

int slozen(int n) {
    if(n == 1)
        return 1;
    for(int i=2; i*i<n; i++) {
        if(n % i == 0)
            return 1;
    }
    return 0;
}

int main() {
    int n;
	cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
        v[i] = slozen(v[i]);   
    }


	int sn = velicina(n);
	vector<int> stablo = napraviStablo(v, sn);

	while(true) {
		string komanda;
		cin >> komanda;

		if(komanda == "postavi") {
			int i, x;
			cin >> i >> x;

			postavi(i, slozen(x), stablo, sn);
		}
		else {
			int l, d;
			cin >> l >> d;
			cout << upit(l, d, stablo, sn) << '\n';
		}
	}

	return 0;
}