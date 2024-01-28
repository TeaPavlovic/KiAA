//sept 2020
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> manacher(string& s) {
    int n = s.size();
    vector<int> p(n, 1);
    int l=0, d=0;

    for(int i=1; i<n; i++) {
        if(i<=d)
            p[i] = min(d-i+1, p[l+d-i]);
        while(i-p[i] >= 0 && i+p[i] < n 
        && s[i+p[i]] == s[i-p[i]])
            p[i]++;
        if(l+i-1 > d) {
            l = i - (p[i] - 1);
            d = i + (p[i] - 1);
        }
    }
    return p;
}

int main() {
    string s;
    int x;
    cin >> s >> x;

    string t = "#";
    for(char c : s) {
        t += c;
        t += "#"; 
    }

    vector<int> p = manacher(t);

    int pocetak = 0;
    for(int i=1; i<p.size(); i++) {
        if(p[i] - 1 >= x && ((p[i]-1) % 2 == x % 2))
            pocetak = i;
    }

    if(pocetak != 0) {
    int pocetak_s = (pocetak - x +  1) / 2;
    cout << s.substr(pocetak_s, x) << '\n';
    }
    else cout << -1 << '\n';
    return 0;
}