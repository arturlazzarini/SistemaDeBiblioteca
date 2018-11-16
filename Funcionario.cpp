#include "Funcionario.hpp"

Funcionario :: Funcionario(){}

Funcionario :: Funcionario(string nome, string senha, int id) : Pessoa(nome,senha,id){}

//Adiciona novos livros ao acervo da biblioteca
void Funcionario::adicionarlivros(Acervo *acervo,string titulo, string autor, string prod){
	
	Livro novo(string titulo, string autor, string prod);
	acervo->adicionarlivro(novo);
}

//Remove novos livros do acervo da biblioteca
void Funcionario::removerLivros(Acervo *acervo,string titulo, string autor, string prod){
	
	Livro livro(string titulo, string autor, string prod);
	acervo->removerLivro(livro);
}
//Adiciona novas multimidias ao acervo da biblioteca
void Funcionario::adicionarMultimidias(Acervo *acervo,string titulo, string autor){
	
	Multimidia nova;
	nova.setTitulo(titulo);
	nova.setAutor(autor);
	acervo->adicionarMultimidia(nova);
}

//Remove multimidia do acervo da biblioteca
void Funcionario::removerMultimidias(Acervo *acervo,string titulo, string autor){
	
	Multimidia multimidia;
	multimidia.setTitulo(titulo);
	multimidia.setAutor(autor);
	acervo->adicionarMultimidia(multimidia);
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
