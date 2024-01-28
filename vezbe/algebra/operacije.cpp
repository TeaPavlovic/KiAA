#include <iostream>

using namespace std;

int mod(int a, int m) {
    if(a >= 0)
        return a % m;
    else
        return (m + a % m) % m;  // -5 mod 4 = -1 + 4
                                //  -4 mod 4 = (0 + 4) % 4 = 0
}

int add(int a, int b, int m) {
    return mod(a + b, m);
}

int sub(int a, int b, int m) {
    return mod(a - b, m);
}

int mul(int a, int b, int m) {
    return mod(mod(a, m) * mod(b, m), m); //zbog prekoracenja
}

//linearni kongruentni generator
// x0 = 1, x1 = (a*x0 +c) mod m ...

int main() {
    int a = 10, c = 6, m = 19;
    int seed = 1; //x0

    int x = seed;
    do {
        x = add(mul(a, x, m), c, m);
        cout << x << ' ';
    } while(x != 1);

    cout << '\n';

    return 0;
}