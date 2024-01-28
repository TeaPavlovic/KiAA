//Jun1 2023
#include <iostream>
#include <vector>

using namespace std;

vector<int> roditelj;
vector<int> rang;

void napravi_dsu(int n) {
    roditelj.resize(n);
    rang.resize(n, 1);
    for(int i=0;i<n;i++)
        roditelj[i] = i;
}

int predstavnik(int a) {
    int t = a;
    while(roditelj[t] != t) {
        t = roditelj[t];
    }
    while(a != t) {
        int tmp = roditelj[a];
        roditelj[a] = t;
        a = tmp;
    }
    return a;
}

int upit(int a) {
    int t = predstavnik(a);
    int k = rang[t];
    return k;
}


void unija(int a, int b) {
    a = predstavnik(a);
    b = predstavnik(b);
    if(a == b)
        return;
    if(rang[a] < rang[b]) {
        roditelj[a] = b;
        rang[b] += rang[a];
    }
    else {
        roditelj[b] = a;
        rang[a] += rang[b];
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    napravi_dsu(n);

    while(m--) {
        string operacija;
        cin >> operacija;
        if(operacija == "M") {
            cin >> a >> b;
            unija(a-1, b-1);
        }
        else if(operacija == "Q") {
            cin >> a;
            cout << upit(a-1) << '\n';
        }
    }
    
    return 0;
}