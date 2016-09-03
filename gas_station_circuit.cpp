#include <cstdio>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <list>
#include <set>
#include <map>

using namespace std;
// here we have to find first station to complete the tour.
// gas[i] = amount of gas available at i th station.
// cost[i] = gas cost required to go to i + 1 th from i th station.

const int N = 100010;

int gas[N], cost[N];

// will return any of the index from where we have to start.
int canCompleteCircuit(int n) {
  int s = n - 1, e = 0;
  int cur_gas = gas[s] - cost[s];
  while (s > e) {
    if (cur_gas >= 0) {
      cur_gas += (gas[e] - cost[e]);
      e++;
    } else {
      s--;
      cur_gas += (gas[s] - cost[s]);
    }
  }
  return (cur_gas >= 0) ? s : -1;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", gas + i, cost + i);
  }
  int ans = canCompleteCircuit(n);
  printf("%d\n", ans);
}

