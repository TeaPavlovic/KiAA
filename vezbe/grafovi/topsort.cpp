#include <iostream>
#include <vector>

using namespace std;

//fja koja vraca niz topoloski uredjenih cvorova
vector<int> topolosko(vector< vector<int> >& graf) {
    int n = graf.size(); //koristicemo puno

    vector<int> indeg(n); //ulazni stepeni cvorova
    for(int u=0; u<n; u++)
        for(int v : graf[u])
            indeg[v]++;

    vector<int> q; //'red' koji popunjavamo i vracamo
    for(int u=0; u<n; u++) 
        if(indeg[u] == 0)
            q.push_back(u);
    
    for(int i=0; i<q.size(); i++) {
        int u = q[i];
        for(int v : graf[u]) {
            indeg[v]--;
            if(indeg[v] == 0)
                q.push_back(v);
        }
    }
    return q;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<int> > graf(n);
    while(m--) {   //uredjeni graf
        int a, b; // a -> b
        cin >> a >> b;
        graf[a].push_back(b);
    }

    vector<int> top = topolosko(graf);

    if(top.size() < n)
        cout << "ciklus" << '\n';

    else  {
        for(int x : top)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}