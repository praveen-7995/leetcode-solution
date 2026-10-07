class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        unordered_set<string> visited;

        queue<string> q;
        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                string curr = q.front();
                q.pop();

                // If valid, this is the minimum-removal level
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // Don't generate the next level
                // after finding valid strings
                if (found)
                    continue;

                for (int i = 0; i < curr.size(); i++) {

                    // Only remove parentheses
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) +
                                  curr.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // We found valid strings at this level,
            // so minimum removals are achieved.
            if (found)
                break;
        }

        return ans;
    }
};