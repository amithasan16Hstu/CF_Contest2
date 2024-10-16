#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string word;
        cin >> word;

        vector<string> syllables;
        string currentSyllable;

        for (int i = 0; i < n; i++) {
            // Check if the current letter is a vowel or consonant
            if (word[i] == 'a' || word[i] == 'e') {
                // If the current syllable is not empty, add it to the vector
                if (!currentSyllable.empty()) {
                    syllables.push_back(currentSyllable);
                    currentSyllable.clear();
                }
                currentSyllable += word[i];
            } else {
                currentSyllable += word[i];
                // If the next letter is a vowel or it's the last letter, add the current syllable
                if (i == n - 1 || word[i + 1] == 'a' || word[i + 1] == 'e') {
                    syllables.push_back(currentSyllable);
                    currentSyllable.clear();
                }
            }
        }

        // Output the syllables separated by dots
        for (const string& syllable : syllables) {
            cout << syllable << ".";
        }

        cout << endl;
    }

    return 0;
}
