#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

// A function that cleans a word of punctuation and non-alphanumeric characters
string clean_word(const string& word){
    string new_word;
    for(char c: word){
        if(isalnum(c) || c == '-'){
            new_word += tolower(c);
        }
    }
    return new_word;
}
// A function that creates a frequency table for a file
map<string , int> frequency_table (const string& filename){
    map<string, int> freq;
    ifstream input(filename);
    if (input.is_open()) {
        string word;
        while (input >> word){
            word = clean_word(word);
            if (!word.empty()) {
                freq[word]++;
            }
        }
        input.close();
    }
    else { // if the file is not opened successfully
        cout << "Unable to open file" << filename << endl; // print an error message
    }
    return freq; // return the map
}
// A function that prints a frequency table
void print_frequency_table(const map<string, int>& freq_table) {
    for (const auto& it : freq_table) {
        cout << it.first << ": " << it.second << endl;
    }
}
int main(){
   string filename;
   cout<<"Enter the file name";
   cin >> filename;
   map<string, int>freq = frequency_table(filename);
   print_frequency_table(freq);
}