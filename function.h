#include <gtk/gtk.h>

void 
cancel_button_clicked (GtkWidget* button,
		       gpointer   user_data)
{
        GtkWidget *win= GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked\n");
        gtk_window_destroy (win);

}


void 
hibernate_button_clicked (GtkWidget* button,
		       gpointer   user_data)
{
        GtkWidget *win= GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked\n");
        gtk_window_destroy (win);

}

void 
lock_button_clicked (GtkWidget* button,
		       gpointer   user_data)
{
        GtkWidget *win= GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked\n");
        gtk_window_destroy (win);

}

void 
shutdown_button_clicked (GtkWidget* button,
		       gpointer   user_data)
{
        GtkWidget *win= GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked\n");
        gtk_window_destroy (win);

}


void 
suspend_button_clicked (GtkWidget* button,
		       gpointer   user_data)
{
        GtkWidget *win= GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked\n");
        gtk_window_destroy (win);

}

void 
reboot_button_clicked (GtkWidget* button,
		       gpointer   user_data)
{
        GtkWidget *win= GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked\n");
        gtk_window_destroy (win);

}

void 
logout_button_clicked (GtkWidget* button,
		       gpointer   user_data)
{
        GtkWidget *win= GTK_WINDOW (user_data);
	g_print("Cancel Button Clicked\n");
        gtk_window_destroy (win);

}
