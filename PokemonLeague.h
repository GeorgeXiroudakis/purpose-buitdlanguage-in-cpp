//
// Created by george and toni on 13/12/2023.
//

#ifndef PAR_POKEMONLEAGUE_H
#define PAR_POKEMONLEAGUE_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cstdarg>

class Pokemon;
class Abilitie;

std::vector<Pokemon> pokemonvect;
std::vector<Abilitie> abilitiesvect;

enum at_def {attacker, defender};

void healThe(enum at_def at_def, int points);

class Pokemon{
public:
    std::string name;
    std::string type;
    int hp;
    std::vector<Abilitie> LearnedAbilities;
    bool isInBall = true;

    Pokemon(){}

    Pokemon(std::string _name, std::string _type, int _hp){
        this->name = _name;
        this->hp = _hp;
        this->type = _type;

        pokemonvect.push_back(*this);

    }

    void operator[](const Pokemon& pok) {
        pokemonvect.push_back(pok);
    }
};

class Abilitie{
public:
    std::string name;
    std::function<void()> foo;

    Abilitie(){}

    Abilitie(std::string _name, std::function<void()> _foo){
        this->name = _name;
        this->foo = _foo;

        abilitiesvect.push_back(*this);

    }

    void operator[](const Abilitie& ab) {
        abilitiesvect.push_back(ab);
    }
};


//class healclass{
//public:
//    healclass(enum at_def at_def, int points){ healThe(at_def, points);}
//
//};


class Learning{
public:
    std::string name;

    Learning(std::string pokNmae){
        name = pokNmae;
    }

    void operator[](const std::string abName){
        for(auto & i : pokemonvect){
            if(i.name == this->name){
                for(auto & y : abilitiesvect){
                    if(y.name == abName){
                        i.LearnedAbilities.push_back(y);
                    }
                }
            }
        }
    }
};

Pokemon attackerPok;
Pokemon defenderPok;
long int rounds = 0;

void dealDamageTo(/*std::string str*/ enum at_def at_def, int points){
    if(at_def != attacker){
        //Case where we are electric 
        if(attackerPok.type == "Electric"){
            //If the one attacking us is Fire and if it isnt
            if(defenderPok.type == "Fire"){
                attackerPok.hp -= (points - points * 0,1);
            }else if(defenderPok.type == "Water"){ //Case where pokemon is Water
                attackerPok.hp -= (points - points * 0,13);
            }else if(defenderPok.type == "Grass"){ //Case where pokemon is Grass
                if(rounds % 2 == 1){
                    attackerPok.hp -= (points - points * 0,13);
                }else{
                    attackerPok.hp -= (points - points * 0,2);
                }
            }else{
                attackerPok.hp -= (points - points * 0,2); //Case where pokemon isnt Fire,Water or Grass
            }
        //Case where we are Water    
        }else if(attackerPok.type == "Water"){
            if(defenderPok.type == "Fire"){ //Case where pokemon is Fire
                attackerPok.hp -= (points + points * (8/100)); //For some reason 0,08 was invalid idk
            }else if(defenderPok.type == "Grass"){ //Case where pokemon is Grass
                if(rounds % 2 == 1){
                    attackerPok.hp -= points;
                }else{
                    attackerPok.hp -= (points - points * 0,07);
                }
            }else if(defenderPok.type == "Water"){ //Case where pokemon is Water
                attackerPok.hp -= points;
            }else{ //Case where it isnt Fire,Grass or Water
                attackerPok.hp -= (points - points * 0,07);
            }

        }else{
            if(defenderPok.type == "Fire"){
                attackerPok.hp -= (points + points * 0,15);
            }else if (defenderPok.type == "Water"){
                attackerPok.hp -= (points + points * 0,07);
            }else if(defenderPok.type == "Grass"){
                if(rounds % 2 == 1){
                    attackerPok.hp -= (points + points * 0,07);
                }else{
                    attackerPok.hp -= points;
                }
            }else{
                attackerPok.hp -= points;
            }
        }
    }else{ 
         if(defenderPok.type == "Electric"){
            //If the one attacking us is Fire and if it isnt
            if(attackerPok.type == "Fire"){
                defenderPok.hp -= (points - points * 0,1);
            }else if(attackerPok.type == "Water"){ //Case where pokemon is Water
                defenderPok.hp -= (points - points * 0,13);
            }else if(attackerPok.type == "Grass"){ //Case where pokemon is Grass
                if(rounds % 2 == 1){
                    defenderPok.hp -= (points - points * 0,13);
                }else{
                    defenderPok.hp -= (points - points * 0,2);
                }
            }else{
                defenderPok.hp -= (points - points * 0,2); //Case where pokemon isnt Fire,Water or Grass
            }
        //Case where we are Water    
        }else if(defenderPok.type == "Water"){
            if(attackerPok.type == "Fire"){ //Case where pokemon is Fire
                defenderPok.hp -= (points + points * (8/100)); //For some reason 0,08 was invalid idk
            }else if(attackerPok.type == "Grass"){ //Case where pokemon is Grass
                if(rounds % 2 == 1){
                    defenderPok.hp -= points;
                }else{
                    defenderPok.hp -= (points - points * 0,07);
                }
            }else if(attackerPok.type == "Water"){ //Case where pokemon is Water
                defenderPok.hp -= points;
            }else{ //Case where it isnt Fire,Grass or Water
                defenderPok.hp -= (points - points * 0,07);
            }

        }else{
            if(attackerPok.type == "Fire"){
                defenderPok.hp -= (points + points * 0,15);
            }else if (attackerPok.type == "Water"){
                defenderPok.hp -= (points + points * 0,07);
            }else if(attackerPok.type == "Grass"){
                if(rounds % 2 == 1){
                    defenderPok.hp -= (points + points * 0,07);
                }else{
                    defenderPok.hp -= points;
                }
            }else{
                defenderPok.hp -= points;
            }
        }
    }
}

void healThe(enum at_def at_def, int points){
    if(at_def == attacker)attackerPok.hp += points;
    else defenderPok.hp += points;
}

int getHPof(enum at_def at_def, int /*ingore*/){
    if(at_def == attacker)return attackerPok.hp;
    else return defenderPok.hp;
}

std::string getTypeof(enum at_def at_def, int /*ingore*/){
    if(at_def == attacker)return attackerPok.type;
    else return defenderPok.type;
}

std::string getNameof(enum at_def at_def, int /*ingore*/){
    if(at_def == attacker)return attackerPok.name;
    else return defenderPok.name;
}

bool IsInBall(enum at_def at_def, int /*ingore*/){
    if(at_def == attacker)return attackerPok.isInBall;
    else return defenderPok.isInBall;
}

void inOutPokeball(enum at_def at_def, std::string in_out){
    if(at_def == attacker){
        if(in_out == "in")attackerPok.isInBall = true;
    }
    else{
        if(in_out == "in")defenderPok.isInBall = true;
    }
}

bool andFunc(const std::vector<bool>& args) {
    bool result = true;
    for (bool arg : args) {
        result = result && arg;
    }
    return result;
}

bool orFunc(const std::vector<bool>& args) {
    bool result = false;
    for (bool arg : args) {
        result = result || arg;
    }
    return result;
}


void printPokemons() {
    std::vector<std::string> printed;
    for (auto poke : pokemonvect) {
        bool flag = false;
        for (auto printedPoke : printed) {
            if (poke.name == printedPoke) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << poke.name << std::endl;
            printed.push_back(poke.name);
        }
    }
}

void printPokeAbilities(std::string pokeName){
    std::vector<std::string> printed;
    Pokemon poke = Pokemon("NULL", " ", 0);
    for(auto pok : pokemonvect){
        if(pok.name == pokeName){
            poke = pok;
            break;
        }
    }

    if(poke.name == "NULL"){
        std::cerr << "pokemone not faund\n";
        return;
    }

    for (auto ability : poke.LearnedAbilities) {
        bool flag = false;
        for (auto printedPoke : printed) {
            if (ability.name == printedPoke) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << ability.name << std::endl;
            printed.push_back(ability.name);
        }
    }
}

bool isPokeDead(Pokemon poke){
    if(poke.hp <= 0) return true;
    return false;
}


void printPokeStatus(Pokemon poke){
    std::cout << "NAME: " << poke.name << std::endl <<
                 "HP: "  << poke.hp << std::endl <<
                 "Type: " << poke.type << std::endl;
}

void fight(){

    std::string selection1;
    std::string selection2;
    Abilitie abilitie1;
    Abilitie abilitie2;
    bool flag = false;

    std::cout << "-------------------- POKEMON THE GAME --------------------" << std::endl;

    std::cout << std::endl << "Player1 select pokemon:" << std::endl;
    std::cout << "---------------" << std::endl;
    printPokemons();
    std::cout << "---------------" << std::endl;
    while(flag == false){
        std::cin >> selection1;

        for(auto poke : pokemonvect){
            if(poke.name == selection1){
                flag = true;
                attackerPok = poke;
                break;
            }
        }
        if(flag == false){
            std::cout << "Invalid Pokemon name please try again." << std::endl;
        }
    }
    std::cout << attackerPok.name << std::endl;

    std::cout << std::endl << "Player2 select pokemon:" << std::endl;
    std::cout << "---------------" << std::endl;
    printPokemons();
    std::cout << "---------------" << std::endl;
    flag = false;
    while(flag == false){
        std::cin >> selection1;

        for(auto poke : pokemonvect){
            if(poke.name == selection1){
                flag = true;
                defenderPok = poke;
                break;
            }
        }
        if(flag == false){
            std::cout << "Invalid Pokemon name please try again." << std::endl;
        }
    }
    std::cout << defenderPok.name << std::endl;
    rounds++;
    while(attackerPok.hp > 0 && defenderPok.hp > 0){
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "     " << "Round" << rounds << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        
        std::cout << attackerPok.name << "(Player1) select ability:" << std::endl;
        std:: cout << "---------------" << std::endl;
        printPokeAbilities(attackerPok.name);
        flag = false;
        while(flag != true){
            std::cin >> selection1;
            for(int i = 0;i < attackerPok.LearnedAbilities.size();i++){
                if(selection1 == attackerPok.LearnedAbilities[i].name){
                    abilitie1 = attackerPok.LearnedAbilities[i];
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                std::cout << "Invalid ability name please try again." << std::endl;
            }
        }
        abilitie1.foo();
        
        std::cout << std::endl << "###############" << std::endl;
        printPokeStatus(attackerPok);
        std::cout << "###############" << std::endl << std::endl;
        printPokeStatus(defenderPok);
        std::cout << "###############" <<std::endl << std::endl;

        if(defenderPok.hp <= 0 ){
            break;
        }

        std::cout << defenderPok.name << "(Player2) select ability:" << std::endl;
        std::cout << "---------------" <<std::endl;
        printPokeAbilities(defenderPok.name);
        flag = false;
        while(flag != true){
            std::cin >> selection2;
            for(int i = 0;i < defenderPok.LearnedAbilities.size();i++){
                if(selection2 == defenderPok.LearnedAbilities[i].name){
                    abilitie2 = defenderPok.LearnedAbilities[i];
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                std::cout << "Invalid ability name please try again." << std::endl;
            }
        }
        abilitie2.foo();
        std::cout << std::endl << "###############" << std::endl;
        printPokeStatus(attackerPok);
        std::cout << "###############" << std::endl << std::endl;
        printPokeStatus(defenderPok);
        std::cout << "###############" <<std::endl << std::endl;
        rounds++;

    }

    if(attackerPok.hp <= 0){
        std::cout << attackerPok.name << " has fainted!" << std::endl;
        std::cout << defenderPok.name << " wins!" <<std::endl;
    }else{
        std::cout << defenderPok.name << " has fainted!" << std::endl;
        std::cout << attackerPok.name << " wins!" <<std::endl;
    }



}


#define BEGIN_GAME \
    int main() {

#define END_GAME \
        ;\
        return 0; \
    }

#define CREATE ;

#define POKEMON Pokemon
#define POKEMONS Pokemon()

#define ABILITY Abilitie
#define ABILITIES Abilitie()

#define ACTION []() { 0 ? 1
#define START 1 + 1;

#define NAME  0 ? "dont get this"
#define TYPE  0 ? "dont get this"
#define HP  0 ? 0

#define DAMAGE  ;dealDamageTo(
#define HEAL  ;healThe(
#define POKEBALL  inOutPokeball(
#define _ "in"
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   pokeball get in out
#define GET_HP(x)  getHPof( x 0 )
#define GET_TYPE(x) getTypeof( x 0 )
#define GET_NAME(x) getNameof( x 0 )
#define IS_IN_POKEBALL(x) ); IsInBall( x 0

#define DEFENDER defender,
#define ATTACKER attacker,

#define IF  if(
#define DO ){
#define ELSE  );}else{
#define NOT !
#define AND(...) andFunc({__VA_ARGS__, true})
#define OR(...) orFunc({__VA_ARGS__, false})


#define DEAR ;Learning(
#define LEARN )
#define ABILITY_NAME(x) #x

#define END  );}
#define END_OUT }

#define SHOW ;std::cout <<

#define DUEL ;fight();

#endif //PAR_POKEMONLEAGUE_H