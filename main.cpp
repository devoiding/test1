#include <iostream>
#include <cstring>

using namespace std;

class Gandalf {
    int magicalPower;
    int age;
    char beardColor[12];
public:
    Gandalf();
    void mp_usage(int mp);
    int get_mp() const;
    void spell_fireball();
    void spell_lightning();
    void action_wait();

};

int main(void) {
    Gandalf gandalf;
    gandalf.spell_fireball();
    gandalf.action_wait();
    gandalf.spell_lightning();
    gandalf.action_wait();
    gandalf.action_wait();
    gandalf.action_wait();
    gandalf.spell_lightning();
    gandalf.action_wait();
    gandalf.action_wait();
    gandalf.spell_fireball();
}

Gandalf::Gandalf() {
    magicalPower = 100;
    age = 2019;
    strcpy(beardColor, "gray");
    cout << "Gandalf the Gray is born with magical power: " << magicalPower << endl;
}

void Gandalf::mp_usage(int mp) {
    magicalPower -= mp;
}

int Gandalf::get_mp() const {
    return magicalPower;
}

void Gandalf::spell_fireball() {
    if (magicalPower > 30) {
        cout << "Gandalf casts Fireball!" << endl;
        mp_usage(30);
    } else {
        cout << "Not enough magical power for Fireball!" << endl;
        cout << "Current magical power: " << magicalPower << endl;
    }
}

void Gandalf::spell_lightning() {
    if (magicalPower > 90) {
        cout << "Gandalf casts Lightning!" << endl;
        mp_usage(90);
    } else {
        cout << "Not enough magical power for Lightning!" << endl;
    }
    cout << "Current magical power: " << magicalPower << endl;
}

void Gandalf::action_wait() {
    cout << "Gandalf waits and regain some magical power." << endl;
    magicalPower += 10;
    if (magicalPower > 100) {
        magicalPower = 100;
    }
    cout << "Current magical power: " << magicalPower << endl;
}

