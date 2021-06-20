#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

/*
class Purse
{
public:
	Purse(); // cria um porta moedas vazio sem dono especificado
	Purse(string owner); // cria um porta moedas vazio cujo dono é "owner"
	void addCoin(float coin); // acrescenta a moeda indicada como parâmetro
	void addCoins(vector<float> coins); // acrescenta as moedas indicadas como parâmetro
	bool removeCoin(float coin); //se existir uma moeda com o valor indicado como parâmetro remove‐a e retorna true, se não retorna false
	bool removeAmount(float amount, vector<float> &coins); // VER DESCRIÇÃO NA ALÍNEA a)
	float tellAmount() const; // retorna o montante total
	vector<float> tellCoins() const; // retorna uma cópia do vetor das moedas
	void show() const; // mostra o dono, as moedas e o montante total
	// ... outros métodos
	static vector<float> possibleCoins; // moedas possíveis: 2, 1, 0.5, 0.2 e 0.1 euro
	friend bool operator==(const Purse& purse1, const Purse& purse2);
private:
	string owner; // o dono do porta‐moedas
	vector<float> coins; // as moedas
	float amount; // o montante total (soma do valor das moedas)
};
*/
/*
* A declaração seria feita no global scope do programa
* O qualificativo static significa que o vetor possibleCoins é comum a todos os objetos da classe Purse
*/
/*
vector<float> Purse::possibleCoins = {2, 1, 0.5F, 0.2F, 0.1F};

Purse::Purse() {};

Purse::Purse(string owner) {
	this->owner = owner;
	coins = {};				// nao é necessario
	amount = 0;
}

void Purse::addCoins(vector<float> coins) {
	this->coins.insert(this->coins.end(), coins.begin(), coins.end());
	for (const float& coin : coins) {
		amount += coin;
	}
}

bool Purse::removeCoin(float coin) {
	vector<float>::iterator it = search(coins.begin(), coins.end(), coin);
	if (it != coins.end()) {
		coins.erase(it);
		amount -= coin;
		return true;
	}
	return false;
}

bool operator==(const Purse& purse1, const Purse& purse2) {
	if (purse1.amount != purse2.amount) return false;
	vector<float> vec1 = purse1.coins;
	vector<float> vec2 = purse2.coins;
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	return (vec1 == vec2);
}

int main() {
	//(time(nullptr));

	Purse anaPurse("Ana");
	anaPurse.addCoins({2, 1, 0.5f, 0.5f, 0.2f, 0.2f, 0.1f});

	Purse purse;

	for (int i = 0; i < 7; i++) {
		int option = rand() % 6;
		purse.addCoin(purse.possibleCoins.at(option));
	}

	purse.show();

	cout << "The content on the 2 purses " << ((anaPurse == purse) ? "is" : "is not") << " the same." << endl;

	return 0;
}
*/

/*
* As moedas podiam ser representadas por um map<Quantity, Amount> (Quantity being a float and Amount being an integer)
*/

/*
map<float> coins;

void Purse::addCoins(float coin) {
	if (coins.find(coin) == coins.end()) {
		coins.insert(pair<float, int>);
	} else {
		coins[coin]++
	}
}
*/

//----------------------------------------------------------------------------------------------------------------------

/*
class Board {
	vector<vector<char>>	board;
	size_t					numLines;
	size_t					numCols;
	char					emptySymbol;
public:
	Board(size_t numLines, size_t numCols, char emptySymbol);
	size_t getLine(size_t line) const;
	string getColumn(size_t column) const;
	char   getCell(size_t line, size_t col) const;
	bool setCell(char pieve, size_t line, size_t col);
	void displayBoard() const;
};

Board::Board(size_t numLines, size_t numCols, char emptySymbol) {
	this->numLines = numLines;
	this->numCols = numCols;
	this->emptySymbol = emptySymbol;
	board.resize(numCols, vector<char>(numLines, emptySymbol));
}

size_t Board::getLine(size_t line) const {
	string lineStr;
	for (int i = 0; i < numCols; i++) {
		lineStr += board.at(line - 1).at(i);
	}
	
}

string Board::getColumn(size_t column) const {
	string col;
	for (int i = 0; i < numLines; i++) {
		if (i == column) col += board.at(i).at(column - 1);
	}
	return col;
}

bool testSequence(const Board& board, size_t& col, char symbol, size_t num) {
	string seq(num, symbol);
	string colStr = board.getColumn(col);
	size_t found = colStr.find(seq);
	return (found != string::npos);
}
*/

//----------------------------------------------------------------------------------------------------------------------

// a) 1 - 2

/*
class Point {
public:
	Point();
	Point(int x, int y);

	Point setX(int x);
	Point setY(int y);
private:
	int x, y; // coordenadas do ponto
};


int main() {
	Point p1, p2(-1, 5);
	p1.setX(2).setY(-3);

	return 0;
}
*/

/*
template<typename T1, typename T2>
class Point {
	T1			x_;
	T2			y_;
public:
	Point();
	Point(T1 x, T2 y);

	T1 getX() const;
	T2 getY() const;
};

int main() {
	Point<char, int> p('A', 3);
	return 0;
}
*/

/*
* Sim, é possivel, porque std::vector suporta iteradores do tipo RandomIterator e a função reverse exige apenas
* iteradores do tipo BidirectionalIterator
* reverse(vec.begin(), vec.end());
*/



/*
* Sim, é possível, contudo vai ocorrer slicing da classe Bird ou Fish ao ser guardadas em variaveis do tipo animal. (ou, seja
* os atributos que forem exclusivos da classe Bird ou Fish) e nao tambem da classe Animal vao ser excluídos
* Para fazer isto corretamente deve ser criado um vetor para um objeto do tipo animal que pode ser dinamically casted para
* qualquer um dos dois tipos derivados
*/