//Odredjivanje najkraceg puta od A do C ako mora ici preko B
#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;
struct grana {
    int sused;
    int duzina;
};

int dijkstra(int u, int k, vector< vector<grana> >& graf) {
    vector<int> d(graf.size(), numeric_limits<int>::max());
    d[u] = 0;

    set< pair<int, int> > red; // duzina, sused
    red.insert({0, u});

    while(!red.empty()) {
        int v = red.begin()->second;
        red.erase(red.begin());

        for(auto g : graf[v]) {
            if(d[v] + g.duzina < d[g.duzina]) {
                red.erase({d[g.sused], g.sused});
                d[g.sused] = d[v] + g.duzina;

                red.insert({d[g.sused], g.sused});
            }
        }
    }
    return d[k];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<grana> > graf(n);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    int a, b, c;
    cin >> a >> b >> c;

    int AB = dijkstra(a, b, graf);
    int BC = dijkstra(b, c, graf);

    cout << AB + BC << '\n';

    return 0;
}