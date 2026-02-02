// Program: Closest Pair of Points using Divide and Conquer

#include <bits/stdc++.h>
using namespace std;

double dist(pair<int,int> p1, pair<int,int> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}

double bruteForce(vector<pair<int,int>>& P, int l, int r) {
    double mn = DBL_MAX;
    for (int i = l; i <= r; i++)
        for (int j = i + 1; j <= r; j++)
            mn = min(mn, dist(P[i], P[j]));
    return mn;
}

double closestUtil(vector<pair<int,int>>& P, int l, int r) {
    if (r - l <= 3)
        return bruteForce(P, l, r);

    int mid = (l + r) / 2;
    double dl = closestUtil(P, l, mid);
    double dr = closestUtil(P, mid + 1, r);
    double d = min(dl, dr);

    vector<pair<int,int>> strip;
    for (int i = l; i <= r; i++)
        if (abs(P[i].first - P[mid].first) < d)
            strip.push_back(P[i]);

    sort(strip.begin(), strip.end(),
         [](auto a, auto b) { return a.second < b.second; });

    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1; j < strip.size() && 
             (strip[j].second - strip[i].second) < d; j++)
            d = min(d, dist(strip[i], strip[j]));

    return d;
}

int main() {
    vector<pair<int,int>> P = {
        {9,3},{2,6},{15,3},{5,1},{1,2},{12,4},{7,2},{4,7},
        {16,5},{3,3},{10,5},{6,4},{14,6},{8,6},{11,1},{13,2}
    };

    sort(P.begin(), P.end());
    cout << closestUtil(P, 0, P.size() - 1);

    return 0;
}
