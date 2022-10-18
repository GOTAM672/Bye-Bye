#include <gtk/gtk.h>
//enum GtkWindowPosition;

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "ByeBye");
  gtk_window_set_default_size (GTK_WINDOW (window), 750, 225);
  gtk_window_set_resizable (GTK_WINDOW (window), false);
  //gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER_ALWAYS);
  //gtk_window_set_decorated (GTK_WINDOW (window), false);
  gtk_widget_show (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
