// Odredjivanje broja odvojenih mreza nakon povezivanja dva racunara
// m - broj povezivanja, a, b - kompjuteri koje povezujemo
// Koristimo union-find
#include <iostream>
#include <vector>

using namespace std;

vector<int> roditelj;
vector<int> rang;

void napraviDsu(int n) {
    roditelj.resize(n);
    rang.resize(n, 1); //stavi svuda rang 1
    for(int i=0; i<n; i++)
        roditelj[i] = i;
}

int predstavnik(int a) {
    int t = a;
    while(roditelj[t] != t) //koren je sam sebi roditelj
        t = roditelj[t];
    //opciono cvorove na putu vezujemo ka predstavniku
    while(a != t) {  //???
        int tmp = roditelj[a];
        roditelj[a] = t;
        a = tmp;
    }
    return a;
}

bool unija(int a, int b) {
    a = predstavnik(a);
    b = predstavnik(b);
    if(a == b) 
        return false; //vec su u uniji
    if(rang[a] < rang[b]) { //manji rang pridruzujemo vecem
        roditelj[a] = b;
        rang[b] += rang[a];
    }
    else {
        roditelj[b] = a;
        rang[a] += rang[b];
    }
    return true;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    napraviDsu(n);

    int brojMreza = n;
    while(m--) {
        cin >> a >> b;
        if(unija(a, b))
            brojMreza--;
        cout << brojMreza << '\n';
    }
    
    return 0;
}