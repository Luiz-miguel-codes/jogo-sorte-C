#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    string nome;
    string historico;

    int dificuldade;
    int numero;
    int palpite;

    int tentativas;
    int maxTentativas;
    int vidas;
    int pontos;
    int moedas;

    int recorde = 9999;

    char jogarNovamente = 's';
    char comprarDica;

    cout << "=================================" << endl;
    cout << "        JOGO DA SORTE" << endl;
    cout << "=================================" << endl;

    cout << "\nDigite seu nome: ";
    cin >> nome;

    moedas = 0;

    while (jogarNovamente == 's' || jogarNovamente == 'S')
    {
        tentativas = 0;
        historico = "";

        cout << "\n=================================" << endl;
        cout << "Escolha a dificuldade:" << endl;
        cout << "1 - Facil" << endl;
        cout << "2 - Medio" << endl;
        cout << "3 - Dificil" << endl;
        cout << "Escolha: ";
        cin >> dificuldade;

        if (dificuldade == 1)
        {
            numero = rand() % 100 + 1;

            maxTentativas = 10;
            vidas = 5;
            pontos = 100;

            cout << "\nVoce escolheu FACIL!" << endl;
            cout << "O numero esta entre 1 e 100." << endl;
        }
        else if (dificuldade == 2)
        {
            numero = rand() % 500 + 1;

            maxTentativas = 8;
            vidas = 4;
            pontos = 150;

            cout << "\nVoce escolheu MEDIO!" << endl;
            cout << "O numero esta entre 1 e 500." << endl;
        }
        else if (dificuldade == 3)
        {
            numero = rand() % 1000 + 1;

            maxTentativas = 6;
            vidas = 3;
            pontos = 200;

            cout << "\nVoce escolheu DIFICIL!" << endl;
            cout << "O numero esta entre 1 e 1000." << endl;
        }
        else
        {
            cout << "\nDificuldade invalida!" << endl;
            continue;
        }

        while (tentativas < maxTentativas &&
               vidas > 0)
        {
            cout << "\n---------------------------------" << endl;

            cout << "Tentativas: "
                 << tentativas
                 << "/"
                 << maxTentativas << endl;

            cout << "Vidas: "
                 << vidas << endl;

            cout << "Pontos: "
                 << pontos << endl;

            cout << "Moedas: "
                 << moedas << endl;

            cout << "Historico: ";

            if (historico == "")
            {
                cout << "Nenhum";
            }
            else
            {
                cout << historico;
            }

            cout << endl;

            cout << "\nDigite seu palpite: ";
            cin >> palpite;

            tentativas++;

            historico += to_string(palpite);
            historico += " ";

            if (palpite == numero)
            {
                cout << "\n=================================" << endl;
                cout << "          PARABENS!" << endl;
                cout << "       VOCE ACERTOU!" << endl;
                cout << "=================================" << endl;

                cout << "\nNumero: "
                     << numero << endl;

                cout << "Tentativas: "
                     << tentativas << endl;

                if (tentativas == 1)
                {
                    pontos += 100;
                    moedas += 20;

                    cout << "\nBONUS DE PRIMEIRA TENTATIVA!" << endl;
                }
                else if (tentativas <= 3)
                {
                    pontos += 50;
                    moedas += 10;
                }
                else
                {
                    pontos += 20;
                    moedas += 5;
                }

                cout << "Pontuacao final: "
                     << pontos << endl;

                cout << "Moedas ganhas!" << endl;

                if (tentativas < recorde)
                {
                    recorde = tentativas;

                    cout << "\nNOVO RECORDE!" << endl;
                }

                break;
            }

            if (palpite > numero)
            {
                cout << "\nO numero sorteado e MENOR!" << endl;
            }
            else
            {
                cout << "\nO numero sorteado e MAIOR!" << endl;
            }

            int distancia;

            if (palpite > numero)
            {
                distancia = palpite - numero;
            }
            else
            {
                distancia = numero - palpite;
            }

            if (distancia <= 10)
            {
                cout << "Muito quente!" << endl;
            }
            else if (distancia <= 50)
            {
                cout << "Quente!" << endl;
            }
            else
            {
                cout << "Frio!" << endl;
            }

            vidas--;

            if (pontos >= 10)
            {
                pontos -= 10;
            }

            cout << "Voce perdeu uma vida!" << endl;

            // LOJA DE DICAS

            if (moedas >= 5)
            {
                cout << "\nDeseja comprar uma dica por 5 moedas? (s/n): ";
                cin >> comprarDica;

                if (comprarDica == 's' || comprarDica == 'S')
                {
                    moedas -= 5;

                    if (numero % 2 == 0)
                    {
                        cout << "DICA: o numero e PAR!" << endl;
                    }
                    else
                    {
                        cout << "DICA: o numero e IMPAR!" << endl;
                    }
                }
            }
        }

        if (palpite != numero)
        {
            cout << "\n=================================" << endl;
            cout << "          VOCE PERDEU!" << endl;
            cout << "=================================" << endl;

            cout << "\nO numero era: "
                 << numero << endl;

            cout << "Tentativas: "
                 << tentativas << endl;

            cout << "Pontos: "
                 << pontos << endl;
        }

        cout << "\n=================================" << endl;
        cout << "             RECORDES" << endl;
        cout << "=================================" << endl;

        if (recorde == 9999)
        {
            cout << "Nenhum recorde ainda." << endl;
        }
        else
        {
            cout << "Menor numero de tentativas: "
                 << recorde << endl;
        }

        cout << "\nDeseja jogar novamente? (s/n): ";
        cin >> jogarNovamente;
    }

    cout << "\n=================================" << endl;
    cout << "          FIM DE JOGO!" << endl;
    cout << "=================================" << endl;

    cout << "Obrigado por jogar, "
         << nome << "!" << endl;

    return 0;
}
