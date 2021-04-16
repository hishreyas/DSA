/*Name:Shreyas Prabhakar Bansode
Roll no:6
Problem: Set B,
b) Write a program that checks whether a string of characters is palindrome or not. The 
function should use a stack library (cststack.h) of stack of characters using a static 
implementation of thestack.
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
  if(isPalindrome(str))
  puts("Entered string is palindrome");
  else
  puts("Entered string is not palindrome");
  return 0;
}