#include "Item.hpp"

void Item::setTitulo(string titulo){
		this->_titulo = titulo;
}
		
void Item::setAutor(string autor){
		this->_autor = autor;
}
		
void Item::setEditora(string editora){
		this->_editora = editora;
}
		
void Item::setCodigo(codigo){
		this->_codigo = codigo;
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
		
int Item::getCodigo(){
		return _codigo;
}
		
void Item::imprimeCampos(){

	cout<<"Título : "<<getTitulo()<<endl;
	cout<<"Autor : "<<getAutor()<<endl;
	cout<<"Editora : "<<getEditora()<<endl;
	cout<<"Codigo : "<<getCodigo()<<endl;
}
