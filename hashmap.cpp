#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include "Block.h"
//https://thispointer.com/how-to-search-by-value-in-a-map-c/

class HashMap{
	private: 
	std::map<std::string,Report> m;
	//string *head;
	
	public:
	void Insert(string hash, Report report)
	{
		m.emplace(hash, report);
	//	head = *hash;
	
	}
	/*
	Report* Search(string hash)
	{
		auto location = m.find(hash);
		
		//Report *r = location.second;
		
		auto temp = m.at[location];
		return temp->second;
	}
	*/
	Report* SearchByID(string FI_ID)
	{
		auto it = m.begin();
		// Iterate through the map
		while(it != m.end())
		{
			// Check if value of this entry matches with given value
			if((it->second.getFiID()).compare(FI_ID));
			{
				return &(it->second);
			}
			// Go to next entry in map
			it++;
		}
	}
	
};
