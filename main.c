#include <gtk/gtk.h>

static gboolean on_window_closed(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_main_quit();
    return TRUE;
}

int main(int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *word_entry = gtk_entry_new();

  gtk_container_add(GTK_CONTAINER(window), word_entry);

  g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);
  g_signal_connect_swapped(window, "delete-event", G_CALLBACK(gtk_widget_destroy), window);
  g_signal_connect(window, "key-press-event", G_CALLBACK(on_window_closed), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}