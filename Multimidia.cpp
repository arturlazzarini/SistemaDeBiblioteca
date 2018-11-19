#include "Multimidia.hpp"

Multimidia::Multimidia(){}

Multimidia::Multimidia(string titulo, string autor, string editora,string tipo, bool disponibilidade) : Item(titulo,autor,editora){
	setTipo(tipo);
	setDisponibilidade(disponibilidade);
}

void Multimidia::setTipo(string tipo){
	this->_tipoMultimidia=tipo;
}
string Multimidia::getTipo(){
	return this->_tipoMultimidia;
}

bool Multimidia::setDisponibilidade(bool disponibilidade){
	_disponibilidade = disponibilidade;
}

bool Multimidia::isDisponivel(){
	return this->_disponibilidade;
}

void Multimidia::mudarDisponibilidade(){
	_disponibilidade = true ? _disponibilidade = false :  _disponibilidade = true;
}

void Multimidia::imprimeCampos(){

	cout<<"Titulo : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Produtora : "<<getEditora()<<endl;
	cout<<"Tipo : "<<getTipo()<<endl;
	
}
