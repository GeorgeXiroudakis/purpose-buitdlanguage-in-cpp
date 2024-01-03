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

END_GAME