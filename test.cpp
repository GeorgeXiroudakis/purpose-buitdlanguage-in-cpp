//
// Created by george on 13/12/2023.
//

#include "PokemonLeague.h"


BEGIN_GAME

    CREATE POKEMON {
            NAME: "Pikachu",
            TYPE: "Electric",
            HP: 120
    }

    CREATE POKEMON {
            NAME: "Squirtle",
            TYPE: "Water",
            HP: 100
    }

    CREATE ABILITY {
            NAME: "TEST ABILITY",
            ACTION: START
                DAMAGE DEFENDER 20
                DAMAGE ATTACKER 50
                HEAL DEFENDER 30
                HEAL ATTACKER 70
                GET_HP(DEFENDER)
                GET_HP(ATTACKER)
                GET_TYPE(DEFENDER)
                GET_TYPE(ATTACKER)
                GET_NAME(DEFENDER)
                GET_NAME(ATTACKER)
                IS_IN_POKEBALL(DEFENDER)
                IS_IN_POKEBALL(ATTACKER)
            END
    }

    CREATE POKEMONS [
            POKEMON{
                    NAME: "snorlax",
                    TYPE: "Fire",
                    HP: 120
            },
            POKEMON{
                    NAME: "Bulbasaur",
                    TYPE: "Grass",
                    HP: 85
            }
    ]

    CREATE ABILITIES [
            ABILITY {
            NAME: "TEST ABILITY2",
             ACTION: START
                        DAMAGE DEFENDER 20
                        DAMAGE ATTACKER 50
                        HEAL DEFENDER 30
                        HEAL ATTACKER 70
                        GET_HP(DEFENDER)
                        GET_HP(ATTACKER)
                        GET_TYPE(DEFENDER)
                        GET_TYPE(ATTACKER)
                        GET_NAME(DEFENDER)
                        GET_NAME(ATTACKER)
                        IS_IN_POKEBALL(DEFENDER)
                        IS_IN_POKEBALL(ATTACKER)
                END
            },
            ABILITY {
                    NAME: "TEST ABILITY3",
                    ACTION: START
                        DAMAGE DEFENDER 20
                        DAMAGE ATTACKER 50
                        HEAL DEFENDER 30
                        HEAL ATTACKER 70
                        GET_HP(DEFENDER)
                        GET_HP(ATTACKER)
                        GET_TYPE(DEFENDER)
                        GET_TYPE(ATTACKER)
                        GET_NAME(DEFENDER)
                        GET_NAME(ATTACKER)
                        IS_IN_POKEBALL(DEFENDER)
                        IS_IN_POKEBALL(ATTACKER)
                    END
            }
    ]

    DEAR "Squirtle" LEARN [
        ABILITY_NAME(TEST ABILITY3)
    ]

//    ;
//for(auto & i : pokemonvect){
//    std::cout << i.name << std::endl;
//}
//
//for(auto & i : abilitiesvect){
//    std::cout << i.name << std::endl;
//}
;std::cout << pokemonvect[1].LearnedAbilities[0].name;

END_GAME