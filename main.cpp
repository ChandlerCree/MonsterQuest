#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

//functions
void attackChoice(int& attackDamage);
void retreatChoice(int& retreatPercentage);
void healChoice(int& healPoints);
void summonChoice(int& summonedDamage);
void monsterAttack(int& monsterDamage);

int main(int argc, char** argv) {

    //variables    
    int monsterHealth = 0, playerHealth = 0, attackDamage = 0, healAmount = 0, retreatChance = 0, retreatInterger = 1, summonCheck = 0, turnTick = 0, gameOverTurns = 0, monsterDeadCheck = 0;
    char startGame;
    char userChoice;
    char retreatChar;
    char rulesChar;
    int startGameInt = 0;
    int rulesInt = 0;
    
    srand(time(0)); //starts a randomization
    
    cout << "Hello and welcome to Dungeon Quest!" << endl;
    cout << "Please press 'e' to enter the Monsters Chamber!" << endl;
    cin>> startGame;
    cout<< endl;
    
    playerHealth = 20;
    monsterHealth = (rand() % 20 + 31);

    //cout<< "pstarthealth: " << playerHealth << endl;
    //cout<< "mstarthealth: " << monsterHealth << endl;
    

    do {
        switch (startGame) {  //asks the user if they wish to begin
            case 'e':
                startGameInt = 1;
                break;
            default: cout << "try again.";
        }
    } while (startGameInt != 1);

    cout<< endl;
    cout<< "You have entered the Chamber, in front of you awaits the Monster." << endl << endl;  //rules
    cout<< "                     ----------RULES----------" << endl;
    cout<< "You must win within 20 turns, or the floor will turn into lava and you will lose." << endl;
    cout<< "You start with 20 health." << endl;
    cout<< "The monster starts with between 30 and 50 health." << endl;
    cout<< "Each turn you may chose one of 4 options." << endl;
    cout<< "The monster will attack you every turn for anywhere between 1-6 damage." << endl;
    cout<< "If you chose to attack, you will do anywhere between 1 and 6 damage." << endl;
    cout<< "    You always attack before the monster." << endl;
    cout<< "If you chose to retreat, you have a 50% chance of success." << endl;
    cout<< "    If you are unsuccessful, the monster still attacks you." << endl;
    cout<< "If you chose to heal, you will regain somewhere between 1 and 8 health." << endl;
    cout<< "    If you heal the monster will attack first." << endl;
    cout<< "If you chose to summon, you will summon a creature that deals between 4 and 12 damage." << endl;
    cout<< "    You may only summon the monster once." << endl << endl;
    
    cout<< "Press 'y' when you understand the rules." << endl;
    cin>> rulesChar;
    do {
        switch (rulesChar) { //asks user if they understand rules
            case 'y':
                rulesInt = 1;
                break;
            default: cout << "Press 'y' when you understand." << endl;
        }
    } while (rulesInt != 1);
    
    cout<< endl;
    cout<< "You go first!" << endl;
    
    do{
        turnTick++; //sets a turn count
        cout<< "It is currently turn " << turnTick << "." << endl;
        cout<< "You have four options to chose from." << endl;
        cout<< "Attack 'a', Retreat 'r', Heal 'h', or Summon 's'" << endl; //displays options to the player for choice
        cout<< "Player health: " << playerHealth << endl; //displays players health
        if (summonCheck == 1){ //a check to see if the player has summoned yet
            cout<< "You have already summoned your being, you can no longer chose to Summon." << endl;
        }
        else{
            cout<< "You may only summon once." << endl;
        }
        cout<< "Enter one of the options" << endl;
        cin>> userChoice; //enters a char for the switch userchoice
        cout<< endl;
        switch(userChoice){ //receives a char and runs a code depending on the users choice
            case 'a':
                cout<< "You draw your diamond tipped sword. Approach the monster fiercely and swing with all your might." << endl;
                // cout<< "Monster health before attack: " << monsterHealth << endl;
                attackChoice(monsterHealth); //calls the pass by reference function attack
                // cout<< "The monster now has " << monsterHealth << " health left." << endl;
                if (monsterHealth > 0) { //checks if the monster has died
                cout<< "The monster attacks you back." << endl;
                monsterAttack(playerHealth); //calls the pass by reference function for monster attack
                cout<< "You now have " << playerHealth << " health remaining." << endl << endl;
                }
                if (playerHealth <=0 || monsterHealth <= 0){ //checks if you or the monster have died
                    break;
                }
                cout<< "Your turn again." << endl;
                break;
                
            case 'r':
                cout<< "You are attempting to retreat." << endl;
                cout<< "Retreating from the fight only has a 70% success rate. You must roll a number below 70 to succeed." << endl;
                cout<< "Still want test your luck and try to retreat? ('y'/'n')" << endl;
                cin>> retreatChar; //char for the switch on if the player wishes to retreat or not
                switch(retreatChar){ //yes or no switch for retreating
                    int retreatChance;
                    case 'y':
                        cout<< "Good luck!" << endl << endl;
                        retreatChoice(retreatChance); //calls the function for randomizing a chance at retreating
                        if (retreatChance <= 70){ //if the number received from the pass by reference function is less than 70 the player successfully retreats
                            cout<< "You successfully escaped the monsters dungeon." << endl << endl;  
                            cout<< "You walk away with nothing to say for yourself." << endl; 
                            cout<< "You took the cowards way out... The monster will continue to haunt you forever." << endl;
                            cout<< "At least you are still alive." << endl;
                            retreatInterger = 0;   //sets a variable to end the while loop                         
                        }
                        else{
                            cout<< "Sorry retreat unsuccessful." << endl;
                            cout<< "The monster attacks you." << endl;
                            monsterAttack(playerHealth); //calls the pass by reference function monster attack
                            cout<< "You now have " << playerHealth << " health remaining." << endl << endl;
                        }
                        break;
                    case 'n':
                        break;
                }
                break;
                
            case 'h':
                cout << "You have selected to heal." << endl;
                if (playerHealth >= 31){ //doesnt let the player heal if they have over 30 health
                    cout<< "Sorry you already have max health." << endl;
                    break;
                }
                
                    cout<< "Since you have chosen to heal, the monster hits you first." << endl;
                    cout<< "The monster attacks you." << endl;
                    monsterAttack(playerHealth); //calls the pass by reference function for monster attacking
                    cout<< "You now have " << playerHealth << " health remaining." << endl << endl;
                    if (playerHealth > 0){ //only allows player to heal if they arent dead
                        cout<< "Player health before heal: " << playerHealth << endl;
                        healChoice(playerHealth); //calls the pass by reference function for healing
                    }

                if (playerHealth >= 31){ //resets player health to max health if they surpass the total
                    cout<< "You have exceeded max health." << endl;
                    cout<< "Resetting health to 30 points." << endl;
                    playerHealth = 30;
                }
                if (playerHealth > 0) { //only runs the if conditional if the player isnt dead
                    cout<< "You now have " << playerHealth << " health remaining." << endl;
                    // cout<< "The monster now has " << monsterHealth << " health remaining." << endl << endl;
                }
                break;
                
            case 's':
                cout << "You have selected to Summon." << endl;
                if (summonCheck == 1){ //checks to see if the player has summoned before or not
                    cout<< "You have already summoned, you cannot select this attack." << endl << endl;
                    break;
                }
                summonChoice(monsterHealth); //calls the pass by reference function for summoning
                // cout<< "The monster now has " << monsterHealth << " health remaining." << endl;
                if (monsterHealth <= 0){ //checks to see if the monster is dead or not
                    monsterDeadCheck = 1; //sets a conditional to end the game
                }
                else{
                cout<< "The monster attacks you back." << endl;
                monsterAttack(playerHealth); //calls the pass by reference function for monster attack
                cout<< "You now have " << playerHealth << " health remaining." << endl << endl;
                }
                summonCheck = 1;
                break;
                
            default: cout<< "Sorry try again" << endl; //makes the user try again if they fail to enter a valid char
        }
        
        
        if (turnTick >= 20) gameOverTurns = 1; //sets a conditional to end the game if the turns run out
        if (gameOverTurns == 1) cout << "You have run out of turns. The floor turns to lava and you burn to death." << endl;
        if (playerHealth <= 0) cout << "You have died!" << endl; //checks to see if the player is dead
        if (monsterHealth <= 0) cout << "You have slain the monster!" << endl; //checks to see if the monster is dead
        else if (monsterHealth <= 10) cout << "The monster is low on health." << endl; //displays to the user if the monster goes below 10 health
        else{};
                
    }while (playerHealth > 0 && monsterHealth > 0 && retreatInterger != 0 && gameOverTurns != 1 && monsterDeadCheck != 1); //a conditional to check whether or not the exit the loop

    cout<< "Game Over." << endl << endl;
    return 0;
}
    

void attackChoice(int& attackDamage){
    srand(time(0)); //randomizes a value
    int pDamage = 0; 
    pDamage = (rand() % 6 + 1); //outputs a value between 1 and 6
    attackDamage = attackDamage - pDamage; // subtracts the damage from the attack from the health of the monster
    cout<< "Your attack did " << pDamage << " damage to the Monster." << endl;
    return;
}
void retreatChoice(int& retreatPercentage){
    srand(time(0)); //randomizes a value
    int outOfOneHundred = 0;
    outOfOneHundred = rand() %100 + 1;   //creates a number for reference by the retreat chance
    cout<< "Your retreat chance was: " << outOfOneHundred << endl;
    retreatPercentage = outOfOneHundred; //sets the retreat chance equal to the number randomized
    return;
}

void healChoice(int& healPoints){
    srand(time(0)); //randomizes a value
    int heal = 0;
    heal = rand() % 7 + 2; //generates a number between 2 and 8
    healPoints = healPoints + heal; //adds the number to the players health
    cout<< "You have healed for " << heal << " health points." << endl;
    return;
}

void summonChoice(int& summonedDamage){
    srand(time(0)); //randomizes a value
    int sDamage = 0;
    sDamage = rand() % 9 + 4; //generates a number between 4 and 12
    summonedDamage = summonedDamage - sDamage; //subtracts damage from the monsters health
    cout<< "Your raise your hands above your head and start to chant magical codes." << endl;
    cout<< "A ball of fire begins to form between your grasps." << endl;
    cout<< "You charge for a few seconds the throw your hands forward." << endl;
    cout<< "Forth shoots the face of a lion, teeth blaring." << endl;
    cout<< "The lion grasps his talons around the monsters neck, and shred the monsters skin." << endl;
    cout<< "Your attack did " << sDamage << " damage to the monster." << endl;
}

void monsterAttack(int& monsterDamage){
    srand(time(0)); //randomizes a value
    int mDamage = 0;
    mDamage = (rand() % 6 + 1); //generates a number between 1 and 6
    monsterDamage = monsterDamage - mDamage; //subtracts the monsters damage from the players health
    cout<< "The monster lashes out and deals " << mDamage << " damage in return." << endl;
    return;   
}
