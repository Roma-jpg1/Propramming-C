#include "func.h"

void plus(struct drobi drobi1, struct drobi drobi2 ){
    struct drobi pl= {drobi1.a*drobi2.b+drobi2.a*drobi1.b, drobi1.b*drobi2.b};
    printf("сложение дробей: %d/%d \n",pl.a,pl.b);
}

void minus(struct drobi drobi1, struct drobi drobi2 ){
    struct drobi mi= {drobi1.a*drobi2.b-drobi2.a*drobi1.b, drobi1.b*drobi2.b};
    printf("вычитание дробей %d/%d \n",mi.a,mi.b);
}