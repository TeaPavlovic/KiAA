//Implementacija prefiksnih stabala (trie)
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Cvor {
    bool krajReci = false;
    map<char, Cvor*> prelaz; //ili grana
};

void dodaj(Cvor* koren, string& s) {
    for(char c : s) {
        if(koren->prelaz.find(c) == koren->prelaz.end())
            koren->prelaz[c] = new Cvor();
        koren = koren->prelaz[c];
    }
    koren->krajReci = true; //kraj reci
}

bool nadji(Cvor* koren, string& s) {
    for(char c : s) {
        if(koren->prelaz.find(c) == koren->prelaz.end())
            return false; //ako nismo nasli neki od karaktra
        koren = koren->prelaz[c];
    }
    return koren->krajReci;
}

void oslobodi(Cvor* koren) { //celo stablo
    //prvo podstablo, pa koren
    for(auto podstablo : koren->prelaz)
        oslobodi(podstablo.second);
    delete koren;
}

void ispisi(Cvor* koren, string& rec) {
    //rekurzivno
    if(koren->krajReci)
        cout << rec << '\n';
    for(auto podstablo : koren->prelaz) {
        rec.push_back(podstablo.first);
        ispisi(podstablo.second, rec);
        rec.pop_back();
    }
}

string nzp(Cvor* koren) {
    string prefiks = "";
    while(koren->prelaz.size() == 1 && !koren->krajReci) {
        //pristupamo prvom elementu mape
        auto it = koren->prelaz.begin(); 

        prefiks.push_back(it->first);
        koren = it->second;
    }
    return prefiks;
}

void autocomplete(Cvor* koren, string& prefiks) {
    for(char c : prefiks) {
        if(koren->prelaz.find(c) == koren->prelaz.end())
            return;
        koren = koren->prelaz[c];
    }
    //ako smo nasli ceo prefiks
    string rec = "";
    ispisi(koren, rec); //ispisi sve nakon prefiksa
}

int main() {
    Cvor* stablo = new Cvor();
    string upit, a;
    while(true) {
        cin >> upit;
        if(upit == "dodaj") {
            cin >> a;
            dodaj(stablo, a);
        }
        else if(upit == "nadji") {
            cin >> a;
            cout << nadji(stablo, a) << '\n';
        }
        else if(upit == "prefiks") {
            cout << nzp(stablo);
        }
         else if(upit == "ispisi") {
            string rec = "";
            ispisi(stablo, rec);
        }
        else if(upit == "autocomp") {
            string s;
            cin >> s;
            autocomplete(stablo, s);
        }
        else break;
    }
    oslobodi(stablo);

    return 0;
}