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

//std::vector<Pokemon> pokemonvect;
std::vector<Abilitie> abilitiesvect;

class Pokemon{
public:
    std::string name;
    std::string type;
    int hp;
    std::vector<Abilitie> LearnedAbilities;
    bool isInBall = true;

    Pokemon(){}

    Pokemon(std::string _name, std::string _type, int _hp);

     int friend operator,(Pokemon& left, const Pokemon& right);

};

class PokemonCollection {
public:
    static std::vector<Pokemon> pokemonvect;

    void operator[](Pokemon& other){
        pokemonvect.push_back(other);
    }

    // Optional: Define the operator[] to access a Pokemon by index
    Pokemon& operator[](size_t index) {
        if (index < pokemonvect.size()) {
            return pokemonvect[index];
        } else {
            // Handle out-of-bounds access or throw an exception
            throw std::out_of_range("Index out of bounds");
        }
    }

};

Pokemon::Pokemon(std::string _name, std::string _type, int _hp) {
    this->name = _name;
    this->hp = _hp;
    this->type = _type;

    PokemonCollection::pokemonvect.push_back(*this);

}

int operator,(Pokemon& left, const Pokemon& right){
    //PokemonCollection::pokemonvect.push_back(right);
    PokemonCollection::pokemonvect.push_back(left);
    return 0;
}


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

    Abilitie& operator[](size_t index){
    	if(index < abilitiesvect.size()){
		return abilitiesvect[index];
	}else{
		exit(EXIT_FAILURE);
	}

    }

    friend Abilitie& operator,(Abilitie& left,const Abilitie& right){
        abilitiesvect.push_back(right);
	return left;
    }

};

enum at_def {attacker, defender};

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


#define BEGIN_GAME \
    int main() {

#define END_GAME \
        ;\
        return 0; \
    }

#define CREATE ;

#define POKEMON Pokemon
#define POKEMONS PokemonCollection::pokemonvect

#define ABILITY Abilitie
#define ABILITIES Abilitie::abilitievector

#define ACTION []() { 0 ? 1
#define START 1 + 1;(1+1

#define NAME  0 ? "dont get this"
#define TYPE  0 ? "dont get this"
#define HP  0 ? 0

#define DAMAGE ); dealDamageTo(
#define HEAL ); healThe(
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   pokeball get in out
#define GET_HP(x) ); getHPof( x 0
#define GET_TYPE(x) ); getTypeof( x 0
#define GET_NAME(x) ); getNameof( x 0
#define IS_IN_POKEBALL(x) ); IsInBall( x 0

#define DEFENDER defender,
#define ATTACKER attacker,

#define END );}           //to proto klinetai apo to dumy, ta mesaia apo to epomeno kai to teleytaio apo ayto



#endif //PAR_POKEMONLEAGUE_H
