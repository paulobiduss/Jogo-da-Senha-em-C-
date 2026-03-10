#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void embaralhar(int *array, int n);

int main() {
    int valores[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int algarismos[5];
    int tamanho = 5;
    int seus_valor[5];
    int tentativas = 0;
    int acertos_perfeitos = 0;

    srand(time(0));
    embaralhar(valores, 11);

    for (int i = 0; i < tamanho; i++) {
        algarismos[i] = valores[i];
    }

    while (acertos_perfeitos != 5) {
        
        acertos_perfeitos = 0;
        tentativas++;
        
        cout << "\n--- TENTATIVA " << tentativas << " ---";
        cout << "\nDigite seus 5 valores (Aperte ENTER para cada um):\n";
        
        for (int i = 0; i < tamanho; i++) {
            cin >> seus_valor[i];
        }

        bool monitoramento[5] = {false, false, false, false, false};

        string relatorio_visual[5];

        for (int i = 0; i < tamanho; i++) {
            if (algarismos[i] == seus_valor[i]) {
                relatorio_visual[i] = "Certo";
                acertos_perfeitos++;
                monitoramento[i] = true;
            }
        }
        for (int i = 0; i < tamanho; i++) {
            if (algarismos[i] != seus_valor[i]) {
                
                bool posicao = false;
                for (int j = 0; j < tamanho; j++) {
                    if (seus_valor[i] == algarismos[j] && monitoramento[j] == false) {
                        posicao = true;
                        monitoramento[j] = true; 
                        break;
                    }
                }
                if (posicao == true) {
                    relatorio_visual[i] = "Posicao Errada";
                } else {
                    relatorio_visual[i] = "Nao Contem";
                }
            }
        }
        
        cout << "\n--- Resultado ---\n";
        for (int i = 0; i < tamanho; i++) {
            cout << seus_valor[i] << " -> " << relatorio_visual[i] << "\n";
        }
        
        cout << "\n";
    }
    printf("\nParabens! Voce descobriu a senha em %d tentativas!\n", tentativas);
    return 0;
}

void embaralhar(int *array, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[i]; 
            array[i] = array[j]; 
            array[j] = t;
        }
    }

}
