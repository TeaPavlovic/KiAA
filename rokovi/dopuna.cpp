//jun 2020
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Cvor{
    bool kraj_reci;
    map<char,Cvor*> grana;
};

void dodaj(Cvor* koren, string& s) {
    for(char c : s) {
        if(koren->grana.find(c) == koren->grana.end())
            koren->grana[c] = new Cvor;
        koren = koren->grana[c];
    }
    koren->kraj_reci = true;
}

bool pronadji(Cvor* koren, string& s) {
    for(char c : s) {
        if(koren->grana.find(c) == koren->grana.end())
            return false;
        koren = koren->grana[c];
    }
    return koren->kraj_reci;
}

string prefiks(Cvor* koren, string& s) {
    string prefiks = "";

    for(char c : s) {
        if(koren->grana.find(c) == koren->grana.end()) {
            return prefiks;
        }
        prefiks += c;
        koren = koren->grana[c];
    }
    return prefiks;
}

void oslobodi(Cvor* koren) {
    for(auto podstablo : koren->grana)
        oslobodi(podstablo.second);
    delete koren;
}

int main() {
    Cvor* stablo = new Cvor();
    int n, m;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        dodaj(stablo, s);
    }
    cin >> m;
    while(m--) {
        string s;
        cin >> s;
        string t = s;
        reverse(t.begin(), t.end());
        string rez = prefiks(stablo, t);
        for(char c : s) {
            rez += c;
        } 
        cout << rez << '\n';
    }

    oslobodi(stablo);

    return 0;
}