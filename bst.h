#ifndef bst_included      // prevent multiple inclusions
#define bst_included

// a binary search tree node
typedef struct bstItem_s {
  struct bstItem_s *l_child;
  struct bstItem_s *r_child;
  char *str;
} bstNode;

// create a new binary search tree
bstNode *bstAlloc();

// free mem associated with a bst, discarding all items it contains
void bstFree(bstNode *bstP);

// append a copy of str to bst
bstNode *bstInsert(bstNode *bstP,char *s);

// print bst inorder
void bstPrintInOrder(bstNode *bstP);

// print bst post-order
void bstPrintPostOrder(bstNode *bstP);

// print bst pre-order
void bstPrintPreOrder(bstNode *bstP);

// remove bstNode
bstNode *bstRemoveNode(bstNode *bstP, char *s);

// find the smallest node in a tree (right tree for bstRemoveNode)
bstNode *bstFindSmallest(bstNode *bstP);

#endif   /* included */
