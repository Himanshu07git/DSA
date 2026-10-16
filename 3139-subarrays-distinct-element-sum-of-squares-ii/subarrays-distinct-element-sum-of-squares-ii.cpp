
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0, sq = 0, lazy = 0;
    };

    vector<Node> tree;
    int n;

    void push(int p, int l, int r) {
        long long v = tree[p].lazy;
        if (v == 0) return;

        long long len = r - l + 1;
        tree[p].sq = (tree[p].sq + 2 * v * tree[p].sum
                      + v * v % MOD * len) % MOD;
        tree[p].sum = (tree[p].sum + v * len) % MOD;

        if (l != r) {
            tree[p * 2].lazy = (tree[p * 2].lazy + v) % MOD;
            tree[p * 2 + 1].lazy =
                (tree[p * 2 + 1].lazy + v) % MOD;
        }
        tree[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        push(p, l, r);

        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            tree[p].lazy = 1;
            push(p, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(p * 2, l, mid, ql, qr);
        update(p * 2 + 1, mid + 1, r, ql, qr);

        tree[p].sum =
            (tree[p * 2].sum + tree[p * 2 + 1].sum) % MOD;
        tree[p].sq =
            (tree[p * 2].sq + tree[p * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = last[nums[i]] + 1;
            update(1, 0, n - 1, l, i);
            last[nums[i]] = i;

            ans = (ans + tree[1].sq) % MOD;
        }

        return ans;
    }
};
