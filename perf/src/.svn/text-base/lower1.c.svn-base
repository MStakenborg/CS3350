/* code motion example */
/* gcc -O2 -o lower1 lower1.c */

/* lower(char* s)
 * converts all characters A-Z in string s to lower case
 */
#include <string.h>
#include <stdio.h>

void lower_1 (char* s) {
  int i;
  for (i = 0; i < strlen(s); i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] -= 'A'-'a';
}


int main () {
  int n = 10000000;
  char s[n];	
  int i = 0;
  for (i=0; i<n; ++i)
    s[i] = 'd';
 
  lower_1(s);	
  
  return 0;
}
