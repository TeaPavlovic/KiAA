//jul 2020
//NE RADI
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int velicina(int n) {
    return pow(2, ceil(log2(n)));
}

vector<int> napraviStablo(int n, int x, vector<int>& niz) {
    vector<int> stablo(2*n);
    for(int i=n;i<2*n;i++) {
        if(niz[i-n] > x)
            stablo[i] = niz[i-n];
        else stablo[i] = 0;
    }

    for(int i=n-1; i>0; i--) {
        stablo[i] = stablo[2*i] + stablo[2*i+1];
    }
    return stablo;
}

void postavi(int i, int v, int x, int n, vector<int>& stablo) {
    int tmp = stablo[i+=n];
    if(v > x) 
        stablo[i] = v;
    else stablo[i] = 0;

    for(i /= 2; i > 0; i/= 2)
        stablo[i/2] += stablo[i] - tmp;
        
    
}

int upit(int l, int d, int x, int n, vector<int>& stablo) {
    int suma = 0;
    for(l += n, d+= n; l <= d; l /=2 , d /= 2) {
        if(l%2 == 1 && stablo[l] > x)
             suma += stablo[l++];
        if(d%2 == 0 && stablo[d] > x) 
            suma += stablo[d--];
    }
    return suma;
}

//fje za stablo koje broji elemente:
vector<int> napraviStablo2(int n, int x, vector<int>& niz) {
    vector<int> stablo(2*n);
    for(int i=n;i<2*n;i++) {
        if(niz[i-n] > x)
            stablo[i] = 1;
        else stablo[i] = 0;
    }
    for(int i=n-1; i>0; i--) {
        stablo[i] = stablo[2*i] + stablo[2*i+1];
    }
    return stablo;
}

void postavi2(int i, int v, int n, int x, vector<int>& stablo) {
    int tmp = stablo[i+=n];
    if(v > x) 
        stablo[i] = 1;
    else stablo[i] = 0;

    for(i /= 2; i > 0; i/= 2)
        stablo[i/2] += stablo[i] - tmp;
}

int main() {
    int n, q, x;
    cin >> n >> q >> x;

    vector<int> niz(n);
    for(int i=0; i<n; i++) {
        cin >> niz[i];
        if(niz[i] < x)
            niz[i] = 0;
    }
    
    int sn = velicina(n);
    vector<int> stabloSuma = napraviStablo(sn, x, niz);
    vector<int> stabloBroj = napraviStablo2(sn, x, niz);

    while(q--) {
        int k, v, a, b;
        cin >> k >> v >> a >> b;
        postavi(k, v, x, sn, stabloSuma);
        postavi2(k, v, x, sn, stabloBroj);
        cout << upit(a, b, x, sn, stabloSuma) << upit(a, b, x, sn, stabloBroj);
    }

    return 0;
}