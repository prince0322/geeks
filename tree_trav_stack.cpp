typedef TreeNode* pnode;

// In order traversal using stack.
inline void inorder(pnode root) {
  stack <pnode> stk;
  bool all_traversed = false;
  while (!all_traversed) {
    while (root) {
      stk.push(root);
      root = root->left;
    }
    if (!stk.empty()) {
      root = stk.top();
      stk.pop();
      // do something with data.
      root = root->right;
    } else {
      all_traversed = false;
    }
  }
}

// PRE order traversal using stack.
// also POST order can also obtained by
// just reversing the some modified PRE order.
inline void preorder(pnode root) {
  stack <pnode> stk;
  stk.push(root);
  while (!stk.empty()) {
    root = stk.top();
    stk.pop();
    while (root) {
      // do something with data.
      if (root->right) {
        stk.push(root->right);
      }
      root = root->left;
    }
  }
}




