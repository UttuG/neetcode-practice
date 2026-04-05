/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
     [](const Interval& a, const Interval& b) {
         return a.start < b.start;
     });

        priority_queue<int,vector<int>,greater<int>> heap; 

        for (Interval i: intervals){
                if(heap.empty()){
                    heap.push(i.end);
                    continue;
                }
                if(heap.top()>i.start){
                    //the earliest ending room is also still busy
                    heap.push(i.end);
                }
                else{
                    heap.pop();
                    heap.push(i.end);
                }
            
        }
        return heap.size();
        
    }
};
