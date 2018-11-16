#include "Multimidia.hpp"

Multimidia::Multimidia(){}

Multimidia::Multimidia(string titulo, string autor, string editora, bool disponibilidade) : Item(titulo,autor,editora,disponibilidade){}

void Multimidia::setItensDisponiveis(int quantidade){
    _itensDisponiveis = quantidade;
}

bool Multimidia::isDisponivel(){
	return this->_disponivel;
}

void Multimidia::mudarDisponibilidade(){
	_disponibilidade = true ? _disponibilidade = false :  _disponibilidade = true;
}

void Multimidia::imprimeCampos(){

	cout<<"Título : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Editora : "<<getEditora()<<endl;
}

void Multimidia::reservar(){
	_disponibilidade = false;
}
