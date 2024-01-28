//Odredjivanje komponenti grafa
//Dfs, a moze i bfs
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<bool>& obidjen, vector< vector<int> >& graf) {
    obidjen[v] = true;
    for(int x : graf[v]) {
        if(!obidjen[x])
            dfs(x, obidjen, graf);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<int> > graf(n);
    
    while(m--) {
        int a, b;
        cin >> a >> b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int brKomp = 0;
    vector<bool> obidjen(n);
    for(int i=0; i<n; i++) {
        if(!obidjen[i]) {
            dfs(i, obidjen, graf);
            brKomp++;
        }
    }

    cout << brKomp << '\n';

    return 0;
}