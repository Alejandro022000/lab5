
#include <map>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"

using namespace std;

string removePunct(string w){
  string word;
  for(int i = 0; i < w.size(); i++){
    if(w[i] == '\'' || isalpha(w[i]) || isdigit(w[i]))
      word += w[i];
  }
  return word;
}

int main(int argc, char *argv[]) {

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

/*
ifstream input("input3.txt");
ofstream output("output.txt");
*/
  
map<string, int> hmap;
string word;

while(input >> word){
  word = removePunct(word);

  transform(word.begin(), word.end(), word.begin(), ::tolower);
  
    if(hmap.find(word) == hmap.end()){
        hmap.insert({word, 1});
    }

    else {
        for (auto x :  hmap){
            if(word == x.first){
                hmap[word]++;
            }
        }
    }

}

  for(auto x = hmap.begin(); x != hmap.end(); x++){
    output << x->first << ": " << x->second << endl;
  }
  
return 0;
}//end main