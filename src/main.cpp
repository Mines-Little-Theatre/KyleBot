#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <dpp/dpp.h>
#include <regex>
#include <array>

#include "util.h"

int main(int argc, const char** argv){
    if(argc != 3){
        std::cerr << "Usage: KyleBot [tokenEnvKey] [sqliteDBLocKey]" << std::endl;
        return -1;
    }


    bool tokenResult = false, dbPathResult = false;
    std::string token, dbPath;

    tokenResult = getEnvValue(argv[1], token);
    dbPathResult = getEnvValue(argv[2], dbPath);
    
    if(!tokenResult || !dbPathResult){
        return -1;
    }

    uint64_t intents = dpp::i_default_intents | dpp::i_message_content;


    dpp::cluster kyleBot(token, intents);

    // shove log messages to stdout cause im lazy
    kyleBot.on_log(dpp::utility::cout_logger());
    
    // This will run for every message created
    kyleBot.on_message_create([](const dpp::message_create_t& event){

            // do nothing if the person who sent the message is a bot 
            if(event.msg.author.is_bot()){
                return;
            }

            // get non const copy of message
            std::string message = event.msg.content;

            unsigned int numberOfPackages = 0;
            bool packageMatched = containsPackage(message, numberOfPackages);

            bool isBoardMember=false, isLegallyBlonde=false;
            
            checkRoles(event.msg.member.get_roles(), isBoardMember, isLegallyBlonde);
        
            if(packageMatched) {

                // if the user does not have a nickname on the server.
                if(event.msg.member.get_nickname().empty()){
                    event.reply(dpp::message("You are not worthy of a package"), true);
                    return;
                }

                // Get formatted name
                const std::string name = processName(event.msg.member.get_nickname(), isBoardMember);

                if(numberOfPackages > 1){
                    event.reply(dpp::message("I've got " + std::to_string(numberOfPackages) + " ***packages*** for " + name), false);
                    return;
                }

                event.reply(dpp::message("I've got a ***package*** for " + name), false);
            }
    });


    kyleBot.start(dpp::st_wait);
    
}
