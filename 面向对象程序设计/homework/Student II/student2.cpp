﻿#include <iostream>
#include <string>
#include <cstring>
#include <iomanip> 
#include <cmath>
using namespace std;
int course_number = 3; //number of courses
const int table_width = 8;//format of output 
const int student_number = 10;//number of students
class Student {
public:
	void set_student_name();//set student_name from input
	void set_student_score();//set student's scores from input
	void get_average_score();//set student's average score by scores
	void print_student_info();//print student's information
	int get_student_score(int i);//get student's score of course i
	float get_student_average_score();//get student's average score
	string get_student_name();//get student's name
	Student() :student_score(new int[course_number]) {}
	~Student() {}
private:
	string student_name;
	int *student_score;//array of student's scores
	float student_average_score;//student's average score
};

void Student::set_student_name() {
	cin >> student_name;
}

void Student::set_student_score() {
	/*set student's scores from input*/
	for (int i = 0; i < course_number; i++)
		cin >> student_score[i];
}

void Student::get_average_score() {
	if (course_number > 0) {//the average score can be calculated only there are more than 1 courses	
		int sum = 0;
		for (int i = 0; i < course_number; i++)
			sum += student_score[i];//the sum of scores of a student
		student_average_score = sum / (float)course_number;
	}
	else
		student_average_score = 0;
}

int Student::get_student_score(int i) {
	if (i >= 0 && i < course_number)
		return student_score[i];
	else
		return 0;
}

float Student::get_student_average_score() {
	return student_average_score;
}

string Student::get_student_name() {
	return student_name;
}

void Student::print_student_info() {
	cout << setiosflags(ios::fixed) << setiosflags(ios::left);//set the output format: Align left
	cout << setw(table_width) << student_name;//set the width of a table
	for (int i = 0; i < course_number; i++)
		cout << setw(table_width) << student_score[i];//output scores
	float temp_average = get_student_average_score();
	if (abs(temp_average - (int)temp_average) < 1e-6) //the average score is an integer
		cout << setw(table_width) << (int)temp_average << endl;//output the average score
	else
		cout << setw(table_width) << setprecision(6) << temp_average << endl;//set precision of the float number
}

int get_course_num() {
	int sum = 0;
	while()
}
int main() {
	int *score_sum = new int[course_number];//storage the sum of score of every course
	float *average_score = new float[course_number];//storage the average score of every course
	int *min_score = new int[course_number];//storage the minimum score of every course
	int *max_score = new int[course_number];//storage the maximum score of every course
	memset(score_sum, 0, sizeof(int)*course_number);//set score_sum's values to 0
	Student *student_list = new Student[student_number];//storage all student's information
	for (int i = 0; i < student_number; i++) {
		student_list[i].set_student_name();
		student_list[i].set_student_score();
		student_list[i].get_average_score();
		for (int j = 0; j < course_number; j++) {
			if (!i) {//i = 0, initialize values of min_score and max_score by the first student's scores
				min_score[j] = student_list[i].get_student_score(j);
				max_score[j] = student_list[i].get_student_score(j);
			}
			else {//update the minimum and maximum scores
				if (min_score[j] > student_list[i].get_student_score(j))
					min_score[j] = student_list[i].get_student_score(j);
				if (max_score[j] < student_list[i].get_student_score(j))
					max_score[j] = student_list[i].get_student_score(j);
			}
			score_sum[j] += student_list[i].get_student_score(j);//add the student's scores to score_sum
		}
	}
	cout << setiosflags(ios::left) << setw(table_width);
	cout << "no      name    score1  score2  score3  average" << endl;
	for (int i = 0; i < student_number; i++) {
		cout << setw(table_width) << (i + 1);//output the number of the student
		student_list[i].print_student_info();//print the student's information
	}
	cout << setprecision(1) << setiosflags(ios::left);//set the precision of minimum scores and maximum scores 
	cout << setw(table_width) << "";
	cout << setw(table_width) << "average";
	for (int j = 0; j < course_number; j++) {
		//get average score of every scorse and output
		average_score[j] = score_sum[j] / (float)student_number;
		cout << setw(table_width) << average_score[j];
	}
	cout << endl << setw(table_width) << "";//an empty table
	cout << setw(table_width) << "min";
	for (int j = 0; j < course_number; j++) {
		cout << setw(table_width) << min_score[j];//output minimum scores
	}
	cout << endl << setw(table_width) << "";
	cout << setw(table_width) << "max";
	for (int j = 0; j < course_number; j++) {
		cout << setw(table_width) << max_score[j];//output maximum scores
	}
	return 0;
}

