#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
    setlocale(LC_ALL,"portuguese");
    int num=3, errado=0, certo=0, tentativas=0, l, c, resposta;
    int mat[num][num], v[num];

    srand(time(NULL));

    for(l=0; l<num; l++) {
        for(c=0;  c<num; c++) {
            mat[l][c] = rand()%20+1;

            if(l==c)
                v[l]=mat[l][c];
        }
    }
    
    //ISSO � COLA***

//    for(l=0; l<num; l++) {
//        for(c=0; c<num; c++) {
//            printf(" %.2d|", mat[l][c]);
//        }
//        printf("\n");
//    }

    for(l=0; l<num; l++){
        Repete:
        printf("\n Adivinhe o n�mero (entre 1 e 20): ");
        scanf("%d", &resposta);

        if (resposta == v[l]) {
            printf(" Este � o n�mero correto: %d\n", resposta);
            certo++;
        }
        else if (resposta < 0) {
            printf(" Tente um n�mero positivo!\n");
            errado++;
            goto Repete;
        }
        else if (resposta > v[l]) {
            printf("Errado! Tente um n�mero menor.\n");
            errado++;
            goto Repete;
        }
        else if (resposta < v[l]) {
            printf(" Errado! Tente um n�mero maior.\n");
            errado++;
            goto Repete;
        }
        else {
            printf("N�mero incorreto. Tente outro n�mero.\n");
            errado++;
            goto Repete;
        }
        tentativas = errado + certo;
    }
    printf("\n\n-->|Parab�ns! Voc� acertou todos os n�meros depois de um total de %d tentativas. (%d erros e %d acertos)", tentativas, errado, certo);
}
