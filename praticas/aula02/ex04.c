#include <stdio.h>

#define PI 3.14159

const double GRAVIDADE = 9.8;

int main() {

    float raio = 2.0;
    float area = PI * raio * raio;

    printf("Area do circulo: %.2f\n", area);

    // #define e const criam constantes de formas diferentes.

    return 0;
}
