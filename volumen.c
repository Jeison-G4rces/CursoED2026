#include "volumen.h"

float volumenEsfera(float rad) {
    float pi = 3.1416;
    return 4/3 * pi * (rad * rad * rad);
}
int volumenCubo(int lado) {
    return lado * lado * lado;
}