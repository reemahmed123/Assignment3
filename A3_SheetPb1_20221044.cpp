// File name: A3_SheetPb1_20221044.cpp
// Purpose: Label Generator
// Author(s): Ganna mohamed ibrahim helal
// ID(s): 20221044
// Section: s7
// Date: 9/12/2023

#include <bits/stdc++.h>
using namespace std ;
class LabelGenerator {
private:
    string prefix ;
    int num ;
public:
    LabelGenerator(string pre , int a){
        prefix = pre ;
        num =a ;
    }
    virtual string nextLabel(){
        return(prefix+" "+ to_string(num++) ) ;
    }
};

class FileLabelGenerator : public LabelGenerator {
private:
    string fileName;
    vector<string> labels;
    int currentLabelIndex = 0;

    void loadLabelsFromFile() {
        ifstream file(fileName);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                labels.push_back(line);
            }
            file.close();
        }
    }

public:
    FileLabelGenerator(string pre,int a, string s ): LabelGenerator(pre,a) , fileName(s){
        loadLabelsFromFile();
}
    string nextLabel() {
        string fileLabel = labels[currentLabelIndex];
        string generatedLabel = LabelGenerator::nextLabel();
        currentLabelIndex ++;
        return generatedLabel + " - " + fileLabel;
    }

};

int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    FileLabelGenerator figureLabels("Figure ", 1, "label.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
    cout << endl;
    return 0;
}
