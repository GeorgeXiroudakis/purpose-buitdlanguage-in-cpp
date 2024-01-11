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


class healclass{
public:
    healclass(enum at_def at_def, int points){ healThe(at_def, points);}

};


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

void dealDamageTo(/*std::string str*/ enum at_def at_def, int points){
    if(at_def == attacker)attackerPok.hp -= points;
    else defenderPok.hp -= points;
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

bool andFunc(bool first, bool second){return first && second;}


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
#define AND ); andfunc

#define DEAR ;Learning(
#define LEARN )
#define ABILITY_NAME(x) #x

#define END  );}
#define END_OUT }

#define SHOW ;std::cout <<

#endif //PAR_POKEMONLEAGUE_H