#include "Funcionario.hpp"

//Adiciona novos itens ao acervo da biblioteca

void Funcionario::adicionarlivro(Acervo *acervo,string titulo, string autor, string _editora){
	
	Livro novo(string titulo, string autor, string _editora);
	acervo->adicionarlivro(novo);
}

//Remove novos itens ao acervo da biblioteca
void Funcionario::removerLivro(Acervo *acervo,string titulo, string autor, string _editora){
	
	Livro livro(string titulo, string autor, string _editora);
	acervo->removerLivro(livro);
}

//Cadastra novos usuários e os adiciona à gerencia
void Funcionario::cadastrarUsuario(Gerencia *adm, string nome, string senha, string id){
	
	Usuario novo(nome, senha, id);
	adm->setUsuarioCadastrado(novo);
}

//Cadastra novos usuários e os adiciona à gerencia
void Funcionario::cadastrarFuncionario(Gerencia *adm, string nome, string senha, string id){
	
	Funcionario novo(nome, senha, id);
	adm->setFuncionarioCadastrado(novo);
}
