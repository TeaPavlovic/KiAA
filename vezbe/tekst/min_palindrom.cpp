//Naci najmanji broj karaktera koje
//treba dodati na pocetak da string 
//postane palindrom
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> p(n);

    for(int i=1; i<n; i++) {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j])
            j = p[j-1];
        if(s[i] == s[j])
            j++;
            p[i] = j;
    }
    return p;
}

int main() {
    string s;
    cin >> s;

    //obrcemo string
    string r = s;
    reverse(r.begin(), r.end());

    string p = s + "#" + r;
    vector<int> ps = kmp(p);

    //podstring od prvog char u r, do poslednjeg koji se ne poklapa
    //i onda nalepimo pocetni string
    cout << p.substr(s.size() + 1, s.size() - ps.back()) << s << '\n';

    return 0;
}
