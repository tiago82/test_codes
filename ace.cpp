#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

const float MAX_RPM = 8000.0f; // RPM máximo do motor
const float MAX_VELOCIDADE = 200.0f; // velocidade máxima do veículo
const float ACELERACAO_MAXIMA = 20.0f; // aceleração máxima do veículo
const float ACELERACAO_MINIMA = 1.0f; // aceleração mínima do veículo
const float ACELERACAO_RPM_MIN = 2000.0f; // RPM mínimo para alcançar a aceleração mínima
const float ACELERACAO_RPM_MAX = 7000.0f; // RPM máximo para alcançar a aceleração máxima




float rpm = 0.0f; // RPM inicial do motor
float velocidade = 0.0f; // velocidade inicial do veículo
float aceleracao = 0.0f; // aceleração inicial do veículo
float tempo = 0.0f; // tempo inicial
float dt = 0.01f; // intervalo de tempo
float forca = 0.0f;

bool acelerando = false;
bool emMovimento = false;

// prototipo
void acelerador (float range);
void freio (float range);
void inercia();
void checkcontrol();
bool checkmove();




int main(){

    while(true){

    cout << "Velocidade: " <<  velocidade << " m/s"<<endl;
    
    checkcontrol();
    
    





}

return 0;
}


bool checkmove(){
    if(velocidade > 0 ){
        return true;
    } 
    else{
        return false;
    }

}



void checkcontrol(){
       // verifica tecla pressionada
    if(GetKeyState(VK_SHIFT) & 0x8000) 
    {
        // Shift down
        //acelerando = true;
        acelerador (30.0f);
    
    }
    if(GetKeyState(VK_RCONTROL) & 0x8000) 
    {
        // Ctrl down
        freio(-30.0f);
    
    }
    if(GetKeyState(VK_LCONTROL) & 0x8000) 
    {
        // Ctrl down
        reduzirVelocidade();
    
    }
    else{
        inercia();
    }
    
}



void acelerador (float range){

    if (velocidade <= MAX_VELOCIDADE){
        velocidade += range*dt;
    }
    // impede que velocidade seja menor que zero
    if (velocidade > MAX_VELOCIDADE){
        velocidade = MAX_VELOCIDADE;
    }
    
}

void freio (float range){

    if (velocidade >= 0){
        velocidade -= range*dt;
    }
    // impede que velocidade seja menor que zero
    if (velocidade < 0){
        velocidade = 0;
    }
    

}
//
void inercia( ){
    if(checkmove() == true){
    cout << "corno " <<endl;
        velocidade -= 0.05f;
    }
} 