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

    Server server1("Local Library", 20, 50);
    Server server2("Tech Company", 50, 100);
    Server server3("Local Bank", 60, 150);
    Server server4("Government Agency", 80, 200);

    Server servers[] = {server1, server2, server3, server4};
    int choice;
    while (true) {
        cout << "Would you like to hack a server or mask your IP address?" << endl;
        cout << "1. Hack a server" << endl;
        cout << "2. Mask IP address" << endl;
        cout << "3. Exit" << endl;
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
                break;
            case 2:
                player.maskIP();
                break;
            case 3:
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
            if (serverChoice < 1 || serverChoice > 4) {
                cout << "Invalid server choice! Please try again." << endl;
                continue;
            }
            player.hack(servers[serverChoice - 1]);
        }

    }
    return 0;
}