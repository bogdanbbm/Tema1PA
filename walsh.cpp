#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct Pair {
    int x;
    int y;
};

class Task{
 public:
    int N;
    int K;
    vector <Pair> pairs;
    vector<int> sol;

    void read_input() {
        ifstream fin("walsh.in");
        fin >> N;
        fin >> K;
        for (int i = 1; i <= K; i++) {
            Pair auxPair;
            fin >> auxPair.x;
            fin >> auxPair.y;
            pairs.push_back(auxPair);
        }
    }

    void get_result() {
        int x, y, mid, nCopy, res;
        for (Pair pair : pairs) {
            res = 0;
            x = pair.x;
            y = pair.y;
            mid = N / 2;
            nCopy = N;

            while (1) {
                if (nCopy == 1) {
                    sol.push_back(res);
                    break;
                }

                if (x <= mid && y <= mid) {
                    nCopy /= 2;
                    mid = nCopy / 2;
                } else if (x > mid && y <= mid) {
                    x -= mid;
                    nCopy /= 2;
                    mid = nCopy / 2;
                } else if (x <= mid && y > mid) {
                    y -= mid;
                    nCopy /= 2;
                    mid = nCopy / 2;
                } else if (x > mid && y > mid) {
                    x -= mid;
                    y -= mid;

                    res = !res;

                    nCopy /= 2;
                    mid = nCopy / 2;
                }
            }
        }
    }

    void print_output() {
        ofstream fout("walsh.out");

        for (int i = 0; i < sol.size(); i++) {
            fout << sol[i] << endl;
        }

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
