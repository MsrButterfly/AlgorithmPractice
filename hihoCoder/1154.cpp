// http://hihocoder.com/problemset/problem/1154
// http://hihocoder.com/contest/mstest2015april2/problem/3

#include <cstdint>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <string>
#include <tuple>
#include <typeindex>
#include <typeinfo>
#include <type_traits>
#include <utility>

using namespace std;

using uint_t = unsigned int;

uint_t nk[1000][1001];

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("1154.in");
    cin.rdbuf(fin.rdbuf());
#endif
    uint_t N, K;
    cin >> N >> K;
    for (uint_t i = 0; i < N; ++i) {
        for (uint_t j = 0; j <= K; ++j) {
            uint_t p;
            cin >> p;
            nk[i][p] = j;
        }
    }
    uint_t last = 0, now = K;
    while (true) {
        uint_t last_c = 0, now_c = 0;
        for (uint_t j = 0; j < N; ++j) {
            if (nk[j][last] < nk[j][now]) {
                ++last_c;
            } else {
                ++now_c;
            }
        }
        if (last_c < now_c) {
            last = now;
        }
        if (--now == 0) {
            break;
        }
    }
    if (last != 0) {
        cout << last << endl;
    } else {
        cout << "otaku" << endl;
    }
    return EXIT_SUCCESS;
}
