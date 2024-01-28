#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> kmp(string s) {
    int n = s.size;
    vector<int> p(n);
    for(int i=0; i<n; i++) {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j])
            j = p[j-1];
        if(s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}