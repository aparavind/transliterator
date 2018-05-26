#include <string.h>
#include "string_utils.h"

//C substring function definition
void substring(const char s[], char* sub, int p, int l) {
   int c = 0;

   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}

void removeLastChar(char* givenString){
    unsigned char cc;
    int len = strlen(givenString);
    int i;
    for (i = (len -1) ; i >= (len - 4) ; i--){
        cc = givenString[i];
        if (cc < 0b10000000){  // this is normal ASCII so just remove last char
            givenString[i] = 0b00000000;
            return;
        }

        if (cc >= 0b11000000){
            givenString[i] = 0b00000000;
            return;
        }

        givenString[i] = 0b000000;

    }
}
