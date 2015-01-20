/* code motion example */
/* gcc -O2 -o lower2 lower2.c */

/* lower (char* s)
 * converts all characters A-Z in string s to lower case
 */
#include <string.h>
#include <stdio.h>

void lower_2 (char* s) {
  int i;
  int n = strlen(s);
  for (i = 0; i < n; i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] -= 'A'-'a';
}

int main () {
  int n = 10000000;
  char s[n];	
  int i = 0;
  for (i=0; i<n; ++i)
    s[i] = 'g';
 
  lower_2(s);	
  
  return 0;
}
