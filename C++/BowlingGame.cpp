#include <vector>

using namespace std;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0, score2 = 0;
        bool last1_strike = false, last2_strike = false;
        bool last1_spare = false, last2_spare = false;
        int n = player1.size();
        for (int i = 0; i < n; i++) {
            int x1 = player1[i], x2 = player2[i];
            int v1 = getValue(x1, last1_strike, last1_spare);
            int v2 = getValue(x2, last2_strike, last2_spare);
            score1 += v1;
            score2 += v2;
            last1_strike = (x1 == 10) || (last1_strike && x1 + player1[i-1] == 10);
            last2_strike = (x2 == 10) || (last2_strike && x2 + player2[i-1] == 10);
            last1_spare = !last1_strike && (x1 + player1[i-1] == 10);
            last2_spare = !last2_strike && (x2 + player2[i-1] == 10);
        }
        if (score1 > score2) {
            return 1;
        } else if (score1 < score2) {
            return 2;
        } else {
            return 0;
        }
    }

private:
    int getValue(int x, bool strike, bool spare) {
        if (strike || spare) {
            return 2 * x;
        } else {
            return x;
        }
    }
};

