#include "sculptor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
//Cria a matriz principal
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
nx = _nx; //atribui o valor nx a variável _nx da matriz
ny = _ny; //o mesmo p/ y
nz = _nz; //o mesmo p/ z
//aloca a memória para a matriz 3D 
v = new Voxel **[nx];
for(int xs=0; xs<nx; xs++){
v[xs]= new Voxel *[_ny];}
for(int xs=0; xs<nx; xs++){
for(int ys=0; ys<ny; ys++){
v[xs][ys]= new Voxel [nz];
}}
for(int xs=0; xs<nx; xs++){
for(int ys=0; ys<ny; ys++){
for(int zs=0; zs<nz; zs++){
//define os parametros iniciais
//sem cores e transparente
v[xs][ys][zs].show=false;
v[xs][ys][zs].r=r;
v[xs][ys][zs].g=g;
v[xs][ys][zs].b=b;
v[xs][ys][zs].a=alpha;
}}}}

//Desalocação de memória para a matriz 3D
Sculptor::~Sculptor()
{
int ax, ay;
ax=nx;
ay=ny;
for(int as=0; as<ax; as++){
for(int ass=0; ass<ay; ass++){
delete[] v[as][ay];
}
}
for(int as=0; as<ax; as++){
delete [] v[as];
}
delete [] v;}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
this->r=r;
this->g=g;
this->b=b;
this->alpha=alpha;
}
//atribuimos os valores 

//para colocar o Voxel
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = alpha;
}

//Excluir o Voxel (só faz fazer o voxel sumir)
void  Sculptor :: cutVoxel ( int x, int y, int z)
{
    v[x][y][z].show = false ;
}


void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
int i,j,k;
for(i = x0; i <= x1; i++){
for(j = y0; j <= y1; j++){
for(k = z0; k <= z1; k++){
putVoxel(i,j,k);
}}}}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
int i,j,k;
for(i = x0; i <= x1; i++){
for(j = y0; j <= y1; j++){
for(k = z0; k <= z1; k++){
cutVoxel(i,j,k);
}}}}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for ( int i = 0 ; i <(2*xcenter); i ++)
    {
        for ( int j = 0 ; j < (2*ycenter); j ++)
        {
            for ( int k = 0 ; k < (2*zcenter); k ++)
            {
                if (((i-xcenter) * (i-xcenter) + (j-ycenter) * (j-ycenter) + (k-zcenter) * (k-zcenter)) <= (radius*radius))
                {
                   putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for ( int i = 0 ; i <(2*xcenter); i ++)
    {
        for ( int j = 0 ; j < (2*ycenter); j ++)
        {
            for ( int k = 0 ; k < (2*zcenter); k ++)
            {
                if (((i-xcenter) * (i-xcenter) + (j-ycenter) * (j-ycenter) + (k-zcenter) * (k-zcenter)) <= (radius*radius))
                {
                   cutVoxel(i,j,k);
                }
            }
        }
    }
}

//definindo o putEllipsoid
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

for(int i=xcenter-rx; i<xcenter+rx; i++)
{
for(int j=ycenter-ry; j<ycenter + ry; j++)
{
for(int k=zcenter-rz; k<zcenter+rz; k++)
{
if ((pow(i-xcenter,2)/pow(rx,2)) + (pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) <= 1)
{
putVoxel(i,j,k);
}
}
}
}
}
//

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=xcenter-rx; i< xcenter+rx; i++)
    {
        for(int j=ycenter-ry; j<ycenter + ry; j++)
        {
            for(int k=zcenter-rz; k< zcenter+rz; k++)
            {
                if ((pow(i-xcenter,2)/pow(rx,2)) + (pow(j-ycenter,2)/pow(ry,2)) + (pow(k-zcenter,2)/pow(rz,2)) <= 1)
                {
                   cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename)
{
int i=0, j=0, k=0;
putVoxel(i,j,k);
std::ofstream arq;
 int total=0;
for(int i = 0; i<nz; i++)
{
for(int j = 0; j<ny; j++)
{
for(int k = 0; k<nx; k++)
{
if(v[i][j][k].show == true)
                {
                    total++;
                }
            }
        }
    }
    int vertices=total*8, faces=total*6;
    arq.open(filename);
    arq<<"OFF"<<std::endl;
    arq<<vertices<<" "<<faces<<" 0"<<std::endl;

    for(int i = 0; i<nz; i++)
    {
        for(int j = 0; j<ny; j++)
        {
            for(int k = 0; k<nx; k++)
            {
                if(v[i][j][k].show == true)
                {
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<std::endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<std::endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<std::endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<std::endl;
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<std::endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<std::endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<std::endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<std::endl;
                }
            }
        }
    }

    int oito=0;

    for(int i = 0; i<nz; i++)
    {
        for(int j = 0; j<nx; j++)
        {
            for(int k = 0; k<ny; k++)
            {
                if(v[i][j][k].show == true)
                {
                    int vvv=oito*8;
                    arq<<"4 "<<vvv<< " "<< vvv+3<<" "<< vvv+2 <<" "<< vvv+1;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arq<<"4 "<< vvv+4<< " "<< vvv+5<<" "<< vvv+6 <<" "<< vvv+7;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arq<<"4 "<< vvv<< " " << vvv+1<<" "<< vvv+5 <<" "<< vvv+4;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arq<<"4 "<< vvv<< " " << vvv+4<<" "<< vvv+7 <<" "<< vvv+3;
                    arq<<" "<< v[i][j][k].r <<" "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arq<<"4 "<< vvv+3<<" " << vvv+7<<" "<< vvv+6 <<" "<< vvv+2;
                    arq<<" "<< v[i][j][k].r << " "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arq<<"4 "<< vvv+1 <<" "<< vvv +2<<" "<< vvv+6 <<" "<< vvv+5;
                    arq<<" "<<v[i][j][k].r << " "<< v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    oito++;
                }
                }
            }
        }
    arq.close();
}