# Jogo da Sorte (C++)

Jogo de adivinhação de número em C++, com sistema de dificuldade, vidas, pontos, moedas e recorde de tentativas.

## Funcionalidades

- 3 níveis de dificuldade (Fácil, Médio, Difícil), cada um com faixa de números, vidas e pontuação diferentes
- Sistema de dicas "quente/frio" baseado na distância até o número sorteado
- Sistema de moedas: ganhas ao acertar, usadas para comprar dicas (se o número é par ou ímpar)
- Bônus de pontuação por acertar rápido (1ª tentativa, até 3 tentativas, etc.)
- Recorde de menor número de tentativas salvo durante a sessão
- Histórico de palpites já feitos
- Opção de jogar novamente ao final da partida

## Tecnologias utilizadas

- C++
- Bibliotecas: `iostream`, `string`, `cstdlib`, `ctime`

## Como compilar e rodar

```bash
g++ sorte.cpp -o sorte
./sorte
```

## Autor

Desenvolvido por Luiz Miguel.
