//jun 2020
#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

using namespace std;

struct grana {
    int sused;
    int duzina;
};

vector<int> dijkstra(int u, vector< vector<grana> >& graf) {
    int n = graf.size();
    vector<int> d(n, numeric_limits<int>::max());
    d[u] = 0;
    set<pair<int, int> > red; //duzina, cvor
    red.insert({0, u});

    while(!red.empty()) {
        int v = red.begin()->second;
        red.erase(red.begin());

        for(grana g : graf[v]) {
            if(d[v] + g.duzina < d[g.sused]) {
                red.erase({d[g.sused], g.sused});
                d[g.sused] = d[v] + g.duzina;
                red.insert({d[g.sused], g.sused});
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<grana> > graf(n);

    while(m--) {
        int x, y, d;
        cin >> x >> y >> d;
        graf[y].push_back({x, d});
    }

    vector<int> d = dijkstra(0, graf);

    int maks = max_element(begin(d), end(d)) - begin(d);

    cout << maks << ' ' << d[maks] << '\n';

    return 0;
}