//fileName: A3_Sheetpb2_20221063.cpp
//Author: Reem Ahmed Abdallah
//ID: 20221063
//Section: s7 / s8
//Purpose: to handle words in a given file name or string and calculate similarity , union , intersection 
//and other operations 
#include <iostream>
#include <string>
#include <vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
bool isFile(string fileName){   //bool function to check if the string name is filename or string 
    ifstream object(fileName);
    if(object.is_open()){
        return true;
    }else{
        return false;
    }
}
class StringSet{
    private:
    set<string>string_set;
    public:
    StringSet(){}
    StringSet(string fileName_or_string){  
        if(isFile(fileName_or_string)){
            loadFromFile(fileName_or_string);
        }
        else{
            loadFromString(fileName_or_string);
        }
    }
    void loadFromFile(string fileName){
        ifstream file(fileName);
        string word;
    while (file >> word) {
        string clean_word;
        for (char c : word) {
            if (isalpha(c)) {
                clean_word.push_back(tolower(c));
            }
        }
        if (!clean_word.empty()) {
            string_set.insert(clean_word);
        }
    }
    file.close();
    }
    void loadFromString(string str){
        string word;
    for (char c : str) {
        if (isalpha(c)) {
            word.push_back(tolower(c));
        } else if (!word.empty()) {
            string_set.insert(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        string_set.insert(word);
    }
    }
    void Add_string(string input){
        string_set.insert(input);
    }
    void Remove_string(string input){
        auto target=find(string_set.begin(),string_set.end(),input);
        if(target!=string_set.end()){
            string_set.erase(target);
        }
    }
    void clear_set(){
        string_set.clear();
    }
    int get_size_of_set(){
        return string_set.size();
    }
    void print_set(){
        for(auto it:string_set){
            cout<<it<<endl;
        }
    }
    StringSet operator+(StringSet another){
        StringSet result;
        result.string_set=string_set;
        for(auto it:another.string_set){
           if(find(result.string_set.begin(),result.string_set.end(),it)==result.string_set.end()){
                result.string_set.insert(it);
           }
        }
        return result;
    }
    StringSet operator*(StringSet another){
        StringSet result;
        for(auto it:another.string_set){
        if(find(string_set.begin(),string_set.end(),it)!=string_set.end()){
            result.string_set.insert(it);
        }
    }
    return result;
}
double Similarity(StringSet another){
    double similarity;
    if(string_set.size()==0&&another.string_set.size()==0){
        similarity=1;
    }
    else if(string_set.size()==0||another.string_set.size()==0){
        similarity=0;
    }
    else{
        int intersection=((*this) * another).get_size_of_set();
        similarity=intersection/(sqrt((*this).get_size_of_set())*sqrt(another.get_size_of_set()));
    }
    return similarity;
}
};
int main(){
    StringSet s1("doc1.txt");
    StringSet s2("Chocolate ice cream, chocolate milk, and chocolate bars are delicious.");
    cout<<"words of s1 : \n";
    s1.print_set();  
    cout<<"--------------------------------------------------------------------------------------------------------\n";
    cout<<"words of s2: \n";
    s2.print_set(); 
    cout<<"-------------------------------------------------------------------------------------------------------\n"; 
    StringSet s3=s1+s2;
    cout<<"union of s1,s2 is: \n";
    s3.print_set(); 
    cout<<"-----------------------------------------------------------------------------------------------------\n";
    StringSet s4=s1*s2;
    cout<<"intersection of s1,s2 is: \n";
    s4.print_set();
    cout<<"-------------------------------------------------------------------------------------------------------\n";
    double s5=s1.Similarity(s2);
    cout<<"similarity between 2 documents= "<<s5;
}