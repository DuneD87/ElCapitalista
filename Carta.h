
/**
 * @class Carta
 * @brief Carta d'una baralla Espanyola
 * @author Xavier Avivar
 */

#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>
#include <sstream>

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
    Carta(int pal, int valor);

    /**Operadors*/

    /**
     * @brief Operador menor
     * @post Compara amb ors, coPes, espases i bastos i pals 1..12
     */
    bool operator<(const Carta & c) const;

    /**
     * @brief Operador major
     * @post Compara amb ors, coPes, espases i bastos i pals 1..12
     */
    bool operator>(const Carta & c) const;

    /**
     * @brief toString metode
     * @pre ---
     * @post Ens dona l'objecte en format de cadena de caracters
     */
    std::string toString() const;

    /**
     * @brief ens dona el valor de la carta
     * @return valor Enter amb el valor de la carta
     */
    int valor() const;
    
    /**
     * @brief ens dona el pal de la carta 
     * @return Enter amb el pal de la carta
     */
    int pal() const;
private:
    int _pal; //@brief Pal de la carta
    int _valor; //@brief Valor de la carta
  
};

#endif /* CARTA_H */

