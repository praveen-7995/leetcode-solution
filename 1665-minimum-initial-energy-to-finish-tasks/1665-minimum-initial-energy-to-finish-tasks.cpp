class Solution {
public:
    bool ispossible(vector<vector<int>>& tasks, int energy) {
        for (auto &task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (energy < minimum) return false;

            energy -= actual;
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int l = 0, r = 1e9;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (ispossible(tasks, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};