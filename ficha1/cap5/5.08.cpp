#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

typedef std::pair<unsigned, unsigned> betResult;

struct EuroMillionsBet {
    std::vector<unsigned> mainNumbers;
    std::vector<unsigned> luckyStars;
};

void readBet(EuroMillionsBet &bet);
void generateRightNumbers(EuroMillionsBet &bet);
void vectorIntersections(const std::vector<unsigned> &v1, const std::vector<unsigned> &v2, std::vector<unsigned> &v3);
void bubbleSortV2(std::vector<unsigned> &v, bool f(int x, int y));
void displayBet(const EuroMillionsBet &bet);
betResult calculateScore(const EuroMillionsBet &bet, const EuroMillionsBet &rightBet, EuroMillionsBet &result);


int main() {
    srand(time(nullptr));
    
    EuroMillionsBet playerBet, rightBet, result;
    betResult numResult;

    // Generating player and random bet
    readBet(playerBet);
    generateRightNumbers(rightBet);

    // Calculating score;
    numResult = calculateScore(playerBet, rightBet, result);

    // Displaying result stats
    std::cout << "You've got " << numResult.first << " main numbers right" << std::endl;
    std::cout << "You've got " << numResult.second << " lucky stars right" << std::endl;

    return 0;
}


void readBet(EuroMillionsBet &bet) {
    //std::vector<unsigned> mainNumbers;
    std::vector<unsigned> luckyStars;
    
    for(int i = 0; i < 12; i++) {
        unsigned mainBet;
        std::cout << "Choose bet number " << i + 1 << " (between 1 and 50): ";
        std::cin >> mainBet;
        bet.mainNumbers.push_back(mainBet);
    }

    unsigned luckyStar;

    // Lucky star number 1
    std::cout << "Choose lucky star number 1 (between 1 and 12): ";
    std::cin >> luckyStar;
    bet.luckyStars.push_back(luckyStar);

    // Lucky star number 2
    std::cout << "Choose lucky star number 2 (between 1 and 12): ";
    std::cin >> luckyStar;
    bet.luckyStars.push_back(luckyStar);
}


void generateRightNumbers(EuroMillionsBet &bet) {
    for(int i = 0; i < 12; i++) {
        unsigned mainBet = rand() % 50 + 1;
        bet.mainNumbers.push_back(mainBet);
    }
    unsigned luckyStar;
    luckyStar = rand() % 12 + 1;
    bet.luckyStars.push_back(luckyStar);
    luckyStar = rand() % 12 + 1;
    bet.luckyStars.push_back(luckyStar);
}


void bubbleSortV2(std::vector<unsigned> &v, bool f(int x, int y)) {
    bool notSorted = true;
    while (notSorted) {
        notSorted = false;
        for (int i = 0; i < v.size() - 1; i++) {
            int curr = v.at(i);
            int next = v.at(i + 1);
            if (f(curr, next)) {
                std::swap(v.at(i), v.at(i + 1));
                notSorted = true;
            }
        }
    }
}


void vectorIntersections(const std::vector<unsigned> &v1, const std::vector<unsigned> &v2, std::vector<unsigned> &v3) {
    std::vector<unsigned> v4 = v1;
    v4.insert(v4.end(), v2.begin(), v2.end());
    bubbleSortV2(v4, [](int n1, int n2) {return n1 > n2;});

    for (int i = 0; i < v4.size() - 1; i++) {
        if (v4.at(i) == v4.at(i + 1)) { v3.push_back(v4.at(i));}
    }
    bubbleSortV2(v3, [](int n1, int n2) {return n1 > n2;});
}


void displayBet(const EuroMillionsBet &bet) {
    for (auto i : bet.mainNumbers) {
        std::cout << i << " | ";
    }
    std::cout << std::endl;

    for (auto j : bet.luckyStars) {
        std::cout << j << " | ";
    }
    std::cout << std::endl;
}


betResult calculateScore(const EuroMillionsBet &bet, const EuroMillionsBet &rightBet, EuroMillionsBet &result) {
    // Calculates the lists of right main numbers and lucky stars
    vectorIntersections(bet.mainNumbers, rightBet.mainNumbers, result.mainNumbers);
    vectorIntersections(bet.luckyStars, rightBet.luckyStars, result.luckyStars);

    displayBet(bet);
    displayBet(rightBet);
    displayBet(result);

    // Number of right main numbers and lucky stars
    std::cout << "KEKW" << std::endl;
    betResult nums = {result.mainNumbers.size(), result.luckyStars.size()};
    return nums;
}