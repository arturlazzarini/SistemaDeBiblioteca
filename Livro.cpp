#include "Livro.hpp"

void Livro::setItensDisponiveis(int quantidade){
	_itensDisponiveis = quantidade;
}

bool Livro::isDisponivel(){
	return this->_disponivel;
}

void Livro::imprimeCampos(){

	cout<<"Título : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Editora : "<<getEditora()<<endl;
}
