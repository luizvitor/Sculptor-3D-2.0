#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

//estrutura para os blocos.
/**
 * @brief The Voxel struct
 */
struct Voxel{
    float red,green,blue; //Cores.
    float alpha;    //Transparência.
    bool isOn; //incluir ou não.
};
//classe para moldar.
/**
 * @brief The Sculptor class
 */
class Sculptor{
protected:
    Voxel ***v;//Matriz 3D.
    int nl,nc,np;//Dimensões.
    float r,g,b,a;//Cores.
public:
    //Alocação da Matriz 3D.
    /**
     * @brief Sculptor
     */
    Sculptor(int _nx=0,int _ny=0,int _nz=0);
    //Liberar a memória utilizada.
    ~Sculptor();
    //Atribuir as cores.
    /**
     * @brief setColor
     */
    void setColor(float _r,float _g,float _b,float alpha);
    //Criar um Voxel.
    /**
     * @brief putVoxel
     */
    void putVoxel(int x,int y,int z);
    //Cortar um Voxel.
    /**
     * @brief cutVoxel
     */
    void cutVoxel(int x,int y,int z);
    //Criar arquivo para leitura do desenho, contendo as dimensões e as cores.
    /**
     * @brief writeOFF
     */
    void writeOFF(string filename);
    //Criar arquivo para armazenar quantidades de poligonos,vertices e posições.
    /**
     * @brief writeVECT
     */
    void writeVECT(string filename);
};

#endif // SCULPTOR_H
