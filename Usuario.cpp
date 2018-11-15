#include "Usuario.hpp"



Usuario::Usuario ( string Nome,string Senha,int Id ,item itensAlugados[] , item itensReservados[]) : Pessoa(Nome,Senha,Id)
{

	this->itensAlugados = itensAlugados;
	this->itensReservados = itensReservados;
}



void Usuario::alugarLivro(string item){
	 
	//fazer as excecoes pro teste nao pode ser item nulo, nem indisponivel
	 _livrosAlugados.push_back(item);
	
}

void Usuario::devolverLivro(string item){

	std::sort(_livrosAlugados.begin(), _livrosAlugados.end()); 
	int j = 0;

	while(j<_livrosAlugados.size()){
      //check de colisão
      if ((_livrosAlugados[j]).compare(item) != 0){
        j++;
      }
      
      //apago o item repetido (modificando o tamanho do vector)
      else if ((_livrosAlugados[j]).compare(item) == 0){
        _livrosAlugados.erase(_livrosAlugados.begin()+j);
        break;
      }

  	}
}

void Usuario::alugarMultimidia(string item){
	 
	 _livrosAlugados.push_back(item);
	
}

void Usuario::devolverMultimidia(string item){

	std::sort(_multimiidiaAlugados.begin(), _multimidiaAlugados.end()); 
	int j = 0;

	while(j<_multimidiaAlugados.size()){
      //check de colisão
      if ((_multimidiaAlugados[j]).compare(item) != 0){
        j++;
      }
      
      //apago o item repetido (modificando o tamanho do vector)
      else if ((_multimidiaAlugados[j]).compare(item) == 0){
        _multimidiaAlugados.erase(_multimidiaAlugados.begin()+j);
        break;
      }

  	}
}


void Usuario::getItensAlugados(Item itensAlugados[]){
	
}


void Usuario::getItensReservados(Item itensReservados[]){}



