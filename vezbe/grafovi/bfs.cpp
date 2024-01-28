#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int v, vector< vector<int> > graf) {
    vector<bool> obidjen(graf.size());
    queue<int> q;
    q.push(v);

    while(!q.empty()) {
        int t = q.front();
        q.pop();
        cout << t << '\n';
        for(int x : graf[t]) {
            if(!obidjen[x]) {
                q.push(x);
                obidjen[x] = true;
            }
        } 
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

	bfs(0, graf);

	return 0;
}