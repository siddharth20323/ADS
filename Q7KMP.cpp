#include <iostream>
#include <string>

using namespace std;

 
void computeLPSArray(const string& pattern, int lps[]) {
    int length = 0;  
    int i = 1;

    lps[0] = 0;   

    
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
               
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

 
void KMPSearch(const string& text, const string& pattern) {
    int m = pattern.size();
    int n = text.size();

    
    int lps[m];  // LPS array
    computeLPSArray(pattern, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

     
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  
        }
         
        else if (i < n && pattern[j] != text[i]) {
             
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    
    KMPSearch(text, pattern);

    return 0;
}
