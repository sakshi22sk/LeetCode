#include <bits/stdc++.h>
using namespace std;

// Segment Tree that tracks covered width
class SegTree {
public:
    int n;
    vector<int> count;
    vector<long long> covered;
    vector<long long> xs;

    SegTree(const vector<long long>& coords) {
        xs = coords;
        n = xs.size() - 1;
        count.assign(4 * n, 0);
        covered.assign(4 * n, 0);
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            count[idx] += val;
        } else {
            int mid = (l + r) / 2;
            update(idx*2, l, mid, ql, qr, val);
            update(idx*2+1, mid, r, ql, qr, val);
        }
        if (count[idx] > 0) {
            covered[idx] = xs[r] - xs[l];
        } else {
            if (l + 1 == r) covered[idx] = 0;
            else covered[idx] = covered[idx*2] + covered[idx*2+1];
        }
    }

    long long getCovered() const {
        return covered[1];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // Gather events: (y, type, x1, x2)
        vector<tuple<long long, int, long long, long long>> events;
        vector<long long> allx;
        for (auto& sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            events.emplace_back(y, 1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);
            allx.push_back(x);
            allx.push_back(x + l);
        }
        sort(allx.begin(), allx.end());
        allx.erase(unique(allx.begin(), allx.end()), allx.end());
        sort(events.begin(), events.end());

        // Calculate total union area
        SegTree st(allx);
        long long prevY = get<0>(events[0]);
        long long totalArea = 0;
        for (auto &e : events) {
            long long y, t, x1, x2;
            tie(y, t, x1, x2) = e;
            long long h = y - prevY;
            if (h > 0) {
                totalArea += st.getCovered() * h;
                prevY = y;
            }
            int l = lower_bound(allx.begin(), allx.end(), x1) - allx.begin();
            int r = lower_bound(allx.begin(), allx.end(), x2) - allx.begin();
            st.update(1, 0, st.n, l, r, t);
        }

        // Sweep again to find y where cum area = totalArea/2
        double half = totalArea / 2.0;
        SegTree st2(allx);
        prevY = get<0>(events[0]);
        long long currentArea = 0;
        for (auto &e : events) {
            long long y, t, x1, x2;
            tie(y, t, x1, x2) = e;
            double h = y - prevY;
            if (h > 0) {
                double coveredW = st2.getCovered();
                double areaPiece = coveredW * h;
                if (currentArea + areaPiece >= half) {
                    return prevY + (half - currentArea) / coveredW;
                }
                currentArea += areaPiece;
                prevY = y;
            }
            int l = lower_bound(allx.begin(), allx.end(), x1) - allx.begin();
            int r = lower_bound(allx.begin(), allx.end(), x2) - allx.begin();
            st2.update(1, 0, st2.n, l, r, t);
        }
        return prevY;
    }
};
