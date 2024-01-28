//jul 2021
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tacka = pair<int, int>; //(x, y)

tacka vec(tacka a, tacka b) {
    return {b.first - a.first, b.second - a.second};
}

int cross(tacka v, tacka u) {
    return v.first * u.second - v.second * u.first;
}

int orient(tacka a, tacka b, tacka c) {
    return cross(vec(a, b), vec(a, c));
}

void sortiraj(vector<tacka>& t) {
    sort(t.begin(), t.end(), [&](tacka a, tacka b) {
            return orient(t[0], a, b) > 0;
    });
}

int main() {
    int n;
    cin >> n;
    vector<tacka> t(n+1);

    t[0] = {0, 0};
    for(int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        t[i] = {x, y};
    }
    sortiraj(t);

    for(int i=1; i<n+1; i++) {
        cout << t[i].first << ' ' << t[i].second << '\n';
    }

}