#include <gtk/gtk.h>

static GtkWidget *word_entry = NULL;
static GtkWidget *start_button = NULL;


static gboolean on_window_closed(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_main_quit();
    return TRUE;
}

static void on_start_clicked() {

    //gtk_widget_hide(button);
    gtk_widget_set_sensitive(start_button, FALSE);
    gtk_widget_set_sensitive(word_entry, TRUE);
}

int main(int argc, char *argv[]) {
    GdkRGBA color;

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gdk_rgba_parse(&color, "rgb(181, 184, 177)"); // серый
    gtk_widget_override_background_color(window, GTK_STATE_NORMAL, &color);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_window_present(GTK_WINDOW(window));
  
    word_entry = gtk_entry_new();
    gtk_widget_set_sensitive(word_entry, FALSE);
 
    start_button = gtk_button_new_with_label("Start");
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_clicked), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
 
    gtk_box_pack_start(GTK_BOX(vbox), word_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), start_button, FALSE, FALSE, 0);
   
    gtk_widget_show_all(window);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);

    gtk_main();

    return 0;
}
