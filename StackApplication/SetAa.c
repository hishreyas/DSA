/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set A,
a)Write a program that reverses a string of characters. The function should use a stack library 
(cststack.h) of stack of characters using a static implementation of the stack.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cststack.h"

int main()
{
  char str[40],rev[40];
  
  puts("Enter string:");
  gets(str);
  puts("Reversed string:");
  puts(strrev(rev,str));
  return 0;
}