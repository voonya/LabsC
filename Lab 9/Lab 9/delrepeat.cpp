#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>




using namespace std;

int create_words(char str[], string words[]) {   //создаем массив слов и строки
    char str_copy[100];
    strcpy_s(str_copy, sizeof(str_copy), str);
    char sep[] = ".,;!? ";
    int count_words = 0;
    char* posw = strtok(str_copy, sep);
    while (posw != NULL) {
        char word_c[100];
        strcpy_s(word_c, sizeof(word_c), posw);
        string word_s = string(word_c);
        words[count_words] = word_s;
        count_words++;
        posw = strtok(NULL, sep);
    }
    return count_words;
}
int find_repeat(string words[], string repeat_words[], int size_arr) { // находим слова которые повторяются
    int number_rep_w = 0;
    for (int i = 0; i < size_arr - 1; i++) {
        for (int k = i + 1; k < size_arr; k++) {
            if (words[i] == words[k]) {
                repeat_words[number_rep_w] = words[i];
                number_rep_w++;
            }
        }
    }
    return number_rep_w;
}
void output_arr(string arr[], int size_arr) {  // вывод массива
    for (int i = 0; i < size_arr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
string delete_repeat(string str, string arr[], int size_arr) { // удаление повторов
    string str_copy = str;
    for (int i = 0; i < size_arr; i++) {
        while (str_copy.find(arr[i]) != string::npos) {
            int pos = str_copy.find(arr[i]);
            str_copy.erase(pos, size(arr[i]));
        }
    }
    return str_copy;
}

