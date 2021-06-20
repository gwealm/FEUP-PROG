#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

/*
void simplify(const string& name, string& sName) {
	size_t firstSpace = name.find_first_of(' '), lastSpace = name.find_last_of(' ');
	string firsName = name.substr(0, firstSpace), lastName = name.substr(lastSpace + 1);
	sName = firsName + ' ' + lastName;
}

int main() {
	ifstream infile("people1.txt");
	if (!infile.is_open()) {
		cerr << "people1.txt not found\n";
		exit(1);
	}

	string name, sName;
	// vector<string> namesVec;
	ofstream outfile("peopl2.txt");
	while (getline(infile, name)) {
		simplify(name, sName);
		// namesVec.push_back(sName);
		// sort(namesVec.begin(), namesVec.end())
		outfile << sName << "\n";
	}
	
	//for (const auto &name : namesVec) {
	//	outFile << name << "\n;
	//}
	infile.close(); outfile.close();
	
	return 0;
}
*/

/*
class Date {
	friend istream& operator>>(istream& f, Date& date);
	friend ostream& operator<<(ostream& f, const Date& date);
	friend bool operator<(const Date& left, const Date& right);
	friend bool operator==(const Date& left, const Date& right);
public:
	Date(int y = 1, int m = 1, int d = 1);
	// ... other methods 
private:
	int y, m, d; // year, month, day 
};

Date::Date(int y, int m, int d) {
	this->y = y;
	this->m = m;
	this->d = d;
}

bool operator<(const Date& left, const Date& right) {
	int lefY = left.y, leftM = left.m, leftD = left.d, rightY = right.y, rightM = right.m, rightD = right.d;
	string leftStr, rightStr;
	stringstream ss;
	ss << setfill('0') << setw(4) << lefY << setw(2) << leftM << setw(2) << leftD;
	leftStr = ss.str();
	ss.clear();
	ss << setfill('0') << setw(4) << rightY << setw(2) << rightM << setw(2) << rightD;
	rightStr = ss.str();
	return leftStr < rightStr;
}

istream& operator>>(istream& f, Date& d) {
	char sep = '-';
	f >> d.y >> sep >> d.m >>  d.d;

	if (!f.good() || d.y < 0 || d.m < 0 || d.y < 0) throw runtime_error("Invalid Date");

	return f;
}


int main() {
	Date d1, d2;
	try {
		cout << "Insert the first date: "; cin >> d1;
		cout << "Insert the second date: "; cin >> d2;
	} catch (const runtime_error &err) {
		cerr << err.what() << endl;
		exit(1);
	}
	if (d1 == d2) {
		cout << d1 << " = " << d2 << endl;
	} else if (d1 < d2) {
		cout << d1 << " < " << d2 << endl;
	} else {
		cout << d1 << ">" << d1 << endl;
	}

	return 0;
}


class Image{
public:
	Image(size_t nLins = 0, size_t nCols = 0, int pixVal = 0); //nLins & nCols are the dimensions 
	//  of the image; pixVal is the initial value of every pixel 
	void setPixel(size_t lin, size_t col, int pixVal); //modifies the value of the pixel at (lin,col)
	bool read(string fileName); // reads the image saved in file fileName, storing it in img ; 
	//  returns true if sucessful, false otherwise 
	Image getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const;
	// returns an image containing a rectangular region of img
	int getPixel(size_t lin, size_t col) const;
 
private:
	vector < vector<int> > img; // image representation 
	// ... other attributes
};

Image Image::getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const {
	Image crop(nLins, nCols, 0);
	vector<int> line;
	size_t cropLine = 0, cropCol = 0;

	for (int i = lin; i < (lin + nLins); i++) {
		for (int j = col; j < (col + nCols); j++) {
			int currPixel = img.at(i).at(j);
			crop.setPixel(cropLine, cropCol, currPixel);
			cropCol++;
		}
		cropCol = 0;
		cropLine++;
	}
	return Image();
}
*/
/*
* Eu escolheria map<Date, vector<Image>>, porque como um std::map é uma estrutura de dados
* associativa permitiria que a um grupo de imagens (separadas por data) fosse associada uma
* determinada data, na qual estas foram tiradas. O acesso seria eficiente, porque teríamos
* apenas de iterar pelo vetor, visto que teríamos "acesso direto" a um vector de Imagens, atráves
* da key Date
*/

/*
int main() {
	map<Date, vector<Image>> dailyImages;
	vector<Image> imagesTook;
	stringstream ss;
	Date d1;
	string fileName;
	
	while (getline(cin, fileName) && !fileName.empty()) {
		Image img;
		ss << fileName;
		string correctFilename = ss.str();
		ss.clear();
		imagesTook.push_back(img);
	}

	dailyImages.insert(pair<Date, vector<Image>>(d1, imagesTook));

	return 0;
}


template <class T>
class Image {
public:
	Image(size_t nLins = 0, size_t nCols = 0, T pixVal = 0); //nLins & nCols are the dimensions 
	//  of the image; pixVal is the initial value of every pixel 
	void setPixel(size_t lin, size_t col, T pixVal); //modifies the value of the pixel at (lin,col)
	bool read(string fileName); // reads the image saved in file fileName, storing it in img ; 
	//  returns true if sucessful, false otherwise 
	Image getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const;
	// returns an image containing a rectangular region of img
	int getPixel(size_t lin, size_t col) const;

private:
	vector <vector<T>> img; // image representation 
	// ... other attributes
};
*/

/*
int readNumber(string msg) {
	int number;
	cout << msg; cin >> number;
	return number;
}

// int num = readNumber("Grade? ");

void readNumber(string msg, int& number) {
	int number;
	cout << msg; cin >> number;
}

// int number = 0;
// readNumber("Grade? ", number);


 // b) Sim, é porque existem parametros default

 // c) Udaria arrays e alocava memoria dinamicamente quando necessitasse de construir um novo objeto
 // Sim, um destrutor para  libertar a memória dinamicamente alocada

 Image::Image(size_t nLins = 0, size_t nCols = 0, int pixVal = 0) {
	 int **img = (int**)malloc(nCols * sizeof(int*));

	 for (int k = 0; k < nCols; k++) {
		 img[k] = (int*)malloc(nLins * sizeof(int));
	 }


	 for (int i = 0; i < nCols; i++) {
		 for (int j = 0; j < nLins; j++)
			img[i][c] = -1;
	 }
 }
 */

 //e)  Porque as std::list suportam bidirectional iterators, logo é impossível usar objetos do
 //    tipo list com um algoritmo que necessita de RandomAcessIterator

 /*
 * virtual void draw() = 0; signfica que o método puramente virtual draw() da classe mãe necessita, obrigatoriamente,
 * de ser definido nas classes derivadas (pois serve apenas como "interface" que será definida posteriormente)
 * Isto implica que cada classe tenha de implementar o método draw(), sendo este o mesmo ou não
 */