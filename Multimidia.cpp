#include "Multimidia.hpp"

void Multimidia::setItensDisponiveis(int quantidade){
    _itensDisponiveis = quantidade;
}

bool Multimidia::isDisponivel(){
	return this->_disponivel;
}

void Multimidia::imprimeCampos(){

	cout<<"Título : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Editora : "<<getEditora()<<endl;
}
