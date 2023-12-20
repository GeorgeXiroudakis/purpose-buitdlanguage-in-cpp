//
// Created by george and toni on 13/12/2023.
//

#ifndef PAR_POKEMONLEAGUE_H
#define PAR_POKEMONLEAGUE_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>

class Pokemon;

std::vector<Pokemon> pokemonvect;

#define BEGIN_GAME \
    int main() {

#define END_GAME \
        ;\
        return 0; \
    }

#define CREATE ;
#define POKEMON Pokemon

#define NAME  0 ? "dong get this"
#define TYPE  0 ? "dong get this"
#define HP  0 ? 0


class Pokemon{
public:
    std::string name;
    std::string type;
    int hp;

    Pokemon(std::string _name, std::string _type, int _hp){
        this->name = _name;
        this->hp = _hp;
        this->type = _type;

        pokemonvect.push_back(*this);

    }

};


#endif //PAR_POKEMONLEAGUE_H
