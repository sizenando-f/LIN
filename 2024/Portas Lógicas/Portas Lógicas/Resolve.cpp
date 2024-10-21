#include "Resolve.h"

using namespace std;

void Resolve::insere(Base* componente)
{
	componentes.push_back(componente->alocar());	// Aloca o componente no vetor 
}

void Resolve::resolveTotal()
{
	for (const auto& componente : componentes) {
		vector<string> entradasIndices = componente->retornaEntradas(); // Recebe as entradas a quais os componentes est�o conectados
		vector<string> saidasIndices = componente->retornaSaidas();	// Recebe as sa�das a quais os componentes est�o conectados
		vector<int> entradas;

		for (const auto& indices : entradasIndices) {
			if (indices != "") {	// Se houver �ndices de entrada
				if (indices[0] == 'e') {	// Se estiver conectado no vetor de entradas
					entradas.push_back(entrada[indices[1] - '0']); // Pega o que est� no vetor de entradas a partir do �ndice convertido para inteiro
				}
				else {
					entradas.push_back(campo[indices[0] - '0'][7 - (indices[1] - '0')]); // Pega o que est� na matriz a partir dos �ndices convertido para inteiro
				}
			}
		}

		vector<bool> resultados = componente->calcula(entradas);	// Armazena os resultados do componente num vetor pra caso tenha mais de uma sa�da

		int i = 0;
		for (const auto& indices : saidasIndices) {
			if (indices != "") {	// Se houver �ndices de sa�da
				if (indices[0] == 's') {	// Se estiver conectado no vetor de sa�da
					saida[indices[1] - '0'] = resultados[i];	// Insere o resultado no vetor de sa�da
				}
				else {
					campo[indices[0] - '0'][7 - (indices[1] - '0')] = resultados[i];	// Insere o resultado no �ndice convertido para inteiro
				}
				i++;	// Incrementa para ir para pr�ximo resultado caso exista
			}
		}
		
	}
}

Resolve::~Resolve()
{
	for (const auto& componente : componentes) {
		delete componente;	// Desaloca cada componente 
	}
}
