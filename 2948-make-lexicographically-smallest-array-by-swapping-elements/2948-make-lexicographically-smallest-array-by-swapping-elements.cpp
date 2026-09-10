class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        // Make groups
        for (int i = 1; i < n; i++) {
            if (a[i].first - a[i - 1].first <= limit)
                unite(a[i].second, a[i - 1].second);
        }

        // Group values and indices
        map<int, vector<int>> values, indices;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            values[root].push_back(nums[i]);
            indices[root].push_back(i);
        }

        // Put smallest values at smallest indices
        for (auto &x : values) {
            int root = x.first;

            sort(x.second.begin(), x.second.end());
            sort(indices[root].begin(), indices[root].end());

            for (int i = 0; i < x.second.size(); i++)
                nums[indices[root][i]] = x.second[i];
        }

        return nums;
    }
};