#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "../Header/class.h"
#include "../Header/function.h"

using std::cout;
using std::cin;
using std::string;
using std::srand;
using std::rand;
using std::time;
using std::endl;

//Main function
int main(void) {
    srand(time(nullptr));

    cout << "Welcome to Server Hacker!" << endl;
    cout << "Enter your hacker alias: ";
    string alias;
    cin >> alias;
    fixInput();
    cout << " " << endl;
    Hacker player(alias);

    Server server1("Local Library", 20, 100);
    Server server2("Tech Company", 40, 200);
    Server server3("Local Bank", 60, 600);
    Server server4("Government Agency", 80, 1000);

    Server servers[] = {server1, server2, server3, server4};
    int choice;
    while (true) {
        bool allServersEmpty = true;
        for (int i = 0; i < 4; i++) {
            if (servers[i].getData() <= 0) {
                allServersEmpty = true;
            }

            else {
                allServersEmpty = false;
                break;
            }
        }

        if (allServersEmpty) {
            cout << " " << endl;
            cout << "All servers have been completely drained of data! Congratulations on hacking all the servers!" << endl;
            cout << " " << endl;
            break;
        }
        
        cout << "Would you like to hack a server or mask your IP address?" << endl;
        cout << "1. Hack a server" << endl;
        cout << "2. Mask IP address" << endl;
        cout << "3. Enter the Black Market" << endl;
        cout << "4. Show Status" << endl;
        cout << "5. Exit game" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        fixInput();
        cout << " " << endl;
        switch (choice) {
            case 1:
                cout << "Available servers to hack:" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << i + 1 << ". " << servers[i].getServerName() << " | Firewall Strength: " << servers[i].getFirewallStrength() << " | Data Available: " << servers[i].getData() << "GB" << endl;
                }
                cout << " " << endl;
                cout << "5. Return to options screen" << endl;
                cout << "6. Exit game" << endl;
                break;

            case 2:
                player.maskIP();
                break;
            case 3:
                cout << "==================================" << endl;
                cout << "You have entered the Black Market!" << endl;
                cout << "==================================" << endl;
                cout << "Available items for purchase:" << endl;
                cout << "1. Overclock Speed(Cost: 100GB) - Increases your hacking speed, allowing you to steal more data per second." << endl;
                cout << "2. Firewall Bypass Multiplyer (Cost: 150GB) - Allows you to bypass firewalls more effectively." << endl;
                cout << "3. Agency Distractor (Cost: 250GB) - Distracts agencies from tracking your activities for 10 seconds of hacking." << endl;
                cout << " " << endl;
                cout << "4. Return to options screen" << endl;
                cout << "5. Exit game" << endl;
                cout << " " << endl;
                int itemChoice;
                cout << "Enter the number of the item you want to purchase: ";
                cin >> itemChoice;
                fixInput();
                cout << " " << endl;

                switch (itemChoice) {
                    case 1:
                        if (player.getStolenData() < 100) {
                            cout << "You do not have enough stolen data to purchase this item!" << endl;
                            continue;
                        }

                        if (!player.blackMarket("Overclock")) {
                            break;
                        }

                        cout << "Overclock purchased successfully! Your hacking speed has been increased." << endl;
                        break;

                    case 2:
                        if (player.getStolenData() < 150) {
                            cout << "You do not have enough stolen data to purchase this item!" << endl;
                            continue;
                        }

                        if (!player.blackMarket("Firewall Bypass Booster")) {
                            break;
                        }

                        cout << "Firewall Bypass Booster purchased successfully! You can now bypass firewalls more effectively." << endl;
                        break;

                    case 3:
                        if (player.getStolenData() < 250) {
                            cout << "You do not have enough stolen data to purchase this item!" << endl;
                            continue;
                        }

                        if (!player.blackMarket("Agency Distractor")) {
                            break;
                        }

                        cout << "Agency Distractor purchased successfully! Agencies will now be distracted for 10 seconds of hacking." << endl;
                        break;
                    
                    case 4:
                        continue;

                    case 5:
                        cout << "Exiting..." << endl;
                        return 0;

                    default:
                        cout << "Invalid item choice! Please try again." << endl;
                        continue;
                }
                break;
            case 4:
                player.showStatus();
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                continue;
        }

        if (choice == 1) {
            int serverChoice;
            cout << "Enter the number of the server you want to hack: ";
            cin >> serverChoice;
            fixInput();
            cout << " " << endl;

            if (serverChoice == 5) {
                continue;
            }

            else if (serverChoice == 6) {
                cout << "Exiting..." << endl;
                return 0;
            }

            else if (serverChoice < 1 || serverChoice > 4) {
                cout << "Invalid server choice! Please try again." << endl;
                continue;
            }

            else if (servers[serverChoice - 1].getData() <= 0) {
                cout << "Server " << servers[serverChoice - 1].getServerName() << " has no data left to steal!" << endl;
                continue;
            }

            int secondsToHack;
            cout << "Target: " << servers[serverChoice - 1].getServerName() << " | Firewall Strength: " << servers[serverChoice - 1].getFirewallStrength() << " | Data Available: " << servers[serverChoice - 1].getData() << "GB" << endl;
            cout << "How many seconds do you want to spend hacking? (Recommended 1-10): ";
            cin >> secondsToHack;
            fixInput();
            cout << " " << endl;
            if (!player.hack(servers[serverChoice - 1], secondsToHack)) {
                continue;
            }
            else {
                break;
            }
        }
    }
    cout << "=============================================" << endl;
    cout << "Thank you for playing Server Hacker! Goodbye!" << endl;
    cout << "=============================================" << endl;
    cout << " " << endl;

    return 0;
}