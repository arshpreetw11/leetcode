class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n=restaurants.size();
        vector<vector<int>> valid;
        for(int i=0;i<n;i++){
            int rating=restaurants[i][1];
            int vegan=restaurants[i][2];
            int price=restaurants[i][3];
            int dist=restaurants[i][4];

            if(veganFriendly && vegan==0){
                continue;
            }
            if(price<=maxPrice && dist<=maxDistance){
                valid.push_back(restaurants[i]);
            }
        }
        sort(valid.begin(),valid.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]==b[1])
            return a[0]>b[0];
            return a[1]>b[1];
        });
        vector<int> idx;
        for(auto & it :valid){
            idx.push_back(it[0]);
        }
        return idx;

        
    }
};