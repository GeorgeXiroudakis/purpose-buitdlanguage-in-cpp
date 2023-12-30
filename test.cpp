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
            NAME: "Solar_Power",
            ACTION: START
                //POKEBALL ATTACKER ---α
                DAMAGE DEFENDER 20
            END
    }

END_GAME