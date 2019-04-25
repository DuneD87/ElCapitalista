
/* 
 * @class Joc
 * @brief Classe encarregada de gestionar les diferents opcions del joc
 * @author Xavier Avivar Rubio
 *
 * Created on 25 / d’abril / 2019, 10:56
 */

#ifndef JOC_H
#define JOC_H

#include <iostream>
#include <cstdlib>

#include "Carta.h"

class Joc {
public:
    /**
     * @brief Constructor per defecte **NO UTILITZAT**
     */
    Joc();
    
    /**
     * @brief Constructor amb parametres
     * @param llavor ens dona la llavor que farem servir per fer la barreja de cartes
     * @param nBaralles ens diu el nombre de baralles que te el joc
     */
    Joc(unsigned llavor,int nBaralles);
    
    /**
     * @brief Destructor
     * @post S'ha alliberat memoria
     */
    ~Joc();
    
    /**
     * @brief Incialitza baralla
     * @pre nBaralles > 0
     * @post S'ha inicialitzat la baralla
     */
    void inicialitzarBaralla();
    
    /**
     * @brief Barreja la baralla
     * @pre ---
     * @post S'ha barrejat la baralla
     */
    void barrejarBaralla();

private:
    
    unsigned _llavor; //@brief Llavor per generar aleatorietat
    int _nBaralles; //@brief Ens diu el nombre de baralles del joc
    Carta * _cartes;//@brief Taula dinamica que conte les cartes;
    int _nCartes;//@brief numero de cartes que conte la baralla;
    static const unsigned a = 1103515245, c = 12345, m = 32768;
    
    /**
     * @brief Generador de nombres aleatoris
     * @pre ---
     * @post S'ha generat un nombre aleatori nou
     */
    unsigned random(unsigned i);
    
    /**
     * @brief Intercanvia les cartes
     * @pre ---
     * @post S'han intercanviat les cartes de posicio
     */
    void intercanvi(Carta& a, Carta& b);
};

#endif /* JOC_H */

