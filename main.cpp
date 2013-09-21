#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

void desenhaZumbi()
{
cout << "                                ....." << endl;
cout << "    Arrrghhhh....              C C  /" << endl;
cout << "                              /<   /" << endl;
cout << "               ___ __________/_#__=o" << endl;
cout << "              /(- /(\\_\\________   \\" << endl;
cout << "              \\ ) \\ )_      \o     \\" << endl;
cout << "              /|\\ /|\\       |'     ||" << endl;
cout << "                             |     _/" << endl;
cout << "                            /o   __\\" << endl;
cout << "                           / '     |" << endl;
cout << "                          / /      |" << endl;
cout << "                         /_/\______|" << endl;
cout << "                        (   _(    <" << endl;
cout << "                         \\    \\    \\" << endl;
cout << "                          \\    \\    |" << endl;
cout << "                           \\____\\____\\" << endl;
cout << "                           ____\\_\\__\\_\\" << endl;
cout << "                         /`   /`     o\\" << endl;
cout << "                         |___ |_______|..." << endl;

}
void escreveMensagem(string mensagem, int demora = 20)
{
    for(int i = 0; i < mensagem.size(); i++)
    {
        cout << mensagem[i];
        Sleep(demora);
    }
}

int main()
{
    int numJogadores, posicaoJogadores[2], vidaJogadores[2], jogadorAtual = 0, dado, ataque;
	int numeroCasas = 30;
    string nomeJogadores[2];
    bool fim, primeiroChegou = false;
    
    srand(time(0));
    setlocale( LC_ALL, "ptb" );

	/*cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\t\t\t\tAtaque dos Zumbis\n\n";
    desenhaZumbi();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    escreveMensagem("\n\n\nTranmissão chegando ...\n\n");
    Sleep(100);
    escreveMensagem("Uma semana atrás o primeiro deles apareceu...\n");
    escreveMensagem("Ninguém sabe vindo de onde...\n");
    escreveMensagem("Outros começaram a surgir em todas as cidades...\n");
    escreveMensagem("Atacando sem piedade, amigos e familiares...\n");
    escreveMensagem("Se você estiver ouvindo esta mensagem não desista!\n");
    escreveMensagem("Estamos reunidos no Cais do Porto...\n");
    escreveMensagem("Sua missão é sobreviver por 30 quadras e chegar até o nosso QG.\n");
    escreveMensagem("Boa sorte!\n");
    escreveMensagem("\n\nFim de tranmissão...\n");
    cout << endl;*/

	cout << "Quantos jogadores vão sobreviver, 1 ou 2 ?" ;
    cin >> numJogadores;

    for(int i = 0; i < numJogadores; i++)
    {
        cout << "Digite o nome do jogador " << i+1 << ": " ;
        cin >> nomeJogadores[i];
        
        vidaJogadores[i] = 5;
        posicaoJogadores[i] = 1;
    }

	// Loop principal do jogo
    do
    {
		system("cls");

		// Percorre a vez de cada jogador
        for(int i = 0 ; i < numJogadores ; i++)  
        {
            if((posicaoJogadores[i] < numeroCasas) && (vidaJogadores[i] > 0))
            {
                cout << endl;
				cout << "**********************************************************************" << endl;
				cout << nomeJogadores[i] << " joga agora." << endl; 
				cout << "**********************************************************************" << endl << endl;
                
				cout << "Você tem " << vidaJogadores[i] << " de vida e está na casa " << posicaoJogadores[i] << " . " << endl; 

                cout << endl;
				cout << "-> Vamos rolar o dado..." << endl;
                cout << endl;

                system("pause");

                // Rolar o dado
                dado = (rand() % 6) + 1;

                cout << endl << "O número sorteado foi: " << dado << "." << endl;
                cout << endl;
        
                // Veio algum zumbi ?
                ataque = rand() % 100;

				if(ataque < 50) 
					ataque = 0;
				else if(ataque < 70) 
					ataque = 1;
				else if(ataque < 90) 
					ataque = 2;
				else 
					ataque = 3;

				//ataque = rand() % 4;
                
                switch(ataque){
                    case 0:
                        cout << "-> Você saiu ileso, nenhum zumbi apareceu." << endl;
						cout << "-> Avance " << dado << " casa(s)." << endl;
                        posicaoJogadores[i] += dado;
                        break;
                    case 1:
                        // recuar uma casa
                        dado -= 1;
                        cout << "Apareceu um zumbi. Após ter matado ele você avançou " << dado << " casa(s)." << endl;
                        posicaoJogadores[i] += dado;
                        break;
                    case 2:
                        cout << "Apareceu um grupo de zumbis. Você perdeu muito tempo matando os zumbis e não avançou nenhuma casa" << endl;
                        break;
                    case 3:
                        cout << "Apareceu uma horda de zumbis. Você saiu ferido e perdeu um ponto de vida." << endl;
                        cout << "Para não morrer você voltou duas casas." << endl;
                        posicaoJogadores[i] -= 2;
                        vidaJogadores[i] -= 1;
                        break;
                }

				// CALCULAR VIDA

                if(vidaJogadores[i] <= 0){
                    vidaJogadores[i] = 0;
                    cout << endl << "-> Você morreu e virou um zumbi! Game over para o jogador " << i+1 << " ." << endl;
                }else{
					cout << "-> Vida: " << vidaJogadores[i] << endl;
				}

				// CALCULAR POSICAO

				if(posicaoJogadores[i] < 0){
					// Não deixa ser menor que 0 as casas
                    posicaoJogadores[i] = 1;
                }
				else if(posicaoJogadores[i] >= numeroCasas){
					// Sobreviveu !!
					if (!primeiroChegou){
						cout << "Parabéns " << nomeJogadores[i] << "." << endl;
						cout << "Você foi o primeiro a chegar sao e salvo ao nosso QG!" <<endl;
						primeiroChegou = true;
					}else{
						cout << endl << "-> Você sobreviveu, tome uma cerveja e comemore \\o/ !!" << endl;
					}
					
				}else{
					// Mostrar posição
					cout << "-> Posição: " << posicaoJogadores[i] << endl;
				}

            } // fim do if
            
        } // fim do for
        
		/*
		*	Caso algum jogador ainda esteja vivo e não chegou na casa 30
		*   Então fim = false
		*   Ex: jogador1, vida 3, casa 14 e jogador2, vida 0, case 27
		*   Vai ser setado no inicio true antes do loop, assim quando chegar a vez do jogador2, é setado novamente pra false
		*   Pra dar continuidade no jogo
		*/
        fim = true; // Termina
        for(int i = 0; i < numJogadores; i++){
            if (vidaJogadores[i] > 0 && posicaoJogadores[i] < numeroCasas){
				// Não termina o jogo
				fim = false;
			}
        }
        
		system("pause");
    }
    while(!fim);

    return 0;

}