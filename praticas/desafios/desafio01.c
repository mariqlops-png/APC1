#include <stdio.h>

int main() {
    int x = 5/2;
    int y = x++;   // qual o valor de y? e de x depois?
    int z = x%2;   // qual o valor de z agora? e de x?

    printf("valor de x: %d\n",x);
    printf("valor de y: %d\n",y);
    printf("valor de z: %d\n",z);


    return 0;
}