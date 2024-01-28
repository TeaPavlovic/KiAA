#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tacka = pair<int, int>; // (x, y)

tacka vec(tacka a, tacka b) { //vektor
    return {b.first - a.first, b.second - a.second};
}

int dot(tacka v, tacka w) {
    return v.first * w.first + v.second * w.second;
}

int cross(tacka v, tacka w) { //racuna orjentaciju
    return v.first * w.second - v.second * w.first;
}

int orient(tacka a, tacka b, tacka c) {
    return cross(vec(a, b), vec(a, c));
}

bool colinear(tacka a, tacka b, tacka c) {
    return cross(vec(a, b), vec(a, c)) == 0;
}

bool inTriangle(tacka a, tacka b, tacka c, tacka d) {
    if(orient(a, b, d) >=0 && orient(b, c, d) >= 0 && orient(c, a, d) >= 0)
        return true;
    if(orient(a, b, d) <=0 && orient(b, c, d) <= 0 && orient(c, a, d) <= 0)
        return true;
    return false;
}

//ispituje konveksnost mnogougla
bool checkConvex(vector<tacka>& p) {
    bool pos = false, neg = false;
    for(int i=0; i<p.size(); i++) {
        int j = (i + 1) % p.size(); //ako je i poslednja tacka
        int k = (i + 2) % p.size();
        if(orient(p[i], p[j], p[k]) > 0)
            pos = true;
        if(orient(p[i], p[j], p[k]) < 0)
            neg = true;
    }
    return !(pos && neg); //ne pojavljuju se obe orjent
}

//Od skupa tacaka dobiti prost mnogougao
vector<tacka> makeSimple(vector<tacka> tacke) {
    vector<tacka> p = tacke; //pravimo kopiju koju menjamo
    swap(p[0], *min_element(begin(p), end(p)));
    sort(begin(p) + 1, end(p), 
            [&](tacka a, tacka b){
                return orient(p[0], a, b) > 0;
            });
    return p;
}

//Najmanji konveksni omotac O(p.size * hull.size)
vector<int> jarvisMarch(vector<tacka>& p) {
    vector<int> hull;

    int t = min_element(begin(p), end(p)) - begin(p); //pozicija najmanje tacke

    do {
        hull.push_back(t); //dodajemo tacku sa najmanjim x
        int nt = (t + 1) % p.size(); //uzimamo tacku razlicitu od t
        for(int i=0; i<p.size(); i++)
            if(orient(p[t], p[i], p[nt]) > 0) //ako se uklapa
                nt = i;                      // uzimamo tacku
        t = nt;
    } while(t != hull[0]); //dok ne dodjemo do pocetne tacke
    return hull;
}

//O(n*logn), n - p.size
vector<int> grahamScan(vector<tacka>& p) {
    swap(p[0], *min_element(begin(p), end(p)));
    sort(begin(p) + 1, end(p), 
            [&](tacka a, tacka b){
                return orient(p[0], a, b) > 0;
            });
    vector<int> hull = {0};
    for(int i=1; i<p.size(); i++) {
        while(hull.size() > 1 && 
                orient(p[hull[hull.size()-2]], p[hull[hull.size()-1]], p[i]) < 0)
            hull.pop_back();
        hull.push_back(i);
    }
    return hull;
}

//Da li je tacka u omotacu
bool inConvex(tacka t, vector<tacka>& p) {
    auto it = lower_bound(begin(p) + 1, end(p), t,
                        [&](tacka a, tacka b){
                            return orient(p[0], a, b) > 0;
                        }); //trazi prvo mesto gde moze da umetne t
     if(it == end(p))
        return false;
    int i = it - begin(p); //uzimamo tu poziciju
        return inTriangle(p[0], p[i-1], p[i], t);
}

//Orjentisana povrsina trougla
float orientedArea(tacka a, tacka b, tacka c) {
    return orient(a, b, c) * 0.5f;
}

//Za bilo koji prost mnogougao
float orientedArea(vector<tacka>& p) {
    float a = 0; 
    for(int i=2; i<p.size(); i++)
        a += orientedArea(p[0], p[i-1], p[i]);
    return a;
}

