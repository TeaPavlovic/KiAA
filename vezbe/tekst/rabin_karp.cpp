//Trazenje reci pomocu hesiranja
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int64_t mod(int64_t a, int64_t M) {
	return (M + a % M) % M;
}

int64_t add(int64_t a, int64_t b, int64_t M) {
	return mod(mod(a, M) + mod(b, M), M);
}

int64_t sub(int64_t a, int64_t b, int64_t M) {
	return mod(mod(a, M) - mod(b, M), M);
}

int64_t mul(int64_t a, int64_t b, int64_t M) {
	return mod(mod(a, M) * mod(b, M), M);
}

//pretvaranje u broj
int64_t num(char c) {
    return (int64_t)(c - 'a' + 1)
}

//hes vrednost niske
int64_t hash_str(string s) {
    int64_t p = 31, M = 1000000009 //1e9 + 9

    int64_t h = 0;
    for(char c : s)
        //p*h + c
        h = add(mul(p, h, M), num(c), M);
    return h;
}

void search(string s, string t) {
    int64_t p = 31, M = 1000000009;

    int n = s.size(); //rec koju trazimo
    int m = t.size(); //string gde je trazimo

    int64_t sh = hash_str(s);
    int64_t th = hash_str(t.substr(0, n));

    //p^(n-1)
    int64_t pn = 1;
    for(int i=0; i<n-1; i++)
        pn = mul(pn, p, M);

    if(sh == th)
        cout << 0 << ' ';
    
    for(int i = n; i < m; i++) {
        //inkrementalno izracunava hes vrednost segmenta
        //(th - pn*(t[i-n]-'a'+1)) * p + (t[i]-'a'+1)
        th = sub(th, mul(pn, num(t[i-n])));
        th = mul(th, p, M);
        th = add(th, num(t[i], M));

        if(sh == th)
            cout << i - n + 1 << ' ';
    }
}

int main() {
    string s, t;
    cin >> s >> t;

    search(s, t);
    cout << '\n';

    return 0;
}

