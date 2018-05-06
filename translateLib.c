/*
    this is a library file which actaully doest teh transliteration
    the main function is TranslateT
    written in C linux from https://github.com/forevergenin/phtranslator/blob/master/PhTranslateLib/PhTranslateLib.cpp
*/

#include "translateLib.h"
#include <glib.h>
#include <wchar.h>

/*
    in dspace malloced space for the hash table
*/

GHashTable* createBrhDev()
{
    return g_hash_table_new(g_str_hash,g_str_equal);
}



void populateBrhDev(GHashTable * gBrhDev,wchar_t brhDev[200][5])
{

    wcscpy(brhDev[0],L"oM");
    wcscpy(brhDev[1],L"ॐ");
    g_hash_table_insert(gBrhDev,brhDev[0],brhDev[1]);
}


wchar_t* brh_get_value(GHashTable * brhDev,const wchar_t * brh)
{
    return g_hash_table_lookup(brhDev,brh);
}

