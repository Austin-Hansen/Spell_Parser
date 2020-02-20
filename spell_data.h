#ifndef __SPELL_DATA_H
#define __SPELL_DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

class Spell{
public:
	int id;
    std::vector <int> classes; //turn into vector
	std::string name;
	std::string school;
	int level;
	int ritual;
	int concentration;
	std::string casting_time;
	std::string range;
	std::string components;
	std::string duration;
	std::string description;
	std::string description_high;

	Spell();
    void write_spell_file(std::vector<Spell> &spell_list);
	void filldata(std::vector<std::string> &names);
	std::vector<Spell> thresh(std::string filename, std::vector<std::string> &names);


};

#endif