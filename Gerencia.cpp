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

int Gerencia::pesquisaFuncionario(int idCadastro, string senhaCadastro){
	
	for(int i=0; i < _funcionariosCadastrados.size(); i++){
		
		if(_funcionariosCadastrados[i].getId() == idCadastro && _funcionariosCadastrados[i].getSenha() == senhaCadastro){
			return 1;	
		}
	}
	return 0;
}

int Gerencia::pesquisaUsuario(int idCadastro, string senhaCadastro){
	
	for(int i=0; i < _usuariosCadastrados.size(); i++){
		
		if(_usuariosCadastrados[i].getId() == idCadastro && _usuariosCadastrados[i].getSenha() == senhaCadastro){
			return 1;
		}			
	}
	return 0;	
}
