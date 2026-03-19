//Mech Battle
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

class Mech {
    char name[30];
    int health;
    int armor;
    int energy;
public:
    Mech(char *newName);
    const char* getName() const;
    int getHealth() const;
    int getArmor() const;
    int getEnergy() const;
    int attack_punch(Mech &target);
    int attack_kick(Mech &target);
    int attack_laser(Mech &target);
    void recharge();
    int repair();
    bool isAlive() const;

};

int main(void) {
    srand(time(nullptr));
    cout << "..." << endl;
    
    cout << "Enter the name of Mech 1: ";
    char name1[30] = {};
    cin.getline(name1, 30);
    
    cout << "Enter the name of Mech 2: ";
    char name2[30] = {};
    cin.getline(name2, 30);

    cout << "Let the battle begin!" << endl << endl;

    Mech mech1(name1);
    Mech mech2(name2);

    int choice;
    bool isPlayer1Turn = true;

    while (mech1.isAlive() && mech2.isAlive()) {
        cout << "\n===============================================" << endl;
        
        if (isPlayer1Turn) {
            cout << mech1.getName() << " | HP: " << mech1.getHealth() << " | Armor: " << mech1.getArmor() << " | Energy: " << mech1.getEnergy() << endl;
            cout << mech2.getName() << " | HP: " << mech2.getHealth() << " | Armor: " << mech2.getArmor() << " | Energy: " << mech2.getEnergy() << endl;
        } 

        else {
            cout << mech2.getName() << " | HP: " << mech2.getHealth() << " | Armor: " << mech2.getArmor() << " | Energy: " << mech2.getEnergy() << endl;
            cout << mech1.getName() << " | HP: " << mech1.getHealth() << " | Armor: " << mech1.getArmor() << " | Energy: " << mech1.getEnergy() << endl;
        }
        
        cout << "===============================================\n" << endl;
        
        cout << "It is " << mech1.getName() << "'s turn. Choose an action:" << endl;
        cout << "1. Punch" << endl;
        cout << "2. Kick" << endl;
        cout << "3. Laser" << endl;
        cout << "4. Recharge" << endl;
        cout << "5. Repair" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                mech1.attack_punch(mech2);
                break;
            case 2:
                mech1.attack_kick(mech2);
                break;
            case 3:
                mech1.attack_laser(mech2);
                break;
            case 4:
                mech1.recharge();
                break;
            case 5:
                mech1.repair();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        if (!mech2.isAlive()) {
            cout << mech2.getName() << " has been defeated! " << mech1.getName() << " wins!" << endl;
            break;
        }

        swap(mech1, mech2);

        isPlayer1Turn = !isPlayer1Turn;
    }

    return 0;
}

Mech::Mech(char *newName) {
    health = 100;
    armor = 50;
    energy = 100;
    name[0] = '\0';
    strcpy(name, newName);
}

const char* Mech::getName() const {
    return name;
}

int Mech::getHealth() const {
    return health;
}

int Mech::getArmor() const {
    return armor;
}

int Mech::getEnergy() const {
    return energy;
}

bool Mech::isAlive() const {
    return health > 0;
}

void Mech::recharge() {
    energy += 20;
    if (energy > 100) {
        energy = 100;
    }
    cout << name << " recharges and now has " << energy << " energy." << endl;
}

int Mech::repair() {
    if (energy < 10) {
        cout << name << " does not have enough energy to repair!" << endl;
        return 1;
    }
    
    armor += 20;
    energy -= 10;

    if (armor > 50) {
        armor = 50;
    }

    cout << name << " uses 10 energy to repair and now has " << armor << " armor." << endl;
    return 0;
}

int Mech::attack_punch(Mech &target) {
    if (energy < 10) {
        cout << name << " does not have enough energy to punch!" << endl;
        return 1;
    }

    energy -= 10;
    double damage = (rand() % 20 + 20) / sqrt(double(target.getArmor() / 2.0));
    target.health -= int(damage);
    target.armor -= damage / 2;

    if (target.armor < 2) {
        target.armor = 2;
    }
    
    cout << name << " punches " << target.name << " for " << int(damage) << " damage!" << endl;

    return 0;
 }

 int Mech::attack_kick(Mech &target) {
    if (energy < 15) {
        cout << name << " does not have enough energy to kick!" << endl;
        return 1;
    }

    energy -= 15;
    double damage = (rand() % 30 + 30) / sqrt(double(target.getArmor() / 2.0));
    target.health -= int(damage);
    target.armor -= damage / 2;

    if (target.armor < 2) {
        target.armor = 2;
    }
    
    cout << name << " kicks " << target.name << " for " << int(damage) << " damage!" << endl;

    return 0;
 }

  int Mech::attack_laser(Mech &target) {
    if (energy < 30) {
        cout << name << " does not have enough energy to fire laser!" << endl;
        return 1;
    }

    energy -= 30;
    double damage = (rand() % 40 + 50) / sqrt(double(target.getArmor() / 4.0));
    target.health -= int(damage);
    target.armor -= damage / 2;

    if (target.armor < 2) {
        target.armor = 2;
    }
    
    cout << name << " fires laser at" << target.name << " for " << int(damage) << " damage!" << endl;

    return 0;
 }