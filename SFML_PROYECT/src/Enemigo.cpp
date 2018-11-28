#include "Enemigo.h"
#include <SFML/Graphics.hpp>
#include "Objeto.h"
#include "stdlib.h"
#include "time.h"

Enemigo::Enemigo(sf::Sprite &s,int x, int y){

    this->s = s;
    posx = x;
    posy = y;
}

void Enemigo::redifine()
{
    int x  = (rand() % 14 + 1)*50;
    int y = (rand() % 14 + 1)*50;
    posfx = x;
    posfy = y;
}
void Enemigo::Draw(int m[15][15],int xo,int yo,sf::RenderWindow &app){

    mov = ruta[rand() % 9];
    redifine();
    if(llegada == false){
        if(mov == "Up"){
            up = true;
            if(Detector(m,xo,yo,up,down,left,right)==false){
                redifine();
            }
            left=right=down=false;
            if(posy == 14*50 - 25)
            {
                posy -= 5;
            }
            else
            {
                //mov = "Down";
                posy+=1;
            }

        }
    if(mov == "Down")
    {
        down = true;
        if(Detector(m,xo,yo,up,down,left,right)==false){
            redifine();
        }
        left=right=up=false;
        if(posy == 0)
        {
            posy += 5;
        }
        else
        {
            //mov = "Up";
            posy-=1;
        }

    }
    if(mov == "Right")
    {
        right = true;
        if(Detector(m,xo,yo,up,down,left,right)==false){
                redifine();
            }
        left=up=down=false;
        if(posx == 14*50)
        {
            posx -= 5;
        }
        else
        {
           // mov = "Left";
            posx-=1;
        }

    }
    if(mov == "Left")
    {
        left = true;
        if(Detector(m,xo,yo,up,down,left,right)==false){
                redifine();
            }
        up=right=down=false;
        if(posx == 0)
        {
            posx += 5;
        }
        else
        {
            //mov = "Right";
            posx+=1;
        }

    }
    }
    if(posx == posfx && posy == posfy)
    {
        Llegada();
    }
    if(llegada == true)
    {
        redifine();
        llegada = false;
    }
    Animation(0,0,57,124,"largo",s,3);
    s.setPosition(posx,posy-75);
    app.draw(s);
}

int Enemigo::getposx()
{
    return posx/50;
}

int Enemigo::getposy()
{
    return posy/50;
}


void Enemigo::Llegada()
{
    llegada = true;
}
