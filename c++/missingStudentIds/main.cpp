#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/InsertionSorter/include/InsertionSorter.cpp"

using namespace std;

int main(){
    int totalStudentIds []= 
        {
            180,59,325,197,32,198,337 ,295,247,117,108,234,41,40,139,63,249,86,421,
            409,87,192,12,159,345,312,350,365,296,129,392,13,94,407,348,403,329,330,
            352,271,417,232,418,125,80,70,327,320,54,224,158,309,424,185,286,385,188,
            375,90,226,291,174,395,14,260,380,429,343,181,326,31,140,157,25,383,51,
            9,331,379,308,253,42,321,405,114,346,376,347,212,362,65,64,149,66,402,
            244,307,294,243,19,263,305,306,193,281,278,45,47,46,57,122,283,62,28,
            415,154,371,120,74,43,119,7,204,314,155,34,8,400,199,299,317,29,93,77,
            141,344,388,335,316,88,318,209,393,397,282,169,104,289,190,399,118,358,
            427,121,186,2,259,410,257,166,142,182,389,284,269,351,183,368,161,61,423,
            374,49,223,99,85,275,413,76,150,165,411,268,1,229,100,311,152,250,258,313,
            167,91,92,280,297,35,357,254,273,151,143,264,187,272,285,367,162,60,26,173,
            195,288,420,134,293,123,377,387,208,287,82,265,240,252,6,213,207,72,298,168,
            71,67,189,95,391,217,115,341,24,301,216,105,292,132,68,406,69,102,22,343,372,
            382,430,323,248,178,179,230,177,342,360,75,336,339,4,176,81,364,386,394,144,
            218,233,238,276,148,425,113,354,175,237,363,419,426
        };
    size_t totalStudentIdsSize = sizeof(totalStudentIds)/sizeof(*totalStudentIds);
    
    
    InsertionSorter* insertionSorter = new InsertionSorter(totalStudentIds,totalStudentIdsSize);
    insertionSorter->sort();
    
    vector<int> numbers = insertionSorter->getNumbers();
    vector<int> missingNumbers;
	int numbersIterator = 0;

    for(int i=1;i<numbers[numbers.size()-1];i++){
        if(numbers[numbersIterator] != i){
        	missingNumbers.push_back(i);
        }else{
        	numbersIterator++;
        }
    }


    cout<<"Total master's: "<<totalStudentIdsSize<<endl;
    cout<<"first Master id: "<<numbers[0]<<endl;
    cout<<"last Master id: "<<numbers[numbers.size()-1]<<endl;
    cout<<endl;
    cout<<"total Missing Id's: "<<missingNumbers.size()<<endl;
    cout<<"first Missing id: "<<missingNumbers[0]<<endl;
    cout<<"last Missing id: "<<missingNumbers[missingNumbers.size()-1]<<endl;

}