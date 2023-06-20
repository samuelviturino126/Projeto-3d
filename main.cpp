#include "sculptor.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  Sculptor projeto(100, 100, 100); //cria a tela 
  projeto.setColor(100, 100, 100, 1);
  projeto.putBox(35, 75, 35, 75, 35, 75); //corpo do boneco 
  projeto.putBox(35, 45, 15, 35, 35, 45); //pernas do boneco
  projeto.putBox(65, 75, 15, 35, 35, 75);
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
