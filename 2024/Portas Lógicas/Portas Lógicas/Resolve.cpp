#include "Resolve.h"
#include <iostream>

using namespace std;

Resolve::Resolve()
{
	for (int i = 0; i < 8; ++i) {
		entrada[i] = 0;
		saida[i] = 0;
		for (int j = 0; j < 8; ++j) {
			campo[i][j] = 0;
		}
	}
}

void Resolve::insere(Base* componente)
{
	componentes.push_back(componente->alocar());	// Aloca o componente no vetor 

}

void Resolve::resolveTotal()
{
	ordenaComponentes();
	for (const auto& componente : componentes) {
		vector<string> entradasIndices = componente->getEntradas(); // Recebe as entradas a quais os componentes est�o conectados
		vector<string> saidasIndices = componente->getSaidas();	// Recebe as sa�das a quais os componentes est�o conectados
		vector<int> entradas;

		for (const auto& indices : entradasIndices) {
			if (indices != "") {	// Se houver �ndices de entrada
				if (indices[0] == 'e') {	// Se estiver conectado no vetor de entradas
					if (indices[1] - '0' >= 0 and indices[1] - '0' < 8) {
						entradas.push_back(entrada[indices[1] - '0']); // Pega o que est� no vetor de entradas a partir do �ndice convertido para inteiro
					}
				}
				else {
					entradas.push_back(campo[7 - (indices[0] - '0')][indices[1] - '0']); // Pega o que est� na matriz a partir dos �ndices convertido para inteiro
				}
			}
		}

		vector<bool> resultados = componente->calcula(entradas);	// Armazena os resultados do componente num vetor pra caso tenha mais de uma sa�da

		int i = 0;
		for (const auto& indices : saidasIndices) {
			if (indices != "") {	// Se houver �ndices de sa�da
				if (indices[0] == 's') {	// Se estiver conectado no vetor de sa�da
					if (indices[1] - '0' >= 0 and indices[1] - '0' < 8) {
						saida[indices[1] - '0'] = resultados[i];	// Insere o resultado no vetor de sa�da
					}
				}
				else {
					campo[7 - (indices[0] - '0')][indices[1] - '0'] = resultados[i];	// Insere o resultado no �ndice convertido para inteiro
				}
				i++;	// Incrementa para ir para pr�ximo resultado caso exista
			}
		}

	}
}

void Resolve::exibeCampo() const
{
	cout << "s | ";
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
	}
	cout << endl << "    ";
	for (int i = 0; i < 8; i++) {
		cout << saida[i] << " ";
	}

	cout << endl << endl;

	cout << "    ";
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << 7-i << " | ";
		for (int j = 0; j < 8; j++) {
			cout << campo[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "    ";

	for (int i = 0; i < 8; i++) {
		cout << entrada[i] << " ";
	}
	cout << endl << "e | ";
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
	}

	cout << endl;
}

void Resolve::editaEntradas(string entradas)
{
	if (entradas.size() != 8) {
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (entradas[i] - '0' == 0 or entradas[i] - '0' == 1) {
			entrada[i] = entradas[i] - '0';
		}
	}
}
void Resolve::editaComponente(int indice)
{
	if (indice > 0 && indice <= componentes.size()) {
		vector<string> ent = componentes[indice - 1]->getSaidas();

		if (ent.size() != 0) {
			for (const auto& indices : ent) {
				if (indices[0] == 'e') {
					entrada[indices[1] - '0'] = 0;
				}
				else if (indices[0] == 's') {
					saida[indices[1] - '0'] = 0;
				}
				else {
					campo[7 - (indices[0] - '0')][indices[1] - '0'] = 0;
				}
			}
		}

		componentes[indice - 1]->editaEntradasSaidas();
	}
}

void Resolve::removeComponente(int indice)
{
	if (indice > 0 && indice <= componentes.size()) {
		vector<string> ent = componentes[indice - 1]->getSaidas();

		if (ent.size() != 0) {
			for (const auto& indices : ent) {
				if (indices[0] == 'e') {
					entrada[indices[1] - '0'] = 0;
				}
				else if (indices[0] == 's') {
					saida[indices[1] - '0'] = 0;
				}
				else {
					campo[7 - (indices[0] - '0')][indices[1] - '0'] = 0;
				}
			}
		}

		componentes.erase(next(componentes.begin(), indice - 1));
	}

}

vector<Base*> Resolve::getComponentes()
{
	return componentes;
}

void Resolve::ordenaComponentes()
{
	sort(componentes.begin(), componentes.end(), [](Base* a, Base* b) {
		auto saidasA = a->getSaidas();
		auto saidasB = b->getSaidas();

		// Fun��o auxiliar para obter o menor �ndice num�rico
		auto obterMenorIndice = [](const vector<string>& saidas) -> int {
			int menorIndice = INT_MAX;
			for (const auto& saida : saidas) {
				if (saida[0] != 'e' && saida[0] != 's') {  // Se n�o for 'e' ou 's'
					int indiceNumerico = saida[1] - '0';    // Converte o segundo caractere para inteiro
					menorIndice = min(menorIndice, indiceNumerico);
				}
			}
			return menorIndice;
			};

		int menorIndiceA = obterMenorIndice(saidasA);
		int menorIndiceB = obterMenorIndice(saidasB);

		// Compara��o baseada no menor �ndice de sa�da
		return menorIndiceA < menorIndiceB;
		});
}

Resolve::~Resolve()
{
	for (const auto& componente : componentes) {
		delete componente;	// Desaloca cada componente 
	}
}