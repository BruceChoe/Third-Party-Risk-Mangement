#pragma once

#include <map>
#include <iostream>
#include <utility>

const char FILENAME[13] = "userdata.bin";

struct PassInfo
{
	PassInfo(std::string & p_salt, std::string & p_encryptedPassword)
		: salt(p_salt), encryptedPassword(p_encryptedPassword)
	{
	}

	friend std::ostream & operator<<(std::ostream & os, PassInfo & info);

	std::string salt;
	std::string encryptedPassword;
};

class PasswordManager
{
public:
	PasswordManager();
	~PasswordManager();

	bool firstTimeLogin(std::string user, std::string pass);
	bool login(std::string user, std::string pass);

	void addUser(std::string user, std::string pass);
	void addUser(std::string user, std::string salt, std::string encryptedPassword);
	void removeUser(std::string user);

	void printAllUsers();

private:
	std::map<std::string, PassInfo> allUserData;

	//PassInfo encrypt(std::string user, std::string pass);
	std::string encryptPassword(std::string password, std::string salt);
	std::string randomSalt();

	void writeFile();
	void readFile();
};