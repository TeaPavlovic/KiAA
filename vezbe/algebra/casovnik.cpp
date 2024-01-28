//Izracunaj koje je vreme, ako se casovnik na svaki sat
//pomeri a sati vise. Dato je trenutno vreme c na satu
#include <iostream>
#include <tuple> //zbog tie

using namespace std;

int euklid(int a, int b, int& x, int& y) {
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    while(r2 > 0) {
        int q = r1 / r2;
        tie(r1, r2) = make_pair(r2, r1 - q*r2);
        tie(x1, x2) = make_pair(x2, x1 - q*x2);
        tie(y1, y2) = make_pair(y2, y1 - q*y2);
    }

    x = x1;
    y = y1;

    return r1;
}

bool diofant(int a, int b, int c, int& x, int& y) {
    int d = euklid(abs(a), abs(b), x, y);
    if(c % d != 0)
        return false;
    if(a < 0)
        x *= -1;
    if(b < 0)
        y *= -1;

    x *= c/d;
    y *= c/d;
    return true;
}

int main() {
    int a, c;
    int m = 12;
    cin >> a >> c;

    int t, y;
    //at = c (mod m)
    //at + my = c
    if(diofant(a, m, c, t, y))
        cout << "Sada je " << (m + t % m) % m << " sati" << '\n';
    else cout << "Sat je bas pokvaren :(" << '\n';

    return 0;
}