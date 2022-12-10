#ifndef UTIL_H
#define UTIL_H

#include <dpp/snowflake.h>
#include <vector>
#include <string>

bool getEnvValue(const std::string& KEY, std::string& _value);


bool containsPackage(std::string& _message, unsigned int& _numberOfPackages);

void checkRoles(const std::vector<dpp::snowflake>& _roles, bool& _isBoardMember, bool& _isLegallyBlonde);



#endif // UTIL_H
