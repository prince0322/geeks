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
// bucket sort.
// generally used when numbers are uniformly distributed.
// divide into bucket on the basis of lower bound.
// use insertion sort to sort each bucket. O(n) practically.

const int N = 10010;

int a[N];

vector<int> buc[N];

inline int h(int val, int n) {
  return (val / n);
}

void insertionSort(int ii) {
  for(int i = 1; i < (int)buc[ii].size(); i++) {
    int x = buc[ii][i], j = i - 1;
    while(j >= 0 && buc[ii][j] >= x) {
      buc[ii][j + 1] = buc[ii][j];
      j--;
    }
    buc[ii][j + 1] = x;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    buc[h(a[i], n)].push_back(a[i]);
  }
  for(int i = 0; i < n; i++) {
    if(buc[i].size() > 1) insertionSort(i);
  }
  int e = 0;
  for(int i = 0; i < n; i++) {
    if(buc[i].size() > 0) {
      for(int j = 0; j < (int)buc[i].size(); j++) {
        a[e++] = buc[i][j];
      }
    }
  }
  for(int i = 0; i < e; i++) {
    printf("%d ", a[i]);
  }
}

