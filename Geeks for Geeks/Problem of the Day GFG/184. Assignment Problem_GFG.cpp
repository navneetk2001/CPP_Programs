// You are the head of a firm and you have to assign jobs to people. You have N persons working under you and you have N jobs that are to be done by these persons. Each person has to do exactly one job and each job has to be done by exactly one person. Each person has his own capability (in terms of time taken) to do any particular job. Your task is to assign the jobs to the persons in such a way that the total time taken is minimum. A job can be assigned to only one person and a person can do only one job.

// Example 1:
// Input:
// N = 2
// Arr[] = {3, 5, 10, 1}
// Output: 4
// Explanation: The first person takes times 3 and 5 for jobs 1 and 2 respectively. The second person takes times 10 and 1 for jobs 1 and 2 respectively. We can see that the optimal assignment will be to give job 1 to person 1 and job 2 to person 2 for a total for 3+1 = 4.

// Example 2:
// Input:
// N = 3
// Arr[] = {2, 1, 2, 9, 8, 1, 1, 1, 1}
// Output: 3 
// Explanation: The optimal arrangement would be to assign job 1 to person 2,job 2 to person 3 and job 3 to person 1.





//Solution Approach :-
#include <bits/stdc++.h>
using namespace std;

namespace std {
template <>
struct hash<pair<short, short>> {
    size_t operator()(pair<short, short> const& v) const
    {
        hash<short> h{};
        return h(v.first) ^ h(v.second);
    }
};
}

static auto f = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return true;
}();

vector<vector<char>> labor;
vector<vector<char>> original_labor;

short n;

void phase1(){
    for (short i = 0; i < n; ++i) {
        auto min_ = numeric_limits<char>::max();
        for (short j = 0; j < n; ++j) {
            min_ = min(min_, labor[i][j]);
        }
        for (short j = 0; j < n; ++j) {
            labor[i][j] -= min_;
        }
    }
}

void phase2(){
    for (short j = 0; j < n; ++j) {
        auto min_ = numeric_limits<char>::max();
        for (short i = 0; i < n; ++i) {
            min_ = min(min_, labor[i][j]);
        }
        for (short i = 0; i < n; ++i) {
            labor[i][j] -= min_;
        }
    }
}

int step3(unordered_set<pair<short, short>>& selected, unordered_set<short>& sel_rows, unordered_set<short>& sel_cols){
    selected.clear();
    sel_rows.clear();
    sel_cols.clear();
    bool changed = false;
    do {
        changed = false;
        for (short i = 0; i < n; ++i) {
            bool skip_row = false;
            for (short j = 0; j < n && !skip_row; ++j) {
                if (labor[i][j] == 0 && sel_cols.find(j) == sel_cols.end() && sel_rows.find(i) == sel_rows.end()) {
                    for (short k = j + 1; k < n; ++k) {
                        if (labor[i][k] == 0 && sel_cols.find(k) == sel_cols.end()) {
                            skip_row = true;
                            break;
                        }
                    }
                    if (skip_row) {
                        break;
                    }

                    sel_cols.insert(j);
                    selected.insert(make_pair(i, j));
                    changed = true;
                    break;
                }
            }
        }

        for (short j = 0; j < n; ++j) {
            bool skip_col = false;
            for (short i = 0; i < n && !skip_col; ++i) {
                if (labor[i][j] == 0 && sel_cols.find(j) == sel_cols.end() && sel_rows.find(i) == sel_rows.end()) {
                    for (short k = i + 1; k < n; ++k) {
                        if (labor[k][j] == 0 && sel_rows.find(k) == sel_rows.end()) {
                            skip_col = true;
                            break;
                        }
                    }
                    if (skip_col) {
                        break;
                    }

                    sel_rows.insert(i);
                    selected.insert(make_pair(i, j));
                    changed = true;
                    break;
                }
            }
        }

    } while (changed);

    for (short i = 0; i < n; ++i) {
        if (sel_rows.find(i) != sel_rows.end()) {
            continue;
        }
        bool skip_row = false;
        for (short j = 0; j < n && !skip_row; ++j) {
            if (labor[i][j] == 0 && sel_cols.find(j) == sel_cols.end()) {
                int zeros_in_row = 0;
                for (short k = j + 1; k < n; ++k) {
                    if (labor[i][k] == 0 && sel_cols.find(k) == sel_cols.end()) {
                        zeros_in_row += 1;
                    }
                }
                short zeros_in_col = 0;
                for (short k = i + 1; k < n; ++k) {
                    if (labor[k][j] == 0 && sel_rows.find(k) == sel_rows.end()) {
                        zeros_in_col += 1;
                    }
                }
                if (zeros_in_col >= zeros_in_row) {
                    sel_cols.insert(j);
                } else {
                    sel_rows.insert(i);
                }
                selected.insert(make_pair(i, j));
                skip_row = true;
                changed = true;
                break;
            }
        }
    }

    for (short j = 0; j < n; ++j) {
        if (sel_cols.find(j) != sel_cols.end()) {
            continue;
        }
        bool skip_col = false;
        for (short i = 0; i < n && !skip_col; ++i) {
            if (labor[i][j] == 0 && sel_rows.find(i) == sel_rows.end()) {
                int zeros_in_row = 0;
                for (short k = j + 1; k < n; ++k) {
                    if (labor[i][k] == 0 && sel_cols.find(k) == sel_cols.end()) {
                        zeros_in_row += 1;
                    }
                }
                int zeros_in_col = 0;
                for (short k = i + 1; k < n; ++k) {
                    if (labor[k][j] == 0 && sel_rows.find(k) == sel_rows.end()) {
                        zeros_in_col += 1;
                    }
                }
                if (zeros_in_col >= zeros_in_row) {
                    sel_cols.insert(j);
                } else {
                    sel_rows.insert(i);
                }
                selected.insert(make_pair(i, j));
                skip_col = true;
                changed = true;
                break;
            }
        }
    }

    return selected.size();
}

int phase4(short selected_from_phase3, unordered_set<pair<short, short>>& selected)
{
    /* test for optimality and return total amount of labor if an optimum is found */
    if (n != selected_from_phase3) {
        return -1;
    }

    int sum = 0;

    for (auto& s : selected) {
        sum += original_labor[s.first][s.second];
    }

    return sum;
}

void phase5(unordered_set<short>& sel_rows, unordered_set<short>& sel_cols)
{
    /* we end up in this phase if there are not enough selected rows/columns during the phase3 */

    auto min_ = numeric_limits<char>::max();
    for (short i = 0; i < n; ++i) {
        if (sel_rows.find(i) != sel_rows.end()) {
            continue;
        }
        for (short j = 0; j < n; ++j) {
            if (sel_cols.find(j) != sel_cols.end()) {
                continue;
            }
            min_ = min(min_, labor[i][j]);
        }
    }

    for (short i = 0; i < n; ++i) {
        if (sel_rows.find(i) != sel_rows.end()) {
            continue;
        }
        for (short j = 0; j < n; ++j) {
            labor[i][j] -= min_;
        }
    }

    for (short j = 0; j < n; ++j) {
        if (sel_cols.find(j) == sel_cols.end()) {
            continue;
        }
        for (short i = 0; i < n; ++i) {
            labor[i][j] += min_;
        }
    }
}

int solve()
{
    original_labor = labor;
    phase1();
    phase2();

    unordered_set<pair<short, short>> selected;
    unordered_set<short> sel_rows;
    unordered_set<short> sel_cols;
    int sels = step3(selected, sel_rows, sel_cols);

    int sum = phase4(sels, selected);
    while (sum == -1) {
        selected.clear();
        phase5(sel_rows, sel_cols);
        sels = step3(selected, sel_rows, sel_cols);
        sum = phase4(sels, selected);
    }

    return sum;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        labor.clear();
        cin >> n;
        labor.resize(n);
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                int v;
                cin >> v;
                labor[j].push_back(v);
            }
        }
        cout << solve() << "\n";
    }
    return 0;
}
