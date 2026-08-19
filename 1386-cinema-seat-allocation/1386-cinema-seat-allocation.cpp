class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        reservedSeats.push_back({0, 10});
        reservedSeats.push_back({n + 1, 0});

        sort(reservedSeats.begin(), reservedSeats.end());

        int size = reservedSeats.size();
        int count = 0;

        for (int i = 1; i < size; ) {

            // Number of completely empty rows
            if (reservedSeats[i][0] > reservedSeats[i - 1][0] + 1) {
                int skipRow = reservedSeats[i][0] - reservedSeats[i - 1][0] - 1;
                count += 2 * skipRow;
            }

            // Last dummy row
            if (reservedSeats[i][0] == n + 1)
                break;

            int row = reservedSeats[i][0];

            bool left = true;    // 2 3 4 5
            bool middle = true;  // 4 5 6 7
            bool right = true;   // 6 7 8 9

            // Check all reserved seats of this row
            int j = i;

            while (j < size && reservedSeats[j][0] == row) {

                int col = reservedSeats[j][1];

                if (col >= 2 && col <= 5)
                    left = false;

                if (col >= 4 && col <= 7)
                    middle = false;

                if (col >= 6 && col <= 9)
                    right = false;

                j++;
            }

            // Your main counting idea
            if (left && right) {
                count += 2;
            }
            else if (left || middle || right) {
                count += 1;
            }

            // Move to next row
            i = j;
        }

        return count;
    }
};