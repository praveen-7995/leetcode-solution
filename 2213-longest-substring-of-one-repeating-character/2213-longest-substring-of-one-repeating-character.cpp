struct Node {
    int len;
    char pref_char;
    int pref_len;
    char suff_char;
    int suff_len;
    int max_len;

    // Constructor for placeholder/empty nodes
    Node() : len(0), pref_char('#'), pref_len(0), suff_char('#'), suff_len(0), max_len(0) {}

    // Constructor for leaf nodes (individual characters)
    Node(char ch) : len(1), pref_char(ch), pref_len(1), suff_char(ch), suff_len(1), max_len(1) {}
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    // Combines left child and right child states into a parent node
    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.len = left.len + right.len;
        
        // Inherit default properties from children
        parent.pref_char = left.pref_char;
        parent.pref_len = left.pref_len;
        parent.suff_char = right.suff_char;
        parent.suff_len = right.suff_len;
        
        // Max length is at least the max of either side
        parent.max_len = max(left.max_len, right.max_len);

        // Check if the internal boundary characters match to form a bridge
        if (left.suff_char == right.pref_char) {
            int bridge_len = left.suff_len + right.pref_len;
            parent.max_len = max(parent.max_len, bridge_len);

            // If left segment is completely uniform, extend parent's prefix
            if (left.pref_len == left.len) {
                parent.pref_len = left.len + right.pref_len;
            }
            // If right segment is completely uniform, extend parent's suffix
            if (right.suff_len == right.len) {
                parent.suff_len = right.len + left.suff_len;
            }
        }
        return parent;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(s[start]);
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node + 1, start, mid);
        build(s, 2 * node + 2, mid + 1, end);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = Node(ch);
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, ch);
        } else {
            update(2 * node + 2, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 0, 0, n - 1);
    }

    void updatePoint(int idx, char ch) {
        update(0, 0, n - 1, idx, ch);
    }

    int getMaxRepeatingLen() {
        return tree[0].max_len; // The root node always holds the global maximum
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryCharacters.length();
        vector<int> lengths(k);

        for (int i = 0; i < k; ++i) {
            st.updatePoint(queryIndices[i], queryCharacters[i]);
            lengths[i] = st.getMaxRepeatingLen();
        }

        return lengths;
    }
};