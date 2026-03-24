#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "../Header/class.h"
#include "../Header/function.h"

using std::cout;
using std::cin;
using std::string;
using std::rand;
using std::endl;
using std::time;

// Server class implementation
Server::Server(string name, int firewall, int data) {
    serverName = name;
    firewallStrength = firewall;
    dataPayload = data;
}

string Server::getServerName() const {
    return serverName;
}

int Server::getFirewallStrength() const {
    return firewallStrength;
}

int Server::getData() const {
    return dataPayload;
}

void Server::setData(int data) {
    dataPayload = data;
}

void Server::drainData(int amount) {
    if (amount > dataPayload) {
        amount = dataPayload;
    }
    dataPayload -= amount;
}

// Hacker class implementation
Hacker::Hacker(string alias) {
    hackerAlias = alias;
    stolenData = 0;
    traceLevel = 0;
    overClockLevel = 1;
    fireWallBypassLevel = 1;
    agencyDistractorLevel = 0;
}

string Hacker::getHackerAlias() const {
    return hackerAlias;
}

int Hacker::getStolenData() const {
    return stolenData;
}

int Hacker::getTraceLevel() const {
    return traceLevel;
}

bool Hacker::hack(Server &target, int secondsToHack) {
    if (target.getData() <= 0) {
        cout << "Server " << target.getServerName() << " has no data left to steal!" << endl;
        return false;
    }
    
    if (secondsToHack < 1) {
        cout << "Invalid input! Please try again." << endl;
        return false;
    }
 
    cout << "--- Initializing Hack ---" << endl;

    int stolenDataThisHack = 0;

    for (int i = 0; i < secondsToHack; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        int dataToTake;

        if (target.getServerName() == "Local Library") {
            dataToTake = 5 * overClockLevel;
        }

        else if (target.getServerName() == "Tech Company") {
            dataToTake = 10 * overClockLevel;
        }

        else if (target.getServerName() == "Local Bank") {
            dataToTake = 15 * overClockLevel;
        }

        else if (target.getServerName() == "Government Agency") {
            dataToTake = 20 * overClockLevel;
        }

        else {
            return true;
        }

        if (target.getData() < dataToTake) {
            dataToTake = target.getData();
        }

        target.drainData(dataToTake);
        stolenData += dataToTake;
        stolenDataThisHack += dataToTake;

        traceLevel += 1;

        static int catchRisk = 0;

        if (agencyDistractorLevel > 0) {
            catchRisk = 0;
            agencyDistractorLevel -= 1;
        }

        else {
            catchRisk = (getTraceLevel() * target.getFirewallStrength()) / (100 * fireWallBypassLevel);
        }
        

        cout << "[Sec " << i + 1 << "] Stole: " << dataToTake << "GB | Trace: " << getTraceLevel() << "% | Catch Risk per Second: " << catchRisk << "%" << endl;
        
        int roll = rand() % 100 + 1;

        if (roll <= catchRisk) {
            cout << endl << "MAJOR CAUTION! CONNECTION TRACED!" << endl;
            cout << endl << target.getServerName() << " have locked you out!" << endl;
            cout << endl << "You have been reported to the authorities and gotten busted!" << endl;
            return true;
        }

        if (target.getData() <= 0) {
            target.setData(0);
            break;
        }
    }
    cout << "--- Hack Completed ---" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Disconnecting from " << target.getServerName() << "..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Disconnected successfully! You stole " << stolenDataThisHack << "GB of data! Total: " << getStolenData() << "GB." << endl;
    return false;
}

void Hacker::maskIP() {
    if (traceLevel == 0) {
        cout << "Your IP address is already masked. No trace detected." << endl;
        return;
    }

    cout << "IP masking will cost you 5GB of stolen data. You have " << getStolenData() << "GB of stolen data. Do you want to proceed? (y/n): ";
    char choice;
    cin >> choice;
    fixInput();
    cout << " " << endl;
    if (choice != 'y' && choice != 'Y') {
        cout << "IP masking cancelled." << endl;
        return;
    }

    if (stolenData < 5) {
        cout << "You do not have enough stolen data to mask your IP address!" << endl;
        return;
    }

    stolenData -= 5;
    
    cout << "Masking IP address..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    traceLevel -= 5;

    if (traceLevel < 0) {
        traceLevel = 0;
    }

    cout << "IP address masked successfully! Trace level has been reduced by 10% and is now at " << traceLevel << "%." << endl;
    return;
}

void Hacker::showStatus() const {
    cout << "=============================================" << endl;
    cout << "Hacker Alias: " << hackerAlias << endl;
    cout << "Stolen Data: " << stolenData << "GB" << endl;
    cout << "Trace Level: " << traceLevel << "%" << endl;
    cout << "Overclock Speed: " << overClockLevel << endl;
    cout << "Firewall Bypass Multiplyer: " << fireWallBypassLevel << endl;
    cout << "Agency Distractor: " << agencyDistractorLevel << " Seconds" << endl;
    cout << "=============================================" << endl;
    cout << " " << endl;
}

int Hacker::blackMarket(string item) {
    if (item == "Overclock") {
        overClockLevel += 1;
        stolenData -= 100;
        cout << "Purchasing Overclock Speed..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 0;
    }

    else if (item == "Firewall Bypass Booster") {
        fireWallBypassLevel += 1;
        stolenData -= 150;
        cout << "Purchasing Firewall Bypass Multiplyer..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 0;
    }

    else if (item == "Agency Distractor") {
        agencyDistractorLevel += 10;
        stolenData -= 250;
        cout << "Purchasing Agency Distractor..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 0;
    }

    else {
        cout << "Invalid item! No purchase made." << endl;
        return -1;
    }
    return 0;
}