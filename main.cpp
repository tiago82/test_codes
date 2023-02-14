#include <iostream>
#include <cmath>

using namespace std;

const float MAX_RPM = 8000.0f; // RPM máximo do motor
const float MAX_VELOCIDADE = 200.0f; // velocidade máxima do veículo
const float ACELERACAO_MAXIMA = 20.0f; // aceleração máxima do veículo
const float ACELERACAO_MINIMA = 1.0f; // aceleração mínima do veículo
const float ACELERACAO_RPM_MIN = 2000.0f; // RPM mínimo para alcançar a aceleração mínima
const float ACELERACAO_RPM_MAX = 7000.0f; // RPM máximo para alcançar a aceleração máxima

float calcular_aceleracao(float rpm) {
    // Calcula a aceleração com base no RPM do motor
    float fator = (rpm - ACELERACAO_RPM_MIN) / (ACELERACAO_RPM_MAX - ACELERACAO_RPM_MIN);
    return ACELERACAO_MINIMA + fator * (ACELERACAO_MAXIMA - ACELERACAO_MINIMA);
}

int main() {
    float rpm = 0.0f; // RPM inicial do motor
    float velocidade = 0.0f; // velocidade inicial do veículo
    float aceleracao = 0.0f; // aceleração inicial do veículo
    float tempo = 0.0f; // tempo inicial
    float dt = 0.01f; // intervalo de tempo
    float forca = 0.0f;
    
    while (true) {
        
        if (velocidade < MAX_VELOCIDADE) {
            aceleracao = calcular_aceleracao(rpm);
            forca = aceleracao * 500.0f; // ajuste da força para obter a aceleração desejada
        }
        float aceleracao_resultante = forca / 1500.0f; // a aceleração resultante é a força dividida pela massa do veículo
        velocidade += aceleracao_resultante * dt;
        if (velocidade > MAX_VELOCIDADE) {
            velocidade = MAX_VELOCIDADE; // limita a velocidade máxima
        }
        if (velocidade == 0.0f) {
            rpm = 0.0f; // tratamento de caso para velocidade zero
        } else {
            rpm = velocidade / MAX_VELOCIDADE * MAX_RPM; // RPM do motor varia com a velocidade
            if (rpm < 0.0f) {
                rpm = 0.0f; // limita o RPM mínimo para zero
            }
        }
        cout << "Velocidade: " << velocidade << " m/s" << endl;
        cout << "RPM: " << rpm << endl;
        tempo += dt;
}

return 0;
}


