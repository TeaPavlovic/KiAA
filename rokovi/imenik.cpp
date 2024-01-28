//jul 2021
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Cvor {
    bool kraj_reci = false;
    map<char, Cvor*> prelaz;
};

void dodaj(string& s, Cvor* koren) {
    for(char c : s) {
        if(koren->prelaz.find(c) == koren->prelaz.end()) {
            koren->prelaz[c] = new Cvor();
        }
        koren = koren->prelaz[c];
    }
}

int sufiks(int& br, Cvor* koren) {
    if(koren->kraj_reci)
        return 0;
    for(auto podstablo : koren->prelaz) {
        br++;
        br = max(sufiks(br, podstablo.second), br);
    }
    return br;
}

int find(string prefiks, Cvor* koren) {
    for(char c : prefiks) {
        if(koren->prelaz.find(c) == koren->prelaz.end()) {
            return 0;
        }
        koren = koren->prelaz[c];
    }
    int br = prefiks.size();
    return sufiks(br, koren);
}

int main() {
    int n;
    cin >> n;

    Cvor* stablo = new Cvor();

    for(int i=1; i<=n; i++) {
        string upit, s;
        cin >> upit >> s;
        if(upit == "add") {
            dodaj(s, stablo);
        }
        if(upit == "find") {
            cout << find(s, stablo) << '\n';
        }
    }
    return 0;
}