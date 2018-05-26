#include <gtk/gtk.h>
#include "translateLib.h"
#include <wchar.h>
#include <iconv.h>
#include "utf8.h"
#include <string.h>
#include <malloc.h>
#include "inputHandler.h"

void on_lbaraha_main_destroy()
{
    char str[50];
    char* convStr = brh_get_value("aa");

    int len = strlen(convStr);

    sprintf(str,"the string is %s and its length is %d",convStr,len);
    free(convStr);
    g_print(str);
    gtk_main_quit();
}

void on_lbaraha_input_insert_at_cursor(GtkButton * translateButton,app_widgets* req_widgets) {
//    GtkTextView* gotpt = req_widgets->w_fullConvText;
    GtkTextIter gitst,gited;
    GtkTextBuffer *gbuf = gtk_text_view_get_buffer(req_widgets->w_inputText);
    gtk_text_buffer_get_start_iter(gbuf,&gitst);
    gtk_text_buffer_get_end_iter(gbuf,&gited);

    char* convText = brh_get_value(
        gtk_text_buffer_get_text(gbuf,&gitst,&gited,FALSE)
    );

    gtk_text_buffer_set_text(
        gtk_text_view_get_buffer(req_widgets->w_fullConvText),
        convText,
        strlen(convText)
    );

    free(convText);
}
