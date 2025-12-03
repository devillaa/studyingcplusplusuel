#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

// PROTÓTIPOS DE FUNÇÕES
void menu();
int lerNumero();
double lerNumeroDecimal();
bool validarEntrada();
void limparBuffer();
void pausar();

// Operações da calculadora
void somar();
void subtrair();
void multiplicar();
void dividir();
void verificarParImpar();
void gerarNumeroAleatorio();
void compararValores();
void calcularMedia();


// FUNÇÃO PRINCIPAL
int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(0));
    
    int opcao;
    bool continuar = true;
    
    cout << "========================================" << endl;
    cout << "   CALCULADORA COMPLETA EM C++" << endl;
    cout << "========================================" << endl;
    cout << "\nBem-vindo ao sistema de calculadora!\n" << endl;
    
    // Loop principal do programa
    while (continuar) {
        menu();
        
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        
        // Valida se a entrada é um número válido
        if (cin.fail()) {
            cout << "\n[ERRO] Entrada invalida! Por favor, digite um numero.\n" << endl;
            limparBuffer();
            pausar();
            continue;
        }
        
        // Processa a opção escolhida usando switch
        switch (opcao) {
            case 1:
                somar();
                break;
            case 2:
                subtrair();
                break;
            case 3:
                multiplicar();
                break;
            case 4:
                dividir();
                break;
            case 5:
                verificarParImpar();
                break;
            case 6:
                gerarNumeroAleatorio();
                break;
            case 7:
                compararValores();
                break;
            case 8:
                calcularMedia();
                break;
            case 0:
                cout << "\nObrigado por usar a Calculadora! Ate logo!" << endl;
                continuar = false;
                break;
            default:
                cout << "\n[ERRO] Opcao invalida! Escolha um numero entre 0 e 8.\n" << endl;
                pausar();
        }
    }
    
    return 0;
}

// FUNÇÕES DE INTERFACE E UTILITÁRIAS


// Exibe o menu principal com todas as opções disponíveis

void menu() {
    cout << "\n========================================" << endl;
    cout << "            MENU PRINCIPAL" << endl;
    cout << "========================================" << endl;
    cout << "1. Soma" << endl;
    cout << "2. Subtracao" << endl;
    cout << "3. Multiplicacao" << endl;
    cout << "4. Divisao" << endl;
    cout << "5. Verificar Par/Impar" << endl;
    cout << "6. Gerar Numero Aleatorio" << endl;
    cout << "7. Comparar Valores" << endl;
    cout << "8. Calcular Media" << endl;
    cout << "0. Sair" << endl;
    cout << "========================================" << endl;
}

/**
 * Lê um número inteiro do usuário com validação
 * @return Número inteiro válido digitado pelo usuário
 */
int lerNumero() {
    int numero;
    
    while (true) {
        cin >> numero;
        
        if (cin.fail()) {
            cout << "[ERRO] Entrada invalida! Digite um numero inteiro: ";
            limparBuffer();
        } else {
            limparBuffer(); // Limpa qualquer caractere extra
            return numero;
        }
    }
}

/**
 * Lê um número decimal do usuário com validação
 * @return Número decimal válido digitado pelo usuário
 */
double lerNumeroDecimal() {
    double numero;
    
    while (true) {
        cin >> numero;
        
        if (cin.fail()) {
            cout << "[ERRO] Entrada invalida! Digite um numero: ";
            limparBuffer();
        } else {
            limparBuffer();
            return numero;
        }
    }
}

/**
 * Valida se a entrada foi bem-sucedida
 * @return true se a entrada é válida, false caso contrário
 */
bool validarEntrada() {
    if (cin.fail()) {
        return false;
    }
    return true;
}

/**
 * Limpa o buffer de entrada para evitar problemas com entradas inválidas
 */
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Pausa a execução e aguarda o usuário pressionar Enter
 */
void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.get();
}


// FUNÇÕES DE OPERAÇÕES MATEMÁTICAS
/**
 * Realiza a soma de dois números
 * Demonstra uso de operador matemático (+)
 */
void somar() {
    cout << "\n=== OPERACAO: SOMA ===" << endl;
    cout << "Digite o primeiro numero: ";
    double num1 = lerNumeroDecimal();
    
    cout << "Digite o segundo numero: ";
    double num2 = lerNumeroDecimal();
    
    // Operação matemática de soma
    double resultado = num1 + num2;
    
    cout << "\nResultado: " << num1 << " + " << num2 << " = " << resultado << endl;
    pausar();
}

/**
 * Realiza a subtração de dois números
 * Demonstra uso de operador matemático (-)
 */
void subtrair() {
    cout << "\n=== OPERACAO: SUBTRACAO ===" << endl;
    cout << "Digite o primeiro numero: ";
    double num1 = lerNumeroDecimal();
    
    cout << "Digite o segundo numero: ";
    double num2 = lerNumeroDecimal();
    
    // Operação matemática de subtração
    double resultado = num1 - num2;
    
    cout << "\nResultado: " << num1 << " - " << num2 << " = " << resultado << endl;
    pausar();
}

/**
 * Realiza a multiplicação de dois números
 * Demonstra uso de operador matemático (*)
 */
void multiplicar() {
    cout << "\n=== OPERACAO: MULTIPLICACAO ===" << endl;
    cout << "Digite o primeiro numero: ";
    double num1 = lerNumeroDecimal();
    
    cout << "Digite o segundo numero: ";
    double num2 = lerNumeroDecimal();
    
    // Operação matemática de multiplicação
    double resultado = num1 * num2;
    
    cout << "\nResultado: " << num1 << " * " << num2 << " = " << resultado << endl;
    pausar();
}

/**
 * Realiza a divisão de dois números
 * Demonstra uso de operador matemático (/) e condicionais
 */
void dividir() {
    cout << "\n=== OPERACAO: DIVISAO ===" << endl;
    cout << "Digite o primeiro numero (dividendo): ";
    double num1 = lerNumeroDecimal();
    
    cout << "Digite o segundo numero (divisor): ";
    double num2 = lerNumeroDecimal();
    
    // Validação usando condicional para evitar divisão por zero
    if (num2 == 0) {
        cout << "\n[ERRO] Divisao por zero nao e permitida!" << endl;
    } else {
        // Operação matemática de divisão
        double resultado = num1 / num2;
        cout << fixed << setprecision(2);
        cout << "\nResultado: " << num1 << " / " << num2 << " = " << resultado << endl;
    }
    
    pausar();
}

/**
 * Verifica se um número é par ou ímpar
 * Demonstra uso de operador matemático (%) e condicionais
 */
void verificarParImpar() {
    cout << "\n=== VERIFICAR PAR/IMPAR ===" << endl;
    cout << "Digite um numero inteiro: ";
    int numero = lerNumero();
    
    // Usa operador módulo (%) para verificar se é par ou ímpar
    // Se número % 2 == 0, então é par
    if (numero % 2 == 0) {
        cout << "\nO numero " << numero << " e PAR." << endl;
    } else {
        cout << "\nO numero " << numero << " e IMPAR." << endl;
    }
    
    pausar();
}

/**
 * Gera um número aleatório dentro de um intervalo
 * Demonstra uso de funções de aleatoriedade (rand, srand)
 */
void gerarNumeroAleatorio() {
    cout << "\n=== GERAR NUMERO ALEATORIO ===" << endl;
    cout << "Digite o valor minimo: ";
    int minimo = lerNumero();
    
    cout << "Digite o valor maximo: ";
    int maximo = lerNumero();
    
    // Validação usando condicional e operador lógico (&&)
    if (minimo >= maximo) {
        cout << "\n[ERRO] O valor minimo deve ser menor que o maximo!" << endl;
    } else {
        // Gera número aleatório no intervalo [minimo, maximo]
        // Usa operador matemático (%) para limitar o intervalo
        int aleatorio = minimo + (rand() % (maximo - minimo + 1));
        
        cout << "\nNumero aleatorio gerado: " << aleatorio << endl;
        cout << "(Intervalo: " << minimo << " a " << maximo << ")" << endl;
    }
    
    pausar();
}

/**
 * Compara dois valores e mostra qual é maior, menor ou se são iguais
 * Demonstra uso de condicionais e operadores lógicos (&&, ||)
 */
void compararValores() {
    cout << "\n=== COMPARAR VALORES ===" << endl;
    cout << "Digite o primeiro numero: ";
    double num1 = lerNumeroDecimal();
    
    cout << "Digite o segundo numero: ";
    double num2 = lerNumeroDecimal();
    
    // Usa condicionais e operadores lógicos para comparar
    if (num1 > num2) {
        cout << "\n" << num1 << " e MAIOR que " << num2 << endl;
    } else if (num1 < num2) {
        cout << "\n" << num1 << " e MENOR que " << num2 << endl;
    } else {
        // Operador lógico (==) implícito no else
        cout << "\n" << num1 << " e IGUAL a " << num2 << endl;
    }
    
    // Demonstração adicional de operadores lógicos
    if (num1 > 0 && num2 > 0) {
        cout << "Ambos os numeros sao positivos." << endl;
    } else if (num1 < 0 || num2 < 0) {
        cout << "Pelo menos um dos numeros e negativo." << endl;
    }
    
    pausar();
}

/**
 * Calcula a média de uma quantidade de números fornecidos pelo usuário
 * Demonstra uso de loops (for) e operadores matemáticos
 */
void calcularMedia() {
    cout << "\n=== CALCULAR MEDIA ===" << endl;
    cout << "Quantos numeros deseja calcular a media? ";
    int quantidade = lerNumero();
    
    // Validação usando condicional
    if (quantidade <= 0) {
        cout << "\n[ERRO] A quantidade deve ser maior que zero!" << endl;
        pausar();
        return;
    }
    
    double soma = 0;
    double numero;
    
    // Loop for para ler todos os números
    for (int i = 1; i <= quantidade; i++) {
        cout << "Digite o numero " << i << ": ";
        numero = lerNumeroDecimal();
        // Operação matemática de soma acumulativa
        soma = soma + numero; // ou soma += numero
    }
    
    // Operação matemática de divisão para calcular a média
    double media = soma / quantidade;
    
    cout << fixed << setprecision(2);
    cout << "\nSoma dos numeros: " << soma << endl;
    cout << "Quantidade de numeros: " << quantidade << endl;
    cout << "Media calculada: " << media << endl;
    
    pausar();
}