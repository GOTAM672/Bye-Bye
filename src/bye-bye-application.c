/* bye-bye-application.c
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

#include "bye-bye-application.h"
#include "bye-bye-window.h"

struct _ByeByeApplication
{
	AdwApplication parent_instance;
};

G_DEFINE_TYPE (ByeByeApplication, bye_bye_application, ADW_TYPE_APPLICATION)

ByeByeApplication *
bye_bye_application_new (const char        *application_id,
                         GApplicationFlags  flags)
{
	g_return_val_if_fail (application_id != NULL, NULL);

	return g_object_new (BYE_BYE_TYPE_APPLICATION,
	                     "application-id", application_id,
	                     "flags", flags,
	                     NULL);
}

static void
bye_bye_application_activate (GApplication *app)
{
	GtkWindow *window;

	g_assert (BYE_BYE_IS_APPLICATION (app));

	window = gtk_application_get_active_window (GTK_APPLICATION (app));

	if (window == NULL)
		window = g_object_new (BYE_BYE_TYPE_WINDOW,
		                       "application", app,
		                       NULL);

	gtk_window_present (window);
}

static void
bye_bye_application_class_init (ByeByeApplicationClass *klass)
{
	GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

	app_class->activate = bye_bye_application_activate;
}

static void
bye_bye_application_about_action (GSimpleAction *action,
                                  GVariant      *parameter,
                                  gpointer       user_data)
{
	static const char *developers[] = {"gotam gorabh", NULL};
	ByeByeApplication *self = user_data;
	GtkWindow *window = NULL;

	g_assert (BYE_BYE_IS_APPLICATION (self));

	window = gtk_application_get_active_window (GTK_APPLICATION (self));

	adw_show_about_window (window,
	                       "application-name", "bye-bye",
	                       "application-icon", "org.gnome.ByeBye",
	                       "developer-name", "gotam gorabh",
	                       "version", "0.1.0",
	                       "developers", developers,
	                       "copyright", "© 2023 gotam gorabh",
	                       NULL);
}

static void
bye_bye_application_quit_action (GSimpleAction *action,
                                 GVariant      *parameter,
                                 gpointer       user_data)
{
	ByeByeApplication *self = user_data;

	g_assert (BYE_BYE_IS_APPLICATION (self));

	g_application_quit (G_APPLICATION (self));
}

static const GActionEntry app_actions[] = {
	{ "quit", bye_bye_application_quit_action },
	{ "about", bye_bye_application_about_action },
};

static void
bye_bye_application_init (ByeByeApplication *self)
{
	g_action_map_add_action_entries (G_ACTION_MAP (self),
	                                 app_actions,
	                                 G_N_ELEMENTS (app_actions),
	                                 self);
	gtk_application_set_accels_for_action (GTK_APPLICATION (self),
	                                       "app.quit",
	                                       (const char *[]) { "<primary>q", NULL });
}
