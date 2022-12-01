#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void header(){
    cout <<endl<<setw(10)<<left<<"No."<<setw(20)<<left<<"Student"<<setw(20)<<right<<"score"<<endl;
    cout<<setw(50)<<setfill('-')<<""<<endl;
    cout<< setw(50)<<setfill(' ')<<""<<endl;
    
}
void footer (double scoreAverage, int total){
    cout<<setw(50)<<setfill('-')<<""<<endl;
    cout<< setw(50)<<setfill(' ')<<""<<endl;
    cout <<setw(10)<<""<<setw(20)<<left<<"Score Total" <<setw(20)<<right<<total<<endl<<endl;
    cout<<setw(50)<<setfill('-')<<""<<endl;
    cout<< setw(50)<<setfill(' ')<<""<<endl;
    cout <<setw(10)<<""<<setw(20)<<left<<"Average Score" <<setw(20)<<right<<scoreAverage<<endl;
}

int score (string &modelAnswer, string &studentAnswer){
    int score = 0;
    for (size_t i =0; i<modelAnswer.size(); i++){
        if(studentAnswer.at(i) == modelAnswer.at(i)){
            score++;
        }
    }
    return score;
}

void displayScore(int num, string name, int studentScore){
    cout <<setw(10)<<left<<num<<setw(20)<<left<<name <<setw(20)<<right<<studentScore<<endl;
}

void totalAverage ( int totalScore,int totalStudent){
    double average = 0;
    if(totalStudent!= 0){
            average = static_cast<double>(totalScore)/totalStudent;
    }
    footer(average,totalScore);
}
int main()
{
	ifstream myFile;
    string answerKey;
    string studentName;
    string studentResponce;
    int totalStudent = 0;
    int studentScore = 0;
    int totalScore = 0;
    int num =0;    
    
    myFile.open("responses.txt");
    if(!myFile){
        cerr <<"Problem Opening File"<<endl;
        return 1;
    }
    header();
    myFile>>answerKey;
    while(myFile>>studentName>>studentResponce){
        ++totalStudent;
        ++num;
        studentScore = score(answerKey,studentResponce);
        totalScore += studentScore;
        displayScore(num,studentName,studentScore);
    }
    
    totalAverage(totalScore,totalStudent);

    
    myFile.close();
	return 0;
}
