#include "spell_data.h"
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

void to_upper(char& ch){
    ch=toupper(static_cast<unsigned char>(ch));
}

void print_vector(std::vector<int> &v){
    int counter;
         while(counter<v.size()){
          cout<<v.at(counter)<<endl;
    }

return;
}

string concat_string_vector(const std::vector<string> &v){
        stringstream out;
        std::string concat;
        //cout<<v.at(0);
       for(size_t i=0;i<v.size();++i){

              //cout<<v[i]<<endl;
              out<<v[i];
              out<<" ";
        
    }
concat=out.str();
//cout<<concat;
   return concat;
}

bool isNumber(const std::string& s) 
{ 
    std::string::const_iterator it=s.begin();
   while(it != s.end() && std::isdigit(*it)) ++it;
   return !s.empty()&&it==s.end();
}
//returns second string token
std:: string tokenize(std::string object,char del,int flag){
char* token;
std::vector<string> tokens;
char* copy;
string concat;
int found;
std::string colon;
stringstream ss(object);
stringstream out;
std::string a="'";
std::string b="’";
size_t pos;
//cout<<object<<"line"<<endl;

copy= const_cast<char*>(object.c_str());
//flag 1 gets rid of colons
//flag 2 handles paragraphs and sentences until encountering a colon
//flag 3 handles lines that can't be sentences or do not need a period

if(flag==1){

while(getline(ss,concat,':')){

   colon=concat;
 }
 return colon;
}

    if(flag>=2){

if(object.find("Casting Time:")!=std::string::npos){
    //cout<<object<<"why"<<endl;
    return "stop";
  }
else if(object.find("'")!=std::string::npos){
     while((pos=object.find(a)) != std::string::npos){
        object.replace(pos,1,b);
     }
   }
}
     copy= const_cast<char*>(object.c_str());

        token=strtok(copy," \n\t\r");
        tokens.push_back(token);
        while(token){
        
        tokens.push_back(token);
        
        token=strtok(NULL," \n\t\r");
        //cout<<token<<endl;
        }
        for(size_t i=0;i<tokens.size();++i){
        if(i !=0){
           if(i!=tokens.size()-1){
              out<<tokens[i];
              out<<" ";
          }
           else{
             if(tokens[i]!=" "){

             
             out<<tokens[i];
             if(flag==2){
             out<<".";
             }
            }
           }
        }
    }
  


    concat=out.str();
    //cout<<concat<<endl;
    return concat;

}
void find(std::string name,Spell &spell){
    int check;
    std::string line;
    std::string send;
    std::string lineupper;
    std::string nameupper;
    std::string garbage;
    std::string description;
    std::string description_high;
    std::vector<std::string> vd;
    std::vector<std::string> vdh;
    int HLflag;

    int i;
   ifstream flame("search.txt");
   //ofstream out("flame.txt");
   check=0;
   HLflag=0;
   nameupper=name;
   nameupper=tokenize(nameupper,' ',3);
   cout<<nameupper;
   //nameupper="Wall of Bones";
   for_each(nameupper.begin(), nameupper.end(), to_upper);
   cout<<nameupper<<endl;
   while(getline(flame,line)){

    lineupper=line;
    for_each(lineupper.begin(), lineupper.end(), to_upper);
    //out<<lineupper<<endl;
    //out<<nameupper<<endl;
    i=lineupper.compare(nameupper);
    //if(nameupper=="RAY OF FATIGUE"){
    //cout<<i<<endl;
    //}
    if(i==0){
    //cout<<"comparing: "<<line<<" to "<<spell.name<<" compare: "<<i<<endl;
      //spell.name=line;
     }
     if(i==0){

        if(getline(flame,line)){
            garbage=line;
        }
        if(getline(flame,line)){   //casting time
          line=tokenize(line,':',1);
          line=tokenize(line,' ',3);
          spell.casting_time=line;
          cout<<spell.casting_time<<endl;
           //cout<<line<<endl;
        }
        if(getline(flame,line)){   //range
         line=tokenize(line,':',1);
         line=tokenize(line,' ',3);
         spell.range=line;
           //cout<<line<<endl;
        }
        if(getline(flame,line)){   //components
        // cout<<line<<endl;
         line=tokenize(line,':',1);
         line=tokenize(line,' ',3);
         //cout<<line<<endl;
         spell.components=line;
           //cout<<line<<endl;
        }
        if(getline(flame,line)){    //duration
           line=tokenize(line,':',1);
           line=tokenize(line,' ',3);
           spell.duration=line;
           //cout<<line<<endl;
        }
        check=0;
        while(getline(flame,line,'.')){
              if(line=="end."||line==" "){
                check=2;
                break;
              }

            line=tokenize(line,' ',2);
            //cout<<line<<endl;
              if(line=="stop"){
                check=2;
                break;
              }
              else if(line!="At Higher Levels."&&check!=8){
                //cout<<line<<"\n"<<endl;
                vd.push_back(line);

              }
              if(line=="At Higher Levels."||check==8){
                if(check==8){
                    //cout<<line<<endl;
                  vdh.push_back(line); 
                }
                HLflag=1;
                check=8;
              }
        }


     }
     if(check==2){
           //cout<<"found: "<<spell.name<<endl;
        break;
     }
     //cout<<line<<endl;
   }
   if(check!=2){
     //cout<<"Did not find: "<<spell.name<<endl;
   }
   
   //return; 
   flame.close();

    ofstream out("flame.txt");
    if(HLflag==1){
    send=concat_string_vector(vdh);
    spell.description_high=send;
    //cout<<spell.description_high<<endl;
    }
    else if(HLflag==0){
        send="";
        spell.description_high=send;
    }
    send=concat_string_vector(vd);    
    spell.description=send;
    //cout<<send<<endl;
    //out<<send;


    //if (!out.good()||out.bad()||out.fail()) { std::cerr<<"Error writing to ..."<<std::endl; } else {  
    //     out <<send<<endl; 
    //    }

    //out<<line<<endl;
    //out.flush();
    out.close();
    
}


int vector_contains(std::string search, std::vector<string> &v){
    int index;

    //if(v.empty()){
    //        v.push_back(search);
    //        return -1;
    //}
    //cout<<search<<endl;

    auto result=std::find(std::begin(v),std::end(v),search);



    if(result != std::end(v)){
        index=std::distance(v.begin(),result);
        //cout<<index<<" Spell index"<<endl;
        return index;
    }
    else{
        //cout<<search<<endl;
        v.push_back(search);
        return -1;
    }
}


//cleans up the mess from parsing the original file and preps it for easy reading
void cleanfiles(std::string filename,std::string secondfile,std::vector<std::string> &names){
	string line;
    //rewrite butane to make it easier to fill variables for spells (flame file)
	vector <std::string> tokens;
    char* token;
    char* copy;
    int i;
	ifstream fuel(filename);
    int counter;
    //ofstream clean("butane.txt");
    //cout<<"Fuck"<<endl;
    
    while(getline(fuel,line)){
    	if(line!="end"){
        copy= const_cast<char*>(line.c_str());

       /*token=strtok(copy,"\n\t\r()");
        //names.push_back(token);
        tokens.push_back(token);
        while(token){
        
        tokens.push_back(token);
        
        token=strtok(NULL," \n\t\r()");
        
        }*/

        while((token=strtok_r(copy,"\r\n\t(),",&copy))){
        if(strcmp(token," ")>0){
        tokens.push_back(token);
        if(counter==0){
            
            vector_contains(token,names);
          }
          counter++;
        }

        }
        counter=0;
       }

    }
    fuel.close();
    counter=0;

    ofstream clean(filename);
    /*for(i=0;i<names.size(); ++i){
        if(names[i]!="\n"||names[i]!=" "){
            
            clean<<names[i]<<"\n";
        }
    }*/

    for(i=0;i<tokens.size(); ++i){
    	if(tokens[i]!="\n"||tokens[i]!=" "){
            cout<<tokens[i]<<"\n";
    		clean<<tokens[i]<<endl;
    	}
    }
    clean.close();

 }

std::string translate(Spell &spell){
    int i;
    int counter;
    std::string returned;
    std::string CList;
    std::string upper;
    upper=spell.school;
    stringstream ss(returned);
    stringstream CL(CList);
    //if the input is a number, then it is either a class or level
    upper[0]=toupper(upper[0]);
    
        i=spell.level;


        switch(i){
            case 0:
            ss<<upper<<" "<<"Cantrip";
            spell.level=-1;
            break;
            case 1:
            ss<<"1st Level "<<upper;
            break;
            case 2:
            ss<<"2nd Level "<<upper;
            break;
            case 3:
            ss<<"3rd Level "<<upper;
            break;
            case 4:
            ss<<"4th Level "<<upper;
            break;
            case 5:
            ss<<"5th Level "<<upper;
            break;
            case 6:
            ss<<"6th Level "<<upper;
            break;
            case 7:
            ss<<"7th Level "<<upper;
            break;
            case 8:
            ss<<"8th Level "<<upper;
            break;
            case 9:
            ss<<"9th Level "<<upper;
            break;
            
            default:
            break;
      }

      spell.school=ss.str();
     counter=0;
     while(counter<spell.classes.size()){
      //cout<<"size "<<spell.classes.size()<<endl;
      i=spell.classes.at(counter);

      switch(i){
           case 11:
            CL<<"Bard";
            break;
            case 12:
            CL<<"Cleric";
            break;
            case 13:
            CL<<"Druid";
            break;
            case 14:
            CL<<"Ranger";
            break;
            case 15:
            CL<<"Sorcerer";
            break;
            case 16:
            CL<<"Paladin";
            break;
            case 17:
            CL<<"Warlock";
            break;
            case 18:
            CL<<"Wizard";
            break;
            default:
            break;
        }
        if(counter<spell.classes.size()-1){
            CL<<",";
        }
        counter++;
    }
      returned=CL.str();
      return returned;

    }


Spell::Spell(){ }
void Spell::write_spell_file(std::vector<Spell> &spell_list){

     int counter;
     Spell spell;
     std::string Clist;
     std::string concentration;
     std::string ritual;
     std::string book;
     std::string output;
     book="fuck you";
     cout<<"enter the name of the book"<<endl;
     getline(cin,book);
     cout<<"enter output file name, format is: name.txt"<<endl;
     getline(cin,output);
     ofstream out(output);
     if(spell.concentration==1){
        concentration="true";
     }
     else if(spell.concentration!=1){
        concentration="false";
     }
     if(spell.ritual==1){
        ritual="true";
     }
     else if(spell.ritual!=1){
        ritual="false";
     }


      out<<"[{"<<"\"version\""<<":"<< "\"3.1.5\""<<"},"<<"{"<<"\"db\""<<":"<<"\"13\""<<"},"<<"{"<<"\"data\""<<":"<<"[";

     counter=0;
     while(counter<spell_list.size()){

        spell=spell_list.at(counter);
        Clist=translate(spell);
        //cout<<spell.casting_time<<endl;
        out<<"{"<<"\"id\""<<":-1"<<",";
        out<<"\"name\""<<":"<<"\""<<spell.name<<"\","<<"\""<<"school"<<"\""<<":"<<"\""<<spell.school<<"\",";
        out<<"\"level\""<<":"<<spell.level<<","<<"\"casting_time""\""<<":"<<"\""<<spell.casting_time<<"\""<<",";
        out<<"\"range\""<<":"<<"\""<<spell.range<<"\""<<","<<"\"components\""<<":"<<"\""<<spell.components<<"\""<<",";
        out<<"\"duration\""<<":"<<"\""<<spell.duration<<"\""<<","<<"\"description\""<<":"<<"\""<<spell.description<<"\""<<",";
        out<<"\"description_high\""<<":"<<"\""<<spell.description_high<<"\""<<","<<"\"book\""<<":"<<"\""<<book<<"\""<<",";
        out<<"\"note\""<<":"<<"\"\""<<","<<"\"classes\""<<":"<<"\""<<Clist<<"\""<<","<<"\"concentration\""<<":";
        out<<"\""<<concentration<<"\""<<","<<"\"ritual\""<<":"<<"\""<<ritual<<"\""<<","<<"\"sound\""<<":"<<"\"\""<<"}";
       // counter=spell_list.size();
        if(counter!=spell_list.size()-1){
        out<<",";
        }

        //out<<spell.name<<endl;
        //out<<spell.school<<endl;
        ++counter;

     }
     out<<"]}]";

}
//threshes the converted text into 2 files that are picked appart by filldata()
std::vector<Spell> Spell::thresh(std::string filename,std::vector<std::string> &names){
	int caught;
	int levels;
    std::string classes;
    vector <std::string> tokens;
    char* token;
    char* copy;
    int i;

    caught=-1;
	ifstream file(filename);
        ofstream file2("butane.txt");
        ofstream searched("search.txt");
	if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {

        if(line=="Bard Spells")
        {
        	classes="Bard Spells";
        	caught = 1;
        }
        if(line=="Cleric Spells")
        {
        	classes=line;
        	caught = 2;
        }
        if(line=="Druid Spells")
        {
        	classes=line;
        	caught = 3;
        }
        if(line=="Ranger Spells")
        {
        	classes=line;
        	caught = 4;
        }
        if(line=="Sorcerer Spells")
        {
        	classes=line;
        	caught = 5;
        }
        if(line=="Paladin Spells")
        {
        	classes=line;
        	caught = 6;
        }
        if(line=="Warlock Spells")
        {
        	classes=line;
        	caught = 7;
        }
        if(line=="Wizard Spells")
        {
        	classes=line;
        	caught = 8;
        }
        //build list of spells
        if(caught>0){
        	if(line!="end"){
            
            if(line=="Cantrips (0 level)"){
            	levels=0;

               }
            else if(line=="1st Level"){
            	levels=1;
               }
            else if(line=="2nd Level"){
            	levels=2;
               }
            else if(line=="3rd Level"){
            	levels=3;
            }
            else if(line=="4th Level"){
            	levels=4;
            }
            else if(line=="5th Level"){
            	levels=5;
            }
            else if(line=="6th Level"){
            	levels=6;
            }
            else if(line=="7th Level"){
            	levels=7;
            }
            else if(line=="8th Level"){
            	levels=8;
            }
            else if(line=="9th Level"){
            	levels=9;
            }
            else{
            	if(line==classes){
            		file2<<" "<<"\n";
            	}
            	else if(line=="  "){
            		file2<<" "<<"\n";
            	}
            	else if(line=="\n"){
                file2<<" "<<"\n";	
                }
        
                    else{
                        if(line=="Spell Descriptions"){
                            caught=0;
                        }
                        if(caught!=0&&line!="end"&&line!=""&&line.find("|")==std::string::npos){
            	          file2<<line<<" "<<"("<<caught+10<<")"<<" "<<"("<<levels<<")"<<"\n";
                        }
                     }
                
             }
            }

        }
        if(caught==0&&line!="end"){
            searched<<line;
            searched<<"\n";
        }
    }
    searched<<"stop";
    file.close();
    file2.close();
    searched.close();
 }
 cleanfiles("butane.txt","search.txt",names);
}


//it already knows the main parsing file is butane and searched is the searched file
void Spell::filldata(std::vector<std::string> &names){
	std::string line;
    
    // print_vector(names);
    int temp_num;
    int track;
    int counter;
   // int i;
    Spell spell;
    int check;
    int index;
    int size=names.size();
    std::vector<Spell> spell_list(size);
    std::vector<std::vector<int>> classes2(size);
    std::vector<std::string> school(size);
    std::vector<int> ritual(size);
    std::vector<int> level(size);
    std::vector<int> concentration(size);

    ofstream fuck("flame.txt");

     for(int i;i<names.size();++i){
        //fuck<<names.at(i)<<endl;
    }


	ifstream data("butane.txt");

     temp_num=100000;//inf
     counter=0;
     check=0;
     track=0;
     line="";

    while(!data.eof()){

          if(getline(data,line)){
            //set if line is equal to a unique name
            if(line=="Spell Descriptions"){
                break;
            }
            //cout<<counter<<endl;
             check=vector_contains(line,names);
             //cout<<check<<" "<<"size of names vector "<<names.size()<<endl;
             //cout<<names.at(check)<<endl;
             //cout<<"school vector size "<<school.size()<<endl;
             //cout<<"classes size "<<classes2.size()<<endl;
             counter++;
          }
          if(getline(data,line)&&check!=-1){

             school.at(check)=line;
             //cout<<school.at(check)<<endl;
          }
          if(getline(data,line)&&check!=-1){
            if(isNumber(line)==true){
             classes2.at(check).push_back(stoi(line));
             ritual[check]=0;
            }
            else if(isNumber(line)==false){
                if(line=="ritual"||line==" ritual"){
                ritual[check]=1;
                concentration[check]=0;
                }
                else if(line!="ritual"){
                    ritual[check]=0;
                    if(line=="concentration"){
                        concentration[check]=1;
                    }
                    else if(line!="concentration"){
                        concentration[check]=0;
                    }
                }                 
                getline(data,line);
                 // cout<<line<<endl;
                  classes2.at(check).push_back(stoi(line));
          }
        } 
        //cout<<"ritual: "<<ritual[check]<<endl;
          if(getline(data,line)){
                level[check]=stoi(line);
            }
            //cout<<"level "<<level[check]<<endl;
    }
data.close();
fuck.close();
//cout<<names[0]<<endl;
//cout<<names[40]<<endl;
counter=0;
int i=0;
//set spells in the spell list
std::string send;
while(counter<classes2.size()){
       send=names.at(counter);
       //tokenize(send,' ',2);
      spell_list.at(counter).name=send;
      spell_list.at(counter).school=school.at(counter);
      spell_list.at(counter).level=level.at(counter);
      spell_list.at(counter).ritual=ritual.at(counter);
      i=0;
      while(i<classes2.at(counter).size()){
        spell_list.at(counter).classes=classes2.at(counter);
        ++i;
      }
      find(send,spell_list.at(counter));
    ++counter;
}



counter=0;
i=0;
while(counter<names.size()){
      spell=spell_list.at(counter);
      cout<<spell.name<<endl;
      cout<<spell.school<<endl;
      cout<<spell.casting_time<<endl;
      cout<<spell.range<<endl;
      cout<<spell.duration<<endl;
      cout<<spell.components<<endl;
      cout<<spell.description<<endl;
      cout<<spell.description_high<<endl;
      if(spell.ritual==1){
        cout<<"Ritual: true"<<endl;
      }
      if(spell.ritual!=1){
        cout<<"Ritual: false"<<endl;
      }
      i=0;
      while(i<spell.classes.size()){
        cout<<spell.classes.at(i)<<",";
        ++i;
      }
       cout<<endl;
    

    counter++;
}

    write_spell_file(spell_list);
     return;
  }

