#include "callbacks.h"

void onOpen(GtkWidget *widget, gpointer data) {
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new("Open File", GTK_WINDOW(data),
										 GTK_FILE_CHOOSER_ACTION_OPEN,
										 "_Cancel", GTK_RESPONSE_CANCEL,
										 "_Open", GTK_RESPONSE_ACCEPT,
										 NULL);

	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
		char *filename;
		GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
		filename = gtk_file_chooser_get_filename(chooser);

		g_free(filename);
	}

	gtk_widget_destroy(dialog);
}

void onSave(GtkWidget *widget, gpointer data) {
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new("Save File", GTK_WINDOW(data),
											 GTK_FILE_CHOOSER_ACTION_OPEN,
										 "_Cancel", GTK_RESPONSE_CANCEL,
										 "_Open", GTK_RESPONSE_ACCEPT,
										 NULL);

	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
		char *filename;
		GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
		filename = gtk_file_chooser_get_filename(chooser);
		g_free(filename);
	}

	gtk_widget_destroy(dialog);
}

void onQuit(GtkWidget *widget, gpointer data) {
	gtk_main_quit();
}
