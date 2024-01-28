//Dat je aciklicni graf sa usmerenim i neusmerenim granama,
//neusmerene grane treba usmeriti tako da graf ostane aciklican

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
    int n, m1, m2; // m1 - usmerene, m2 - neusmerene grane
    cin >> n >> m1 >> m2;

    vector< vector<int> > graf(n);
    while(m1--) {   //uredjeni graf
        int a, b; // a -> b
        cin >> a >> b;
        graf[a].push_back(b);
    }

    vector<int> top = topolosko(graf);

    vector<int> index(n); //pomocni niz koji sadrzi nove poz cvorova
    for(int i=0; i<n; i++)
        index[top[i]] = i; 
    
    //ucitavamo neusmerene grane
    while(m2--) {
        int a, b;
        cin >> a >> b;
        if(index[a] < index[b])
            cout << a << ' ' << b << '\n';
        else 
        cout << b << ' ' << a << '\n';
    }
    
    return 0;
}