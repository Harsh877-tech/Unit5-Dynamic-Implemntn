#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Function to print the 2D grid
void printLCSTable(const vector<vector<int>>& table, const string& str1, const string& str2) {
    int cellWidth = 3;
    int tableWidth = (str2.length() + 1) * (cellWidth + 1) + 1;

    // Print top row with alphabets
    cout << setw(cellWidth + 1) << " ";
    for (char c : str2) {
        cout << setw(cellWidth) << c << " ";
    }
    cout << endl;

    // Print horizontal line
    cout << string(tableWidth, '-') << endl;

    // Print table contents
    for (size_t i = 0; i < table.size(); i++) {
        if (i == 0) {
            cout << setw(cellWidth) << " " << "| ";
        } else {
            cout << setw(cellWidth) << str1[i-1] << "| ";
        }
        for (int val : table[i]) {
            cout << setw(cellWidth) << val << " ";
        }
        cout << endl;
    }
}

// Function to find the longest common substring
string findLCS(const string& str1, const string& str2) {
    int len1 = str1.length(), len2 = str2.length();
    vector<vector<int>> table(len1 + 1, vector<int>(len2 + 1, 0));
    int maxLen = 0, endPos = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                if (table[i][j] > maxLen) {
                    maxLen = table[i][j];
                    endPos = i - 1;
                }
            }
        }
    }

    printLCSTable(table, str1, str2);

    return str1.substr(endPos - maxLen + 1, maxLen);
}

int main() {
    string str1, str2;
    
    cout << "Please input first string: ";
    cin >> str1;
    cout << "Please input second string: ";
    cin >> str2;
    
    if (str1.length() != str2.length()) {
        cout << "Error: Strings must have equal length." << endl;
        return 1;
    }
    
    string lcs = findLCS(str1, str2);
    
    cout << "\nLongest Common Substring: " << lcs << endl;
    cout << "Length: " << lcs.length() << endl;
    
    return 0;
}
