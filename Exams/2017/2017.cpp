#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

/*
void toUpperStr(string *s) {
	string upperStr;
	for (int i = 0; i < s->length(); i++) {
		if (islower(s->at(i))) s->at(i) = toupper(s->at(i));
	}
}


string transformLine(const string s) {
	string newStr;
	for (char chr : s) {
		if (isalpha(chr) || isspace(chr))
			newStr += chr;
		else
			newStr += ' ';
	}
	return newStr;
}


void decomposeLine(const string &line, vector<string> &words) {
	string newLine = transformLine(line);
	stringstream ss(newLine);

	string word;
	while (ss >> word) {
		words.push_back(word);
	}
}


int main() {
	ifstream file("C:\\docs\\text.txt");
	vector<string> wordsFile;
	vector<string> line;
	string lin;
	
	while (getline(file, lin)) {
		decomposeLine(lin, line);
		wordsFile.insert(wordsFile.end(), line.begin(), line.end());
		line.clear();
	}

	file.close();
	sort(wordsFile.begin(), wordsFile.end());


	ofstream newFile("words.txt");
	for (const string& wrd : wordsFile) {
		newFile << wrd << "\n";
	}
	newFile.close();
	
	return 0;
}
*/

/*
* Usar um std::set<words> (Sendo words std::string), de modo a que não fosse permitida a 
* existència de palavras repetidas
*/
/*
set<string> wordSet;
for (const string &str : wordsFile) {
	wordSet.insert(str);
}
wordsFile.clear();
for (string str : wordsFile) {
	wordsFile.push_back(str);
}
*/

//--------------------------------------------------------------------------------------------------------------------

/*
* É possível fazê-lo, porque o construtor de Board ( Board(size_t numLines = 10, size_t numColumns = 10) ) tem
* os seus parâmetros com um default value, oou seja, se nao for passado nenhum valor, numLines = 10 e size_t numColumns = 10.
* Na classe Ship isto não accontece
*/


// Ships -> 1 to 5
// Sea   -> -1

/*
struct Position {
	int lin, col;
};

class Ship {
public:
	Ship(unsigned int identifier, char symbol, Position position, char direction, size_t size);
	unsigned int id() const; //returns identifier
	Position pos() const; //returns position   
	char dir() const;  //returns direction  
	size_t size() const; //returns size
	// ... OTHER METHODS
private:
	unsigned int identifier; // ship id number
	// ... OTHER ATTRIBUTES AND/OR METHODS
};


class Board {
public:
	Board(size_t numLines = 10, size_t numColumns = 10);
	bool putShip(const Ship& s); //add ship to board, if possible
	// ... OTHER METHODS
private:
	bool canPutShip(Position pos, char dir, size_t size);
	size_t numLines, numColumns;
	vector<vector<int>> board; // each element = ship id or ‐1   
	vector<Ship> ships;
	// ... OTHER ATTRIBUTES AND/OR METHODS
};

Board::Board(size_t numLines, size_t numColumns) {
	this->numColumns = numColumns;
	this->numLines = numLines;
	board.resize(numLines, vector<int>(numColumns, -1));
}

bool Board::putShip(const Ship& s) {
	Position pos = s.pos();
	char dir = s.dir();
	size_t size = s.size();
	bool canPlace = canPutShip(pos, dir, size);
	if (!canPlace) return false;

	size_t MIN_LINE = 0, MAX_LINE = board.size(), MIN_COL = 0, MAX_COL = board.at(0).size();
	switch (dir) {
		case 'H':
			for (size_t i = 0; i < MAX_COL; i++) {
				board.at(pos.lin).at(pos.col - i) = s.id();
			}
		case 'V':
			for (size_t i = 0; i < MAX_LINE; i++) {
				board.at(pos.lin - i).at(pos.col) = s.id();
			}
	}
	return true;
}

bool Board::canPutShip(Position pos, char dir, size_t size) {
	size_t MIN_LINE = 0, MAX_LINE = board.size(), MIN_COL = 0, MAX_COL = board.at(0).size();
	switch (dir) {
	  case 'H': // TO DO: test if ship with length 'size' can be put at 'pos', in horizontal direction         
		  
		  for (size_t i = 0; i < size; i++) {
			  if ((pos.lin - i) < MIN_LINE || (pos.lin - i) > MAX_LINE || pos.col < MIN_COL || pos.col > MAX_COL) {
				  return false;
			  } else if (board.at(pos.lin - 1).at(pos.col) != -1) {
				  return false;
			  }
		  }
		  return true;

	  case 'V': // TO DO, just this line: test if ship ... can be put in vertical direction
		// DONE. This piece of code was correctly implemented but was carelessly erased …
	}
	return true;
}


int main() {
	Board board(10, 20);
	cout << "Insert ship data:" << endl;
	
	unsigned int id = 0;
	Position pos = { 0, 0 };
	char dir, symbol;
	size_t sizeShip = 0;

	cout << "Id: ";
	cin >> id;

	cout << "Dir: ";
	cin >> dir;

	cout << "Symbol: ";
	cin >> symbol;

	cout << "Pos (lin and col) : ";
	cin >> pos.lin >> pos.col;

	cout << "Size: ";
	cin >> sizeShip;

	Ship ship(id, symbol, pos, dir, sizeShip);

	bool canPlace = board.putShip(ship);

	if (!canPlace) throw "Can't put ship!";

	board.putShip(ship);

	return 0;
}

*/


/*
float average(const int grades[], int numStudents) {
	int sum = 0;
	for (int i = 0; i < numStudents; i++) {
		sum += grades[i];
	}

	return static_cast<float> (sum) / numStudents;
}

int main() {
	int studentsNum;

	cout << "Number of students: ";
	cin >> studentsNum;

	int* grades = (int*)malloc(studentsNum * sizeof(int));

	readGrades(grades, studentsNum);

	for (int i = 0; i < studentsNum; i++) {
		cout << grades[i] << " | ";
	}
}
*/

/*
* c)
* Seria necessário passar uma função de comparação entre elementos do tipo Position,
* uma vez que não é implícito para o compilador como comparar variáveis deste tipo.
* 
* d)
* 2 3
* 2
* 2 3
* ----------------------------
* 2 3
* 2
* 2
* ----------------------------
* Nao compilaria, porque os protected da classe Base (_a) ficariam privados
* e a classe Derived nao teria acesso a estes
*/
