#include<iostream>
#include<string>
#include<fstream>
#include "sleepy_discord/sleepy_discord.h"
#include "extrafunc.h"

class MyClientClass : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) override {
        if (message.startsWith("say bish")) {
                sendMessage(message.channelID, "Nibba i say no bish " + message.author.username);
        } else if (message.startsWith("?cmd")) {
                std::string extractCommand = message.content.substr(4) + " | sed 's/\x1B\[[0-9;\?]*[a-zA-Z]//g' | sed 's/```/ /g'";
                std::string output = execCmd(extractCommand.c_str());
                sendMessage(message.channelID, "```bash\n" + output.substr(0,1200) + "```");
        }
    }
};

int main() {
    std::string TOKEN = "";
    std::cout << "Enter your token: ";
    std::cin >> TOKEN;
    MyClientClass client(TOKEN, SleepyDiscord::USER_CONTROLED_THREADS);
    //tell Discord to send use message events
    client.setIntents(SleepyDiscord::Intent::SERVER_MESSAGES);
    client.run();
}