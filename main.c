#include <gtk/gtk.h>
//#include <glib/glib.h>


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
  

  GtkWidget *cancel;
  GtkWidget *hibernate;
  GtkWidget *lock;
  GtkWidget *logout;
  GtkWidget *reboot;
  GtkWidget *shutdown;
  GtkWidget *suspend;

  //const gchar *homedir;
  //homedir = g_get_home_dir();

  cancel = gtk_image_new_from_file ("/home/Bye-Bye/img/cancel.png");
  hibernate = gtk_image_new_from_file ("/home/Bye-Bye/img/hibernate.png");
  lock = gtk_image_new_from_file ("/home/Bye-Bye/img/lock.png");
  logout = gtk_image_new_from_file ("/home/Bye-Bye/img/logout.png");
  reboot = gtk_image_new_from_file ("/home/Bye-Bye/img/reboot.png");
  shutdown = gtk_image_new_from_file ("/home/Bye-Bye/img/shutdown.png");
  suspend = gtk_image_new_from_file ("/home/Bye-Bye/img/suspend.png");


  GtkWidget *label;
  label = gtk_label_new ("Cancel");
  gtk_label_set_markup (GTK_LABEL (<b>Cancel</b>));



  GtkWidget *grid;
  grid = gtk_grid_new ();

  gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
  gtk_grid_set_roe_spacing (GTK_GRID (grid), 10);
  gtk_grid_column_homogenous (GTK_GRID (grid), true);





  




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
