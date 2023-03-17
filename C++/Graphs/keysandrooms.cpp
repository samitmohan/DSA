// https://leetcode.com/problems/keys-and-rooms/
// simple dfs

class Solution {
public:
  void dfs(int start, vector<vector<int>> &rooms, vector<bool> &visited) {
    visited[start] = true; // 0
    for (int i : rooms[start]) {
      if (!visited[i]) {
        // visit it recursively
        dfs(i, rooms, visited);
      }
    }
  }

  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, 0);

    dfs(0, rooms, visited); // dfs starting from 0
    // check if all rooms are visited or nto
    for (bool i : visited) {
      if (!i)  return false;
    }
    return true;
  }
};
