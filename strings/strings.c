#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int len = 0;
    while(*s!='\0'){
        s++;
        len++;
    }
    return len;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


char *reverse_string(char *rv, char *s)
{
   return strcpy(rv, strrev(s));
    const int len = string_length(s);
    s += len;
    int i = len;
    while(i>=0){
        *rv = *s;
        s--;
        rv++;
        i--;
    }
    *rv='\0';
    return rv -= len;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";
    char quote3[] = "hello world";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));
    printf("The length of the reversed string is: %d\n", string_length(reverse_string(rv,quote1)));
    printf("The length of the reversed string is: %d\n", strlen(reverse_string(rv,quote1)));

    return 0;
}
#endif
    
