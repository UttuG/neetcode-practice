class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // the approach for this is 2 pointer

        //for this i will maintain a pointer for left and right
        // and a set to maintain all of the seen characters

        int l = 0;
        int r = 0;
        unordered_set<int> set_s;
        int max_length =0 ;

        //the looping condition:
            // once the right pointer hits length of the string, the max_length can't increase

        //base case
        if (s.length()==0){
            return 0;
        }
        while(r<s.length()){
            //check the current index of r and see if in the set
            if(set_s.count(s[r])){
                //this means that this value was in the set
                //continue code to update the l pointer
                while(s[l]!=s[r]){ //while the character for r and l don't match
                    //remove the character from set
                    set_s.erase(s[l]);
                    //increment l
                    l++;
                }
                l++; //now that we have found the index which overlapped in value with r, we can safely increment
                // l so the the substring from l to r is not overlapping
            }
            else{
                set_s.insert(s[r]);
                max_length = max((r-l+1),max_length);
            }

            //increment r
            r++;
        }
        return max_length;
    }
};
