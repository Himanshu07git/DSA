
class Solution {
public:
    bool canAliceWin(int n) {
        int stones = n;
        int turn = 10;

        while (stones >= turn) {
            stones -= turn;
            turn--;

            if (turn == 0) break;
            
            // Switch turns automatically
        }

        return (10 - turn) % 2 == 1;
    }
};
