#include <iostream>
#include <fstream>
#include <string>
#include "spell_data.h"

using namespace std;

//writes out spell names and seperates lines needed by later get data function
int main(){
    Spell spell;
    std::vector<std::string> names;
    std::string filename;
    cout<<"enter filename"<<endl;
    getline(cin,filename);
    spell.thresh(filename,names);
    //std::vector<Spell> spell_list;
    spell.filldata(names);
    return 0;
}
