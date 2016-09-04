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

struct Node {
  char c;
  Node *l, *r, *eq;
  bool is_end;

  Node(char ch = '0') : l(NULL), r(NULL), eq(NULL), c(ch), is_end(false) {}
};

typedef Node* pnode;

inline void add(pnode &root, const char *s) {
  if (root == NULL) {
    root = new Node(s[0]);
  }
  if (root->c < s[0]) {
    add(root->l, s);
  } else if (root->c > s[0]) {
    add(root->r, s);
  } else {
    if (s[0] == 0) {
      root->is_end = true;
    } else {
      add(root->eq, s + 1);
    }
  }
}

inline bool check(pnode &root, const char *s) {
  if (root == NULL) {
    return false;
  }
  if (root->c < s[0]) {
    return check(root->l, s);
  }
  if (root->c > s[0]) {
    return check(root->r, s);
  }
  if (s[0] == 0) {
    return root->is_end;
  }
  return check(root->eq, s + 1);
}

int main() {
  int q;
  scanf("%d", &q);
  pnode root = NULL;
  while (q--) {
    int cmd;
    string z;
    cin >> cmd >> z;
    if (cmd == 1) { // add
      add(root, z.c_str());
    } else { // check
      if (check(root, z.c_str())) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
}

