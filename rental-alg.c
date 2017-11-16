#include<stdio.h>
struct carro {
    int *id;
    char *disponivel;
};

// interface grafica
void interface(char msg[15]){
    printf("\n---------------------------\n");
    printf("%s\n", msg);
    printf("---------------------------\n\n");
}

void main(){

    // carros disponiveis
    struct carro celta;
        celta.id = 1;
        celta.disponivel = 'y';

    struct carro gol;
        gol.id = 2;
        gol.disponivel = 'y';

    struct carro palio;
        palio.id = 3;
        palio.disponivel = 'y';

        // escolhendo o carro

        int idCarro;
        float valorCarro;

        interface("Sistema de Locação Veicular");

        printf("Olá! Qual carro você gostaria de escolher? \n");
        printf("1. Celta - R$50,00/d\n");
        printf("2. Gol - R$70,00/d\n");
        printf("3. Palio - R$90,00/d\n");
        scanf("\n%d", &idCarro);

            // selecionando o carro
            switch(idCarro){
                case 1: printf("\nVocê escolheu o celta! A diária dele é de R$50,00\n");
                celta.disponivel = 'n';
                valorCarro = 50;
                break;
                case 2: printf("\nVocê escolheu o gol! A diária dele é de R$70,00\n");
                gol.disponivel = 'n';
                valorCarro = 70;
                break;
                case 3: printf("\nVocê escolheu o palio! A diária dele é de R$90,00\n");
                palio.disponivel = 'n';
                valorCarro = 90;
                break;
            }

                // selecionando as diárias

                int diarias, idadeLocador;
                float subtotal, descontoOng, descontoIdoso;
                int ong;

                interface("Escolhendo diarias");

                printf("\nVocê pretende alugar o carro por quantos dias? \t\n");
                scanf("%d", &diarias);

                subtotal = diarias * valorCarro;

                    printf("\nO subtotal da sua requisição foi de R$%.2f.\n", subtotal);

                    interface("Conhecendo melhor o cliente");

                    // verificador de condicoes para concessão de desconto
                    // se membro de ong parceira
                    printf("\nVocê é membro ou parceiro da ONG? 1.sim 2.nao \n");
                    scanf("%d", &ong);

                        if (ong == 1) {
                            descontoOng = subtotal - ((subtotal*5)/100);
                            printf("\nVocê conseguiu um desconto por isso e o valor final fica em: R$%.2f\n", descontoOng);
                        } else if (ong == 2) {
                            descontoOng = subtotal;
                            printf("\nO valor final fica em: R$%.2f\n", descontoOng);
                        } else {
                            printf("\nResposta inválida. Tente novamente!");
                        }

                        //se idoso
                        printf("\nQual a sua idade? \n");
                        scanf("%d", &idadeLocador);

                            interface("Dados do Pedido");

                            // o software assume que o locador se torna idoso a partir dos 65 anos
                            if (idadeLocador > 65) {
                                descontoIdoso = descontoOng - ((descontoOng*10)/100);
                                printf("\nPor ser idoso você conseguiu um desconto \nde 10 por cento e o valor final ficou em R$%.2f\n\n", descontoIdoso);
                            } else {
                                descontoIdoso = descontoOng;
                                printf("\nO valor final fica em: R$%.2f\n\n", descontoIdoso);
                            }


}
