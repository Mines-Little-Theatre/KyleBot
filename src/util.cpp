#include <iostream>

#include "util.h"



bool getEnvValue(const std::string& KEY, std::string& _value){
    const char* valuePtr = std::getenv(KEY.c_str());

    if (valuePtr == nullptr){
        std::cerr << "Failed to locate key: " << KEY << std::endl;
        return false;
    }
    
    _value = valuePtr;

    return true;
}

bool containsPackage(std::string& _message, unsigned int& _numberOfPackages){
    const std::string PACKAGE = "package";
    
    // lower case the string
    std::transform(_message.begin(), _message.end(), _message.begin(), ::tolower);

    bool packageMatched = _message.find(PACKAGE) != std::string::npos;

    _numberOfPackages = 0;

    // if there are no packages - then don't search for more
    if (!packageMatched){
        return packageMatched;    
    }

    // this implments the KMP algorithmn for searching for the number of occurences of a substring in a string
    // Used to find the number of packages in the message

    for(size_t offset = _message.find(PACKAGE); offset != std::string::npos; 
            offset = _message.find(PACKAGE, offset + PACKAGE.length())) 
    {
        _numberOfPackages++;
    }

    return packageMatched;

}



void checkRoles(const std::vector<dpp::snowflake>& _roles, bool& _isBoardMember, bool& _isLegallyBlonde){
    const dpp::snowflake legallyBlondeRole(935610120883306516);
    const dpp::snowflake boardMemberRole(734032739237625916);

    for (const auto role : _roles) {

        if(role == legallyBlondeRole){
            _isLegallyBlonde = true;
        }
        else if(role == boardMemberRole){
            _isBoardMember = true;
        }
    }

}
