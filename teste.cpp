#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

#include "Livro.hpp"
#include "Acervo.hpp"

using namespace std;

int main(){ 

	string titulo;
	string autor;
	string prod;

	string line;

	ifstream inFile; // inFile é o arquivo de leitura dos dados

	inFile.open("itens.txt", ios::in); // abre o arquivo para leitura

	if (! inFile){
		cout << "Arquivo txt nao pode ser aberto" << endl;
		abort();
	} 

	while(getline(inFile, line)){
		stringstream ss(line);
		getline(ss, titulo, '/');
		getline(ss, autor, '/');
		getline(ss, prod, '/');

		Livro novo(titulo, autor, prod, true);     // Linha 35 a 37 ainda não testada dentro do sistema.
                                                   // Teste do codigo feito apenas no arquivo txt                 
		Acervo atual.adicionarLivro(novo);         // e imprimindo os itens (linha 39). 

		cout << titulo << " / " << autor << " / " << prod << endl;
	}

	inFile.close();

	return 0;
} 