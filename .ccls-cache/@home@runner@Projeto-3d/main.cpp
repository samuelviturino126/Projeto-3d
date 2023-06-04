#include "sculptor.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  Sculptor projeto(50, 50, 50); //cria a tela 
  projeto.setColor(100, 100, 29, 0);
  projeto.putBox(0, 30, 0, 30, 0, 30); //corpo da garrafa
  projeto.putBox(10, 20, 30, 35, 10, 20); //parte de cima da carrafa
  projeto.setColor(1,0,1,1);
  projeto.putBox(10, 29, 10, 29, 10, 29);
  projeto.writeOFF((char*)"write.off");
  
   // Sculptor projeto(100,100,100); //crio a área a ser utilizada 
    //projeto.setColor(720, 0, 170, 1); //cor do corpinho
    //projeto.putEllipsoid(50, 50, 50, 10, 10, 15);//corpinho
    //projeto.putBox(43, 40, 43, 58, 45, 63);
    //projeto.putEllipsoid(45, 50, 35, 3, 3, 5);//1pez
    //projeto.putEllipsoid(55, 50, 35, 3, 3, 5);//2pezinho
    //projeto.setColor(180, 180, 180, 1);//co do olho /cor olhinho
    //projeto.putEllipsoid(50, 58, 58, 4, 2, 3); //olhinho
    //projeto.writeOFF((char*)"write.off"); //escreve o arquivo
    return 0;
}