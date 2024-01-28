#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, int p, int& t, vector<int>& num, 
            vector< vector<int> >& graf) {
        int low = num[u] = ++t;
        bool ap = false;
        int count = 0; //broj dece prvog cvora

        for(int v : graf[u])
            if(num[v] == 0) {
                int v_low = dfs(v, u, t, num, graf);
            //ako nije koren, a jeste most
                if(num[u] > 1 && num[u] <= v_low)
                    ap = true;
                low = min(low, v_low); //prosledjuje se lowlink ako je manji
                count++; //ako cvor nije vec obidjen preko nekog drugog
                        //mora iz prvog cvora da se obidje  
            }
            else if(v != p)
                low = min(low, num[v]); //ako postoji alt put do viseg cvora
            //proveravamo da li je ap ili spec slucaj korena
            if(ap || (num[u] == 1 && count > 1))
                cout << u << ' ';
            
            return low;
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
    
    int t = 0;
    vector<int> num(n);

    dfs(0, 0, t, num, graf);
    cout << '\n';

    return 0;
}