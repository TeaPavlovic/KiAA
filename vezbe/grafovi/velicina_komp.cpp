//Odredjivanje velicine komponente povezanosti koja sadrzi cvor 0
//Dfs, a moze i bfs
#include <iostream>
#include <vector>

using namespace std;

int dfs(int v, vector<bool>& obidjen, vector< vector<int> >& graf) {
    int br = 0;
    obidjen[v] = true;
    for(int x : graf[v]) {
        if(!obidjen[x]) {
            br += dfs(x, obidjen, graf);
        }
    }
    return br + 1; //nismo racunali cvor iz kog krecemo
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

    vector<bool> obidjen(n);

    cout << dfs(0, obidjen, graf) << '\n';

    return 0;
}