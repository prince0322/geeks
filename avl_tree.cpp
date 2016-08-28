#include<bits/stdc++.h>

using namespace std;

struct Node {
  int key, val;
  int height;
  Node *l, *r;

  Node() {}
  Node(int k, int v) : key(k), val(v), height(1), l(NULL), r(NULL) {}
};

typedef Node* pnode;

inline int getHeight(pnode root) {
  return (root) ? root->height : 0;
}

inline void updateHeight(pnode root) {
  if (root) {
    root->height = max(getHeight(root->l), getHeight(root->r)) + 1;
  }
}

inline pnode rRotate(pnode y) {
  pnode x = y->l;
  pnode t = x->r;
  x->r = y;
  y->l = t;
  updateHeight(y);
  updateHeight(x);
  return x;
}

inline pnode lRotate(pnode y) {
  pnode x = y->r;
  pnode t = x->l;
  x->l = y;
  y->r = t;
  updateHeight(y);
  updateHeight(x);
  return x;
}

inline pnode smallest(pnode root) {
  if (!root) {
    return root;
  }
  while (root->l) {
    root = root->l;
  }
  return root;
}

inline int getBalFactor(pnode root) {
  if (root) {
    return getHeight(root->l) - getHeight(root->r);
  }
  return 0;
}

// insert a key value pair. here duplicate not allow.
pnode insertNode(pnode root, int key, int val) {
  if (!root) {
    root = new Node(key, val);
    return root;
  }
  if (key < root->key) {
    root->l = insertNode(root->l, key, val);
  } else if (key > root->key) {
    root->r = insertNode(root->r, key, val);
  }
  updateHeight(root);
  int balFactor = getBalFactor(root);
  // l - l case.
  if (balFactor > 1 && key < root->l->key) {
    return rRotate(root);
  }
  // r - r case.
  if (balFactor < -1 && key > root->r->key) {
    return lRotate(root);
  }
  // l - r case.
  if (balFactor > 1 && key > root->l->key) {
    root->l = lRotate(root->l);
    return rRotate(root);
  }
  // r - l case.
  if (balFactor < -1 && key < root->r->key) {
    root->r = rRotate(root->r);
    return lRotate(root);
  }
  return root;
}

pnode deleteNode(pnode root, int key) {
  if (!root) {
    return root;
  }
  if (key < root->key) {
    root->l = deleteNode(root->l, key);
  } else if (key > root->key) {
    root->r = deleteNode(root->r, key);
  } else {
    if (!root->l || !root->r) {
      pnode x = root->l ? root->l : root->r;
      if (x) {
        *root = *x;
      } else {
        x = root;
        root = NULL;
      }
      delete(x);
    } else { // l and r both exist.
      pnode x = smallest(root->r);
      root->key = x->key;
      root->val = x->val;
      deleteNode(root->r, x->key);
    }
  }
  if (!root) { // tree containing only one node.
    return root;
  }
  updateHeight(root);
  int balFactor = getBalFactor(root);
  // l - l case.
  if (balFactor > 1 && key < root->l->key) {
    return rRotate(root);
  }
  // r - r case.
  if (balFactor < -1 && key > root->r->key) {
    return lRotate(root);
  }
  // l - r case.
  if (balFactor > 1 && key > root->l->key) {
    root->l = lRotate(root->l);
    return rRotate(root);
  }
  // r - l case.
  if (balFactor < -1 && key < root->r->key) {
    root->r = rRotate(root->r);
    return lRotate(root);
  }
  return root;
}

vector <int> ans;

inline void walk(pnode root) {
  if (root) {
    walk(root->l);
    //printf("(%d %d) ", root->key, root->val);
    ans.push_back(root->key);
    walk(root->r);
  }
}

int main() {
  pnode root = NULL;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = insertNode(root, x, -1);
  }
  walk(root);
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d\n", ans[i]);
  }
}







