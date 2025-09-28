// Gerardo Alberto Mendoza Castillo A01666338
// Fabian Lopez Perez A01661836

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> line_to_vector(string line) {
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

vector<int> file_menu() {
    string file_name, line;
    cout << "Please enter the input text file name: ";
    cin >> file_name;
    ifstream imported_file(file_name);
    if (!imported_file) {
        cout << "\nError opening txt file" << endl;
        return line_to_vector("0");
    }
    vector<string> file_content;
    while (getline(imported_file, line))
        file_content.push_back(line);
    imported_file.close();
    return line_to_vector(file_content[0]);
}

int user_menu(vector<int> input_vector){
    if (input_vector == line_to_vector("0"))
        return 0;
    int sort_algorithm;
    cout << "\nSorting Algorithms\n[1] Bucket Sort\n[2] Insertion Sort\n[3] Selection Sort\n[4] Merge Sort\n[5] Quick Sort\n\nPlease choose the algorithm to use: ";
    cin >> sort_algorithm;
    return sort_algorithm;
}

void print_vector(vector<int> input_vector, bool output_text) {
    if (output_text == true)
        cout << "\nOutput array:\n\n";
    else
        cout << "\nInput array:\n\n";
    for (int i = 0; i < input_vector.size(); ++i) {
        cout << input_vector[i];
        if (i < input_vector.size() - 1)
            cout << ", ";
    }
    cout << "\n\n";
}

vector<int> bucket_sort(vector<int> input_vector) {
    cout << "Finding maximum value in array...\n";
    int max_value = input_vector[0];
    for (int i = 1; i < input_vector.size(); i++)
        if (input_vector[i] > max_value)
            max_value = input_vector[i];
    cout << max_value << "\n\nCreating two-dimensional array...\n0 | 0\n0 | 0\n\nBucket sorting values...\n";
    vector<vector<int>> bucket_vector(2, vector<int>(max_value, 0));
    for (int i = 0; i < input_vector.size(); ++i) {
        if (bucket_vector[0][input_vector[i] - 1] == 0)
            bucket_vector[0][input_vector[i] - 1] = input_vector[i];
        bucket_vector[1][input_vector[i] - 1] += 1;
    }
    vector<int> sorted_vector;
    for (int i = 0; i < max_value; i++)
        if (bucket_vector[0][i] != 0)
            for (int k = 0; k < bucket_vector[1][i]; k++){
                sorted_vector.push_back(bucket_vector[0][i]);
                cout << bucket_vector[0][i] << " - " << bucket_vector[1][i] << "\n";
            }
    return sorted_vector;
}

vector<int> insertion_sort(vector<int> sorted_vector) {
    cout << "Dividing array in two sections...\n••• | •••\n\nComparing adjacent values...\n";
    for (int i = 1; i < sorted_vector.size(); i++) {
        cout << "{" << sorted_vector[i - 1] << "} {" << sorted_vector[i] << "}\n";
        int j = i, current_value = sorted_vector[i];
        while (j > 0 && sorted_vector[j - 1] > current_value) {
            sorted_vector[j] = sorted_vector[j - 1];
            j--;
        }
        sorted_vector[j] = current_value;
    }
    cout << "\nFinishing to insert sections...\n" << sorted_vector.size() << " sorted items | 0 unsorted items\n";
    return sorted_vector;
}

vector<int> selection_sort(vector<int> sorted_vector) {
    cout << "Finding minimum values...\n(First element: " << sorted_vector[0] << ")\n\nSwapping item positions...\n";
    for (int i = 0; i < sorted_vector.size(); i++) {
        int min_value_index = i;
        for (int j = i + 1; j < sorted_vector.size(); j++)
            if (sorted_vector[j] < sorted_vector[min_value_index])
                min_value_index = j;
        if (min_value_index != i) {
            swap(sorted_vector[i], sorted_vector[min_value_index]);
            cout << sorted_vector[i] << " <-> " << sorted_vector[min_value_index] << "\n";
        }
    }
    cout << "\nCompleting selection sort...\n+ Total items found in array: " << sorted_vector.size() << "\n";
    return sorted_vector;
}

static vector<int> merge_two(const vector<int>& a, const vector<int>& b) {
    vector<int> out;
    out.reserve(a.size() + b.size());
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) out.push_back(a[i++]);
        else               out.push_back(b[j++]);
    }
    while (i < a.size()) out.push_back(a[i++]);
    while (j < b.size()) out.push_back(b[j++]);
    return out;
}

vector<int> merge_sort(vector<int> input_vector) {
    if (input_vector.size() <= 1) return input_vector;
    size_t mid = input_vector.size() / 2;
    vector<int> left_part(input_vector.begin(), input_vector.begin() + mid);
    vector<int> right_part(input_vector.begin() + mid, input_vector.end());
    left_part = merge_sort(left_part);
    right_part = merge_sort(right_part);
    cout<<"\nMerging subarrays...\n(" << left_part.size() + right_part.size() << " current items)\n";
    return merge_two(left_part, right_part);
}

vector<int> quick_sort(vector<int> input_vector) {
    if (input_vector.size() <= 1)
        return input_vector;
    vector<int> left_part, right_part;
    cout << "\nArranging items around pivot...\n- Current pivot: " << input_vector[0] << "\n";
    for (int i = 1; i < input_vector.size(); i++) {
        if (input_vector[i] < input_vector[0])
            left_part.push_back(input_vector[i]);
        else
            right_part.push_back(input_vector[i]);
    }
    vector<int> sorted_left_part = quick_sort(left_part);
    vector<int> sorted_right_part = quick_sort(right_part);
    vector<int> sorted_vector;
    sorted_vector.insert(sorted_vector.end(), sorted_left_part.begin(), sorted_left_part.end());
    sorted_vector.push_back(input_vector[0]);
    sorted_vector.insert(sorted_vector.end(), sorted_right_part.begin(), sorted_right_part.end());
    return sorted_vector;
}

vector<int> sort_vector(vector<int> input_vector, int sort_algorithm) {
    print_vector(input_vector, false);
    switch(sort_algorithm) {
        case 0:
            return input_vector;
        case 1:
            cout << "* Bucket Sort Algorithm\n\n";
            return bucket_sort(input_vector);
        case 2:
            cout << "* Insertion Sort Algorithm\n\n";
            return insertion_sort(input_vector);
        case 3:
            cout << "* Selection Sort Algorithm\n\n";
            return selection_sort(input_vector);
        case 4:
            cout << "* Merge Sort Algorithm\n";
            return merge_sort(input_vector);
        case 5:
            cout << "* Quick Sort Algorithm\n";
            return quick_sort(input_vector);
        default:
            cout << "Invalid option\nAlgorithm not found\n";
            return input_vector;
    }
}

int main() {
    vector<int> L = file_menu();
    vector<int> L_s = sort_vector(L, user_menu(L));
    print_vector(L_s, true);
    return 0;
}
