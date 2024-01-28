//jul 2021
//NE RADI
#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, vector<bool>& obidjen, vector<bool>& kritican,
        vector<int>& cena, vector< vector<int> >& graf) {
    
    obidjen[u] = true;
    int povezaniServeri = 0;
    
    for(int v : graf[u]) {
        if(!obidjen[v]) {
            int povezani = dfs(v, obidjen, kritican, cena, graf);
            if(povezani > 0) { //ako je sused kritican
                    povezaniServeri++;
            }
        }
    }
     if(povezaniServeri > 0)
            kritican[u] = true;
     return povezaniServeri;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > graf(n);
    while(m--) {
        int u, v;
        cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    } 
    vector<int> cena(n);
    for(int i=0; i<n; i++) {
        cin >> cena[i];
    }
    int u;
    cin >> u;
    vector<bool> obidjen(n, false);
    vector<bool> kritican(n, false);
    dfs(u, obidjen, kritican, cena, graf);

    int zbir = 0;
    for(int i=0; i<n; i++) {
        if(kritican[i])
            zbir += cena[i];
    }

    cout << zbir << '\n';
}
