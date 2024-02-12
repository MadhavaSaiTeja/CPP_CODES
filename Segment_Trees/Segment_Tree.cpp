#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define int ll

void build(int ind, int low, int high, vector<int>& arr, int seg[]) {
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid, arr, seg);
    build(2 * ind + 2, mid + 1, high, arr, seg);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int query(int ind, int low, int high, int l, int r, int seg[]) {
    if (l <= low && r >= high) {
        return seg[ind];
    }
    if (l > high || r < low) {
        return 0;
    }
    int mid = low + (high - low) / 2;
    int left = query(2 * ind + 1, low, mid, l, r, seg);
    int right = query(2 * ind + 2, mid + 1, high, l, r, seg);
    return left + right;
}

void update(int ind, int low, int high, int i, int val, int seg[]) {
    if (low == high) {
        seg[ind] = val;
        return;
    }
    int mid = low + (high - low) / 2;
    if (i <= mid) {
        update(2 * ind + 1, low, mid, i, val, seg);
    } else {
        update(2 * ind + 2, mid + 1, high, i, val, seg);
    }
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void Solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int seg[4 * n];
    build(0, 0, n - 1, arr, seg);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(0, 0, n - 1, k - 1, u, seg);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(0, 0, n - 1, a - 1, b - 1, seg) << endl;
        }
    }
}

int32_t main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        Solve();
    }
}
