#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
	Student();   
	Student(const string& code, const string& name);
	void setGrades(double shortExam, double project, double exam);
	string getCode() const;   
	string getName() const;
	int getFinalGrade() const;														// other get and set methods   
	bool isApproved() const;														// is the student approved or not ?   
	static int weightShortExam, weightProject, weightExam;							// weights in percentage (ex:20,30,50)
private:   
	string code;																	// student code   
	string name; 																	// student complete name   
	double shortExam, project, exam; 												// grades obtained by the student in the different components   
	int finalGrade; 
};

// Static variables initialization
int Student::weightShortExam = 20, Student::weightProject = 30, Student::weightExam = 50;


void Student::setGrades(double shortExam, double project, double exam) {
	this->shortExam = shortExam;
	this->project = project;
	this->exam = exam;

	finalGrade = static_cast<int> (round((shortExam * weightShortExam + project * weightProject + exam * weightShortExam) / 100));
}


Student::Student() { shortExam = 0, project = 0, exam = 0, finalGrade = 0; }


Student::Student(const string& code, const string& name) {
	this->code = code;
	this->name = name;
}


string Student::getCode() const {
	return this->code;
}


string Student::getName() const {
	return this->name;
}


int Student::getFinalGrade() const {
	return this->finalGrade;
}


bool Student::isApproved() const {
	return (getFinalGrade() >= 9.5);
}


Student readStudentData() {
	string code, name;
	double shortExam, project, exam;

	cout << "Student code? ";
	cin >> code;

	cout << "Student name? ";
	cin >> name;

	cout << "Short exam grade? ";
	cin >> shortExam;

	cout << "Project grade? ";
	cin >> project;

	cout << "Exam grade? ";
	cin >> exam;

	Student student(code, name);
	student.setGrades(shortExam, project, exam);
	return student;
}


void showAboveAverageStudents(ostream& out, const vector<Student>& studentVec) {
	double sum = 0;
	for (const Student &stud : studentVec) sum += stud.getFinalGrade();

	double average = static_cast<double> (sum) / studentVec.size();

	for (const Student& stud2 : studentVec) {
		if (stud2.getFinalGrade() > average) {
			out << stud2.getName() << "\t"
				<< stud2.getCode() << "\t"
				<< stud2.getFinalGrade() << "\t"
				<< endl;
		}
	}
}


int main() {
	vector<Student> studsVec;

	while (true) {
		Student stud = readStudentData();

		if (cin.fail()) { break; }
		studsVec.push_back(stud);
	}

	showAboveAverageStudents(cout, studsVec);
	return 0;
}