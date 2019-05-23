
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
#include "ConjuntCartes.h"
#include "PilaCartes.h"

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
    Jugador(const std::string & nom);
    
    /**
     * @brief Afegeix una carta
     * @pre ---
     * @post S'ha afegit una carta al Conjunt de cartes
     */
    void afegirCarta(const Carta & c);
    
    /**
     * @brief Eliminar conjunt de cartes
     * @pre 0 < n < nombre de cartes a la ma
     * @post S'ha elimant un conjunt de cartes de la ma i empilat a la pila
     */
    void eliminarConjuntCartes(int nCartes, int valor, PilaCartes & p);
    
    /**
     * @brief Mostra el jugador
     * @pre ---
     * @post Ens dona el jugador en format de cadena de caracters
     */
    std::string toString() const;
    
    /**
     * @brief Conte les cartes
     * @pre nCartes ha de ser inferior al nombre d'elements a la ma del jugador i 
     * el valor ha d'estar entre 1 i 12
     * @post Ens diu si el jugador el nombre de cartes amb el valor donat
     */
    bool teCartesRepetides(int nCartes, int valor);
    
    /**
     * @brief Li queden cartes
     * @pre ---
     * @post Ens diu si el jugador encara te cartes
     */
    bool quedenCartes() const;
    
    /**
     * @brief Mostra la ma del jugador
     * @pre El jugador encara te cartes
     * @post S'han mostrat les cartes que te el jugador actualment
     */
    void mostrarMa() const;
    
    /**
     * @brief Ens diu si el jugador ha finalitzat la ronda
     * @pre ---
     * @post Retorna cert si el jugador ja no te cartes
     */
    bool haAcabat() const;
    
private:
    ConjuntCartes _ma;//@brief Conjunt de cartes que tindra el jugador
    std::string _nom;//@brief Nom del jugador
    bool _haAcabat; //@brief Ens diu si el jugador ha acabat la ronda
};

#endif /* JUGADOR_H */

