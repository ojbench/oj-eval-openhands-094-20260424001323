
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

struct Center {
    int r, c;
    int val;
};

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> g(m, vector<int>(n));
    vector<Center> centers;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            centers.push_back({3 * i + 1, 3 * j + 1, g[i][j]});
        }
    }

    for (int r = 0; r < 3 * m; ++r) {
        for (int c = 0; c < 3 * n; ++c) {
            bool is_center = false;
            int center_val = 0;
            vector<int> v_a, v_b;

            for (const auto& center : centers) {
                int dist = abs(r - center.r) + abs(c - center.c);
                if (dist == 0) {
                    is_center = true;
                    center_val = center.val;
                    break;
                } else if (dist == 1) {
                    v_a.push_back(center.val);
                } else if (dist == 2) {
                    v_b.push_back(center.val);
                }
            }

            int result = 0;
            if (is_center) {
                result = center_val;
            } else {
                double avg_a = 0, avg_b = 0;
                if (!v_a.empty()) {
                    double sum = 0;
                    for (int v : v_a) sum += v;
                    avg_a = sum / v_a.size();
                }
                if (!v_b.empty()) {
                    double sum = 0;
                    for (int v : v_b) sum += v;
                    avg_b = sum / v_b.size();
                }

                if (v_a.empty() && !v_b.empty()) {
                    result = (int)floor(avg_b);
                } else if (!v_a.empty() && v_b.empty()) {
                    result = (int)floor(avg_a);
                } else if (!v_a.empty() && !v_b.empty()) {
                    result = (int)floor(avg_a * 0.8 + avg_b * 0.2 + 1e-9);
                }
            }
            cout << result << " ";
        }
        cout << endl;
    }

    return 0;
}
