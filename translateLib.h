#include <glib.h>
#include "strctbrhDev.h"



#define BRH_MAX_SIZE 4
#define CONV_MAX_SIZE 7
#define BRH_CONVERTED_MAX_SIZE 11

char* brh_get_value(const char * brh);


void initialize_hashtable();
int next_conv_char(char* brh,char** outStr,int * remove_last_char, char* tempChar, int resetAll);
int get_matching_i(char* brh,int hasMinus,strctbrhDev** adx);
