//Lector HW 05 Binary Search
/*
Gerardo Alberto Mendoza Castillo A01666338
Fabian Lopez Perez A01661836
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> read_file(string file_name) {
    ifstream imported_file(file_name);
    if (!imported_file)
        cout << "Error opening txt file" << endl;
    vector<string> file_content;
    string line;
    while (getline(imported_file, line))
        file_content.push_back(line);
    imported_file.close();
    return file_content;
}

vector<int> line_to_vector(string line) {
    line.erase(0, 1).erase(line.size() - 1, 1);
    int numeric_characters;
    char text_characters;
    vector<int> created_vector;
    stringstream ss(line);
    while (ss >> numeric_characters) {
        created_vector.push_back(numeric_characters);
        ss >> text_characters;
    }
    return created_vector;
}

int binary_search(vector<int> input_vector, int search_item) {
    int low_bound = 0, high_bound = input_vector.size() - 1, item_location = -2;
    while (item_location == -2) {
        if (search_item == input_vector[(low_bound + high_bound) / 2])
            item_location = (low_bound + high_bound) / 2;
        else if (low_bound == high_bound)
            item_location = -1;
        else if (search_item < input_vector[(low_bound + high_bound) / 2])
            high_bound = (low_bound + high_bound) / 2 - 1;
        else if (search_item > input_vector[(low_bound + high_bound) / 2])
            low_bound = (low_bound + high_bound) / 2 + 1;
    }
    return item_location;
}

int main() {
    string file_name; 
    cout << "Inserte el nombre del archivo" << endl; // This allows that the user provides the name
    cin >> file_name;
    vector<string> file_content = read_file(file_name);
    vector<int> L = line_to_vector(file_content[0]);
    int x = stoi(file_content[1]);
    int slot = binary_search(L, x);
    cout << slot << "\n";
    return 0;
}



