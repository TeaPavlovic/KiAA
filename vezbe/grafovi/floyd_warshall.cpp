//All pair shortest path
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct grana {
    int sused;
    int duzina;
};

int addinf(int x, int y) {
    if(x == numeric_limits<int>::max() || y == numeric_limits<int>::max())
        return numeric_limits<int>::max();
    return x + y;
}

vector< vector<int> > floyd_warshall(vector< vector<grana> >& graf) {
    int n = graf.size();
    vector< vector<int> > D(n, vector<int>(n, numeric_limits<int>::max()));
    
    for(int i=0; i<n; i++)
        for(auto g : graf[i])
            D[i][g.sused] = g.duzina;

    for(int i=0; i<n; i++)
        D[i][i] = 0;
    
    for(int k = 0; k<n; k++)
        for(i=0; i<n; i++)
            for(int j = 0; j<n; j++)
                D[i][j] = min(D[i][j], addinf(D[i][k] + D[k][j]));
    return D;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<grana> > graf(n);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
    }

    vector< vector<int> > D = floyd_warshall(graf);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout << D[i][j] << ' ';
        cout << '\n';
    }
}