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
// stack implementation using array.
// one of the application : convert number in binary.

const int N = 100010;

int stk[N], sz;

inline void push(int val) {
  stk[sz] = val;
  sz++;
}

inline int top() {
  if (sz > 0) {
    return stk[sz - 1];
  }
  return -1;
}

inline void pop() {
  if (sz > 0) {
    sz--;
  }
}

inline bool isEmpty() {
  return (sz <= 0);
}

char s[N];

// here find longest valid substring.
int main() {
  scanf("%s", s);
  int len = strlen(s);
  push(-1); // for getting length of valid substring for base.
  int ans = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '(') {
      push(i);
    } else if (s[i] == ')') {
      pop();
      if (isEmpty()) {
        push(i);
      } else {
        ans = max(ans, i - top());
      }
    }
  }
  printf("%d\n", ans);
}

