//Union-find
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
    while(a != t) {
        int tmp = roditelj[a];
        roditelj[a] = t;
        a = tmp;
    }
    return a;
}

void unija(int a, int b) {
    a = predstavnik(a);
    b = predstavnik(b);
    if(a == b) 
        return; //vec su u uniji
    if(rang[a] < rang[b]) { //manji rang pridruzujemo vecem
        roditelj[a] = b;
        rang[b] += rang[a];
    }
    else {
        roditelj[b] = a;
        rang[a] += rang[b];
    }
}

int main() {
    int n, a, b;
    cin >> n;

    napraviDsu(n);

    while(true) {
        string operacija;
        cin >> operacija;
        if(operacija == "unija") {
            cin >> a >> b;
            unija(a, b);
        }
        else if(operacija == "predstavnik") {
            cin >> a;
            cout << predstavnik(a) << '\n';
        }
    }
    
    return 0;
}