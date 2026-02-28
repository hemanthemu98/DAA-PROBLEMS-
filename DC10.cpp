#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closestUtil(vector<Point>& px, int l, int r, vector<Point>& py) {
    if(r - l <= 3) {
        double min_d = DBL_MAX;
        for(int i = l; i <= r; i++) {
            for(int j = i + 1; j <= r; j++) {
                min_d = min(min_d, dist(px[i], px[j]));
            }
        }
        return min_d;
    }
    int mid = l + (r - l) / 2;
    Point mid_p = px[mid];
    vector<Point> pyl, pyr;
    for(auto& p : py) {
        if(p.x <= mid_p.x) pyl.push_back(p);
        else pyr.push_back(p);
    }
    double dl = closestUtil(px, l, mid, pyl);
    double dr = closestUtil(px, mid + 1, r, pyr);
    double d = min(dl, dr);
    vector<Point> strip;
    for(auto& p : py) {
        if(abs(p.x - mid_p.x) < d) strip.push_back(p);
    }
    sort(strip.begin(), strip.end(), [](Point a, Point b){ return a.y < b.y; });
    for(size_t i = 0; i < strip.size(); i++) {
        for(size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            double dd = dist(strip[i], strip[j]);
            if(dd < d) d = dd;
        }
    }
    return d;
}

int main() {
    vector<Point> points = {
        {9,3}, {2,6}, {15,3}, {5,1}, {1,2}, {12,4}, {7,2}, {4,7}, {16,5}, {3,3}, {10,5}, {6,4}, {14,6}, {8,6}, {11,1}, {13,2}
    };
    vector<Point> px = points;
    sort(px.begin(), px.end(), [](Point a, Point b){ return a.x < b.x; });
    vector<Point> py = points;
    sort(py.begin(), py.end(), [](Point a, Point b){ return a.y < b.y; });
    double min_d = closestUtil(px, 0, points.size() - 1, py);
    cout << fixed << setprecision(6) << min_d << endl;
    return 0;
}
