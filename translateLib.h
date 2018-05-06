#include <glib.h>

GHashTable * createBrhDev();

void populateBrhDev(GHashTable * gBrhDev,wchar_t brhDev[200][5]);

wchar_t* brh_get_value(GHashTable * brhDev,const wchar_t * brh);


