
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
    void eliminarConjuntCartes(int nCartes, int valor, PilaCartes & p,bool mostrar);
    
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
    
    /**
     * @brief Dona les pitjors cartes
     * @pre ---
     * @post Donem n cartes al jugador passat per parametre
     */
    void donarPitjorCartes(Jugador &j, int nCartes, PilaCartes & p);
    
    /**
     * @brief Dona millor cartes
     * @pre ---
     * @post Donem les n millors cartes al jugador passat per parametre
     */
    void donarMillorCartes(Jugador &j, int nCartes);
    
    /**
     * @brief Elimina totes les cartes
     * @pre ---
     * @post S'han eliminat totes les cartes de la ma del jugador
     */
    void eliminarMa();
    
private:
    ConjuntCartes *_ma;//@brief Conjunt de cartes que tindra el jugador
    std::string _nom;//@brief Nom del jugador
    bool _haAcabat; //@brief Ens diu si el jugador ha acabat la ronda
};

#endif /* JUGADOR_H */

