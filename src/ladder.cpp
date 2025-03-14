#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout << "Error: " << msg << endl;
    cout << "Start word: " << word1 << " End word: " << word2 << endl;
}

// Function to check if two words are within a given edit distance
bool edit_distance_within(const string& str1, const string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();

    // If the length difference is greater than d, they are not within edit distance
    if (abs(len1 - len2) > d) return false;

    // Count how many positions the strings differ
    int diff_count = 0;
    int i = 0, j = 0;

    while (i < len1 && j < len2) {
        if (str1[i] != str2[j]) {
            diff_count++;
            if (diff_count > d) return false;

            // Skip one character in the longer string (insert or delete)
            if (len1 > len2) {
                i++;
            } else if (len2 > len1) {
                j++;
            } else {
                i++;
                j++;
            }
        } else {
            i++;
            j++;
        }
    }

    // If the remaining part of the string is greater than allowed edit distance, return false
    if (i < len1 || j < len2) {
        diff_count++;
    }

    return diff_count <= d;
}

// Function to check if two words are adjacent (differ by exactly 1 letter)
bool is_adjacent(const string& word1, const string& word2) {
    if (word1.length() == word2.length()) {
        int diff_count = 0;
        for (size_t i = 0; i < word1.length(); ++i) {
            if (word1[i] != word2[i]) {
                diff_count++;
                if (diff_count > 1) {
                    return false;
                }
            }
        }
        return diff_count == 1;
    }
    return false;
}