/*
Greedy Algorithms:

Greedy algorithms are a problem-solving paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most immediate benefit or optimal solution at the current step. These algorithms do not reconsider the choices made previously, which makes them efficient in terms of time complexity.

Why use Greedy Algorithms:
    1. Simplicity: They are easy to understand and implement.
    2. Efficiency: They often provide optimal or near-optimal solutions for many problems.
    3. Applicability: They work well for optimization problems like scheduling, graph traversal, and resource allocation.

However, greedy algorithms do not always guarantee the globally optimal solution. They work best when the problem exhibits the "greedy-choice property" and "optimal substructure."

Example: Activity Selection Problem
The goal is to select the maximum number of activities that don't overlap, given their start and end times.

Time Complexity: O(n log n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

void activitySelection(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:" << endl;

    int lastEndTime = activities[0].end;
    cout << "(" << activities[0].start << ", " << activities[0].end << ")" << endl;

    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEndTime) {
            cout << "(" << activities[i].start << ", " << activities[i].end << ")" << endl;
            lastEndTime = activities[i].end;
        }
    }
}

int main() {
    vector<Activity> activities = {
        {1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 9}, {8, 9}
    };

    activitySelection(activities);

    return 0;
}