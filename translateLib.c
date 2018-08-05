/*
    this is a library file which actaully doest teh transliteration
    the main function is TranslateT
    written in C linux from https://github.com/forevergenin/phtranslator/blob/master/PhTranslateLib/PhTranslateLib.cpp
*/

#include "translateLib.h"
#include <string.h>
#include <glib.h>
#include <wchar.h>
#include "string_utils.h"
#include <malloc.h>


static GHashTable *hBrhDev = NULL;

/*
    in dspace malloced space for the hash table
*/

GHashTable* createBrhDev()
{
    return g_hash_table_new(g_str_hash,g_str_equal);
}



void populateBrhDev(const char * inpLang,const char * outLang)
{
    insert_into_ghashtable(hBrhDev,inpLang,outLang);
}


char* brh_get_value(const char * brh,const char * inpLang,const char * outLang)
{
    initialize_hashtable(inpLang,outLang);
    next_conv_char(NULL,NULL,NULL,NULL,1);
    char* loop_brh = (char *)brh;
    int offset = 0;
    int remove_last_char;
    char tempChar[2];

    char* outStr = calloc((int)(strlen(brh)*CONV_MAX_SIZE),sizeof(char));
    char* tmpStr;

    do {
        remove_last_char = 0;
        tempChar[0] = '\0';
       offset = next_conv_char(loop_brh,&tmpStr,&remove_last_char,tempChar,0);
       if (offset == 0){
            break;
       }
       if (remove_last_char == 1){
            removeLastChar(outStr);
       }

       if (tempChar[0] != '\0'){
        strcat(outStr,tempChar);
       } else {
        strcat(outStr,tmpStr);
       }
       loop_brh += offset;
    } while (1);

    return outStr;
}

void initialize_hashtable(const char * inpLang,const char * outLang){
    if (hBrhDev == NULL){
        hBrhDev = createBrhDev();
        populateBrhDev(inpLang,outLang);
    }
}

int next_conv_char(char* brh,char** outStr,int * remove_last_char,char* tempChar, int resetAll){
    static int previousMinussable = 0;

    if (resetAll == 1){
        previousMinussable = 0;
        return 0;
    }

    if (brh[0] == '\0'){
        return 0;
    }


    int i;


    strctbrhDev* adx;
    i = get_matching_i(brh,previousMinussable,&adx);
    if ((i==0) && (previousMinussable == 1)){
        i = get_matching_i(brh,0,&adx);
    }
    if (i > 0){
        *outStr = adx->opDvn;
        *remove_last_char = (adx->performMinusOne) && previousMinussable;
        previousMinussable =  adx->isMinussable;
    } else {
        tempChar[0] = brh[0];
        tempChar[1] = '\0';
        i++;
    }
    return i;
}

int get_matching_i(char* brh,int hasMinus,strctbrhDev** adx){
     int l = strlen(brh);
     int i;
    for (i = (BRH_MAX_SIZE > l)? l : BRH_MAX_SIZE ;i > 0 ; i--){
        char tmp_brh[BRH_CONVERTED_MAX_SIZE] ;
        substring(brh,tmp_brh,1,i);
        if (hasMinus){
            strcat(tmp_brh,"[%% e %%]");
        }
        *adx = (strctbrhDev*)g_hash_table_lookup(hBrhDev,tmp_brh);
        if (*adx != NULL){
            break;
        }
    }
    return i;
}
