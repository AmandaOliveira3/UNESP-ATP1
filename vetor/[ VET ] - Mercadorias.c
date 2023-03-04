
#include <stdio.h>

int main(void)
{
    int vet_produto[10],vet_total[10], i,a;
    int codigocliente, codigoprodutocompra,quantidade, achou = 0, pos;

    for (a = 0; a < 10; a++)
	{
        scanf("%d %d", &vet_produto[a], &vet_total[a]);
    }

    for (;;){
        scanf("%d", &codigocliente);

        if (codigocliente == 0)
		{
            break;
   	 }
        scanf("%d %d", &codigoprodutocompra, &quantidade);
        achou = 0;

        for (i = 0; i < 10; i++){
            if (codigoprodutocompra == vet_produto[i]){
                achou = 1;
                pos = i;
            }
        }
        if (achou!= 1)        {
            printf("Codigo inexistente\n");
        }
        else        {
            if (vet_total[pos] >= quantidade)            {
                vet_total[pos] -= quantidade;
                printf("Pedido atendido. Obrigado e volte sempre\n");
            }
            else            {
                printf("Sem estoque suficiente para esta compra\n");
            }
        }
    }
    for (a = 0; a < 10; a++)    {
        printf("%d: %d\n", vet_produto[a],vet_total[a]);
    }
    
}

