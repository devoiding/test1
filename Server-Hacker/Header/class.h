#include <string>

#ifndef CLASS_H
#define CLASS_H

class Server {
    std::string serverName;
    int firewallStrength;
    int dataPayload;
public: 
    Server(std::string name, int firewall, int data);
    std::string getServerName() const;
    int getFirewallStrength() const;
    int getData() const;
    void setData(int data);
    void drainData(int amount);
};

class Hacker {
    std::string hackerAlias;
    int stolenData;
    int traceLevel;
    int overClockLevel;
    int fireWallBypassLevel;
    int agencyDistractorLevel;
public:
    Hacker(std::string alias);
    std::string getHackerAlias() const;
    int getStolenData() const;
    int getTraceLevel() const;
    bool hack(Server &target, int secondsToHack);
    void maskIP();
    void showStatus() const;
    int blackMarket(std::string item);
};

#endif 
