#include <gtk/gtk.h>

void 
cancel_button_clicked (GtkWidget* win, 
		       gpointer   user_data)
{
        //GtkWidget *win = GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked");
        gtk_window_destroy (win);

}


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
  gtk_window_set_decorated (GTK_WINDOW (window), false);
  

  // Buttons
/*

  GtkWidget *cancel;
  GtkWidget *hibernate;
  GtkWidget *lock;
  GtkWidget *logout;
  GtkWidget *reboot;
  GtkWidget *shutdown;
  GtkWidget *suspend;

  //const gchar *homedir;
  //homedir = g_get_home_dir();

  cancel = gtk_image_new_from_file ("./img/cancel.png");
  hibernate = gtk_image_new_from_file ("./img/hibernate.png");
  lock = gtk_image_new_from_file ("./img/lock.png");
  logout = gtk_image_new_from_file ("./img/logout.png");
  reboot = gtk_image_new_from_file ("./img/reboot.png");
  shutdown = gtk_image_new_from_file ("./img/shutdown.png");
  suspend = gtk_image_new_from_file ("./img/suspend.png");

 */

  //  Gtk Labels
  
  GtkWidget *label_cancel;
  label_cancel = gtk_label_new ("Cancel");
  gtk_label_set_markup (GTK_LABEL (label_cancel), "<b>Cancel</b>");
  
  GtkWidget *label_hibernate;
  label_hibernate = gtk_label_new ("Hibernate");
  gtk_label_set_markup (GTK_LABEL (label_hibernate), "<b>Hibernate</b>");
  
  GtkWidget *label_lock;
  label_lock = gtk_label_new ("Lock");
  gtk_label_set_markup (GTK_LABEL (label_lock), "<b>Lock</b>");
  
  GtkWidget *label_logout;
  label_logout = gtk_label_new ("Logout");
  gtk_label_set_markup (GTK_LABEL (label_logout), "<b>Logout</b>");
  
  GtkWidget *label_reboot;
  label_reboot = gtk_label_new ("Reboot");
  gtk_label_set_markup (GTK_LABEL (label_reboot), "<b>Reboot</b>");
  
  GtkWidget *label_shutdown;
  label_shutdown = gtk_label_new ("Shutdown");
  gtk_label_set_markup (GTK_LABEL (label_shutdown), "<b>Shutdown</b>");
  
  GtkWidget *label_suspend;
  label_suspend = gtk_label_new ("Suspend");
  gtk_label_set_markup (GTK_LABEL (label_suspend), "<b>Suspend</b>");



  GtkWidget *grid;
  grid = gtk_grid_new ();

  gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
  gtk_grid_set_row_spacing (GTK_GRID (grid), 10);
  gtk_grid_set_column_homogeneous (GTK_GRID (grid), true);



  GtkWidget *cancel_button;
  cancel_button = gtk_button_new ();
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (cancel_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), cancel);
  g_signal_connect (GTK_WINDOW (window), "clicked", G_CALLBACK(cancel_button_clicked), NULL);
  




  
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
