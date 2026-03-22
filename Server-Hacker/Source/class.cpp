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

void Hacker::hack(Server &target) {
    if (target.getData() <= 0) {
        cout << "Server " << target.getServerName() << " has no data left to steal!" << endl;
        return;
    }

    int secondsToHack;
    cout << "Target: " << target.getServerName() << " | Firewall Strength: " << target.getFirewallStrength() << " | Data Available: " << target.getData() << "GB" << endl;
    cout << "How many seconds do you want to spend hacking? (Recommended 1-10): ";
    cin >> secondsToHack;
    fixInput();
    cout << " " << endl;

    if (secondsToHack < 1) {
        cout << "Invalid input! Please try again." << endl;
        return;
    }
 
    cout << "--- Initializing Hack ---" << endl;

    int stolenDataThisHack = 0;

    for (int i = 0; i < secondsToHack; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        int dataToTake = 5;
        if (target.getData() < 5) {
            dataToTake = target.getData();
        }

        target.drainData(dataToTake);
        stolenData += dataToTake;
        stolenDataThisHack += dataToTake;

        traceLevel += 1;

        int catchRisk = (getTraceLevel() * target.getFirewallStrength()) / 100;

        cout << "[Sec " << i + 1 << "] Stole: " << dataToTake << "GB | Trace: " << getTraceLevel() << "% | Catch Risk per Second: " << catchRisk << "%" << endl;
        
        int roll = rand() % 100 + 1;

        if (roll <= catchRisk) {
            cout << endl << "MAJOR CAUTION! CONNECTION TRACED!" << endl;
            cout << endl << target.getServerName() << " have locked you out!" << endl;
            cout << endl << "You have been reported to the authorities and gotten busted!" << endl;
            exit(1);
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
    return;
}

void Hacker::maskIP() {
    if (traceLevel == 0) {
        cout << "Your IP address is already masked. No trace detected." << endl;
        return;
    }

    cout << "IP masking will cost you 10GB of stolen data. You have " << getStolenData() << "GB of stolen data. Do you want to proceed? (y/n): ";
    char choice;
    cin >> choice;
    fixInput();
    cout << " " << endl;
    if (choice != 'y' && choice != 'Y') {
        cout << "IP masking cancelled." << endl;
        return;
    }

    if (stolenData < 10) {
        cout << "You do not have enough stolen data to mask your IP address!" << endl;
        return;
    }

    stolenData -= 10;
    
    cout << "Masking IP address..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    traceLevel -= 5;

    if (traceLevel < 0) {
        traceLevel = 0;
    }

    cout << "IP address masked successfully! Trace level has been reduced by 10% and is now at " << traceLevel << "%." << endl;
    return;
}