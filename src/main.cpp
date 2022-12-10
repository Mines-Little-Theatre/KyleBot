#include "dispatcher.h"
#include "message.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <dpp/dpp.h>
#include <regex>
#include <array>


std::string getToken(const std::string& KEY){
    const char* tokenPtr = std::getenv(KEY.c_str());

    if (tokenPtr == nullptr){
        std::cerr << "Failed to locate key: " << KEY << std::endl;
        throw std::runtime_error("Failed to read API Token.");
    }

    std::string token(tokenPtr);

    return token;
}



int main(int argc, const char** argv){
    if(argc != 2){
        std::cerr << "Usage: [kyleBot] [tokenEnvKey]" << std::endl;
        return -1;
    }

    const std::string TOKEN = getToken(argv[1]);
    // const dpp::snowflake legallyblondeRole(935610120883306516);

    uint64_t intents = dpp::i_default_intents | dpp::i_message_content;


    dpp::cluster kyleBot(TOKEN, intents);

    // shove log messages to stdout cause im lazy
    
    kyleBot.on_log(dpp::utility::cout_logger());
    
    // This will run for every message created
    kyleBot.on_message_create([](const dpp::message_create_t& event){

            // do nothing if the person who sent the message is a bot 
            if(event.msg.author.is_bot()){
                return;
            }
            
            // lower cases the message then uses the find method to see if package occurs anywhere in the
            //  message
            std::string message = event.msg.content;
            std::transform(message.begin(), message.end(), message.begin(), ::tolower);

            bool packageMatched = message.find("package") != std::string::npos;

            if(packageMatched) {

                // if the user does not have a nickname on the server.
                if(event.msg.member.nickname.empty()){
                    event.reply(dpp::message("You are not worthy of a package"), true);
                    return;
                }

                event.reply(dpp::message("I've got a ***package*** for " + event.msg.member.nickname), false);
            }
    });


    kyleBot.start(dpp::st_wait);
    
}
