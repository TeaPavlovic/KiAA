//Odredjivanje racunara sa najmanjim ID iz iste mreze
//Union-find
#include <iostream>
#include <vector>

using namespace std;

vector<int> roditelj;
vector<int> rang;
vector<int> najmanji;

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
    return a;
}

void unija(int a, int b) {
    a = predstavnik(a);
    b = predstavnik(b);
    if(a == b) 
        return; //vec su u uniji
    if(rang[a] < rang[b]) { //manji rang pridruzujemo vecem
        roditelj[a] = b;
        rang[b] += rang[a]; // a pripada b
        najmanji[b] = min(najmanji[a], najmanji[b]);
    }
    else {
        roditelj[b] = a;
        rang[a] += rang[b];
        najmanji[a] = min(najmanji[a], najmanji[b]);
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    napraviDsu(n);

    while(m--) {
        string upit;
        if(upit == "povezi") {
            cin >> a >> b;
            unija(a, b);
        }
        else if(upit == "najmanji") {
            cin >> a;
            cout << najmanji[predstavnik(a)] << '\n';
        }
    }
    
    return 0;
}