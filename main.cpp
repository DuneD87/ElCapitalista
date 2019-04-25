

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
    std::cout<<"ENTRA EL NOMBRE DE BARALLES:\n";
    int nBaralles;
    std::cin>>nBaralles;
    Joc j(llavor,nBaralles);
    j.inicialitzarBaralla();
    return 0;
}

