#include "Usuario.hpp"

Usuario::Usuario (string nome, string senha, int id, item itensAlugados[], item itensReservados[]) : Pessoa(nome,senha,id){
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

void Usuario::imprimeLivrosAlugados(){

  for(int i=0; i<_livrosAlugados.size(); i++){
    cout<<"Título : "<<_livrosAlugados[i].getTitulo()<<endl;
    cout<<"Autor : "<<_livrosAlugados[i].getAutor()<<endl;
    cout<<"Editora : "<<_livrosAlugados[i].getEditora()<<endl;
  }
}

void Usuario::imprimeMultimidiaAlugados(){

  for(int i=0; i<_multimidiaAlugados.size(); i++){
    cout<<"Título : "<<_multimidiaAlugados[i].getTitulo()<<endl;
    cout<<"Autor : "<<_multimidiaAlugados[i].getAutor()<<endl;
    cout<<"Editora : "<<_multimidiaAlugados[i].getEditora()<<endl;
  }
}

void Usuario::imprimeLivrosReservados(){

  for(int i=0; i<_livrosReservados.size(); i++){
    cout<<"Título : "<<_livrosReservados[i].getTitulo()<<endl;
    cout<<"Autor : "<<_livrosReservados[i].getAutor()<<endl;
    cout<<"Editora : "<<_livrosReservados[i].getEditora()<<endl;
  }
}

void Usuario::imprimeMultimidiaReservados(){

  for(int i=0; i<_multimidiaReservados.size(); i++){
    cout<<"Título : "<<_multimidiaReservados[i].getTitulo()<<endl;
    cout<<"Autor : "<<_multimidiaReservados[i].getAutor()<<endl;
    cout<<"Editora : "<<_multimidiaReservados[i].getEditora()<<endl;
  }
}

