#include <bits/stdc++.h>
using namespace std;

struct OfflineUser {
  int returnTimestamp;
  int userId;
  bool operator>(const OfflineUser& other) const {
    return returnTimestamp > other.returnTimestamp;
  }
};

class Solution {
public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<int> ans(numberOfUsers, 0);
    vector<int> online(numberOfUsers, 1); // 1 == online, 0 == offline

    // min-heap for offline users returning (by returnTimestamp)
    priority_queue<OfflineUser, vector<OfflineUser>, greater<>> offlineQueue;
    int allMentionsCount = 0;

    // sort by timestamp, and if tie, ensure MESSAGE (lexicographically earlier) are processed first
    sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
      int ta = stoi(a[1]), tb = stoi(b[1]);
      if (ta != tb) return ta < tb;
      // tie-breaker: reverse order by event type so "MESSAGE" comes before "OFFLINE"
      return a[0] > b[0];
    });

    for (const auto& event : events) {
      const string& eventType = event[0];
      int timestamp = stoi(event[1]);

      // Bring users back online whose return time has come
      while (!offlineQueue.empty() && offlineQueue.top().returnTimestamp <= timestamp) {
        online[offlineQueue.top().userId] = 1;
        offlineQueue.pop();
      }

      if (eventType == "MESSAGE") {
        const string& mentionsString = event[2];
        if (mentionsString == "ALL") {
          ++allMentionsCount;
        } else if (mentionsString == "HERE") {
          for (int u = 0; u < numberOfUsers; ++u)
            if (online[u]) ++ans[u];
        } else {
          // mentionsString is like "id0 id5 id3" etc.
          istringstream iss(mentionsString);
          string token;
          while (iss >> token) {
            // token format "id<number>"
            if (token.size() > 2 && token.rfind("id", 0) == 0) {
              int uid = stoi(token.substr(2));
              if (0 <= uid && uid < numberOfUsers) ++ans[uid];
            }
          }
        }
      } else if (eventType == "OFFLINE") {
        int userId = stoi(event[2]);
        if (0 <= userId && userId < numberOfUsers) {
          online[userId] = 0;
          offlineQueue.push({timestamp + 60, userId});
        }
      }
    }

    // add global ALL mentions to every user
    for (int u = 0; u < numberOfUsers; ++u) ans[u] += allMentionsCount;
    return ans;
  }
};
