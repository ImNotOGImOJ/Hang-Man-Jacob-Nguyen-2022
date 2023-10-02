#include <iostream>
#include <vector>
#include "ufo_functions.hpp"
using namespace std;
int main() {
  string codeword = "superman";
  string answer, t;
  int misses = 0;
  bool guess = false;
  char letter;

  answer = generate(t, codeword);
  vector<char> incorrect;

  greet();

  while(answer != codeword && misses < 6){
    display_misses(misses); 
    display_status(incorrect, answer);  
    cout << "\n enter the word/phrase 1 letter at a time\n to save guy:\n";
    cin >> letter;

    for(int i = 0;i<codeword.size();i++){
     if (letter == codeword[i]){
       answer[i] = letter;
       guess = true;
     } 
    }
    
    if (guess == true){
      cout << "correct\n\n\n\n\n\n\n";
    } else {
      cout << "guy goes up\n\n\n\n\n\n\n";
      incorrect.push_back(letter);
      misses++;
    }
    
    guess = false;
  }
  if (misses == 6){
     display_misses(6);
  } else {
    cout << "you did it!";
  }
  cout << "\n\n\n\n" << end_game(answer, codeword) << "\n\n";
}