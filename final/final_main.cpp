/*
 * Interactive Story Game - "Broken Dream"
* Author: Conner Torrescano
 * Date: 6/17/2025
 *
 * ==== Project Features ====
 * Variables (3+ types): 579, 588, 593
 * If/else statements: 488, 491
 * Switch statement: 269 
 * For Loop: 175
 * While Loop: 266
 * Function w/ return: 322
 * Void function: 385
 * Function w/ params: 413
 * Vector usage: 103
 * Struct/Class: 100
 * Enum: 48
 * File Reading: 414-460
 * Modern Feature (auto): 552
 * Modern Feature (range-for): 515 
 * =========================
 
 */


#include <iostream>
#include <limits>
#include <cstdio>
#include <sstream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include <numeric>
#include <random>
#include <map>
using namespace std;



//Enums and constant values


enum class GameState {
    MAIN_MENU,
    PLAYING,
    PAUSED,
    GAME_OVER,
    FIGHTING,
    EXPLORING
};

enum class RoomDirections {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    EXIT
};

enum class PlayerState {
    ALIVE,
    INJURED,
    DEAD
};

enum class EnemyState {
    LIVING,
    DEFEATED
};

enum class Combat {
    ATTACK,
    DEFEND,
    HESITATE
};

/*
enum class Items {
    SWORD,
    SHIELD,
    HEALTH_POTION,
    KEY,
    SECRET_GUN,
    SECRET_KEY,
    ARMOR,
    BOOK,
    JOURNAL

};
*/


//Structs and classes

struct RoomInformation {
    string room_name;
    string room_description;
    vector<string> room_options;
    map<string, RoomInformation*> exits;
    map<string, string> lockedDoors;
    vector<string> items;
    vector<int> enemies;
};


//This used to be a class but with restructuring, became a struct
struct Player{
//private:
    string player_name;
    double player_health;
    vector<string> player_inventory;
    PlayerState player_state;
    RoomInformation* currentRoom = nullptr;

    void validatePlayerHealth() {
        if (player_health > 200.00 || player_health < 0.0) {
            cout << " - Invalid Player Health - ";
            player_health = 100.00;
        };
    }

    void checkPlayerStatus() {
        if (player_health < 0) {
            cout << " - You have died - \n";
            setPlayerState(PlayerState::DEAD);
        }
    }



//public:
    //constructors
    Player() : player_name("Player"), player_health(100.00), player_state(PlayerState::ALIVE) {}
    Player(string pn, double ph) : player_name(pn), player_health(ph) {}

    //accessors
    string getPlayerName() const { return player_name; }
    double getPlayerHealth() const { return player_health; }
    //RoomInformation* getPlayerRoom() const { return currentRoom; }

    //setters
    void setPlayerName(string pn) { player_name = pn; }
    void setPlayerHealth(double ph) { player_health = ph; }
    void setPlayerState(PlayerState ps) { player_state = ps; }
    //void setPlayerRoom(RoomInformation* ri) { currentRoom = ri; }


    void addItemToInventory(string item) {
        auto find_item = find(player_inventory.begin(), player_inventory.end(), item);
        
        if (find_item != player_inventory.end()) {
            cout << item << ": is already in your inventory." << endl;

        }
        else {
            player_inventory.push_back(item);
            cout << item << ": was added to your inventory!" << endl;

        }

    }


    void displayPlayerInventory() const {
        if (player_inventory.empty()) {
            cout << "No items in inventory." << endl;
            return;
        }

        for (size_t i = 0; i < player_inventory.size(); i++) {
            cout << "Item " << i+1 << ". " << player_inventory[i] << endl;
        }
        cout << endl;
    }

    bool hasItem(const string& item) const {
        return find(player_inventory.begin(), player_inventory.end(), item) != player_inventory.end();
    }

};


struct Enemy {
    double enemy_health;
};

class CombatEncounter {
private:
    double critical_attack;
    double injured;
    double attack;
    double armor;
    

public:
    //Constructors
    CombatEncounter() : critical_attack(0), injured(0), attack(1), armor() {}
    CombatEncounter(double crit, double inj, double at, double ar) : critical_attack(crit), injured(inj), attack(at), armor(ar) {}

    //Getters
    double getCriticalHit() const { return critical_attack; }
    double getInjuredHit() const { return injured; }
    double getAttack() const { return rand() % 20 + 10; }


    //Setters
    void resetCriticalChance(double critical_attack) { critical_attack = rand() % 10 + 1; }
    void resetInjuredChance(double injured) { injured = rand() % 15 + 1; }
    void resetAttack(double attack) { attack = rand() % 20 + 1; }

    double calculateDamage(Player& player) {
        double attack = getAttack();
        bool hasSword = false;
        for (size_t i = 0; i < player.player_inventory.size(); i++) {
            if(player.player_inventory[i] == "sword") {
                hasSword = true;
            }
        }
        return hasSword ? attack * 2 : attack;
    }

    double calculateEnemyDamage() {
        return getAttack() / 3;
    }
};


//Function declarations
void clearInputBuffer();
int getIntInput();
double getDoubleInput();
int openingGameMenu();
int pausedGameMenu();
void tutorialDisplay();
void playGameStart();
int playingGameMenu(Player& player);
//void changeSettings();
void loadSceneFromFile(const string& filename,  map<string, RoomInformation>& rooms, Player& player);
bool validateGameFiles(const string& filename);
bool moveRooms(Player& player, const string& direction);
void displayRoom(const Player& player);
void takeItem(Player& player, const string& itemName);
void fightEnemy(Player& player);
void finalBattle(Player& player);



//Main
int main() {
    srand(time(0));
    bool running = true;
    GameState game_state = GameState::MAIN_MENU;
    bool files_downloaded = validateGameFiles("game_content.txt");

    if (files_downloaded == false) {
        cout << " - Error in Starting Game, please check that files are installed - " << endl;
        running = false;
    }


    while (running){
        int start = openingGameMenu();
        
        switch (start) {   

            case 1: // Play Game
                game_state = GameState::PLAYING;
                playGameStart();
                break;

            case 2: // Change settings
                //changeSettings();
                break;
            
            case 3: // Load save
                break;

            case 4: // Erase save
                break;
            
            case 5: // View Tutorial
                tutorialDisplay();
                break;

            case 6: //view credits - add references too
                break;
            
            case 7: // Exit
                cout << " - Exiting Game - ";
                running = false;
                break;

            default:
                cout << " - Invalid input, please try again - ";

        };

        if (game_state != GameState::MAIN_MENU){running = false;};

    }

    return 0;
}




//Functions

//Input Validations
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int getIntInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();  
    return value;
}


double getDoubleInput() {
    double value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a decimal: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

bool validateGameFiles(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could Not Open - " << filename << endl;
        return false;
    }
    else {
        return true;
    }

}


int openingGameMenu() {
    cout << "===== Broken Dream =====\n";
    cout << "1. Play Broken Dream\n"; 
    cout << "2. Change Settings\n";
    cout << "3. Load Saved Game\n";
    cout << "4. Erase Saved Game\n";
    cout << "5. View Tutorial\n";
    cout << "6. View Credits\n";
    cout << "7. Exit\n"; 
    cout << "Enter your choice (1-7): \n";
    cout << "======================\n";
    return getIntInput();
}


int pausedGameMenu() {
    cout << "===== GAME PAUSED =====\n";
    cout << "1. Resume\n"; 
    cout << "2. Change Settings\n";
    cout << "3. Save Game\n";
    cout << "4. \n"; 
    cout << "5. \n"; 
    cout << "6. \n"; 
    cout << "7. Exit\n";
    cout << "Enter your choice (1-7): ";

    return getIntInput();
}

void tutorialDisplay() {
    cout << " - Welcome to Broken Dream - \n\n";
    cout << "Interaction:\n";
    cout << "   All interactions will be performed by input from the keyboard.";
    cout << "\nWhen prompted, enter the number or letter associated with the action and press the enter key.\n\n";
    cout << "Combat:\n";
    cout << "   As with interactions, input the number or character provided when prompted followed by the enter key."
    << " Some actions are timed, so be aware that you'll have to input under pressure.";
    cout << "\n\nPausing/Saving:\n";
    cout << "   To pause the game, there will be a prompt available in each interation.";
    cout << " For saving, in the pause menu there will be an option to save and to exit.";
    cout << "\n\nEnjoy Broken Dream!\n";
    cout << "--------------------------------------------------------------------------------------------------------\n\n";

    return;

}

/*
void changeSettings() {
    cout << 




}
*/

void loadSceneFromFile(const string& filename, map<string, RoomInformation>& rooms, Player& player) {
    
    ifstream file(filename);
    if (!file) {
        cerr << "Error: File Could Not Open" << filename << endl;
        return;
    }

    string line;
    string mode;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            if (line == "# name|description") mode = "room";
            else if (line == "# exits: from|direction|to") mode = "exit";
            else if (line == "# locked: from|direction|required_key") mode = "locked";
            else if (line == "# items: room|item") mode = "item";
            else if (line == "# enemies: room|amount") mode = "enemy";
            continue;
        }
    
        stringstream ss(line);
        string part1, part2, part3;
        getline(ss, part1, '|');
        getline(ss, part2, '|');
        getline(ss, part3);

        if (mode == "room") {
            RoomInformation room;
            room.room_name = part1;
            room.room_description = part2;
            rooms[room.room_name] = room;
        } else if (mode == "exit") {
            rooms[part1].exits[part2] = &rooms[part3];
        } else if (mode == "locked") {
            rooms[part1].lockedDoors[part2] = part3;
        } else if (mode == "item") {
            rooms[part1].items.push_back(part2);
        } else if (mode == "enemy") {
            rooms[part1].enemies.push_back(stoi(part2));
        }
    }

    file.close();

    if (!rooms.empty()) {
        player.currentRoom = &rooms.begin()->second;
    }
}


int playingGameMenu(Player& player) {
    cout << "\n" << player.getPlayerName() << "\n";
    cout << "1. Take Item\n"; 
    cout << "2. Look Around Room\n";
    cout << "3. Attack Enemy\n";
    cout << "4. Go North\n";
    cout << "5. Go East\n";
    cout << "6. Go South\n";
    cout << "7. Go West\n";
    cout << "8. Display Player Info\n";
    cout << "9. Pause Game\n";
    cout << "0. Exit\n"; 
    cout << "======================\n";
    cout << "Enter your choice (0-9): \n>";

    return getIntInput();

}

void displayRoom(Player& player) {
    RoomInformation* room = player.currentRoom;
    cout << "You are in " << room->room_name << ".\n" << room->room_description << "\n";

    cout << "There is ";
    if (room->items.empty()) {
        cout << "nothing to pick up here.\n";
    } 
    else {
        for (const auto& item : room->items) {
            cout << "a " << item << " here.\n";
        }
    }

    cout << "There are ";
    if (room->enemies.empty()) {
        cout << "no enemies here.\n";
    }
    else {
        for (const auto& enemy : room->enemies) {
            cout << enemy << " enemies here.\n";
        }
    }

    if (room->room_name == "Throne Room") {
        finalBattle(player);
        return;
    }
    

    cout << "There are doors that lead ( ";

    for (const auto& exit : room->exits) {
        cout << exit.first;
        cout << "  ";
    }
    cout << " )\n";

}

//This function was implemented with the help of chatgpt
bool moveRooms(Player& player, const string& direction) {
    RoomInformation* current = player.currentRoom;

    if (!current->exits.count(direction)) {
        cout << "You're unable to go that way.\n";
        return false;
    }

    if (current->lockedDoors.count(direction)) {
        string requiredKey = current->lockedDoors[direction];
        if (!player.hasItem(requiredKey)) {
            cout << "The door won't budge. You need " << requiredKey << ".\n";
            return false;
        }
        else {
            cout << "You use the " << requiredKey << " to open the way.\n";      
            current->lockedDoors.erase(direction);
        }

    }

    player.currentRoom = current->exits[direction];
    displayRoom(player);
    return true;

}

void takeItem(Player& player, const string& itemName) {
    auto& items = player.currentRoom->items;
    auto it = find(items.begin(), items.end(), itemName);
    if (it != items.end()) {
        player.addItemToInventory(itemName);
        items.erase(it);
        std::cout << "You picked up: " << itemName << "\n";
    } else {
        std::cout << "There's not a " << itemName << " to pick up. (or invalid input)\n";
    }
}


int enemyEncounterMenu() {
    cout << "\n----ENEMY ENCOUNTER----\n";
    cout << "1. Attack\n"; 
    cout << "2. Defend\n";
    cout << "3. Display Player Info\n";
    cout << "4. Display Enemy Info\n";
    cout << "5. Pause Game\n";
    cout << "------------------------\n";
    cout << "Enter your choice (1-5): \n>";

    return getIntInput();
}

void fightEnemy(Player& player) {
    RoomInformation* room = player.currentRoom;
    int enemy_count = 0;
    for (const auto& enemy : room->enemies) {
        enemy_count = enemy;
    }

    auto& monsters = player.currentRoom->enemies;
    auto monster = find(monsters.begin(), monsters.end(), enemy_count);


    bool alive = true;
    bool running = true;
    double player_hp = player.getPlayerHealth();
    CombatEncounter damage;
    vector<Enemy> enemies;
    double player_turn;
    double enemy_turn;
    for (int i = 0; i < enemy_count; i++) {
        enemies.push_back({100.00});
    }

    if (room->enemies.empty()) {
        cout << "-No Enemies to attack-\n";
        return;
    }

    double enemy_life = enemies[0].enemy_health;

    while (running && alive){
        int p_choice = enemyEncounterMenu();

        switch (p_choice) {
            case 1: // Attack
                if (!enemies.empty()) { 
                    player_turn = damage.calculateDamage(player);
                    cout << "-Attacking, you deal " << player_turn << " hit points-\n";

                    enemy_life = enemy_life - player_turn;

                    if (enemy_life <= 10) {
                        cout << "Enemy Slain!\n";
                        enemies.erase(enemies.begin());
                        enemy_count += 1;
                        enemy_life = 100.00;
                        cout << "Enemies left: " << enemies.size() << "\n";
                    }

                    else {
                        cout << "Enemy health: " << enemy_life << "\n";                   
                    }
                }
                else {
                    monsters.erase(monster);
                    cout << "-No enemies to fight-\n";
                    player.setPlayerHealth(100.00);
                    running = false;
                }
                break;

            case 2: // Defend
                player_turn = rand() % 61; // !!Make sure shield makes it to full block
                cout << "-Defending, you'll block " << player_turn << "% of damage-\n";


                break;

            case 3: // Display Player info
                cout << "Player health: " << player.player_health << "\n";
                break;

            case 4: // Display Enemy info
                cout << "Enemies left: " << enemies.size() << "\n";
                cout << "Enemy health: " << enemies[0].enemy_health << "\n";
                break;

            case 5: // pause game
                break;
                
            default:
                cout << "-- Invalid Input --";
            

        };

        //enemy turn

        if (running == false) {
            player.player_health = 100.00;

        }
        else {
            enemy_turn = damage.calculateEnemyDamage();
            cout << "-The enemy swings back, dealing " << enemy_turn << " hit points.-\n";
            player_hp = player_hp - enemy_turn;
            player.setPlayerHealth(player_hp);
            cout << "-You have " << player.getPlayerHealth() << " hit points left.-\n";
            if (player.player_health <= 0) {
                alive = false;
                player.setPlayerState(PlayerState::DEAD);
            }            
        }


    }


}

void finalBattle(Player& player) {
    cout << "Ahead of you looms a great winged beast. Behind, a door leaks sunlight.\n";
    bool won = false;

    int enemy_count = 1;
    bool alive = true;
    bool running = true;
    double player_hp = player.getPlayerHealth();
    CombatEncounter damage;
    double player_turn;
    double enemy_turn;

    double enemy_life = 500.00;


    while (running && alive){
        int p_choice = enemyEncounterMenu();

        switch (p_choice) {
            case 1: // Attack
                player_turn = damage.calculateDamage(player);
                cout << "-Attacking, you deal " << player_turn << " hit points-\n";

                enemy_life = enemy_life - player_turn;

                if (enemy_life <= 10) {
                    cout << "Final Enemy Slain!!\n";
                    won = true;
                }
                else {
                    cout << "Enemy health: " << enemy_life << "\n";                     
                }

                break;

            case 2: // Defend
                player_turn = rand() % 61; // !!Make sure shield makes it to full block
                cout << "-Defending, you'll block " << player_turn << "% of damage-\n";


                break;

            case 3: // Display Player info
                cout << "Player health: " << player.player_health << "\n";
                break;

            case 4: // Display Enemy info
                cout << "Enemy health: " << enemy_life << "\n";
                break;

            case 5: // pause game
                break;
                
            default:
                cout << "-- Invalid Input --";
            

        };

        //enemy turn

        if (won == true) {
            cout << "You did it!\n";
            cout << "Opening the door, you see sunlight. While clouds hang with hints of storm, the fresh air still brings tremendous relief.\n";
            cout << "The land rolls with grassy hills, untamed by man.\n";
            cout << "== YOU WIN! ==\n";
            exit(0);

        }
        else {
            enemy_turn = damage.calculateEnemyDamage();
            cout << "-The enemy swings back, dealing " << enemy_turn << " hit points.-\n";
            player_hp = player_hp - enemy_turn;
            player.setPlayerHealth(player_hp);
            cout << "-You have " << player.getPlayerHealth() << " hit points left.-\n";
            if (player.player_health <= 0) {
                alive = false;
                player.setPlayerState(PlayerState::DEAD);
                return;
            }            
        }


    }




}



void playGameStart() {    
    map<string, RoomInformation> rooms;
    Player newplayer;
    string newname;
    string item;
    GameState game_state = GameState::PLAYING;
    newplayer.setPlayerHealth(100.00);
    newplayer.setPlayerState(PlayerState::ALIVE);
    bool running = true;

    loadSceneFromFile("game_content.txt", rooms, newplayer); 

    if (!newplayer.currentRoom) {
        cerr << " - Failed to load - \n";
        return;
    }

    
    cout << "\nWelcome to Broken Dream, to begin, what would you like to be called? (Enter player name): ";
    getline(cin, newname);
    newplayer.setPlayerName(newname);
    cout << newplayer.getPlayerName() << "\n";   

    displayRoom(newplayer);

    while (running) {
        int p_choice = playingGameMenu(newplayer);

        switch (p_choice) {
            case 0: //Exit
                cout << "- Exited - \n";
                running = false;
                break;

            case 1: // Take item
                cout << "Enter the item in the room: \n>";
                getline(cin, item);
                takeItem(newplayer, item);
                break;

            case 2: // Look around
                displayRoom(newplayer);
                break;

            case 3: //Attack
                newplayer.setPlayerHealth(100.00);
                fightEnemy(newplayer);
                break;

            case 4: // Go north
                moveRooms(newplayer, "north");
                break;

            case 5: //Go east
                moveRooms(newplayer, "east");

                break;

            case 6://go south
                moveRooms(newplayer, "south");

                break;

            case 7://go west
                moveRooms(newplayer, "west");

                break;

            case 8:
                newplayer.displayPlayerInventory();
                break;

            case 9:
                pausedGameMenu();
                break;

            default:
                cout << "- Invalid input, please try again - \n";


        };

        if (game_state != GameState::PLAYING){running = false;};
        if (newplayer.player_state == PlayerState::DEAD) {
            running = false;
            cout << " - Game Over - \n";
        }


    }

}
