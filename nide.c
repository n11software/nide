#include <gtk/gtk.h>

static void
activate(GtkApplication* app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *menubar;
	GtkWidget *textView;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "N11 IDE");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = createMenuBar(window);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	textView = createTextView();
	gtk_box_pack_start(GTK_BOX(vbox), textView, TRUE, TRUE, 0);
	
	gtk_widget_show_all(window);
}

int
main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.n11.nide", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
