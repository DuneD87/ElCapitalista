
/* 
 * @brief Cua dinamica d'elements generics
 * @author Xavier Avivar
 * @note Com se que l'haure de reutilitzar per la practica final, la faig d'elements generics
 * Created on 27 / de març / 2019, 20:05
 */

#ifndef CUADINAMICA_H
#define CUADINAMICA_H

#include <iostream>

#include "Carta.h"

template <class element>
class CuaDinamica {
public:
    /**
     * @brief Constructor per defecte
     * @pre --
     * @post S'ha construit una cua buida
     */
    CuaDinamica<element>();
    
    /**
     * @brief Constructor de copia
     * @pre --
     * @post S'ha fet una copia de l'element o a la nostra cua
     */
    CuaDinamica<element>(const CuaDinamica &o);
    
    /**
     * @brief Destructor
     * @pre --
     * @post S'ha alliberat memoria
     */
    ~CuaDinamica<element>();
    
    /**
     * @brief Operador d'assignacio
     * @pre --
     * @post S'ha assignat o a la nostra cua
     */
    CuaDinamica& operator=(const CuaDinamica &o);
    
    /**
     * @brief Encua l'element
     * @pre --
     * @post S'ha afegit l'element e al final de la cua
     */
    void Encua(const element &e);
    
    /**
     * @brief Desencua l'element
     * @pre --
     * @post S'ha eliminat el primer element de la cua
     */
    void Desencua();
    
    /**
     * @brief Ens dona el primer element
     * @pre Cua no buida
     * @post Ens torna el primer element de la cua
     */
    element Primer() const;
    
    /**
     * @brief Diu si es buida
     * @pre --
     * @post Ens diu si no hi ha cap element a la cua
     */
    bool esBuida() const;
    
    /**
     * @brief Numero d'elements
     * @pre --
     * @post Ens diu quants elements hi ha a la cua
     */
    int nElements() const;
    
private:
    
    /**
     * @brief --
     * @pre o no es buida
     * @post S'ha copiat o a la cua
     */
    void copia(const CuaDinamica &o);
    
    /**
     * @brief --
     * @pre Cua no buida
     * @post S'ha alliberat memoria
     */
    void allibera();

    struct Node {
        element dada;
        Node *seguent;
    };
    
    Node *_primer;//@brief Apunta al primer element de la cua
    Node *_darrer;//@brief Apunta al darrer element de la cua
};

#endif /* CUADINAMICA_H */

