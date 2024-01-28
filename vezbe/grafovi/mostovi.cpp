//Algoritam za pronalazenje mostova u grafu
#include <iostream>
#include <vector>

using namespace std;

int dfs(int u,int p, int& t, vector<int>& num, 
        vector< vector<int> >& graf) {
    //cuvamo low link vrednost
    int low = num[u] = ++t;
            
    for(int v : graf[u]) {
        if(num[v] == 0) { //nismo obisli cvor
            int v_low = dfs(v, u, t, num, graf);
            if(num[u] < v_low)
                cout << u << ' ' << v << '\n'; //ispisujemo most
            low = min(low, v_low);
            //ako je v_low manji od num[u], postoji
            //alt put
        }
        else if(v != p) //obilazimo sve susede osim roditelja
                        //tj sve povratne grane
            low = min(low, num[v]);
    }
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
	vector<int> num(n, 0);
	dfs(0, 0, t, num, graf);

	return 0;
}