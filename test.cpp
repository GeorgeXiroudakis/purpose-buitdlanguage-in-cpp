//
// Created by george on 13/12/2023.
//

#include "PokemonLeague.h"


BEGIN_GAME

    //single pokemon creation
    CREATE POKEMON {
            NAME: "Pikachu",
            TYPE: "Electric",
            HP: 100
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

    CREATE ABILITY {
        NAME: "TYPE_ATTACK",
        ACTION: START
            IF GET_TYPE(DEFENDER) == "Grass" DO
                DAMAGE ATTACKER 60
            ELSE
                DAMAGE DEFENDER 30
            END
        END_OUT
    }

    //single abbility creation with if else
    CREATE ABILITY {
            NAME: "HEAL_ME",
            ACTION: START

                IF GET_HP(ATTACKER) < 30 DO
                    HEAL ATTACKER 50
                ELSE
                    HEAL ATTACKER 10
                END
            END_OUT
    }

    //single abbility creation with if not
    CREATE ABILITY {
    NAME: "NEAR_DEATH_STRENGTH",
    ACTION: START
        IF NOT (GET_HP(ATTACKER) > 15) DO
            DAMAGE DEFENDER 80
            END
        END_OUT
    }

    //single abbility creation with if and
    CREATE ABILITY {
    NAME: "MID_HP_MID_DAMAGE",
    ACTION: START
        IF AND (GET_HP(ATTACKER) < 90, GET_HP(ATTACKER) < 200, GET_HP(ATTACKER) < 70) DO
            DAMAGE DEFENDER 80
        END
    END_OUT
    }

    //single abbility creation with if or
    CREATE ABILITY {
    NAME: "HIGH_HP_OR_LOW_BIG_DAMAGE",
    ACTION: START
        IF OR (GET_HP(ATTACKER) < 15, GET_HP(ATTACKER) < 120, GET_HP(ATTACKER) < 170) DO
            DAMAGE ATTACKER 40
        END
    END_OUT
    }

    //multiple abilite creation
    CREATE ABILITIES [
            //ability with show
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
        ABILITY_NAME(HIGH_HP_OR_LOW_BIG_DAMAGE)
    ]

    DEAR "Pikachu" LEARN [
            ABILITY_NAME(big_heal)
    ]

    DEAR "Pikachu" LEARN [
            ABILITY_NAME(NEAR_DEATH_STRENGTH)
    ]

    DEAR "Pikachu" LEARN [
            ABILITY_NAME(TYPE_ATTACK)
    ]

    DEAR "Bulbasaur" LEARN[
        ABILITY_NAME(scare_then_damage)
    ]
    
    DEAR "Bulbasaur" LEARN[
        ABILITY_NAME(MID_HP_MID_DAMAGE)
    ]

    DEAR "Bulbasaur" LEARN[
        ABILITY_NAME(TYPE_ATTACK)
    ]

    DEAR "Bulbasaur" LEARN[
        ABILITY_NAME(biig_heal)
    ]

    DUEL

    //;attackerPok = pokemonvect[0];pokemonvect[0].LearnedAbilities[0].foo();std::cout << attackerPok.hp;

END_GAME