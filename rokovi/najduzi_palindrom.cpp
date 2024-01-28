//jun 2020
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> manacher(string s) {
    int n = s.size();
    vector<int> p(n, 1);

    int l = 0, d = 0;
    for(int i=1; i<n; i++) {
        if(i <= d) {
            p[i] = min(d-i+1, p[l+d-i]);
        }

        while(i-p[i] >= 0 && i+p[i] < n && s[i+p[i]] == s[i-p[i]]) {
            p[i]++;
        }
        if(i+p[i]-1 > d) {
            l = i - (p[i] - 1);
            d = i + (p[i] - 1);
        }
    }
    return p;
}

int main() {
    string s;
    int x;
    cin >> s;
    cin >> x;

    string t = "#";
    for(char c : s) {
        t += c;
        t += "#";
    }

    vector<int> p = manacher(t);

    int pocetak = -1;
    for(int i = 0; i < t.size(); i++)
        if (p[i] > x || p[i] >= p[pocetak])//zato sto oduzimamo 1
            pocetak = i;
    
    if(pocetak != -1) {
        int pocetak_s = (pocetak - p[pocetak] + 1) / 2;
        string rez = s.substr(pocetak_s, p[pocetak] - 1);
        cout << rez.size() << ' ' << rez << '\n';
    }

    else cout << -1;

    return 0;
}