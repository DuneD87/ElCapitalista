
/* 
 * @brief Llista ordenada d'elements generics
 * @author Xavier Avivar Rubio
 * @note Com segurament l'he de reutilitzar, la faig d'element generics
 * Created on 2 / d’abril / 2019, 17:06
 */

#ifndef LLISTAORDENADA_H
#define LLISTAORDENADA_H

#include <iostream>
#include <sstream>

#include "Carta.h"

template<class element>
class LlistaOrdenada {
public:
    /**
     * @ordre O(1)
     * @brief Constructor per defecte
     * @pre --
     * @post S'ha construit una llista buida
     */
    LlistaOrdenada<element>();
    
    /**
     * @ordre O(n)
     * @brief Constructor de copia
     * @pre --
     * @post S'ha copiat "orig" a la nostra llista
     */
    LlistaOrdenada<element>(const LlistaOrdenada& orig);
    
    /**
     * @ordre O(n)
     * @brief Destructor
     * @pre --
     * @post S'ha alliberat memoria
     */
    ~LlistaOrdenada<element>();
    
    /**
     * @ordre O(n)
     * @brief Operador d'assignacio
     * @pre --
     * @post S'ha assignat e a la nostra llista 
     */
    LlistaOrdenada& operator = (const LlistaOrdenada<element> &e);
    
    /**
     * @ordre O(1)
     * @brief Ens diu si la llista es buida
     * @pre --
     * @post Retorna cert si la llista es buida, fals altrament
     */
    bool esBuida() const;
    
    /**
     * @ordre O(n)
     * @brief Ens diu si existeix l'element
     * @pre Llista no buida
     * @post Retorna cert si l'element e existeix a la llista, fals altrament
     */
    bool existeix(const element& e)  const;
    
    /**
     * @ordre O(n)
     * @brief Ens dona el contingut de la llista
     * @pre --
     * @post Ens torna el contingut de la llista en forma de cadena de caracters
     */
    std::string toString() const;
    
    /**
     * @ordre O(1)
     * @brief Nombre d'elements a la llista
     * @pre --
     * @post Ens diu el nombre de l'elements a la llista
     */
    int nElements() const;
    /**
     * @ordre O(n)
     * @brief Insereix l'element
     * @pre Element no repetit ?
     * @post S'ha inserit l'element 'e' a la nostra llista
     */
    void inserir(const element& e);
    
    /**
     * @ordre O(n)
     * @brief Esborra l'element
     * @pre Llista no buida
     * @post S'ha esborrat l'element 'e' de  la nostra llista
     */
    element esborrar(const element& e);
    
    /**
     * @ordre O(n)
     * @brief Iterador 
     * @pre ---
     * @post Ens dona una referencia de l'element de la llista
     */
    element & elem();
    
    /**
     * @ordre O(1)
     * @brief Es fi
     * @pre --
     * @post Ens diu si hem arribat al final de la llista
     */
    bool esFi() const;
    
private:
    
    /**
     * @ordre O(n)
     * @brief Copia la llista
     * @pre --
     * @post S'ha copiat la llista 'o'
     */
    void copia(const LlistaOrdenada& o);
    
    /**
     * @ordre O(n)
     * @brief Allibera memoria
     * @pre --
     * @post S'ha alliberat memoria
     */
    void allibera();
    
    struct Node {
        element dada;
        Node *seg;
    };
    Node *_inici;// @brief Punter al inici de la llista
    Node * _punt;//@brief Punter d interes
    int _nElems;// @brief Ens diu el nombre d'elements a la llista
};

#endif /* LLISTAORDENADA_H */

