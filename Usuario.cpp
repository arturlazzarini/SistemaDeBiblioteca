#include "Usuario.hpp"



Usuario::Usuario ( string Nome,string Senha,int Id ,item itensAlugados[] , item itensReservados[]) : Pessoa(Nome,Senha,Id)
{

	this->itensAlugados = itensAlugados;
	this->itensReservados = itensReservados;
}



void Usuario::alugarItem(string item){

	

	
}


void Usuario::reservarItem(string item){}


void Usuario::devolverItem(string item){}


void Usuario::getItensAlugados(Item itensAlugados[]){}


void Usuario::getItensReservados(Item itensReservados[]){}



