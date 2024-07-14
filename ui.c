#include "ui.h"
#include "callbacks.h"

GtkWidget* createMenuBar(GtkWidget *window) {
	GtkWidget *menubar;
	GtkWidget *fileMenu;
	GtkWidget *fileMi;
	GtkWidget *openMi;
	GtkWidget *saveMi;
	GtkWidget *quitMi;

	menubar = gtk_menu_bar_new();
	fileMenu = gtk_menu_new();
	fileMi = gtk_menu_item_new_with_label("File");
	openMi = gtk_menu_item_new_with_label("Open");
	saveMi = gtk_menu_item_new_with_label("Save");
	quitMi = gtk_menu_item_new_with_label("Quit");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), saveMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);

	g_signal_connect(openMi, "activate", G_CALLBACK(onOpen), window);
	g_signal_connect(saveMi, "activate", G_CALLBACK(onSave), window);
	g_signal_connect(quitMi, "activate", G_CALLBACK(onQuit), NULL);

	return menubar;
}

GtkWidget* createTextView() {
	GtkWidget *scrolledWindow;
	GtkWidget *textView;

	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	textView = gtk_text_view_new();
	gtk_container_add(GTK_CONTAINER(scrolledWindow), textView);

	return scrolledWindow;
}
