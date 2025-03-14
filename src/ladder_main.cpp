#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "ladder.h"
#include "ladder.cpp"

using namespace std;

int main() {
    // Initialize the word list and load words from file
    set<string> word_list;
    string file_name = "src/words.txt"; // You can change this to the desired word list file

    // Load words from the file into the word list
    load_words(word_list, file_name);

    if (word_list.empty()) {
        cerr << "Error: No words loaded. Make sure the file " << file_name << " exists and is not empty." << endl;
        return 1;
    }

    // Prompt user for start and end words
    string begin_word, end_word;

    cout << "Enter the start word: ";
    cin >> begin_word;
    cout << "Enter the end word: ";
    cin >> end_word;

    // Validate if start and end words are in the word list
    if (word_list.find(begin_word) == word_list.end()) {
        cerr << "Error: Start word '" << begin_word << "' not found in the dictionary." << endl;
        return 1;
    }
    if (word_list.find(end_word) == word_list.end()) {
        cerr << "Error: End word '" << end_word << "' not found in the dictionary." << endl;
        return 1;
    }

    // Generate the word ladder
    vector<string> ladder = generate_word_ladder(begin_word, end_word, word_list);

    // Print the result
    print_word_ladder(ladder);

    return 0;
}
