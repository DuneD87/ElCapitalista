
/* 
 * @brief Taula dinamica de cartes
 * @author Xavier Avivar
 *
 * Created on 8 / d’abril / 2019, 18:29
 */

#ifndef CONJUNTCARTES_H
#define CONJUNTCARTES_H

#include <iostream>
#include <sstream>

#include "Carta.h"

class ConjuntCartes {
public:
    /**
     * @brief Constructor per defecte
     * @pre ---
     * @post S'ha construit una taula dinamica per defecte
     */
    ConjuntCartes();
    
    /**
     * @brief Constructor amb parametres
     * @pre ---
     * @post S'ha construit una nova taula amb maxim nombre d'elements prefixats
     */
    ConjuntCartes(int max);
    
    /**
     * @brief Constructor de copia
     * @pre Taula orig no buida
     * @post S'ha construit una copia de orig
     */
    ConjuntCartes(const ConjuntCartes& orig);
    
    /**
     * @brief Destructor
     * @pre ---
     * @post S'ha alliberat memoria
     */
    ~ConjuntCartes();
    
    /**
     * @brief Operador d'assignacio
     * @pre ---
     * @post S'ha assignat el contigut de la taula orig, al nostre objecte
     */
    ConjuntCartes & operator =(const ConjuntCartes& t);
    
    /**
     * @brief Afegeix element
     * @pre ---
     * @post S'ha afegit l'element e
     */
    void afegir(const Carta &e);
    
    /**
     * @brief Elimina element
     * @pre ---
     * @post S'ha eliminat l'element e
     */
    void eliminar(const Carta &e);
    
    /**
     * @brief Converteix l'objecte en text
     * @pre ---
     * @post S'ha convertit el contingut de l'estructura a cadena de caracters
     */
    std::string toString() const;
    
    /**
     * @brief Numero d'elements
     * @pre ---
     * @post Ens diu el nombre d'elements dins de la taula
     */
    int tamany() const;
    
    /**
     * @brief Operador d'indexacio
     * @pre 0<=i<=nElems
     * @post Retorna l'element a la posicio i de la taula dinamica
     */
    Carta & elem(int j);
    
    /**
     * @brief Cerca l'element
     * @pre ---
     * @post Ens diu si l'element es troba dins de la taula
     */
    bool cercar(const Carta & e);

private:
    
    /**
     * @brief Copia l'element
     * @pre ---
     * @post S'ha copiat el contingut de la taula al nostre objecte
     */
    void copia(const ConjuntCartes& t);
    
    /**
     * @brief Allibera memoria
     * @pre ---
     * @post S'ha alliberat memoria
     */
    void allibera();
    
    /**
     * @brief Reserva memoria
     * @pre ---
     * @post S'ha reservat memoria
     */
    void reservar();
    
    /**
     * @brief Amplia la taula
     * @pre ---
     * @post S'ha ampliat el tamany de la taula
     */
    void ampliar();
    
    /**
     * @brief Cerca binaria
     * @pre ---
     * @post Cerca l'element dins de la taula (metode immersiu del metode 'cercar')
     */
    void cercaBinaria(const Carta & e, int &pos, bool &trobat);
    /*Atributs*/
    
    int _nElems; //@brief Ens diu el nombre d'elements
    int _maxElems; //@brief Ens diu la mida prefixada de la taula
    Carta * _taula; //@brief Taula dinamica d'elements
};

#endif /* TAULADINAMICA_H */
