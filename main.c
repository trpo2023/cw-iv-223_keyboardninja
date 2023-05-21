#include <gtk/gtk.h>

static gboolean on_delete_event(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_main_quit();
    return TRUE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(on_delete_event), NULL);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}