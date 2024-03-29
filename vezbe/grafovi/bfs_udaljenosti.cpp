//Primena bfs u odredjivanju najkraceg puta do cvora u grafu
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int v, vector< vector<int> >& graf) {
    vector<int> udaljenost(graf.size(), -1);
    queue<int> q;
    q.push(v);
    udaljenost[v] = 0;

    while(!q.empty()) {
        int t = q.front(); //trenutni cvor koji obradjujemo
        q.pop();

        for(int x : graf[t]) {
            if(udaljenost[x] == -1) {
                q.push(x);
                udaljenost[x] = udaljenost[t] + 1;
            } 
        }
    }
    return udaljenost;
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
vector<int> udaljenosti = bfs(0, graf);
    for(int x : udaljenosti)
	    cout << x << ' ';
    cout << '\n';

	return 0;
}