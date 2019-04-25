
/**
 * @class Carta
 * @brief Carta d'una baralla Espanyola
 * @author Xavier Avivar
 */

#ifndef CARTA_H
#define CARTA_H

#include <iostream>

class Carta {
public:
    /**
     * @brief Constructorr per defecte
     */
    Carta();

    /**
     * @brief Constructor amb parametres
     * @param pal ens diu el pal de la carta
     * @param valor ens diu el valor de la carta
     */
    Carta(char pal, int valor,int ordre);

    /**Operadors*/

    /**
     * @brief Operador menor
     * @post Compara amb ors, copes, espases i bastos i pals 1..12
     */
    bool operator<(const Carta & c) const;

    /**
     * @brief Operador major
     * @post Compara amb ors, copes, espases i bastos i pals 1..12
     */
    bool operator>(const Carta & c) const;

    /**
     * @brief toString metode
     * @pre ---
     * @post Ens dona l'objecte en format de cadena de caracters
     */
    std::string toString() const;
    
    /**
     * @brief marranada
     * @pre ---
     * @post Canvia l'ordre en el que s'ordenen les cartes 0 = pal 1 = valor
     */
    void setOrdre(int ordre);
    /**
     * @brief ens dona el valor de la carta
     * @return valor
     */
    int valor() const;
private:

    char _pal; //@brief Pal de la carta
    int _valor; //@brief Valor de la carta
    int _ordre; //@brief Ens diu com ordenar la carta
    /**
     * @brief Es menor
     * @pre ---
     * @post Ens diu si la carta es menor o igual
     */
    bool esMenor(const Carta & c) const;
    
    /**
     * @brief Es major
     * @pre ---
     * @post Ens diu si la carta es major
     */
    bool esMajor(const Carta & c) const;
    
};

#endif /* CARTA_H */

