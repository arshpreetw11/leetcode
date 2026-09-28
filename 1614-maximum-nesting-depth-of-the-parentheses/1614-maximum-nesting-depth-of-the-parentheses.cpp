class Solution {
public:
    int maxDepth(string s) {
        int current = 0, maxDepth = 0;
    
    for (char c : s) {
        if (c == '(') {
            current++;
            maxDepth = max(maxDepth, current);
        } else if (c == ')') {
            current--;
        }
    }
    
    return maxDepth;
    }
};