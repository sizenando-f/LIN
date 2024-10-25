#include "ResolveApp.h"
#include <iostream>

void ResolveApp::insereComponente(ComponentesApp* comp)
{
	registroDeComponentes.push_back(comp->alocarApp());
}

void ResolveApp::mainDoApp()
{
	int esc;
	string entradas;

	do {
		system("cls");
		resolve.exibeCampo();
		cout << endl << "MENU" << endl;
		cout << "1. Editar entrada" << endl << "2. Inserir componente" << endl << "3. Editar componente" << endl << "4. Remover componente" << endl << "5. Sair" << endl << "Escolha: ";
		cin >> esc;

		int i = 1, esc2;
		switch (esc)
		{
		case 1:
			cout << "               01234567" << endl;
			cout << "Insira 8 bits: ";
			cin >> entradas;

			if (entradas.size() != 8) break;

			resolve.editaEntradas(entradas);
			break;
		case 2:
			for (const auto& componente : registroDeComponentes) {
				cout << i << ". " << componente->getNome() << endl;
				i++;
			}
			cout << i << ". voltar" << endl;

			cout << "Escolha: ";
			cin >> esc2;
			
			if (esc2 >= 1 && esc <= i) {
				if (esc2 <= registroDeComponentes.size()) {
					registroDeComponentes.at(esc2 - 1)->leEntradasESaidas();
					resolve.insere(dynamic_cast<Base*>(registroDeComponentes.at(esc2 - 1)));
				}
			}
			break;
		case 3: {
			vector<Base*> comp = resolve.getComponentes();
			if (comp.size() != 0) {
				int i = 1, esc;
				for (const auto& componente : comp) {
					cout << i++ << ". " << componente->getNome() << " ";
					for (const auto& indices : componente->getEntradas()) {
						cout << indices << " ";
					}
					for (const auto& indices : componente->getSaidas()) {
						cout << indices << " ";
					}
					cout << endl;
				}
				cout << i << ". voltar" << endl;
				cout << "escolha: ";
				cin >> esc;
				if (esc >= 1 && esc <= i) resolve.editaComponente(esc);
			}
			break;
		}
		case 4: {
			vector<Base*> comp = resolve.getComponentes();
			if (comp.size() == 0) return;
			int i = 1, esc;
			for (const auto& componente : comp) {
				cout << i++ << ". " << componente->getNome() << " ";
				for (const auto& indices : componente->getEntradas()) {
					cout << indices << " ";
				}
				for (const auto& indices : componente->getSaidas()) {
					cout << indices << " ";
				}
				cout << endl;
			}
			cout << i << ". voltar" << endl;
			cout << "escolha: ";
			cin >> esc;
			if (esc >= 1 && esc <= i) resolve.removeComponente(esc);
			break;
		}
		default:
			break;
		}
		resolve.resolveTotal();
	} while (esc != 5);
}

ResolveApp::~ResolveApp()
{
	for (const auto& componente : registroDeComponentes) {
		delete componente;
	}
}