/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    enum EventType {
        JOINING,
        LEAVING
    };
    struct Event {
        int       id;
        int       time;
        EventType type;
    };
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Event> events;
        int j = 0;
        for (const auto& v : schedule) {
            for (int i = 0; i < v.size(); ++i) {
                events.push_back({j, v[i].start, EventType::JOINING});
                events.push_back({j, v[i].end, EventType::LEAVING});
            }
            j += 1;
        }
        auto compare = [](const Event& x, const Event& y) -> bool {
            if (x.time == y.time) {
                return x.type < y.type;
            }
            return x.time < y.time;
        };
        sort(events.begin(), events.end(), compare);
        Interval i(-1, -1);
        vector<Interval> freeTime;
        unordered_set<int> working;
        for (const auto& e : events) {
            if (e.type == EventType::JOINING) {
                if (working.size() == 0 && i.start != -1) {
                    i.end = e.time;
                    freeTime.push_back(i);
                }
                working.insert(e.id);
            }
            else {
                working.erase(e.id);
            }
            if (working.size() == 0) {
                i.start = e.time;
            }
        }
        return freeTime; 
    }
};