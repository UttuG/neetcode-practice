class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courses;

        // initialize all courses
        for (int i = 0; i < numCourses; i++) courses[i] = {};

        // fill in prerequisites
        for (auto &pair : prerequisites) {   // loop variable is 'pair'
            int course = pair[0];            // first element
            int prereq = pair[1];            // second element
            courses[course].push_back(prereq);
        }

        while (!courses.empty()) { 
            set<int> removed;

            // find courses with no prerequisites
            for (auto &p : courses) {
                if (p.second.empty()) removed.insert(p.first);
            }

            // if no course can be removed, cycle detected
            if (removed.empty()) return false;

            // remove courses from map
            for (int i : removed) courses.erase(i);

            // remove these courses from remaining courses' prereqs
            for (auto &p : courses) {
                vector<int> newPrereqs;
                for (int prereq : p.second) {
                    if (!removed.count(prereq)) newPrereqs.push_back(prereq);
                }
                p.second = newPrereqs;
            }
        }

        return true;
    }
};
