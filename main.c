#include <gtk/gtk.h>

int
main (int   argc,
      char *argv[])
{
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
  gtk_builder_connect_signals(builder,NULL);

  g_object_unref(builder);

  gtk_widget_show(GTK_WIDGET(window));

  gtk_main ();

  return 0;
}

void on_lbaraha_main2_destroy()
{
    int i;
    char str[50];
    i = 15 + 6;
    sprintf(str,"the i is %i",i);
    g_print(str);
    gtk_main_quit();
}
