#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base
{
	//Vetores com �ndices
	vector<string> entradas, saidas;

	// Nome do componente
	string nome;
public:
	// Getter e setter para o nome
	string getNome() const;
	void setNome(string n);

	// Getters e setters para entradas e sa�das
	vector<string> getEntradas() const;
	vector<string> getSaidas() const;
	void setEntradas(vector<string> e);
	void setSaidas(vector<string> s);

	// Getter e setter para o n�mmero de entradas aceitas pelo componente
	virtual void setNumeroEntradas(unsigned n) = 0;
	virtual unsigned getNumeroEntradas() const = 0;

	// Func�o para altera��o de entradas e sa�das do componente
	virtual void editaEntradasSaidas() = 0;

	// C�lculo do componente l�gico
	virtual vector<bool> calcula(vector<int> entradas) const = 0;

	// Aloca��o do componente e destrutor
	virtual Base* alocar() = 0;
	virtual ~Base();
};

/*
	- A cria��o de uma vari�vel de n�mero de entradas � necess�rio para o futuro carregamento de 
	componenentes, como uma vari�vel de controle.
	- O uso de cin e cout em um componente n�o � recomendado, por�m, o uso dele nesse caso se torna especial pois � necess�rio
	para a edi��o unit�ria de um componente j� existente no campo de pinos.
*/

class And : public Base {
	// Inicializa��o do n�mero de entradas aceitas pelo componente
	unsigned nEntradas = 2;
public:
	// Construtores
	And();
	And(vector<string> e, vector<string> s, unsigned nEntradas);

	// Fun��es sobrescritas
	void editaEntradasSaidas() override;

	void setNumeroEntradas(unsigned n) override;
	unsigned getNumeroEntradas() const override;

	vector<bool> calcula(vector<int> entradas) const override;

	Base* alocar() override;
};

class Or : public Base {
	// Inicializa��o do n�mero de entradas aceitas pelo componente
	unsigned nEntradas = 2;
public:
	// Construtores
	Or();
	Or(vector<string> e, vector<string> s, unsigned nEntradas);

	// Fun��es sobrescritas
	void editaEntradasSaidas() override;

	void setNumeroEntradas(unsigned n) override;
	unsigned getNumeroEntradas() const override;

	vector<bool> calcula(vector<int> entradas) const override;

	Base* alocar() override;
};

class Not : public Base {
	// Inicializa��o do n�mero de entradas aceitas pelo componente
	unsigned nEntradas = 1;
public:
	// Construtores
	Not();
	Not(vector<string> e, vector<string> s, unsigned nEntradas);

	// Fun��es sobrescritas
	void editaEntradasSaidas() override;

	void setNumeroEntradas(unsigned n) override;
	unsigned getNumeroEntradas() const override;

	vector<bool> calcula(vector<int> entradas) const override;

	Base* alocar() override;
};

class Wire : public Base {
	// Inicializa��o do n�mero de entradas aceitas pelo componente
	unsigned nEntradas = 1;
public:
	// Construtores
	Wire();
	Wire(vector<string> e, vector<string> s, unsigned nEntradas);

	// Fun��es sobrescritas
	void editaEntradasSaidas() override;

	void setNumeroEntradas(unsigned n) override;
	unsigned getNumeroEntradas() const override;

	vector<bool> calcula(vector<int> entradas) const override;

	Base* alocar() override;
};