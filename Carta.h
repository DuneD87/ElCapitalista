/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carta.h
 * Author: drive
 *
 * Created on 15 / d’abril / 2019, 12:23
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
    Carta(char pal, int valor);
    
    /**Operadors*/
    
    /**
     * @brief Operador menor
     */
    bool operator < (const Carta & c) const;
    
    /**
     * @brief Operador major
     */
    bool operator > (const Carta & c) const;
    
    /**
     * @brief Operador menor o igual
     */
    bool operator <= (const Carta & c) const;
    
    /**
     * @brief operador d'igualtat
     */
    bool operator == (const Carta & c) const;
    
    /**
     * @brief toString metod
     */
    std::string toString() const;
    
    private:
        char _pal;//@brief Pal de la carta
        int _valor;//@brief Valor de la carta
        
};

#endif /* CARTA_H */

