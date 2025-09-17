class FoodRatings {
public:
struct cmp {
    bool operator()(const pair<int,string> &a, const pair<int,string> &b) const {
        if (a.first != b.first) return a.first < b.first;  // sort by int ascending
        return a.second > b.second;  // if int same, reverse lexicographic
    }
};
    // set<pair<int,string>,cmp> st;
    unordered_map<string,set<pair<int,string>,cmp>> mp;
    unordered_map<string,int> rt;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            mp[cuisines[i]].insert({ratings[i], foods[i]});
            rt[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        pair<int,string> pr = {rt[food], food};
        for(auto& it : mp){
            if(it.second.count(pr)){
                // cout << food << endl;
                it.second.erase(pr);
                it.second.insert({newRating,food});
                rt[food] = newRating;
                break;
            }
        }
    }
    
    string highestRated(string cuisine) {
        auto lr = *mp[cuisine].rbegin();
        
        return lr.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */