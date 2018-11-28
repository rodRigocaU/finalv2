#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Objeto.h"
#include "Player.h"
#include "string"

#include <SFML/Graphics.hpp>
class Enemigo : public Objeto
{
    public:
        Enemigo(sf::Sprite&,int, int);
        void Llegada();
        void Draw(int [15][15],int,int,sf::RenderWindow&);
        void redifine();
        int getposx();
        int getposy();

    private:
        int posx,posy,posfx,posfy;
        string ruta[10] = {"Up","Down","Right","Left","Up","Down","Right","Left","Up","Down"};
        string mov;
        bool up=false,down=false,left=false;
        bool right=true;
        bool llegada;
        sf::Sprite s;
        int cont=0;
};

#endif // ENEMIGO_H
