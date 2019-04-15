
/* 
 * @brief Taula dinamica d'elements generics
 * @author Xavier Avivar
 *
 * Created on 8 / d’abril / 2019, 18:29
 */

#ifndef TAULADINAMICA_H
#define TAULADINAMICA_H

#include <iostream>
#include <sstream>

#include "Carta.h"

template<class element>
class TaulaDinamica {
public:
    /**
     * @brief Constructor per defecte
     * @pre ---
     * @post S'ha construit una taula dinamica per defecte
     */
    TaulaDinamica();
    
    /**
     * @brief Constructor amb parametres
     * @pre ---
     * @post S'ha construit una nova taula amb maxim nombre d'elements prefixats
     */
    TaulaDinamica(int max);
    
    /**
     * @brief Constructor de copia
     * @pre Taula orig no buida
     * @post S'ha construit una copia de orig
     */
    TaulaDinamica(const TaulaDinamica& orig);
    
    /**
     * @brief Destructor
     * @pre ---
     * @post S'ha alliberat memoria
     */
    ~TaulaDinamica();
    
    /**
     * @brief Operador d'assignacio
     * @pre ---
     * @post S'ha assignat el contigut de la taula orig, al nostre objecte
     */
    TaulaDinamica & operator =(const TaulaDinamica& t);
    
    /**
     * @brief Afegeix element
     * @pre ---
     * @post S'ha afegit l'element e
     */
    bool afegir(element &e);
    
    /**
     * @brief Elimina element
     * @pre ---
     * @post S'ha eliminat l'element e
     */
    element & eliminar(element &e);
    
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
    element & operator [](int i);
    
    /**
     * @brief Cerca l'element
     * @pre ---
     * @post Ens diu si l'element es troba dins de la taula
     */
    bool cercar(element & e);

private:
    
    /**
     * @brief Copia l'element
     * @pre ---
     * @post S'ha copiat el contingut de la taula al nostre objecte
     */
    void copia(const TaulaDinamica& t);
    
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
    void cercaBinaria(element & e, int &pos, bool &trobat);
    /*Atributs*/
    
    int _nElems; //@brief Ens diu el nombre d'elements
    int _maxElems; //@brief Ens diu la mida prefixada de la taula
    element * _taula; //@brief Taula dinamica d'elements
};

#endif /* TAULADINAMICA_H */

