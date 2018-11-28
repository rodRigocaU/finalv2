#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Hielo.h"
#include "fruits.h"
#include "Enemigo.h"
#include "Miscelanea.h"


using namespace std;

sf::Sprite Game::TtoS(char *rute,sf::Texture &t){
    t.loadFromFile(rute);
    t.setSmooth(true);
    sf::Sprite s;
    s.setTexture(t);
    return s;
}

void Game::Run(sf::RenderWindow &app){
    sf::Texture ba;
    sf::Texture pl;
    sf::Texture ic;
    sf::Texture ich;
    sf::Texture icv;
    sf::Texture ob;
    sf::Texture ob2;
    sf::Texture me;
    sf::Texture frut;
    sf::Font font;
    sf::Text cad_1;
    sf::Text cad_2;
    sf::String str;
    sf::Texture enEmy;
    sf::Texture Back;
    sf::Texture Menus;


    char *menu_S = "Images/menu.jpg";
    char *fruti = "Images/fruit.png";
    char *enemy =  "Images/enemy.png";
    char *back_s = "Images/back.png";
    char *menus = "Images/menus.png";

    char *ice = "Images/bloque.png";
    char *iceh = "Images/hielo.png";
    char *bg = "Images/background.png";
    char *player = "Images/icecream.png";
    char *tronco = "Images/tronco.png";
    char *tronc2 = "Images/tronco2.png";

    font.loadFromFile("Images/MAGNETOB.TTF");
    cad_1.setCharacterSize(20);
    cad_2.setCharacterSize(20);

    str = "PRESS E TO CONTINUE";
    cad_1.setString(str);
    cad_1.setFont(font);
    cad_1.setColor(sf::Color(255,106,0));
    cad_1.setPosition(225,500);

    str = "PRESS ESC TO EXIT";
    cad_2.setString(str);
    cad_2.setFont(font);
    cad_2.setColor(sf::Color(255,106,0));
    cad_2.setPosition(225,600);


    int nivel1[15][15] = {{9,8,9,8,9,8,9,8,9,8,9,8,9,8,9},
                          {8,1,1,0,0,0,0,0,0,0,0,0,1,1,8},
                          {9,1,0,0,0,0,0,0,0,0,0,0,0,1,9},
                          {8,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
                          {9,0,0,0,0,1,1,0,1,1,0,0,0,0,9},
                          {8,0,0,0,0,0,0,4,0,0,0,0,0,0,8},
                          {9,0,0,1,0,0,0,0,0,0,0,1,0,0,9},
                          {8,0,0,1,0,0,0,2,0,0,0,1,0,0,8},
                          {9,0,0,1,0,0,0,0,0,0,0,1,0,0,9},
                          {8,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
                          {9,0,0,0,0,1,1,0,1,1,0,0,0,0,9},
                          {8,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
                          {9,1,0,0,0,0,0,0,0,0,0,0,0,1,9},
                          {8,1,1,0,0,0,0,0,0,0,0,0,1,1,8},
                          {9,8,9,8,9,8,9,8,9,8,9,8,9,8,9},};

    int frutita[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
                          {0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,3,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,3,0,0,0,0,0,0,0,0,0,0,0,3,0},
                          {0,3,3,3,0,0,0,3,0,0,0,3,3,3,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},};


    sf::Sprite Ice = TtoS(ice,ic);
    sf::Sprite Icehove = TtoS(iceh,ich);
    sf::Sprite Background = TtoS(bg,ba);
    sf::Sprite Icecream = TtoS(player,pl);
    sf::Sprite Troncos = TtoS(tronco,ob);
    sf::Sprite Troncos2 = TtoS(tronc2,ob2);

    sf::Sprite Menu = TtoS(menu_S,me);
    sf::Sprite fruta = TtoS(fruti,frut);
    sf::Sprite Enemys = TtoS(enemy,enEmy);
    sf::Sprite Backs = TtoS(back_s,Back);
    sf::Sprite Men = TtoS(menus,Menus);
    sf::Sprite MEn = TtoS(menus,Menus);


    Men.setPosition(225,490);
    MEn.setPosition(225,590);


    Backs.setPosition(0,0);
    Background.setPosition(50,50);
    Menu.setPosition(135,50);

    Player helado(Icecream,nivel1);
    Hielo hielo(Ice);
    Miscelanea tronco1(Troncos);
    Miscelanea tronco2(Troncos2);
    fruits fresa;
    Enemigo eny(Enemys,4*50,6*50);

    while(app.isOpen()){
        app.setFramerateLimit(FPS);
        app.clear(sf::Color (200,200,200));
        if(menu)
        {
            FPS = 5;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)){cad_1.setColor(sf::Color(255,0,102)); menu = false;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){cad_2.setColor(sf::Color(255,0,102));app.draw(cad_2);app.display();app.close();}
            app.draw(Backs);
            app.draw(Menu);
            app.draw(Men);
            app.draw(MEn);
            app.draw(cad_1);
            app.draw(cad_2);
            app.display();
            sf::Event e;
            while(app.pollEvent(e)){
                if(e.type == sf::Event::Closed)
                    app.close();}

        }
        else
        {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){app.close();}

        FPS = 60;

        app.clear(sf::Color (200,200,200));

        app.draw(Background);

        srand(time(NULL));
        for(int y=0;y<15;y++){
            for(int x=0;x<15;x++){
                fresa.setpos(x);
                fresa.setpoy(y);
                if(nivel1[y][x]==2){
                    helado.Controls(app,nivel1,Icehove);
                    helado.Draw(nivel1,x,y,app);
                    if(helado.getPosx() == eny.getposx() && helado.getPosy() == eny.getposy()){nivel1[y][x] = 4;}
                }
                if(nivel1[y][x]==1){
                    hielo.Draw(nivel1,x,y,app);
                }
                if(nivel1[y][x]==4){
                    eny.Draw(nivel1,x,y,app);
                }
                if(nivel1[y][x]==8){
                    tronco2.Draw(nivel1,x,y,app);
                }
                if(nivel1[y][x]==9){
                    tronco1.Draw(nivel1,x,y,app);
                }
                if(frutita[y][x]==3){
                    fruta.setPosition(fresa.getpos(),fresa.getpoy()-25);
                    app.draw(fruta);
                }
                if(nivel1[y][x]== 2 && frutita[y][x] == 3)
                {
                    frutita[y][x] = 0;
                    score_fruit++;
                }
            }
        }
        //eny.Draw(nivel1,0,0,app);
        //Enemys.setPosition(eny.getposx()*50,eny.getposy()*50);
        //app.draw(Enemys);
        app.display();
        sf::Event e;
        while(app.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                app.close();
        }
        }
    }
}
