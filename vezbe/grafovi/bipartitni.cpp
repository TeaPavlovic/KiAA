//Odredjuje da li je graf bipartitan
#include <iostream>
#include <vector>

using namespace std;
//0 - neobidjen
//1, 2 - moguce boje
//suprotna(trBoja) = 3 - trenutna boja
bool dfs(int v, int trBoja, vector<int>& boja, vector< vector<int> > graf) {
    boja[v] = trBoja;
    for(int x : graf[v]) {
        if(boja[x] == boja[v]) //ako su susedi iste boje
            return false;
        //ako neki cvor nismo mogli da obojimo
        if(boja[x] == 0 && !dfs(x, 3-trBoja, boja, graf))
            return false;
    }
    return true;
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

    vector<int> boja(n);

    if(dfs(0, 1, boja, graf))
        cout << "jeste" << '\n';
    else
        cout << "nije" << '\n';
    return 0;
}