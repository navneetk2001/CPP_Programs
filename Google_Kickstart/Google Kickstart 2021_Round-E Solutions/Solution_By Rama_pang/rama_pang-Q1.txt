#include <bits/stdc++.h>
using namespace std;

void Main() {
  string S;
  cin >> S;
  map<char, int> cnt;
  for (auto i : S) cnt[i]++;
  int mx = 0;
  for (auto i : cnt) mx = max(mx, i.second);
  if (mx > int(S.size()) - mx) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  int n = S.size();
  vector<pair<char, int>> pos;
  for (int i = 0; i < n; i++) {
    pos.emplace_back(S[i], i);
  }
  sort(begin(pos), end(pos));
  for (int i = 0; i < n; i++) {
    S[pos[(i + mx) % n].second] = pos[i].first;
  }
  cout << S << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    Main();
  }
  return 0;
}
