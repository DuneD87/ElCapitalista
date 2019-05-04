
/* 
 * @brief Pila de cartes
 * @author Xavier Avivar
 *
 * Created on 4 / de maig / 2019, 18:19
 */

#ifndef PILACARTES_H
#define PILACARTES_H

#include <iostream>

#include "Carta.h"

class PilaCartes {
public:
    /**
     * @brief Constructor
     * @post S'ha creat una pila buida
     */
    PilaCartes();
    
    /**
     * @brief Constructor de copia
     * @post S'ha copiat orig a la pila actual
     */
    PilaCartes(const PilaCartes& orig);
    
    /**
     * @brief Operador d'assigancio
     * @post S'ha assignat orig a la nostra pila
     */
    PilaCartes & operator = (const PilaCartes& orig);
    
    /**
     * @brief Destructor
     * @post S'ha alliberat memoria
     */
    ~PilaCartes();
    
    /**
     * @brief Cim de la pila
     * @pre Pila no buida
     * @post Ens dona l'element que es troba al cim de la pila
     */
    Carta cim() const;
    
    /**
     * @brief Empila
     * @pre ---
     * @post S'ha afegit l'element al cim de la pila
     */
    void empila(const Carta& c);
    
    /**
     * @brief Desempila
     * @pre ---
     * @post S'ha eliminat l'element que es troba al cim de la pila
     */
    void desempila();
    
    /**
     * @brief Buida
     * @pre ---
     * @post Ens diu si la pila es buida
     */
    bool buida();
    
private:
    struct Node {
        Node * seg;
        Carta valor;
    };
    
    Node * _cim;//@brief Cim de la pila
    
    /**
     * @brief Allibera
     * @pre ---
     * @post S'ha alliberat memoria
     */
    void allibera();
    
    /**
     * @brief Copia
     * @pre ---
     * @post S'ha copiat el contingut de orig a la nostra pila
     */
    void copia(const PilaCartes & orig);
};

#endif /* PILACARTES_H */

