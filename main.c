#include <gtk/gtk.h>

static GtkWidget *word_entry = NULL;
static GtkWidget *start_button = NULL;
static GtkWidget *label_word = NULL;
static GtkWidget *button_language = NULL;
static GtkWidget *accuracy_label = NULL;
static GtkWidget *button_reset=NULL;


gchar *language = "en"; // По умолчанию будет использоваться английский язык
gint correct_words = 0;
gchar *current_word;
// Массивы слов на русском и английском языках
gchar *russian_words[] = {"переменная", "алгоритм", "разработчик", "отказоустойчивость", "компьютер", "реализация", 
"функция", "библиотека", "веб-страница", "таблица","оператор","обработка"};
gchar *english_words[] = {"to verify", "to plug in", "to debug", "access", "include", "implementation",
 "keyboard", "language", "lightweight", "network", "process ", "programming","mouse","static variable"};

static gboolean on_window_closed(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_main_quit();
    return TRUE;
}

// Функция для вывода случайного слова на экран
static void set_word() {
    gint index;
    gint num_words;
    gchar **words;
    
    if (strcmp(language, "ru") == 0) { // Если выбран русский язык, используем массив слов на русском языке
        words = russian_words;
        num_words = G_N_ELEMENTS(russian_words);
    } else { // Если выбран английский язык, используем массив слов на английском языке
        words = english_words;
        num_words = G_N_ELEMENTS(english_words);
    }
    
    // Генерируем случайный индекс слова
    index = g_random_int_range(0, num_words);
    
    current_word = words[index];
    gtk_label_set_text(GTK_LABEL(label_word), current_word);
}

void on_language_clicked() {
    if (strcmp(language, "en") == 0) {
        language = "ru";
        gtk_button_set_label(GTK_BUTTON(button_language), "RU");
    } else {
        language = "en";
        gtk_button_set_label(GTK_BUTTON(button_language), "EN");
    }
    set_word();
}

static void on_start_clicked() {
    correct_words = 0;
    set_word();
    gtk_widget_set_sensitive(start_button, FALSE);
    gtk_widget_set_sensitive(word_entry, TRUE);
    gtk_widget_set_sensitive(button_reset, TRUE);
    gtk_widget_set_sensitive(button_language, TRUE);
     gtk_label_set_text(GTK_LABEL(accuracy_label), "Correct words: 0");
}

static void on_reset_clicked() {
    correct_words = 0;
    set_word();
    gtk_widget_set_sensitive(word_entry, TRUE);
    gtk_label_set_text(GTK_LABEL(accuracy_label), "Correct words: 0");
}
// Функция обработки события "activate" поля ввода слова
void on_input_activate(GtkEntry *entry, gpointer user_data) {
    gchar *text = gtk_entry_get_text(GTK_ENTRY(word_entry));
    
    if (strcmp(text, current_word) == 0) { // Если введенное слово совпадает с текущим словом
        correct_words++;
    }
    char buffer[100];
    sprintf(buffer, "Correct words: %d", correct_words);
    gtk_label_set_text(GTK_LABEL(accuracy_label), buffer);
    gtk_widget_show(accuracy_label);

    set_word(); // Генерируем новое слово
    gtk_entry_set_text(GTK_ENTRY(word_entry), ""); // Очищаем поле ввода
}

int main(int argc, char *argv[]) {

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //gdk_rgba_parse(&color, "rgb(189, 216, 255)"); // голубой
    //gtk_widget_override_background_color(window, GTK_STATE_NORMAL, &color);
    gtk_window_set_title(GTK_WINDOW(window), "Keyboard Ninja");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    GtkCssProvider *css_provider = gtk_css_provider_new();

    // Загружаем стиль для объекта GtkCssProvider
    gtk_css_provider_load_from_data(css_provider, "window {background-color: #8fd8f2}", -1, NULL);

    // Создаем GtkStyleContext и применяем к нему объект GtkCssProvider
    GtkStyleContext *context = gtk_widget_get_style_context(window);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
   
    gtk_window_present(GTK_WINDOW(window));
    
    label_word = gtk_label_new("-");
    gtk_label_set_selectable(GTK_LABEL(label_word), TRUE);

    word_entry = gtk_entry_new();
    gtk_widget_set_sensitive(word_entry, FALSE);
    g_signal_connect(word_entry, "activate", G_CALLBACK(on_input_activate), NULL);
 
    accuracy_label = gtk_label_new("Press Start ");
    gtk_widget_hide(accuracy_label);

    start_button = gtk_button_new_with_label("Start");
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_clicked), NULL);

    button_language = gtk_button_new_with_label("EN");
    g_signal_connect(button_language, "clicked", G_CALLBACK(on_language_clicked), NULL);
    gtk_widget_set_sensitive(button_language, FALSE);

    button_reset = gtk_button_new_with_label("Reset");
    g_signal_connect(button_reset, "clicked", G_CALLBACK(on_reset_clicked), NULL);
    gtk_widget_set_sensitive(button_reset, FALSE);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    gtk_box_pack_start(GTK_BOX(vbox), label_word, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), word_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), accuracy_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), start_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button_reset, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), button_language, FALSE, FALSE, 0);
    gtk_widget_show_all(window);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);

    gtk_main();

    return 0;
}
