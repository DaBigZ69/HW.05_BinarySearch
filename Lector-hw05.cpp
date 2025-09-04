//Lector HW 05 Binary Search
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
  
  ifstream imported_file;
  imported_file.open("file_name.txt");
  
  
  string imported_line;
  while (getline(imported_file, imported_line)){
    stringstream current_line(imported_line);
    cout<<imported_line<<"\n";
  }
  imported_file.close();
  
}
