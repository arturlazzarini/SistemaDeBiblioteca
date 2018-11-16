#include "Gerencia.hpp"

Gerencia::Gerencia(){}

void Gerencia::setUsuarioCadastrado(Usuario novo){
	
	_usuariosCadastrados.push_back(novo);
	cout<<"Usuario cadastrado com sucesso"<<endl;
}

void Gerencia::setFuncionarioCadastrado(Funcionario novo){
	
	_funcionariosCadastrados.push_back(novo);
	cout<<"Funcionario cadastrado com sucesso"<<endl;
}

int Gerencia::pesquisaFuncionario(Pessoa *funcionario){
	
	for(int i=0; i < _funcionariosCadastrados.size(); i++){
		
		if(_funcionariosCadastrados[i].getId() == funcionario->getId() && _funcionariosCadastrados[i].getSenha() == funcionario->getSenha()){
			funcionario->setNome(_funcionariosCadastrados[i].getNome());
			return 1;	
		}
	}
	return 0;
}

int Gerencia::pesquisaUsuario(Pessoa *usuario){
	
	for(int i=0; i < _usuariosCadastrados.size(); i++){
		
		if(_usuariosCadastrados[i].getId() == usuario->getId() && _usuariosCadastrados[i].getSenha() == usuario->getSenha()){
			usuario->setNome(_usuariosCadastrados[i].getNome());
			return 1;
		}			
	}
	return 0;	
}
