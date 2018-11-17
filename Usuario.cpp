#include "Usuario.hpp"

Usuario::Usuario(){}

Usuario::Usuario(string nome, string senha, int id) : Pessoa(nome,senha,id){}

void Usuario::alugarLivro(Livro item){
	 
	//fazer as excecoes pro teste: nao pode ser item nulo, nem indisponivel
	_livrosAlugados.push_back(item);
}

void Usuario::reservarLivro(Livro item){
   
  //fazer as excecoes pro teste: nao pode ser item nulo, nem indisponivel
  _livrosReservados.push_back(item);
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

void Usuario::alugarMultimidia(Multimidia item){
	 
	_multimidiaAlugados.push_back(item);
}

void Usuario::reservarMultimidia(Multimidia item){
  
  _multimidiaReservados.push_back(item);
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

void Usuario::imprimeLivrosAlugados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhum livro alugado"<<endl; 
    return;   
  }

  for(int i=0; i<_livrosAlugados.size(); i++){
	_livrosAlugados[i].imprimirCampos();
  }
}

void Usuario::imprimeMultimidiaAlugados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhuma multimidia alugada"<<endl; 
    return;   
  }

  for(int i=0; i<_multimidiaAlugados.size(); i++){
	_multimidiaAlugados[i].imprimirCampos();
  }
}

void Usuario::imprimeLivrosReservados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhum livro reservado"<<endl; 
    return;   
  }

  for(int i=0; i<_livrosReservados.size(); i++){
	_livrosReservados[i].imprimirCampos();
  }
}

void Usuario::imprimeMultimidiaReservados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhuma multimidia reservada"<<endl; 
    return;   
  }

  for(int i=0; i<_multimidiaReservados.size(); i++){
	_multimidiaReservados[i].imprimirCampos();

  }
}
