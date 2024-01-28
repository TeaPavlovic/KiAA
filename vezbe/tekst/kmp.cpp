//Prefikis sufiks
//abcabdabcabc
#include <iostream>
#include <string>
#include <vector>

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
    string s, t;
    cin >> s >> t;

    string p = s + "#" + t;
    vector<int> ps = kmp(p);

    for(int i=0; i<ps.size(); i++)
        if(ps[i] == s.size())
            //i - (n+1) - (n-1)
           cout << i - 2 * s.size() << ' ';
    cout << '\n';

    return 0;
}
