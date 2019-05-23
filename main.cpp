

/* 
 * @brief Programa principal que inicialitzara el nostre joc
 * @author Xavier Avivar Rubio
 *
 * Created on 15 / d’abril / 2019, 12:23
 */

#include <cstdlib>
#include <iostream>

#include "Joc.h"

int main(int argc, char** argv) {
    std::cout<<"*** JOC DE L'ESCLAU ***\n"<<
            "ENTRA LA LLAVOR:\n";
    unsigned llavor;
    std::cin>>llavor;
    /*std::cout<<"ENTRA EL NOMBRE DE BARALLES:\n";
    int nBaralles;
    std::cin>>nBaralles;*/
    std::cout<<"ENTRA EL NOMBRE DE JUGADORS:\n";
    int nJugadors;
    std::cin>>nJugadors;
    Joc j(llavor,nJugadors);
    j.inicialitzarJugadors();
    std::cout<<"ENTRA EL NOMBRE DE BARALLES:\n";
    int nBaralles;
    std::cin>>nBaralles;
    j.inicialitzarBaralla(nBaralles);
    j.ronda();
    std::cout<<"VOLS FER UNA NOVA RONDA?\n";
    char novaRonda;
    std::cin>>novaRonda;
    j.mostrarClassificacio();
    return 0;
}

