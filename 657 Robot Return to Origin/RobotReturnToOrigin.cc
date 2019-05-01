class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;
        for (char move: moves) {
            if (move == 'D') vertical--;
            else if (move == 'U') vertical++;
            else if (move == 'L') horizontal--;
            else if (move == 'R') horizontal++;
        }
        return !vertical && !horizontal;
    }
};