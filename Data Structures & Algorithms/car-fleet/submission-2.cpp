class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = 1;
        int n = position.size();
        vector<pair<int,int>> cars;

        for(int i = 0; i < n; i++) { 
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        
        double t1 = (double)(target - cars[0].first) / cars[0].second;
        for(int i = 1; i < n; i++) {
            double t2 = (double)(target - cars[i].first) / cars[i].second;
            if(t2 > t1) {
                fleets++;
                t1 = t2;
            }
        }
        return fleets;
    }
};
