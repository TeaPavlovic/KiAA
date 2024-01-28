#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<bool>& obidjen, vector< vector<int> > graf) {
    obidjen[v] = true;
    for(int x : graf[v]) {
        if(!obidjen[x]) {
            dfs(x, obidjen, graf);
            cout << x << ' ';
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<int> > graf(n);

    //Ucitavamo neusmeren graf:
    while(m--) {
        int a, b;
        cin >> a >> b;

        graf[b].push_back(a);
        graf[a].push_back(b);
    }

    vector<bool> obidjen(n);

    dfs(0, obidjen, graf);

    cout << '\n';
    return 0;
}