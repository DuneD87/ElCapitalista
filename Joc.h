
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

#include "Jugador.h"
#include "Carta.h"
#include "PilaCartes.h"

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
    Joc(unsigned llavor,int nJugadors);
    
    /**
     * @brief Destructor
     * @post S'ha alliberat memoria
     */
    ~Joc();
    
    /**
     * @brief Constructor de copia
     * @pre ---
     * @post S'ha copiat l'objecte o al nostre objecte
     */
    Joc(const Joc & o);
    
    /**
     * @brief Operador d'assignacio
     * @pre ---
     * @post S'ha assignat el contingut del objecte parametre al nostre objecte
     */
    Joc & operator = (const Joc & j);
    
    /**
     * @brief Incialitza baralla
     * @pre nBaralles > 0
     * @post S'ha inicialitzat la baralla
     */
    void inicialitzarBaralla(int nBaralles);
    
    /**
     * @brief Barreja la baralla
     * @pre ---
     * @post S'ha barrejat la baralla fen servir l'algoritme de fisher yates
     */
    void barrejarBaralla();
    
    /**
     * @brief Inicialitza jugadors
     * @pre 0 < nJugadors
     * @post S'ha omplert una taula amb n jugadors
     */
    void inicialitzarJugadors();
   
    /**
     * @brief Reparteix cartes
     * @pre ---
     * @post S'han repartir les cartes entre tots els jugadors
     */
    void repartirCartes();
    
    /**
     * @brief Ronda d'una partida
     * @pre ---
     * @post S'ha efectuat una ronda de la partida
     */
    void ronda();
    
    /**
     * @brief Mostra la classificacio
     * @pre S'ha jugat una ronda previament
     * @post S'ha mostrar la classificacio de la ronda
     */
    void mostrarClassificacio() const;
    
    /**
     * @brief Intercanvi de cartes
     * @pre S'ha jugat una ronda previament
     * @post S'han intercanviat les cartes entre els diferents jugadors
     */
    void intercanviarCartes();
    
    /**
     * @brief Inicialitza la ronda
     * @pre S'ha jugat una ronda previament
     * @post S'han eliminat totes les cartes dels jugadors i buidat la pila
     */
    void inicialitzarRonda();
    
private:
    
    unsigned _llavor; //@brief Llavor per generar aleatorietat
    int _nBaralles; //@brief Ens diu el nombre de baralles del joc
    //Carta * _cartes;//@brief Taula dinamica que conte les cartes
    int _nCartes;//@brief numero de cartes que conte la baralla
    int _nJugadors;//@brief Numero de jugadors
    Jugador * _jugadors;//@brief Taula dinamica de jugadors
    int * _classificacio;
    PilaCartes _descartades;//@brief Pila de cartes descartades
    
    static const unsigned a = 1103515245, c = 12345, m = 32768; //Constants necessaries per generar nombres aleatoris
    
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
    
    /**
     * @breif Reserva memoria
     * @pre ---
     * @post S'ha reservat memoria per els jugadors i les cartes
     */
    void reserva();
    
    /**
     * @brief Allibera memoria
     * @pre ---
     * @post S'ha alliberat memoria
     */
    void allibera();
    
    /**
     * @brief Compara 2 valors de cartes
     * @pre x i y >= 1 && <= 12
     * @post Retorna cert si el valor de la carta es mes gran, fals altrament
     */
    bool esMesGran(int x, int y) const;
    
    /**
     * @brief Inicia el torn
     * @pre Tots els jugadors han passat o el jugador ha tret un 2
     * @post Les cartes anteriors s'han posat a 0, el jugador podra tirar qualsevol carta
     */
    void iniciTorn(int torn, int &nAnterior, int &cAnterior, int &hanPassat);
    
    /**
     * @brief Copia l'estructura
     * @pre ---
     * @post S'ha copiat el contingut de l'estructura
     */
    void copiar(const Joc & o);
};

#endif /* JOC_H */

