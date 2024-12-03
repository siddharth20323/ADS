#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SuffixTreeNode {
public:
    vector<SuffixTreeNode*> children;
    int start, end;

    SuffixTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        this->children = vector<SuffixTreeNode*>(256, nullptr);
    }
};

class SuffixTree {
private:
    string text;
    SuffixTreeNode* root;

public:
    SuffixTree(string text) {
        this->text = text;
        this->root = new SuffixTreeNode(-1, -1);
        buildSuffixTree();
    }

    void buildSuffixTree() {
        int n = text.length();
        
        // Iterate through all suffixes of the text
        for (int i = 0; i < n; i++) {
            SuffixTreeNode* node = root;
            // For each suffix, insert it into the tree
            for (int j = i; j < n; j++) {
                char c = text[j];
                if (node->children[c] == nullptr) {
                    node->children[c] = new SuffixTreeNode(i, j);
                }
                node = node->children[c];
            }
        }
    }

    // Function to print all the suffixes from the tree (Inorder traversal)
    void printSuffixes(SuffixTreeNode* node, string& suffix) {
        if (node == nullptr) return;

        // Print the substring from node's start to end
        if (node->start != -1 && node->end != -1) {
            for (int i = node->start; i <= node->end; i++) {
                suffix += text[i];
            }
            cout << suffix << endl;
            suffix = suffix.substr(0, suffix.length() - (node->end - node->start + 1));
        }

        // Traverse through all children
        for (int i = 0; i < 256; i++) {
            if (node->children[i] != nullptr) {
                suffix += char(i);
                printSuffixes(node->children[i], suffix);
                suffix = suffix.substr(0, suffix.length() - 1);
            }
        }
    }

    void printAllSuffixes() {
        string suffix = "";
        printSuffixes(root, suffix);
    }
};

// Main function
int main() {
    string text = "banana";
    SuffixTree suffixTree(text);

    cout << "All suffixes of the string:" << endl;
    suffixTree.printAllSuffixes();

    return 0;
}
