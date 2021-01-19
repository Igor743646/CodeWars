#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string back(const vector<vector<int>> &table, const string& x, const string& y, size_t i, size_t j) {
    if (i == 0 or j == 0) {
        return "";
    }
    if (x[i-1] == y[j-1]) {
        return back(table, x, y, i-1, j-1) + x[i-1];
    }
    if (table[i][j-1] > table[i-1][j]) {
        return back(table, x, y, i, j-1);
    }
    return back(table, x, y, i-1, j);
}

string lcs(const string& x, const string& y) {
  if (x == "" or y == "") return "";
  
  vector<vector<int>> table;
  
  for (size_t i = 0; i <= x.size(); ++i) {
      table.push_back(vector<int>());
      for (size_t j = 0; j <= y.size(); ++j) {
          table[i].push_back(0);
      }
  }
  
  for (size_t i = 1; i <= x.size(); ++i) {
      for (size_t j = 1; j <= y.size(); ++j) {
          if (x[i-1] == y[j-1]) {
            table[i][j] = table[i-1][j-1] + 1;
          } else {
            table[i][j] = max(table[i][j-1], table[i-1][j]);
          }
      }
  }
  
  return back(table, x, y, x.size(), y.size());
}
