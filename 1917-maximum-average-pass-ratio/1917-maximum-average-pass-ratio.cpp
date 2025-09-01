class Solution {
public:

    double diff(int i, int j){
        return (double)(i+1)/(j+1) - (double)i/j;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double,int,int>> pq;
        for(auto it : classes){
            int i = it[0], j = it[1];
            pq.push({diff(i,j), i, j});
        }

        double sum = 0.0;
        while(extraStudents--){
            auto [a,b,c] = pq.top();
            pq.pop();
            b++;c++;
            pq.push({diff(b,c),b,c});
        }

        while(!pq.empty()){
            auto [a,b,c] = pq.top();
            pq.pop();
            sum += (double)b/c;
        }
        return sum/classes.size();
    }
};