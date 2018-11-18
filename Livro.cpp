#include "Livro.hpp"

Livro::Livro(){}

Livro::Livro(string titulo, string autor, string editora, bool disponibilidade) : Item(titulo,autor,editora,disponibilidade){}

bool Livro::isDisponivel(){
	return this->_disponivel;
}

void Livro::mudarDisponibilidade(){
	_disponibilidade = true ? _disponibilidade = false :  _disponibilidade = true;
}

void Livro::imprimeCampos(){
	cout<<"Título : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Editora : "<<getEditora()<<endl;
}