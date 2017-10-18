#include <stdio.h>      // for printf
#include <stdlib.h>     // for free() and malloc
#include <string.h>     // for strlen
#include "bst.h"    // for bst operations

/* read no more than limit chars into s, return #chars read. Doesnt include trailing /n */
int gets_n(char *s, int limit)
{
  char *p = s;        // indexing into s
  char c;

  if (fgets(s, limit, stdin))
  {
    while ((c=*p) && (c != '\n'))   // scans p through s until 0 or \n
    {
       p++;
    }
    if (c =='\n')
    {
      *p = 0;
    }
  }
    return (p-s); //will be num chars read (not including terminator \n
}

// user input names to bst
bstNode *userInput(bstNode *bstP)
{
  
  printf("Enter the names you would like to add:\n");
  char buf[100];
    
  while(gets_n(buf, 100))
  {
    bstP= bstInsert(bstP,buf);
  }
  return bstP;
}

// delete names from bst
bstNode *deleteInputNames(bstNode *bstP)
{
  printf("Enter the names you would like to delete:\n");
  char buf[100];

  while(gets_n(buf, 100))
  {
    bstP= bstRemoveNode(bstP,buf);
  }
  return bstP;
}

// read from file into bst
bstNode *readFromFile(bstNode *bstP, FILE *fP)
{
  
  char fileBuf[100];
  
  while (fgets(fileBuf, 100, fP) != NULL)
  {
    bstP = bstInsert(bstP,fileBuf);
  }
  
  
  return bstP;
}

// write to file
void writeToFile(bstNode *bstP, FILE *fP)
{
  writeToFile(bstP->l_child,fP);
  fprintf(fP,bstP->str);
  writeToFile(bstP->r_child,fP);  
   
}

// menu
char menu()
{
  char answer = 0;
  printf(" \n");
  printf("Select what to do next:\n");
  printf("Enter '9' to quit the program.\n");
  printf("Enter '1' to enter names into a binary search tree.\n");
  printf("Enter '2' to remove names from a binary search tree.\n");
  printf("Enter '3' to print the binary search tree.\n");
  printf("Enter '4' to enter names into bst from a file.\n");
  printf("Enter '5' to write the tree into a file.\n");
  answer = getchar();
  getchar();
  
  return answer;
}

// main method-------------------------------------------------------------
int main()
{
 
  char endflag = 2;
  char selection = 0;
  FILE *fP = fopen("bstNames.txt","r+");

  // create a bst node pointer
  bstNode *root;

  printf(" \n");
  printf("Welcome!\n");
  
  do {                              //causing seg fault*                                  
    printf(" \n");

    selection = menu();

  
    if (selection == '9') //stop
      endflag = 1;
     
    else if (selection =='1') // enter names into bst using user input
    {
      root = userInput(root);
    }
    else if (selection =='2') // remove names from bst using user input
    {
      root = deleteInputNames(root);
    }
    else if (selection =='3') // print nodes
    {
      printf(" \n");
      printf("In-order:\n");
      bstPrintInOrder(root);
      printf(" \n");
      printf("Pre-order:\n");
      bstPrintPreOrder(root);
      printf(" \n");
      printf("Post-order:\n");
      printf(" \n");
    }
    else if (selection =='4') // enter names from file
    {
      root = readFromFile(root,fP);
      printf("Inserted names from file.\n");
    }
    else if (selection =='5') // write names to file
    {
      writeToFile(root,fP);
      
      printf("Wrote tree to file.\n");
    }
 
    //   used for testing before menu
    // not commenting loop
    
    printf(" \n");
    printf("Printing in-order:\n");
    bstPrintInOrder(root);

 
    printf("\n");
    printf("Printing pre-order:\n");
    bstPrintPreOrder(root);
  
    printf("\n");
    printf("Printing post-order:\n");
    bstPrintPostOrder(root);
    
    } while (endflag != 1);
    

  printf("Goodbye\n");
  return 0;
}

