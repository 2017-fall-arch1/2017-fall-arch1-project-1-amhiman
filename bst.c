
#include <stdio.h>            // for puts
#include <stdlib.h>           // for malloc
#include <string.h>           // for strcmp
#include "bst.h"              // for bst operations


// Create a binary search tree
bstNode *bstAlloc()
{
  bstNode *bstP = (bstNode *)malloc(sizeof(bstNode));
  bstP->l_child = 0;
  bstP->r_child = 0;
  return bstP;
}

// delete all elements off of the bst
void bstFree(bstNode *bstP)
{
  //bstNode *current = bstP;
  if (bstP != 0)
  {
    bstFree(bstP->l_child);
    bstFree(bstP->r_child);
    free(bstP);
  }  
}

// insert a copy of str to bst
bstNode *bstInsert(bstNode *bstP, char *s)
{
  if(bstP == 0)
    {
      int len;
      char *copyOfString;

      // Compute string length
      for(len= 0; s[len]; len++)
      {
        ;
      }
   
      copyOfString = (char *)malloc(len+1);
      // copy into copyOfString
      for (len = 0; s[len]; len++)
      {
        copyOfString[len] = s[len];
      }
      copyOfString[len] = 0;    // terminate

      
      
      // create a new node, put the string in it
      bstNode *current = bstAlloc();
      current->str = copyOfString;

      bstP = current; // point to current
    }

  // bstNode was not null, find position
  if ( strcmp(s, bstP->str) < 0)  // s<current node so go left
  {
    bstP->l_child = bstInsert(bstP->l_child,s);
  }
  else if ( strcmp(s, bstP->str) > 0)  // s>current node so go right
  {
    bstP->r_child = bstInsert(bstP->r_child,s);
  }

  return bstP;
}

// print bst  in order-alphabetical
void bstPrintInOrder(bstNode *bstP)
{
  if (bstP != 0)
  {
    bstPrintInOrder(bstP->l_child);
    printf("%s \n",bstP->str);
    bstPrintInOrder(bstP->r_child);
  }
}

// print bst post- order
void bstPrintPostOrder(bstNode *bstP)
{
  if (bstP != 0)
  {
    bstPrintPostOrder(bstP->l_child);
    bstPrintPostOrder(bstP->r_child);
    printf("%s \n",bstP->str);

  }
}

// print bst pre-order
void bstPrintPreOrder(bstNode *bstP)
{
  if (bstP != 0)
  {
    printf("%s \n",bstP->str);
    bstPrintPreOrder(bstP->l_child);
    bstPrintPreOrder(bstP->r_child);
  }
}

// remove a node
bstNode* bstRemoveNode(bstNode *bstP, char *s)  //change pointers
{
  // search for the node containting s
  if (bstP == 0)
  {
    printf("The node is not contained in the bst\n");
    return NULL;
  }
  if ( strcmp(s, bstP->str) < 0)  // less go left
  {
    bstP->l_child = bstRemoveNode(bstP->l_child,s);
  }
  else if ( strcmp(s, bstP->str) > 0) // more go right
  {
    bstP->r_child = bstRemoveNode(bstP->r_child,s);
  }
  else if ( strcmp(s, bstP->str) == 0)
  {
    // remove node
    // first check if left/right/both is empty
    if ((bstP->l_child == 0) && (bstP->r_child == 0)) //leaf
    {
      free(bstP);
      return NULL;
    }
    else if (bstP->l_child == 0)
    {
      bstNode *temp = bstP;    // save then free
      bstP = bstP->r_child;
      free(temp);
    }
    else if (bstP->r_child == 0)
    {
      bstNode *temp = bstP;   // save then free
      bstP = bstP->l_child;
      free(temp);
    }
    else 
    {
      bstNode *temp = bstFindSmallest(bstP->r_child); // smallest on right
      // copy temp
      bstP->str = temp->str;
      bstP->r_child = bstRemoveNode(bstP->r_child, temp->str);    
    }
  }
return bstP;    // root
  
}

// finds the smallest node in the tree
bstNode *bstFindSmallest(bstNode *bstP)
{
  
  bstNode *current = bstP;

  //traverse left
  while (current->l_child != 0)
  {
    current = current->l_child;
  }
  return current;
  
}
