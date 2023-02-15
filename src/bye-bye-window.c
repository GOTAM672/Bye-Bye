/* bye-bye-window.c
 *
 * Copyright 2023 gotam gorabh
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"

#include "bye-bye-window.h"

struct _ByeByeWindow
{
	AdwApplicationWindow  parent_instance;

	/* Template widgets */
	GtkHeaderBar        *header_bar;
	//GtkLabel            *label;
        GtkButton           *cancel_button;
        GtkButton           *reboot_button;
        GtkButton           *logout_button;
        GtkButton           *shutdown_button;
        GtkButton           *suspend_button;
        GtkButton           *hibernate_button;
        GtkButton           *lock_button;

};

G_DEFINE_FINAL_TYPE (ByeByeWindow, bye_bye_window, ADW_TYPE_APPLICATION_WINDOW)

static void
bye_bye_window_cancel_clicked (ByeByeWindow *self)
{
  GtkNative *native;

  /* Returns the nearest GtkNative ancestor of self widget. */
  native = gtk_widget_get_native (GTK_WIDGET (self));

  g_print ("Cancel button clicked .");

  gtk_window_destroy (GTK_WINDOW (native));

}

static void
bye_bye_window_reboot_clicked (ByeByeWindow *self)
{

  gchar *standard_output = NULL;
  GError *error = NULL;
  gint exit_status;

  gboolean success = g_spawn_command_line_sync("reboot",
                                               &standard_output,
                                               NULL,
                                               &exit_status,
                                               &error);
  if (success) {
    g_print("Output: %s\n", standard_output);
    g_print("Exit status: %d\n", exit_status);
  } else {

    g_print("Failed to execute command\n");
    g_print("Error: %s\n", error->message);
  }

  g_free(standard_output);
  g_free(error);

  g_print ("Reboot button clicked .");
}

static void
bye_bye_window_logout_clicked (ByeByeWindow *self)
{
  g_print ("Logout button clicked .");
}

static void
bye_bye_window_shutdown_clicked (ByeByeWindow *self)
{
  g_print ("Shutdown button clicked .");
}

static void
bye_bye_window_suspend_clicked (ByeByeWindow *self)
{
  gchar *standard_output = NULL;
  GError *error = NULL;
  gint exit_status;

  gboolean success = g_spawn_command_line_sync("systemctl suspend",
                                               &standard_output,
                                               NULL,
                                               &exit_status,
                                               &error);
  if (success) {
    g_print("Output: %s\n", standard_output);
    g_print("Exit status: %d\n", exit_status);
  } else {

    g_print("Failed to execute command\n");
    g_print("Error: %s\n", error->message);
  }

  g_free(standard_output);
  g_free(error);
  g_print ("Suspend button clicked .");
}

static void
bye_bye_window_hibernate_clicked (ByeByeWindow *self)
{
  gchar *standard_output = NULL;
  GError *error = NULL;
  gint exit_status;

  gboolean success = g_spawn_command_line_sync("systemctl hibernate",
                                               &standard_output,
                                               NULL,
                                               &exit_status,
                                               &error);
  if (success) {
    g_print("Output: %s\n", standard_output);
    g_print("Exit status: %d\n", exit_status);
  } else {

    g_print("Failed to execute command\n");
    g_print("Error: %s\n", error->message);
  }

  g_free(standard_output);
  g_free(error);
  g_print ("Hibernate button clicked .");
}

static void
bye_bye_window_lock_clicked (ByeByeWindow *self)
{

}

static void
bye_bye_window_class_init (ByeByeWindowClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/org/gnome/ByeBye/bye-bye-window.ui");
	gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, header_bar);
	//gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, label);
        gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, cancel_button);
        gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, reboot_button);
        gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, logout_button);
        gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, shutdown_button);
        gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, suspend_button);
        gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, hibernate_button);
        gtk_widget_class_bind_template_child (widget_class, ByeByeWindow, lock_button);
}

static void
bye_bye_window_init (ByeByeWindow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));

        /* signals when buttons clicked */
        g_signal_connect (self->cancel_button, "clicked", G_CALLBACK (bye_bye_window_cancel_clicked), self);
        g_signal_connect (self->reboot_button, "clicked", G_CALLBACK (bye_bye_window_reboot_clicked), self);
        g_signal_connect (self->logout_button, "clicked", G_CALLBACK (bye_bye_window_logout_clicked), self);
        g_signal_connect (self->shutdown_button, "clicked", G_CALLBACK (bye_bye_window_shutdown_clicked), self);
        g_signal_connect (self->suspend_button, "clicked", G_CALLBACK (bye_bye_window_suspend_clicked), self);
        g_signal_connect (self->hibernate_button, "clicked", G_CALLBACK (bye_bye_window_hibernate_clicked), self);
        g_signal_connect (self->lock_button, "clicked", G_CALLBACK (bye_bye_window_lock_clicked), self);

}
