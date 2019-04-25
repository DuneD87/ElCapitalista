
/* 
 * @class Jugador
 * @brief Classe encarregada de guardar dades i tenir els metodes pertinents dels jugadors
 * @author Xavier Avivar Rubio
 *
 * Created on 25 / d’abril / 2019, 21:32
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

#include "Carta.h"
#include "LlistaOrdenada.h"//Conjunt cartes == llista ordeanda ?

class Jugador {
public:
    /**
     * @brief Constructor per defecte **NO UTILITZAT**
     */
    Jugador();
    
    /**
     * @brief Constructor amb paramatres
     * @param nom del jugador
     */
    Jugador(std::string nom);
    
    /**
     * @brief Afegeix una carta
     * @pre ---
     * @post S'ha afegit una carta al Conjunt de cartes
     */
    void afegirCarta(const Carta & c);
    
    /**
     * @brief Eliminar conjunt de cartes
     * @pre 0 < n < nombre de cartes a la ma
     * @post S'ha elimant un conjunt de cartes de la ma
     */
    void eliminarConjuntCartes(int nCartes, int valor);
    
    /**
     * @brief Mostra el jugador
     * @pre ---
     * @post Ens dona el jugador en format de cadena de caracters
     */
    std::string toString() const;
    
private:
    LlistaOrdenada<Carta> _ma;//@brief Conjunt de cartes que tindra el jugador
    std::string _nom;//@brief Nom del jugador
    bool _desc; //@brief Ens diu si el jugador esta desqualificat
};

#endif /* JUGADOR_H */

