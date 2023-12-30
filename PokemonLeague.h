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

class Pokemon{
public:
    std::string name;
    std::string type;
    int hp;

    Pokemon(){}

    Pokemon(std::string _name, std::string _type, int _hp){
        this->name = _name;
        this->hp = _hp;
        this->type = _type;

        pokemonvect.push_back(*this);

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
};

enum at_def {attacker, defender};

Pokemon attackerPok;
Pokemon defenderPok;

void dealDamageTo(enum at_def at_def, int points){
    if(at_def == attacker)attackerPok.hp -= points;
    else defenderPok.hp -= points;
}

#define BEGIN_GAME \
    int main() {

#define END_GAME \
        ;\
        return 0; \
    }

#define CREATE ;

#define POKEMON Pokemon

#define ABILITY Abilitie
#define ACTION []() { 0 ? 1
#define START 1 + 1;

#define NAME  0 ? "dont get this"
#define TYPE  0 ? "dont get this"
#define HP  0 ? 0

#define DAMAGE dealDamageTo(
#define DEFENDER defender,

#define END );}



#endif //PAR_POKEMONLEAGUE_H
