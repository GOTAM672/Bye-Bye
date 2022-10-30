#include <gtk/gtk.h>
#include "function.h"


static void
activate (GtkApplication* app,
          gpointer        user_data)
{

  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "ByeBye");
  gtk_window_set_default_size (GTK_WINDOW (window), 750, 80);
  gtk_window_set_resizable (GTK_WINDOW (window), true);
  //gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_decorated (GTK_WINDOW (window), true);
  

  // Buttons


  GtkWidget *cancel;
  GtkWidget *hibernate;
  GtkWidget *lock;
  GtkWidget *logout;
  GtkWidget *reboot;
  GtkWidget *shutdown;
  GtkWidget *suspend;

  //const gchar *homedir;
  //homedir = g_get_home_dir();

  cancel = gtk_image_new_from_file ("/home/gotam/Bye-Bye/img/cancel.png");
  hibernate = gtk_image_new_from_file ("./img/hibernate.png");
  lock = gtk_image_new_from_file ("./img/lock.png");
  logout = gtk_image_new_from_file ("./img/logout.png");
  reboot = gtk_image_new_from_file ("./img/reboot.png");
  shutdown = gtk_image_new_from_file ("./img/shutdown.png");
  suspend = gtk_image_new_from_file ("./img/suspend.png");



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




  // cancel button
  GtkWidget *cancel_button;
  cancel_button = gtk_button_new_with_label("CANCEL");
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (cancel_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), lock);
  g_signal_connect (cancel_button, "clicked", G_CALLBACK(cancel_button_clicked), window);
  
  
  // hibernate button
  GtkWidget *hibernate_button;
  hibernate_button = gtk_button_new ();
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (hibernate_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), cancel);
  g_signal_connect (hibernate_button, "clicked", G_CALLBACK(hibernate_button_clicked), window);
  
  
  // lock button
  GtkWidget *lock_button;
  lock_button = gtk_button_new ();
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (lock_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), cancel);
  g_signal_connect (lock_button, "clicked", G_CALLBACK(lock_button_clicked), window);
  
  
  // logout button
  GtkWidget *logout_button;
  logout_button = gtk_button_new ();
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (logout_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), cancel);
  g_signal_connect (logout_button, "clicked", G_CALLBACK(logout_button_clicked), window);
  
  
  // reboot button
  GtkWidget *reboot_button;
  reboot_button = gtk_button_new ();
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (reboot_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), cancel);
  g_signal_connect (reboot_button, "clicked", G_CALLBACK(reboot_button_clicked), window);
  
  
  // shutdown button
  GtkWidget *shutdown_button;
  shutdown_button = gtk_button_new ();
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (shutdown_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), cancel);
  g_signal_connect (shutdown_button, "clicked", G_CALLBACK(shutdown_button_clicked), window);
  
  
  // suspend button
  GtkWidget *suspend_button;
  suspend_button = gtk_button_new ();
  //gtk_button_set_relief (GTK_BUTTON (cancel_button), GTK_RELIEF_STYLE_NONE);
  gtk_widget_set_hexpand (GTK_BUTTON (suspend_button), false);
  //gtk_button_set_image (GTK_BUTTON (cancel_button), cancel);
  g_signal_connect (suspend_button, "clicked", G_CALLBACK(suspend_button_clicked), window);
  

  
  
  
  
  
  

  GtkWidget *grid;
  grid = gtk_grid_new ();

  gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
  gtk_grid_set_row_spacing (GTK_GRID (grid), 10);
  gtk_grid_set_column_homogeneous (GTK_GRID (grid), true);

  
  gtk_grid_attach (GTK_GRID (grid), cancel_button, 0, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label_cancel, 0, 1, 1, 1);
  
  gtk_grid_attach (GTK_GRID (grid), logout_button, 1, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label_logout, 1, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (grid), hibernate_button, 2, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label_hibernate, 2, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (grid), lock_button, 3, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label_lock, 3, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (grid), reboot_button, 4, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label_reboot,  4, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (grid), shutdown_button, 5, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label_shutdown, 5, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (grid), suspend_button, 6, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label_suspend, 6, 1, 1, 1);

  
  /* Pack the container in the window */
  gtk_window_set_child (GTK_WINDOW (window), grid);



  
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
