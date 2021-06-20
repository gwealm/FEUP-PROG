#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

typedef vector<unsigned int> vuid;

/* 1

vector<unsigned int>genRandom(unsigned int n, unsigned int m) {
	vector<unsigned int> randVec;
	for (unsigned int i = 0; i < n; i++) {
		unsigned int nRand = rand() % (m + 1);
		randVec.push_back(nRand);
	}
	return randVec;
};

unsigned int *genRandomC(unsigned int n, unsigned int m) {
	unsigned int* randArr = (unsigned int*)malloc(n * sizeof(unsigned int));
	for (unsigned int i = 0; i < n; i++) {
		unsigned int nRand = rand() % (m + 1);
		randArr[i] = nRand;
	}
	return randArr;
}


unsigned int vectorReduce(const vector<unsigned int>& v1, vector<unsigned int>& v2) {
	unsigned int count = 0;
	for (size_t i = 0; i < v1.size(); i++) {
		for (size_t j = 0; j < v2.size(); j++) {
			if (v1.at(i) == v2.at(j)) {
				v2.erase(v2.begin() + j);
				count++;
				j--;
			}
		}
	}
	return count;
}


void displayVector(const vector<unsigned int> &v1) {
	for (const unsigned int& el : v1) {
		cout << setw(2) << el << " ";
	}
	cout << endl;
}


int main() {
	unsigned int n, m;
	cout << "n? ";
	cin >> n;
	cout << "m? ";
	cin >> m;

	vuid v1 = genRandom(n, m);
	vuid v2 = genRandom(n, m);

	unsigned int count = vectorReduce(v1, v2);

	displayVector(v1);
	displayVector(v2);

	cout << count << " elements were removed from 2nd vector\n";

	return 0;
}
*/

/*

class Game {
public:
	Game(const string& filename);
	int neighborMines(int line, int col) const;
		// other methods;
private:
	vector<vector<char>> mines;
		// other attributes

};

Game::Game(const string& filename) {
	ifstream f(filename);

	if (!f.is_open()) exit(1);
	char sep;
	int numlines, numcols, line, col;
	f >> numlines >> sep >> numcols;
	mines.resize(numlines, vector<char>(numcols, ' '));
	while (line >> sep >> col) mines.at(line).at(col) = 'M';
}


int Game::neighborMines(int line, int col) const
{	
	const int MIN_LINE = 0, MIN_COL = 0, MAX_LINE = mines.size(), MAX_COL = mines.at(0).size();

	vector<vector<int>> adjacentCells = {
											{line - 1, col - 1}, {line - 1, col}, {line - 1, col + 1},
											{line, col - 1},	    			{line, col + 1},
											{line + 1, col + 1}, {line + 1, col}, {line + 1, col + 1}
	};
	for (int i = 0; i < adjacentCells.size(); i++) {
		int currLine = adjacentCells.at(i).at(0);
		int currCol = adjacentCells.at(i).at(1);
		if (!(currLine < MIN_LINE || currLine >= MAX_LINE || currCol < MIN_COL || currCol >= MAX_COL)) {
			if (mines.at(currLine).at(currCol) == 'M') throw runtime_error("boom");
		}
	}
	return 0;
}

*/

/*
class Student              // representa um estudante 
{
public:
	Student(int id = 0, const string& name = "");
	int getId() const;
	string getName() const;
	void enrollCourse(Course* course);
	bool setGrade(int courseId, int grade);
	double getAverageGrade() const;
	// ... outros métodos 
private:
	int id;                   // número de identificação do estudante 
	string name;              // nome do estudante 
	vector<Course*> courses; // UC's em que está matriculado 
	map<int, int> grades;     // notas obtidas nas UC's (chave= courseId) 
	// ... outros atributos 
};
//-------------------------------------------------------------------   
class Course                // representa uma unidade curricular (UC) 
{
public:
	Course(int id = 0, const string& name = "");
	int getId() const;
	string getName() const;
	// ... outros métodos  
private:
	int id;
	string name;
	// ... outros atributos 
};


Student::Student(int id, const string& name) {
	this->id = id;
	this->name = name;
}


void Student::enrollCourse(Course* course) {
	courses.push_back(course);
}


bool Student::setGrade(int courseId, int grade) {
	for (auto course : courses) {
		if (course->getId() == courseId) {
			if (this->grades.find(grade) == grades.end()) {
				this->grades.insert(pair<int, int>(courseId, grade));
				return true;
			}
		}
	}
	return false;
}


double Student::getAverageGrade() const {
	int sum = 0;
	for (const auto& kvp : grades) {
		sum += kvp.second;
	}
	return ceil(static_cast<double> (sum) / grades.size());
}



int main() {

	Course prog(1, "PROG");
	Student ada(12345, "Ada");
	ada.enrollCourse(&prog);
	ada.setGrade(1, 20);

	return 0;
}
*/

/* b) Sim, considero, porque se optassemos por usar vector<Course> courses não só teriamos mais custos de memória, porque em vez de
*  termos um vetor de apontadores para cursos, teríamos uma cópia de um vetor de cursos para cada estudante. Para além disso, a probabilidade
* de erro seria maior, uma vez que a cada atualização de um Curso, teríamos de fazer essa alteração para todos os estudantes que frequentassem o mesmo.
*
* c) map<ID, map<Year, Grade>> grades  ( sendo ID, Year e Grade ints)
* Pois desta forma teriamos por UC um map que associa a nota em cada ano que esta foi frequentada (estudante se matriculou)
* Como sao usados maps (contentores associativos), o acesso à nota obtida numa UC em determinado ano seria feito de forma eficiente
*/