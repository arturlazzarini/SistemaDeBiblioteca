#include "Item.hpp"

Item::Item(){}

Item::Item(string titulo, string autor, string editora){
	this->_titulo = titulo;
	this->_autor = autor;
	this->_editora = editora;
}

void Item::setTitulo(string titulo){
		this->_titulo = titulo;
}
		
void Item::setAutor(string autor){
		this->_autor = autor;
}
		
void Item::setEditora(string editora){
		this->_editora = editora;
}

string Item::getTitulo(){
		return _titulo;
}
		
string Item::getAutor(){
		return _autor;
}
		
string Item::getEditora(){
		return _editora;
}
			
void Item::imprimeCampos(){

	cout<<"Titulo : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Editora : "<<getEditora()<<endl;
}