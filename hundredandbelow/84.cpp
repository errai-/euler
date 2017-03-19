#include <iostream>
#include <math.h>
#include <cstdint>
#include <vector>
#include <stdlib.h>
#include <random>

using std::uint64_t;
using std::endl;
using std::cout;

class Game{
private:
  int position;
  int diceSum;
  int CCTop;
  int CHTop;
  uint64_t turnCount;
  const int gotosCC[2]; // Tot 16
  const int gotosCH[6]; // Tot 16
  const int locsCC[3];
  const int locsCH[3];
  const int locsU[2];
  int CCOrder[16];
  int CHOrder[16];
  void randomizeCC();
  void randomizeCH();
  std::mt19937_64 mersenne;
  std::uniform_int_distribution<int> dice;
  std::uniform_int_distribution<int> deck;
public:
  Game():
    gotosCC{0,10},
    gotosCH{0,10,11,24,39,5},
    locsCC{2,17,33},
    locsCH{7,22,36},
    locsU{12,28},
    dice(1,4),
    deck(1,16)
  {
    position = 0;
    diceSum = 0;
    CCTop = 0;
    CHTop = 0;
    randomizeCC();
    randomizeCH();
  }

  bool rollDices();
  bool CC();
  bool CH();
  int turn();
  uint64_t getTurnCount(){ return turnCount; }
};

void Game::randomizeCC(){
  for (int i = 0; i != 16; ++i){
    CCOrder[i] = -1;
  }
  int success = 0;
  while (success < 2){
    int probe = deck(mersenne);
    if (CCOrder[ probe ] == -1){
      CCOrder[ probe ] = success;
      ++success;
    }
  }
}

void Game::randomizeCH(){
  for (int i = 0; i != 16; ++i){
    CHOrder[i] = -1;
  }
  int success = 0;
  while (success < 10){
    int probe = deck(mersenne);
    if (CHOrder[ probe ] == -1){
      CHOrder[ probe ] = success;
      ++success;
    }
  }
}

bool Game::rollDices(){
  int die1 = dice(mersenne);
  int die2 = dice(mersenne);
  diceSum = die1+die2;
  return die1 == die2;
}

// return value false if landed to jail
bool Game::CC(){
  bool noJail = true;
  if (CCOrder[CCTop] != -1) {
    position = gotosCC[CCOrder[CCTop]];
    if ( position == 10 ){
      noJail = false;
    }
  }
  CCTop++;
  CCTop = CCTop % 16;
  return noJail;
}

bool Game::CH(){
  bool noJail = true;
  if (CHOrder[CHTop] == -1){
    noJail = true;
  } else if (CHOrder[CHTop] < 6) {
    position = gotosCH[CHOrder[CHTop]];
    if ( position == 10 ){ // If landed in jail, break loop
      noJail = false;
    }
  } else if (CHOrder[CHTop] < 8) {
    int tenLoc = (int) ( (position+5)/10 );
    position = tenLoc*10+5;
    position = position%40;
  } else if (CHOrder[CHTop] == 8) {
    if (locsU[1]<position){
      position = locsU[0];
    } else if (locsU[0]<position){
      position = locsU[1];
    } else {
      position = locsU[0];
    }
  } else if (CHOrder[CHTop] == 9) {
    position -= 3;
    if ( position == 33 ){
      noJail = CC();
    }
  }
  CHTop++;
  CHTop = CHTop % 16;
  return noJail;
}

int Game::turn(){
  bool indicator = true;
  int doubleCalc = 0;

  // Loop dice roll while a new throw is given
  while (indicator){
    indicator = rollDices();
    if (indicator) doubleCalc++;
    if (doubleCalc == 3){
      position = 10;
      break;
    }

    position += diceSum;
    position = position % 40;
    if (position == 30){
      position = 10;
      break;
    }
    for (int i = 0; i != 3; ++i){
      if ( locsCC[i] == position ){
        indicator = CC() && indicator;
        break;
      } else if ( locsCH[i] == position ){
        indicator = CH() && indicator;
        break;
      }
    }
  }

  turnCount++;
  return position;
}

int main(void){

  uint64_t board[40];
  for (int i = 0; i != 40; ++i){
    board[i] = 0;
  }

  int iterations = 10000000;
  Game spels;
  for (int i = 0; i!=iterations; ++i){
    board[spels.turn()]++;
  }

  for (int i = 0; i!=40; ++i){
    double percent = (double) 100.0*board[i]/iterations;
    cout << i << ": " << percent << endl;
  }

  return 0;
}
