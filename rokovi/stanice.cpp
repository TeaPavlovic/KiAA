//jun 2023
#include <iostream>
#include <vector>
#include <limits>
#include <set>

using namespace std;

struct grana {
    int sused;
    int duzina;
};

int mod(int u, int v) {
    if(v - u > 0)
        return v - u;
    else return 0;
}

vector<int> dijkstra(int u, vector< vector<grana> >& graf) {
    int n = graf.size();
    vector<int> d(n, numeric_limits<int>::max());
    d[u] = 0;

    set< pair<int, int> > red; //tezina, cvor
    red.insert({0, u});

    while(!red.empty()) {
        int v = red.begin()->second;
        red.erase(red.begin());

        for(grana g : graf[v]) {
            

            if(d[v] + mod(d[v], g.duzina) < d[g.sused]) { 
                red.erase({d[g.sused], g.sused});
                d[g.sused] = d[v] + mod(d[v], g.duzina); //modifikuje granu
                red.insert({d[g.sused], g.sused});
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<grana> > graf(n);

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;

        graf[a-1].push_back({b-1, c});
        graf[b-1].push_back({a-1, c});
    }

    vector<int> dist = dijkstra(0, graf);

    cout << dist[n-1] << '\n';

    return 0;
}