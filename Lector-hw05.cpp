#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream imported_file("test_binary_search.txt");
    
    if (!imported_file)
        cout << "Error opening txt file" << endl;
    
    vector<string> file_content;
    string line;
    while (getline(imported_file, line))
        file_content.push_back(line);
    
    imported_file.close();
    
    string file_line = file_content[0];
    
    file_line.erase(0, 1).erase(file_line.size() - 1, 1);
    int numeric_characters;
    char text_characters;
    vector<int> L;
    stringstream ss(file_line);
    while (ss >> numeric_characters) {
        L.push_back(numeric_characters);
        ss >> text_characters;
    }
    
    int x = stoi(file_content[1]);
    
    int low_bound = 0, high_bound = L.size() - 1;
    int slot = -2;
    while (slot == -2){
        if (x == L[(low_bound + high_bound) / 2])
            slot = (low_bound + high_bound) / 2;
        else if (low_bound == high_bound)
            slot = -1;
        else if (x < L[(low_bound + high_bound) / 2])
            high_bound = (low_bound + high_bound) / 2 - 1;
        else if (x > L[(low_bound + high_bound) / 2])
            low_bound = (low_bound + high_bound) / 2 + 1;
    }
    
    cout << slot << "\n";
    return 0;
}
