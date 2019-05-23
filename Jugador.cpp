
#include "Jugador.h"

Jugador::Jugador() {
}

Jugador::Jugador(const std::string& nom) {
    _nom = nom;
    _ma = new ConjuntCartes();
}




void Jugador::afegirCarta(const Carta& c) {

    _ma->afegir(c);
}

void Jugador::eliminarConjuntCartes(int nCartes, int valor, PilaCartes & p, bool mostrar) {
    
    for (int i = 0; i < nCartes; i++) {
        bool cartaEliminada = false;
        for (int i = 0; i < _ma->tamany(); i++) {
            if ((_ma->elem(i).valor() == valor) && !cartaEliminada) {

                if (mostrar) std::cout<<_ma->elem(i).toString();
                p.empila(_ma->elem(i));
                _ma->eliminar(_ma->elem(i));
                cartaEliminada = true;
            }
        }
    }
}

std::string Jugador::toString() const {
    return _nom;
}

bool Jugador::teCartesRepetides(int nCartes, int valor) {
    int n = 0;
                    
    for (int i = 0; i < nCartes; i++) {
        //Mirem si existeixen n cartes amb el valor donat
        for (int j = 0 ; j < _ma->tamany(); j++) {
            if (_ma->elem(j).valor() == valor)
                n++;
        }
    }
    
    return n >= nCartes;
}

bool Jugador::quedenCartes() const {
    return _ma->tamany() > 0;
}

void Jugador::mostrarMa() const {
    std::cout<<_ma->toString()<<'\n';
}

bool Jugador::haAcabat() const {
    return _ma->tamany() == 0;
}

void Jugador::donarCartes(Jugador& j, int nCartes, PilaCartes & p) {
    std::cout<<"EL JUGADOR/A"<< _nom<<" I EL JUGADOR/A "<<j._nom<<" INTERCANVIEN "<<nCartes<<" CARTES\n";
    int cartesDonades = 0;
    std::cout<<"- JUGADOR/A "<<_nom<<" -\n";
    std::cout<<_ma->toString()<<'\n';
    std::cout<<"QUINES CARTES VOLS TIRAR?\n";
    while (cartesDonades < nCartes) {
        int actual;
        std::cin>>actual;
        eliminarConjuntCartes(1,actual,p,false);
        if (!p.buida()) j.afegirCarta(p.cim());
        p.desempila();
        cartesDonades++;
        
    }
}

void Jugador::eliminarMa() {
    for (int i = 0; i < _ma->tamany(); i++) {
        _ma->eliminar(_ma->elem(i));
    }
}
