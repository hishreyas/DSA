#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "polylist.h"


int main()
{
  DoublyList *poly1;
  DoublyList *poly2;
  DoublyList *polysum;
  char polystr1[40];
  char polystr2[40];
  
  puts("Enter Polynomial 1:");
  gets(polystr1);
  poly1=newPoly("3X^3+4X^2");
  printPoly(poly1);
  puts("Enter Polynomial 2:");
  gets(polystr2);
  poly2=newPoly("27X^3+0X^2");
  printPoly(poly2);
  polysum=addPoly(poly1,poly2);
  printf("\nPolynomial 1 + Polynomial 2:");
  printPoly(polysum);
  
}