//sept 2020
#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

struct grana {
    int sused;
    int tezina;
};

vector<grana> prim(vector< vector<grana> >& graf) {
    vector<bool> dodat(graf.size());
    vector<grana> stablo(graf.size(), {-1, 0}); //jer neke tezine ostanu besk
    set< pair<int, int> > red; //tezina, cvor

    red.insert({0, 0});

    while(!red.empty()) {
        int v = red.begin()->second;
        red.erase(red.begin());
        dodat[v] = true;

        for(auto g : graf[v]) {
            if(!dodat[g.sused] && /*g.tezina < stablo[g.sused].tezina &&*/ g.tezina >= 0) {
                red.erase({stablo[g.sused].tezina, g.sused});
                stablo[g.sused].tezina = g.tezina;
                red.insert({stablo[g.sused].tezina, g.sused});
            }
        }
    }
    return stablo;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<grana> > graf(n);

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graf[u].push_back({v, w});
        graf[v].push_back({u, w});
    }
    vector<grana> stablo = prim(graf);

    int tezina = 0;
    for(auto g : stablo) {
        cout << g.sused << ' ';
        if(g.tezina >= 0)
            tezina += g.tezina;
    }
    cout << tezina << '\n';

    return 0;
}