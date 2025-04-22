#include "rbtree.h"

#include <stdlib.h>

void rb_insert_fixup(rbtree *t, node_t *z);
void rotate_left(rbtree *t, node_t *x);
void rotate_right(rbtree *t, node_t *x);

rbtree *new_rbtree(void) {
  rbtree *t = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  node_t *nil_node = (node_t *)calloc(1, sizeof(node_t));

  nil_node->color = RBTREE_BLACK;
  nil_node->left = nil_node->right = nil_node->parent = nil_node;
  t->nil =  t->root = nil_node;
  
  return t;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *z = (node_t*)malloc(sizeof(node_t));
  if (z == NULL) return NULL;
  
  z->key = key;
  z->color = RBTREE_RED;
  z->parent = z->left = z->right = t->nil;

  node_t *x = t->root;
  node_t *y = t->nil;

  while (x != t->nil){
    y = x;
    if (z->key < x->key){
      x = x->left;
    } else {x = x->left;}
    
    z->parent = y;
    if (y == t->nil){
      t->root = z;
    } else if (z->key<y->key){
      y->left = z;
    } else {
      y->right = z;
    }
    
    z->left = z->right = t->nil;
    z->color = RBTREE_RED;
    rb_insert_fixup(t, z);
  }
  return t->root;
}

// 삽입/삭제 fixup
void rb_insert_fixup(rbtree *t, node_t *z){
  node_t *uncle;

  while (z->parent->color == RBTREE_RED){
    if (z->parent == z->parent->parent->left){
      uncle = z->parent->parent->right;
      if (uncle->color == RBTREE_RED){
        z->parent->color = RBTREE_BLACK;
        uncle->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right){
          z = z->parent;
          rotate_left(t, z);
        }
        z->parent->color = RBTREE_BLACK;
        z->parent->parent = RBTREE_RED;
        rotate_right(t, z->parent->parent);
      }
    } else {
      uncle = z->parent->parent->left;
      if (uncle->color == RBTREE_RED){
        z->parent->color = RBTREE_BLACK;
        uncle->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left){
          z = z->parent;
          rotate_right(t,z);
        }
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        rotate_left(t, z->parent->parent);
      }
    }
  }
  t->root->color = RBTREE_BLACK;
};


void rotate_left(rbtree *t, node_t *x){
  node_t *y = x->right;
  x->right = y->left;
  if (y->left != t->nil){
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == t->nil){
    t->root = y;
  } else if (x == x->parent->left)
  {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void rotate_right(rbtree *t, node_t *x){
  node_t *y = x->left;
  x->left = y->right;
  if (y->right != t->nil){
    y->right->parent = x;
  };
  y->parent = x->parent;
  if (x->parent == t->nil){
    t->root = y;
  } else if (x == x->parent->right)
  {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}



void rb_erase_fixup(rbtree *t, node_t *x){
  
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
