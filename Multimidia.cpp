#include "Multimidia.hpp"

Multimidia::Multimidia(){}

Multimidia::Multimidia(string titulo, string autor, string editora,string tipo, bool disponibilidade) : Item(titulo,autor,editora,disponibilidade){
	setTipo(tipo);
}

void Multimidia::setTipo(string tipo){
	this->tipoMultimidia=tipo;
}
string Multimidia::getTipo(){
	return this->tipoMultimidia;
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
	cout<<"Produtora : "<<getEditora()<<endl;
	cout<<"Tipo : "<<getTipo()<<endl;
	
}
