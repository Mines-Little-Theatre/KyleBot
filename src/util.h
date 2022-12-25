#ifndef UTIL_H
#define UTIL_H

#include <dpp/snowflake.h>
#include <vector>
#include <string>

/**
 * This function reads an enviromental variable. Check return value to see if the data in value should be trusted.
 *
 * @param KEY the name of the enviromental
 * @param _value the value of the enviromental variable, if it was able to be read successfully
 * 
 * @return true if the variable was found and was able to be read from successfully.
 */

bool getEnvValue(const std::string& KEY, std::string& _value);

/**
 * This function checks to see if a message contains the word "package" and counts the number of times that it occurs.
 * Implements the KMP algorithm for counting the number of times a substring occurs.
 * This function always has a valid state.
 *
 * @param _message the message to check to see if package occurs
 * @param _numberOfPackages the number of times that pacakage occurs in the string
 *
 * @return true if _numberOfPackages >= 1.
 */

bool containsPackage(std::string& _message, unsigned int& _numberOfPackages);

/**
 * This function checks to see if any of the roles that a member has are the legally blonde role or the board member role. 
 * This works by matching the snowflakes.
 *
 * @param _roles a vector containing all the roles of a member.
 * @param _isBoardMember will be set to true if a member has the board member role.
 * @param _isLegallyBlonde wil be set to true if a member has the legally blonde role.
 */

void checkRoles(const std::vector<dpp::snowflake>& _roles, bool& _isBoardMember, bool& _isLegallyBlonde);


/**
 * This function builds the name that Kyle will use in his message. 
 * If the member has the board role, then it will attempt to call the member by thier title 
 * (IE: John Doe - President would be The President). This works by finding the string " - " in the middle of someones server nickname then getting the substring from there.
 * If processing the board name fails or the member does not have the board role, then it will attempt to call the member by thier first name. 
 * (IE: John Doe and John Doe-President both are John). If that fails, then just the users nickname will be set. 
 * This function assumes that the value passed in _userNickname is valid.
 *
 * @param _userNickname a string representing the member's nickname on the server.
 * @param IS_BOARD a boolean representing if the member has the board role on the server.
 *
 * @return the name that Kyle will use in his message.
 */

std::string processName(const std::string& _userNickname, const bool& IS_BOARD);



#endif // UTIL_H
