#include "Livro.hpp"

Livro::Livro(){}

Livro::Livro(string titulo, string autor, string editora, bool disponibilidade) : Item(titulo,autor,editora){
	setDisponibilidade(disponibilidade);
}

bool Livro::setDisponibilidade(bool disponibilidade){
	_disponibilidade = disponibilidade;
}

bool Livro::isDisponivel(){
	return this->_disponibilidade;
}

void Livro::mudarDisponibilidade(){
	_disponibilidade = true ? _disponibilidade = false :  _disponibilidade = true;
}

void Livro::imprimeCampos(){
	cout<<"Titulo : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Editora : "<<getEditora()<<endl;
}