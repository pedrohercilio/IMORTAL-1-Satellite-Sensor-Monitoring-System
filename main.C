#include <stdio.h>

// Função que calcula a média das 3 leituras
double calcular_media(double a, double b, double c){
    return (a+b+c) / 3;
}

// Função que encontra valor máximo
double encontrar_maximo(double a, double b, double c){
    if ((a >= b) && (a >= c)) return a;
    else if ((b >= a) && (b >= c)) return b;
    else return c;
}

// Função que encontra valor mínimo
double encontrar_minimo(double a, double b, double c){
    if ((a <= b) && (a <= c)) return a;
    else if ((b <= a) && (b <= c)) return b;
    else return c;
}

// Procedimento que calcula desvios em relação à média
void desvios(double a, double b, double c){
    double media = calcular_media(a, b, c);
    printf("\033[36m\nDesvio do valor 1 =\033[0m %.2lf", a - media);
    printf("\n\033[36mDesvio do valor 2 =\033[0m %.2lf", b - media);
    printf("\n\033[36mDesvio do valor 3 =\033[0m %.2lf\n", c - media);
}

// Procedimento que verifica se valores estão dentro da faixa
void verif_faixa(double a, double b, double c, double min, double max){
            if (a > max) printf("\n\033[31mLeitura 1: ACIMA DO LIMITE\033[0m"); else if (a < min) printf("\n\033[33mLeitura 1: ABAIXO DO LIMITE\033[0m"); else printf("\n\033[32mLeitura 1: OK\033[0m");
            if (b > max) printf("\n\033[31mLeitura 2: ACIMA DO LIMITE\033[0m"); else if (b < min) printf("\n\033[33mLeitura 2: ABAIXO DO LIMITE\033[0m"); else printf("\n\033[32mLeitura 2: OK\033[0m");
            if (c > max) printf("\n\033[31mLeitura 3: ACIMA DO LIMITE\033[0m"); else if (c < min) printf("\n\033[33mLeitura 3: ABAIXO DO LIMITE\033[0m"); else printf("\n\033[32mLeitura 3: OK\033[0m");
            printf("\n");
}

// Procedimento que exibe barra gráfica com limite de 20
void exibir_barra_grafica(double media){
    if (media > 20) media = 20;
    if (media < 0) media = 0;
    for (int i = 0; i < (int)media; i++){
            printf("\033[33m*\033[0m");
    }
} 

// Procedimento que exibe o relatório completo
void exibir_relatorio_completo(double a, double b, double c, double min, double max){
    double media = calcular_media(a, b, c);
    printf("\n\033[35m====Relatório====\033[0m");
    printf("\n\033[36mMédia =\033[0m %.2lf", media);
    printf("\n\033[36mValor máximo =\033[0m %.2lf", encontrar_maximo(a, b, c));
    printf("\n\033[36mValor mínimo =\033[0m %.2lf", encontrar_minimo(a, b, c));
    desvios(a, b, c);
    verif_faixa(a, b, c, min, max);
    printf("\n\033[36mIntensidade média: \033[0m%.2lf\n", media);
    printf("\033[31m[\033[0m"); exibir_barra_grafica(media); printf("\033[32m]\033[0m\n");
}



// Função principal do código
int main() {

    // Declaração de variáveis
    double v1, v2, v3;
    char opcao2, opcao3;
    double min, max;

    // Primeiro looping (Recebe valores, repete enquanto o usuário optar por realizar outra simulação)
    while(1){
        printf("\n\033[36mDigite a primeira leitura: \033[0m");
        scanf("%lf", &v1);
        printf("\n\033[36mDigite a segunda leitura: \033[0m");
        scanf("%lf", &v2);
        printf("\n\033[36mDigite a terceira leitura: \033[0m");
        scanf("%lf", &v3);

        // Controle de não repetição de valores
        int faixa_definida = 0;

        // Segundo looping (Printa o menu principal sempre que o usuário optar por realizar outra operação)
        while(1){
            printf("\033[34m\n======= MENU =======\033[0m\n");
            printf("1. Calcular a média\n");
            printf("2. Encontrar o valor mínimo e máximo\n");
            printf("3. Desvios\n");
            printf("4. Verificação de faixa\n");
            printf("5. Barra gráfica\n");
            printf("6. Relatório\n");
            printf("\033[31m0. Sair\033[0m\n");

            // Salva a escolha do usuário em uma variável
            printf("\n\033[36mEscolha uma opção: \033[0m");
            int opcao;
            scanf("%d", &opcao);

            // Se a escolha do usuário for igual a zero o segundo looping (menu) acaba
            if (opcao == 0){
                break;
            }

            // A partir da variável 'opcao' (escolha do usuário) o código executa
            switch (opcao){

            // Variável é igual a 1, mostra na tela a média das leituras que o usuário digitou anteriormente
            case 1:
                printf("\n\033[36mMédia =\033[0m %.2lf\n", calcular_media(v1, v2, v3));
                break;
            
            // Variável é igual a 2, mostra na tela a maior e menor leitura que o usuário digitou anteriormente
            case 2:
                printf("\n\033[36mValor máximo =\033[0m %.2lf", encontrar_maximo(v1, v2, v3));
                printf("\n\033[36mValor mínimo =\033[0m %.2lf\n", encontrar_minimo(v1, v2, v3));
                break;

            // Variável é igual a 3, mostra na tela os desvios de cada leitura em relação a média
            case 3:
                desvios(v1, v2, v3);
                break;

            // Variável é igual a 4, mostra na tela a verificação de faixa (se as leituras estão ou não nos limites estabelecidos)
            case 4:
                // Defini os limites da faixa (máximo e mínimo)
                while(1){
                    printf("\n\033[36mDigite o valor mínimo: \033[0m"); scanf("%lf", &min);
                    printf("\n\033[36mDigite o valor máximo: \033[0m"); scanf("%lf", &max);
                    if (max > min){        
                        verif_faixa(v1, v2, v3, min, max);

                        // Defini como positivo, permitindo que o case 6 seja acessado
                        faixa_definida = 1;
                        printf("\033[32mFaixa definida com sucesso!\033[0m\n");
                        break;
                    }
                    else { printf("\n\033[31mO valor máximo tem que ser maior que o mínimo.\033[0m\n"); }
                }
                break;

            // Variável é igual a 5, mostra na tela a média e a barra gráfica da intensidade
            case 5:{
                double media = calcular_media(v1, v2, v3);
                printf("\n\033[36mIntensidade média: \033[0m%.2lf\n", media);
                printf("\033[31m[\033[0m"); exibir_barra_grafica(media); printf("\033[32m]\033[0m\n");
                break;
            }

            // Variável é igual a 6, caso os limites tenham sido definidos no case 4, será exibido o relatório completo (todas as informações juntas)
            case 6:
                    if (faixa_definida) exibir_relatorio_completo(v1, v2, v3, min, max);
                    else printf("\033[33m\nDefina primeiro os valores de mínimo e máximo (opção 4).\n\033[0m");
                    break;

            // É acessado caso a variável não seja igual a nenhum dos casos
            default:
                printf("\n\033[31mDigite um valor válido\033[0m\n");
                break;
            }

            // Recebe se o usuário deseja realizar outra operação com os mesmos valores e quebra o looping do menu caso não queira
            while(1){
                printf("\n\033[36mDeseja realizar outra operação? (s/n): \033[0m");
                scanf(" %c", &opcao2);
                
                if ((opcao2 == 's') || (opcao2 == 'S')){
                    continue;
                }
                else if ((opcao2 == 'n') || (opcao2 == 'N')){
                break;
                }
                else printf("\n\033[31mDigite uma opção válida\033[0m\n");
            }
        }
        fim_menu:
        printf("\n\033[34mFim da Simulação\033[0m\n");

        // Recebe se o usuário deseja realizar outra simulação com novos valores e encerra o programa caso não queira
        
        while(1){
            printf("\n\033[36mDeseja realizar outra simulação? (s/n): \033[0m");
            scanf(" %c", &opcao3);
            
            if ((opcao3 == 's') || (opcao3 == 'S')){
                continue;
            }
            else if ((opcao3 == 'n') || (opcao3 == 'N')){
                printf("\n\033[34mEncerrando sistema...\033[0m");
                break;
            }
            else printf("\n\n\033[31mDigite uma opção válida\033[0m\n");
    }

    return 0;
}