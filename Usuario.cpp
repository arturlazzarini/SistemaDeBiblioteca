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
	for(int i=0;i <_livrosAlugados.size() ;i++){
		
		if(_livrosAlugados[i].getTitulo() == item){
				_livrosAlugados.erase(_livrosAlugados.begin()+i);
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
	
	int naoExiste=0;
	
	for(int i=0;i <_multimidiaAlugados.size() ;i++){
		
		if(_multimidiaAlugados[i].getTitulo() == item){
				_multimidiaAlugados.erase(_multimidiaAlugados.begin()+i);
				cout<<"Multimidia devolvida com sucesso"<<endl;
		}
		else
			naoExiste++;
	}
	if(naoExiste==_multimidiaAlugados.size())
		cout<<"esta multimidia nao estava alugada"<<endl;
}

void Usuario::imprimeLivrosAlugados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhum livro alugado"<<endl;    
  }
	else	
		for(int i=0; i<_livrosAlugados.size(); i++){
			_livrosAlugados[i].imprimeCampos();
		}
}

void Usuario::imprimeMultimidiaAlugados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhuma multimidia alugada"<<endl; 
  }
	else	
		for(int i=0; i<_multimidiaAlugados.size(); i++){
			_multimidiaAlugados[i].imprimeCampos();
		}
}

void Usuario::imprimeLivrosReservados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhum livro reservado"<<endl;   
  }

  else
	  for(int i=0; i<_livrosReservados.size(); i++){
		_livrosReservados[i].imprimeCampos();
		}
}

void Usuario::imprimeMultimidiaReservados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhuma multimidia reservada"<<endl;    
  }

  else 
	  for(int i=0; i<_multimidiaReservados.size(); i++){
		_multimidiaReservados[i].imprimeCampos();
	  }
}