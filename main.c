#include <gtk/gtk.h>
#include <wchar.h>
#include "translateLib.h"
#include "inputHandler.h"



int
main (int   argc,
      char *argv[])
{

  // the struct which will store reference to the required widgets
  app_widgets *req_widgets = g_slice_new(app_widgets);

  GtkBuilder *builder;
  GObject *window;
  GError *error = NULL;

  gtk_init (&argc, &argv);


  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  if (gtk_builder_add_from_file (builder, "transliterator_builder.glade", &error) == 0)
    {
      g_printerr ("Error loading file: %s\n", error->message);
      g_clear_error (&error);
      return 1;
    }

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "lbaraha_main");
  //gtk_builder_connect_signals(builder,NULL);

   req_widgets->w_fullConvText = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"destinationDisplayView"));
   req_widgets->w_oneLineLabel = GTK_LABEL(gtk_builder_get_object(builder,"currentLineDisplayView"));
   req_widgets->w_inputText = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"sourceText"));
   req_widgets->w_actualWindow = GTK_WINDOW(window);

    gtk_builder_connect_signals(builder, req_widgets);
  g_object_unref(builder);

//    inputBox = (GtkTextView*)GTK_WIDGET(gtk_builder_get_object(builder,"sourceText"));

//   inputBuffer = gtk_text_view_get_buffer(inputBox);

//    gtk_builder_connect_signals

    gtk_widget_show(GTK_WIDGET(window));

  gtk_main ();

  g_slice_free(app_widgets,req_widgets);

  return 0;
}


