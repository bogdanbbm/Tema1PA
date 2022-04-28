#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Task{
 public:
    int N;
    vector<string> words;
    int answear;

    void read_input() {
        ifstream fin("statistics.in");

        fin >> N;

        for (int i = 1; i <= N; i++) {
            string auxWord;
            fin >> auxWord;
            words.push_back(auxWord);
        }

        fin.close();
    }

    void get_result() {
        int ans, sum, net_freq;
        answear = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            vector<int> dominance;

            for (int i = 0; i < words.size(); i++) {
                string s = words[i];
                net_freq = 0;

                for (char x : s) {
                    if (x == ch)
                        net_freq++;
                    else
                        net_freq--;
                }
                dominance.push_back(net_freq);
            }

            sort(dominance.begin(), dominance.end(), greater<int>());

            ans = 0;
            sum = 0;
            for (int x : dominance) {
                sum += x;
                if (sum > 0) {
                    ans++;
                }
            }
            answear = max(answear, ans);
        }
    }

    void print_output() {
        ofstream fout("statistics.out");
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
