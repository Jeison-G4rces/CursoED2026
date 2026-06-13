#include <stdio.h>
#include "areas.h"
#include "volumen.h"

int main() {
    int a; 
    int lado;
    float r;
    float rad;
    printf("ingrese la medida de un lado del cuadrado: ");
    scanf("%d", &a);

    printf("ingrese el radio del circulo: ");
    scanf("%f", &r);
    
    printf("ingrese el radio de la esfera: ");
    scanf("%f", &rad);
    
    printf("ingrese la medida de un lado del cubo: ");
    scanf("%d", &lado);

    printf("El area del cuadrado es = %d\n", AreaCuadrado(a));
    printf("El area del circulo es = %f\n", AreaCirculo(r));
    printf("El volumen de la esfera es = %f\n", volumenEsfera(rad));
    printf("El volumen del cubo es = %d\n", volumenCubo(lado));
    return 0;

}
