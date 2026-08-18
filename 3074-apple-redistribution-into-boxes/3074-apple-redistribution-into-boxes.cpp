class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        sort(capacity.rbegin(),capacity.rend());
        int total=0;
        for(int x: apple){
            total+=x;
        }
        int i=0,boxes=0;
        while(total>0){
            total-=capacity[i];
            i++;
            boxes++;
        }
        return boxes;
    }
};