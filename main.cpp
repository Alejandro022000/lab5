
#include <map>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

string delete_punctuaction(string);
void to_lower(string &single_word){
  for (int x=0; x<single_word.size(); x++)
        single_word[x] = tolower(single_word[x]);
}

int main(int argc, char *argv[]) {
string single_word;
map<string, int> dict;

ArgumentManager am(argc, argv);
ifstream input(am.get("input"));
ofstream output(am.get("output"));
/*
ifstream input("input333.txt");
ofstream output("output.txt");
*/
while(input >> single_word){
  single_word = delete_punctuaction(single_word);
  to_lower(single_word);  
  
  if(dict.find(single_word) == dict.end()){
      dict.insert({single_word, 1});
  }
  else {
      for (auto x :  dict){
          if(single_word == x.first){
              dict[single_word]++;
          }
      }
  }

}

  for(auto x = dict.begin(); x != dict.end(); x++){
    cout << x->first << ": " << x->second << endl;
    output << x->first << ": " << x->second << endl;
  }
  
return 0;
}


string delete_punctuaction(string temp_word){
  string single_word;
  for(int i = 0; i < temp_word.size(); i++){
    if(isalpha(temp_word[i])|| temp_word[i] == '\''){
      single_word += temp_word[i];
    }
  }
  return single_word;
}

