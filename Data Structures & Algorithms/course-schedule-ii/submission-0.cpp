class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courses;

        // initialize all courses with empty prereq list
        for (int i = 0; i < numCourses; i++) courses[i] = {};

        // fill in prerequisites
        for (auto &pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            courses[course].push_back(prereq);
        }

        vector<int> result;

        while (!courses.empty()) {
            vector<int> removed;

            // find courses with no prerequisites
            for (auto &p : courses) {
                if (p.second.empty()) removed.push_back(p.first);
            }

            // if no course can be removed, there's a cycle
            if (removed.empty()) return {};

            // add removed courses to the result in this round
            result.insert(result.end(), removed.begin(), removed.end());

            // remove courses from the map
            for (int i : removed) courses.erase(i);

            // remove these courses from remaining courses' prereqs
            for (auto &p : courses) {
                vector<int> newPrereqs;
                for (int prereq : p.second) {
                    if (find(removed.begin(), removed.end(), prereq) == removed.end()) {
                        newPrereqs.push_back(prereq);
                    }
                }
                p.second = newPrereqs;
            }
        }

        return result;
    }
};
