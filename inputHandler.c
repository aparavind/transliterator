#include <gtk/gtk.h>
#include "translateLib.h"
#include <wchar.h>
#include <iconv.h>
#include "utf8.h"

void on_lbaraha_main_destroy()
{
    wchar_t str[50];
    gchar outStr[100];
    GHashTable * gBrhDev = createBrhDev();
    wchar_t brhDev[200][5];
    populateBrhDev(gBrhDev,brhDev);

    swprintf(str,50,L"the string is %ls",brh_get_value(gBrhDev,L"oM"));
    wchar_to_utf8(str,100,outStr,100,0);
    g_print(outStr);
    gtk_main_quit();
}
