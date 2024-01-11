//
// Created by george on 13/12/2023.
//

#include "PokemonLeague.h"


BEGIN_GAME

    //single pokemon creation
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


    //multiple pokemon creation
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

    //single abbility creation
    CREATE ABILITY {
    NAME: "HIDE",
    ACTION: START
            POKEBALL DEFENDER _
        END
    }

    //single abbility creation with if
    CREATE ABILITY {
            NAME: "HEAL ME",
            ACTION: START

                IF GET_HP(ATTACKER) < 30 DO
                    HEAL ATTACKER 50
                ELSE
                    HEAL ATTACKER 10
                END
            END_OUT
    }


    //multiple abilite creation
    CREATE ABILITIES [
            ABILITY {
            NAME: "scare_then_damage",
             ACTION: START
                        SHOW "I the attacker: " << GET_NAME(ATTACKER) << " will damage you\n"
                        DAMAGE DEFENDER 20
                END
            },
            ABILITY {
                    NAME: "big_heal",
                    ACTION: START
                        HEAL ATTACKER 70
                    END
            }
    ]

    //single learn
    DEAR "Pikachu" LEARN [
        ABILITY_NAME(scare_then_damage)
    ]

    DEAR "Pikachu" LEARN [
            ABILITY_NAME(big_heal)
    ]

    ;attackerPok = pokemonvect[0];pokemonvect[0].LearnedAbilities[0].foo();std::cout << attackerPok.hp;

END_GAME