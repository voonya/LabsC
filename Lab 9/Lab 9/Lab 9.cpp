#include "delrepeat.h"

using namespace std;

int main() {
    char input_str[100];
    cin.getline(input_str, 256);

    // разбиваем строку на массив слов
    string words[50];
    int number_words = create_words(input_str, words);

    // находим элементы которые повторяються
    string repeat_words[50];
    int number_rep_w = find_repeat(words, repeat_words, number_words);
    //output_arr(repeat_words,number_rep_w);

    //удаляем из исходной строки слова, которые повторяются
    string new_str = delete_repeat(input_str, repeat_words, number_rep_w);
    cout << new_str;

    return 0;
}