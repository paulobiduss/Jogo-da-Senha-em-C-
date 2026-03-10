# 🔐 Jogo da Senha (Mastermind) em C++

Este é um projeto de terminal desenvolvido em **C++** que recria o clássico jogo de tabuleiro Mastermind (conhecido no Brasil como Jogo da Senha). O foco deste projeto é a aplicação prática de **dedução lógica, algoritmos de busca e manipulação de arrays**.

---

## 🎮 Como Jogar

O computador atua como o "Mestre do Jogo" e gera uma **senha secreta de 5 números diferentes** (escolhidos de 1 a 10). O seu objetivo é adivinhar quais são esses números e em quais posições eles estão, no menor número de tentativas possível.

A cada palpite de 5 números, o **Robô Inspetor** do jogo retornará um feedback preciso para cada posição:
* 🟢 **Certo:** O número existe na senha e está na cadeira exata.
* 🟡 **Posição Errada:** O número existe na senha secreta, mas está sentado na cadeira incorreta.
* 🔴 **Não Contém:** O número não faz parte da senha secreta.

---

## 🧠 Destaques da Lógica e Arquitetura

Este sistema foi construído contornando desafios clássicos de programação lógica:

### 1. A Fábrica de Senhas (Sem Repetições)
Para garantir a regra de ouro do jogo (5 algarismos **diferentes**), o sistema não faz sorteios independentes. Foi implementada a lógica do **Globo de Bingo**:
* Um vetor com o universo completo (1 a 10) é preenchido.
* Um algoritmo matemático de embaralhamento sem "viés de módulo" mistura todo o vetor.
* O sistema então extrai apenas os 5 primeiros índices, garantindo uma senha criptograficamente justa e sem repetições.

### 2. O Inspetor de Duas Fases (Prevenção de Falsos Positivos)
Para lidar com jogadores que tentam burlar o sistema digitando o mesmo número várias vezes (ex: `1, 1, 1, 1, 1`), o código não usa uma verificação linear simples. Ele utiliza uma **Prancheta de Monitoramento** baseada na "Regra do Ingresso Único":
* **Fase 1 (Tiro Certeiro):** Varre o palpite procurando apenas acertos exatos. Se achar, marca aquele número da senha como "ingresso rasgado".
* **Fase 2 (O Radar):** Varre os números restantes buscando posições erradas. Ele cruza o valor digitado com o status do ingresso na senha. Isso impede que um único número na senha gere múltiplos avisos de "Posição Errada" no terminal.

---

## 🚀 Como Executar o Projeto

1. Certifique-se de ter um compilador C++ instalado (como o GCC/MinGW).
2. Clone este repositório para a sua máquina local.
3. Abra o terminal na pasta do projeto e compile o código:
   `g++ nome_do_arquivo.cpp -o jogo_da_senha`
4. Execute o jogo no terminal:
   `./jogo_da_senha` (No Linux/Mac) ou `jogo_da_senha.exe` (No Windows).
