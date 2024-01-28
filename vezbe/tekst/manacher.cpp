//Najduzi palindrom u niski
//primer: ababab
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> manacher(string s) {
    int n = s.size();
    vector<int> p(n, 1); //svi char imaju pp bar 1

    int l=0, d=0;
    for(int i=1; i<n; i++) { // za 0 poziciju max moze da bude 1
        if(i <= d)
            p[i] = min(p[l+d-i], d-i+1);

        while(i+p[i] < n && i-p[i] >= 0 && s[i+p[i]] == s[i-p[i]]) {
            p[i]++;
        }
        if(i + p[i] - 1 > d) {
        l = i - (p[i] - 1);
        d = i + (p[i] - 1);
        } 
    }

    return p;
}

int main() {
    string s;
    cin >> s;

    string t = "#";
    for(char c : s) {
        t+=c;
        t+= "#";
    }

    vector<int> p = manacher(t);

    int i = max_element(begin(p), end(p)) - begin(p); //oduzimanjem dobijamo indeks
    cout << p[i]-1 << '\n';

    int pocetak_s = (i - p[i] + 1) / 2;

    cout << s.substr(pocetak_s, p[i] - 1) << '\n'; //(prva poz, duzina)

    return 0;
}