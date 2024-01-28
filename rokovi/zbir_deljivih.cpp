//sept 2021
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, m, n;
    cin >> k >> m >> n;

    vector<int> delioci(m+1);
    for(int i=1; i<=m; i++) {
            for(int j=i; j<=m; j+=i) {
                delioci[j]++;
            }
    }

    while(n--) {
        int a, b;
        cin >> a >> b;
        int zbir = 0;
        for(int i= a; i<=b; i++) {
            if(delioci[i] >= k)
                zbir += i;
        }
        cout << zbir << '\n';
    }
}