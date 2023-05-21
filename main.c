#include <gtk/gtk.h>

static gboolean on_window_closed(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_main_quit();
    return TRUE;
}

static void on_start_clicked(GtkWidget *button, GtkWidget *entry) {

    gtk_widget_hide(button);

    gtk_widget_set_sensitive(entry, TRUE);
}

int main(int argc, char *argv[]) {

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    GtkWidget *word_entry = gtk_entry_new();
   // g_signal_connect(word_entry, "activate", G_CALLBACK(on_input_activate), NULL);
    
    GtkWidget *start_button = gtk_button_new_with_label("Start");
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_clicked), word_entry);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_set_sensitive(word_entry, FALSE);
    gtk_box_pack_start(GTK_BOX(vbox), start_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), word_entry, FALSE, FALSE, 0);

    gtk_widget_show_all(window);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);

    gtk_main();

    return 0;
}
