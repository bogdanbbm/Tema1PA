#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct Object {
    int weight;
    int price;

    Object(int _weight, int _price)
        : weight(_weight)
        , price(_price) { }
};

class Task{
 public:
    int N, K;
    vector<int> target;
    vector<int> p;

    vector<int> operations;
    int answear;

    void read_input() {
        ifstream fin("prinel.in");
        fin >> N >> K;

        int auxNumber;
        for (int i = 1; i <= N; i++) {
            fin >> auxNumber;
            target.push_back(auxNumber);
        }

        p.push_back(0);
        for (int i = 1; i <= N; i++) {
            fin >> auxNumber;
            p.push_back(auxNumber);
        }

        fin.close();
    }

    void get_max_points() {
        vector<int>v(K + 1);
        int sol = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = K - operations[i]; j >= 0; j--) {
                if (v[j + operations[i]] < v[j] + p[i]) {
                    v[j + operations[i]] = v[j] + p[i];

                    if (v[j + operations[i]] > sol)
                        sol = v[j + operations[i]];
                }
            }
        }

        answear = sol;
    }

    void get_result() {
        int max = *max_element(target.begin(), target.end());

        vector<int> dp(max + 1);
        for (int i = 1; i <= max; i++) {
            dp[i] = INT_MAX;
        }

        dp[1] = 0;
        for (int i = 1; i <= max; i++) {
            if (dp[i] == INT_MAX) {
                continue;
            }
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if (i + j <= max) {
                        dp[i + j] = min(dp[i + j], dp[i] + 1);
                    }
                    if (i + i / j <= max) {
                        dp[i + i / j]
                            = min(dp[i + i / j], dp[i] + 1);
                    }
                }
            }
        }
        operations.push_back(0);
        for (int x : target) {
            operations.push_back(dp[x]);
        }

        get_max_points();
    }

    void print_output() {
        ofstream fout("prinel.out");
        fout << answear;
        fout.close();
    }

    void solve() {
        read_input();
        get_result();
        print_output();
    }
};

int main() {
    auto *task = new (nothrow) Task();

    task->solve();
    delete task;

    return 0;
}
