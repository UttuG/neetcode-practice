class TimeMap {
public:

    unordered_map<string,vector<pair<int,string>>> mapping;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        //edge case if the key is not set in mapping
        if(mapping.count(key)==0){
            return "";
        }

        //there is some confusion between the index of timestep and the val of timestep here
        int l =0;
        int r = mapping[key].size()-1;
        
        //edge cases:
        //if timestamp is smaller than l:
        if (timestamp<mapping[key][l].first){
            return "";
        }
        int valid_tp = l;
        while(l<=r){
            int mid = (l+r)/2;
            if(mapping[key][mid].first == timestamp){
                return mapping[key][mid].second;
            }
            if(mapping[key][mid].first < timestamp){
                //update the valid_tp
                valid_tp = max(mid,valid_tp);
                l = mid+1;
            }
            if (mapping[key][mid].first > timestamp){
                r = mid -1;
            }
        }
        return mapping[key][valid_tp].second;
    }
};
