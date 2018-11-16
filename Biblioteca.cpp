#include "Biblioteca.hpp"

//os numeros que representam e diferenciam usuarios e funcionarios no sistema
const int pessoaUsuario = 1;
const int pessoaFuncionario = 2;

Biblioteca::Biblioteca(){
		
	usuario = nullptr;
	funcionario = nullptr;
	administrador = nullptr;
	acervo = nullptr;
}
	
Biblioteca::~Biblioteca(){
	
	delete usuario;
	delete funcionario;
	delete administrador;
	delete acervo;
}

void Biblioteca::interfacePrincipal(){
	
    usuario = new Usuario(); 
	funcionario = new Funcionario();
	administrador= new Gerencia();
	acervo= new Acervo();

	determinaInterface();
	
	desalocaDados();
}

//identifica o tipo da pessoa que acessa o sistema para disponibilizar sua respectiva interface
void Biblioteca::determinaInterface(){
	
	int interface = 0;
	
	while(interfacea<pessoaUsuario||interface>pessoaFuncionario){
		
		cout<<"Voce deseja acessar o sistema como:"<<endl;
		cout<<"Usuario da Biblioteca(1)"<<endl;
		cout<<"Funcionario da Biblioteca(2)"<<endl;

		cin>>interface;
	}
	
	interfaceUsuario(interface);
}

//interface com login/cadastro e menu para usuario/funcionario
void Biblioteca::interfaceUsuario(int interfaceTipo){
	
	int execucao =1;
	int acesso=0;
	
	while(execucao){
		
		acesso=telaInicial(interfaceTipo);
		
		if(acesso == 0)
			cout<<"Acesso Negado: Falha em realizar o login"<<endl;

		while(acesso){
			
			if(interface == pessoaUsuario)
				menuUsuario(acesso);
			
			if(interface == pessoaUsuario)
				menuFuncionario(acesso);
		}
	}
}

//Tela de inicio comum à interface do usuario e à interface do funcionario
int Biblioteca::telaInicial(int tipoUsuario){
	
	int telaInicio = 1
	int acessoPermitido = 0;
	char c = ' ';
	int idCadastro;
	string nomeCadastro;
	string senhaCadastro;
	
	while(telaInicio){
		
		try{
			while(c != 'n' && c != 's'){	
			
				cout<<"Voce possui cadastro na biblioteca?(s/n)"<<endl;
				cin>> c;
					
				if(c == 's'){
					
					acessoPermitido=login(usuario,tipoUsuario);
					return acessoPermitido;
				}
						
				if(c == 'n')
					throw LoginInvalido();
			}
		}
			
			catch(LoginInvalido& invalido){
					
				cout<<"Voce deseja realizar um cadastro na biblioteca?(s/n)"<<endl;
				cin>>char cadastrar;
				
				if(cadastrar == 's'){
					
					cout<<"Digite seu Nome, seu id e sua senha"<<endl;
					cin>>idCadastro >>nomeCadastro >> senhaCadastro;
					
					funcionario->cadastrarUsuario(administrador,idCadastro,nomeCadastro,senhaCadastro)
				}
					
					
				if(cadastrar == 'n')
					telaInicio=0;	
			}
	}
	
	return 0;	
}	

//login retorna 1 caso o acesso seja valido
int Biblioteca::login(Pessoa *p,int tipoUsuario){
	
	int idUsuario;
	string senhaUsuario
	
	cout<<"Digite O seu ID e sua senha"<<endl;
	
	cin>>nomeUsuario>>senhaUsuario;
	
	p->setId(idUsuario);
	p->setSenha(senhaUsuario);
	
	if(tipoUsuario == pessoaUsuario){
		return administrador->pesquisaUsuario(p);
			
		
		else
			throw LoginInvalido();
	}
		
	if(tipoUsuario == pessoaFuncionario){
		return administrador->pesquisaFuncionario(p);
			
		
		else
			throw LoginInvalido();
	}	
}

void Biblioteca::menuUsuario(){
	
	string nomeLivro;
	string autorLivro;
	string editora;
	string nomeMultimidia;
	string autorMultimidia;
	int menu=1;
	int operacao=0;
	int tipoPesquisa=0;
	
	while(menu){
		
		while(operacao<1||operacao>11){
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4/5/6/7/8/9/10/11)"<<endl;
			
			cout<<"Reservar Livro(1)"<<endl;
			cout<<"Alugar Livro(2)"<<endl;
			cout<<"Devolver Livro(3)"<<endl;
			cout<<"Reservar Multimidia(4)"<<endl;
			cout<<"Alugar Multimidia(5)"<<endl;
			cout<<"Devolver Multimidia(6)"<<endl;
			cout<<"Imprimir livros alugados(7)"<<endl;
			cout<<"Imprimir livros reservados(8)"<<endl;
			cout<<"Pesquisar livro(9)"<<endl;
			cout<<"Pesquisar multimidia(10)"<<endl;
			cout<<"Sair do sistema(11)"<<endl;
			
			cin>>operacao;
		}
		
		if(operacao==1){
			
			cout<<"Digite o titulo e o autor do livro que voce quer reservar"<endl;
			cin>>nomeLivro>>autorLivro;
			
			Livro livroReservado;
			
			livroReservado.setTitulo(nomeLivro);
			livroReservado.setAutor(autorLivro);
			
			usuario->reservarLivro(livroReservado);
			acervo->mudarDisponibilidadeLivro(livroReservado);
		}
			
		if(operacao==2){	
		
			cout<<"Digite o titulo e o autor do livro que voce quer alugar"<endl;
			
			cin>>nomeLivro>>autorLivro;
			
			Livro livroAlugado;
			
			livroAlugado.setTitulo(nomeLivro);
			livroAlugado.setAutor(autorLivro);
			
			acervo->mudarDisponibilidadeLivro(livroAlugado);
			usuario->alugarLivro(livroAlugado);
			
		}
		if(operacao==3){	
		
			cout<<"Digite o titulo do livro que voce quer devolver"<endl;
			
			cin>>nomeLivro>>nomeAutor;			
			
			usuario->devolverLivro(nomeLivro);
			
			Livro livroDevolvido;
			
			livroDevolvido.setTitulo(nomeLivro);
			livroDevolvido.setAutor(autorLivro);
			
			acervo->mudarDisponibilidadeLivro(livroDevolvido);
		}
		
		if(operacao==4){	
		
			cout<<"Digite o titulo e o autor da multimidia que voce quer reservar"<endl;
			cin>>nomeMultimidia>>autorMultimidia;
			
			Multimidia multimidiaReservado;
			
			multimidiaReservado.setTitulo(nomeMultimidia);
			multimidiaReservado.setAutor(autorMultimidia);
				
			acervo->mudarDisponibilidadeMultimidia(multimidiaReservado);
			usuario->reservarMultimidia(multimidiaReservado);
		}
		
		if(operacao==5){	
		
			cout<<"Digite o titulo e o autor da multimidia que voce quer alugar"<endl;
			
			cin>>nomeMultimidia>>autorMultimidia;
			
			Multimidia multimidiaAlugado;
			
			multimidiaAlugado.setTitulo(nomeMultimidia);
			multimidiaAlugado.setAutor(autorMultimidia);
				
			usuario->alugarMultimidia(multimidiaAlugado);
			acervo->mudarDisponibilidadeMultimidia(MultimidiaAlugado);
		}
		
		if(operacao==6){
			
			cout<<"Digite o titulo da multimidia que voce quer devolver"<endl;
			
			cin>>nomeMultimidia>>autorMultimidia;			
			
			usuario->devolverMultimidia(nomeMultimidia);
			
			Multimidia multimidiaDevolvido;
			
			multimidiaDevolvido.setTitulo(nomeMultimidia);
			multimidiaDevolvido.setAutor(autorMultimidia);
			
			acervo->mudarDisponibilidadeMultimidia(multimidiaDevolvido);
		}
		
		if(operacao==7){	
			usuario->imprimeLivrosAlugados();
		}
		
		if(operacao==8){	
			usuario->imprimeLivrosReservados();
		}
		
		if(operacao==9){
			
			while(tipoPesquisa<1||tipoPesquisa>3){
				
				cout<<"Voce deseja pesquisar por :"<<endl;
				cout<<"Titulo do livro(1)"<<endl;
				cout<<"Nome do autor(2)"<<endl;
				cout<<"Nome da editora(3)"<<endl;
				
				cin>>tipoPesquisa;
			}
			if(tipoPesquisa==1){
				
				cout<<"Digite o titulo do livro que voce deseja pesquisar"<<endl;
				
				cin>>nomeLivro;
				
				acervo->procuraLivro(nomeLivro,tipoPesquisa);
			}
				
			if(tipoPesquisa==2){
				
				cout<<"Digite o autor do livro que voce deseja pesquisar"<<endl;
				
				cin>>autorLivro;
				
				acervo->procuraLivro(autorLivro,tipoPesquisa);
			}
				
			if(tipoPesquisa==3){
				
				cout<<"Digite a editora do livro que voce deseja pesquisar"<<endl;
				cin>>editoraLivro;
				
				acervo->procuraLivro(editoraLivro,tipoPesquisa);
			}		
			
		}
		
		if(operacao==10){	
		
			while(tipoPesquisa<1||tipoPesquisa>2){
				
				cout<<"Voce deseja pesquisar por :"<<endl;
				cout<<"Titulo da multimidia(1)"<<endl;
				cout<<"Nome do autor(2)"<<endl;
				
				cin>>tipoPesquisa;
			}
			
			if(tipoPesquisa==1){
				
				cout<<"Digite o titulo da multimidia que voce deseja pesquisar"<<endl;
				
				cin>>nomeMultimidia;
				
				acervo->procuraMultimidia(nomeMultimidia,tipoPesquisa);
			}
				
			if(tipoPesquisa==2){
				
				cout<<"Digite o autor da multimidia que voce deseja pesquisar"<<endl;
				
				cin>>autorMultimidia;
				
				acervo->procuraLivro(autorMultimidia,tipoPesquisa);
			}
		}
		
		if(operacao==11){
			menu=0;
		}
	}	
}

void Biblioteca::menuFuncionario(){
	
	int menu=1;
	int operacao=0;
	string nomeLivro,autorLivro,editoraLivro,nomeMultimidia,autorMultimidia;
	string nomeUsuario,userUsuario,senhaUsuario,nomeFuncionario,userFuncionario,senhaFuncionario;
	
	while(menu){

		while(operacao<1||operacao>7){
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4/5/6/7/8/9)"<<endl;
			
			cout<<"Adicionar livro ao acervo da bibliteca(1)"<<endl;
			cout<<"Remover livro do acervo da biblioteca(2)"<<endl;
			cout<<"Adicionar multimidia ao acervo da bibliteca(3)"<<endl;
			cout<<"Remover multimidia do acervo da biblioteca(4)"<<endl;
			cout<<"Cadastrar novo usuario da biblioteca(5)"<<endl;
			cout<<"Cadastrar novo funcionario da biblioteca(6)"<<endl;
			cout<<"Imprimir colecao de livros(7)"<<endl;
			cout<<"Imprimir colecao de multimidia(8)"<<endl;
			cout<<"Sair do sistema(9)"<<endl;
			
			cin>>operacao;
		}
		
		if(operacao == 1){
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer adicionar"<endl;
			
			cin>>nomeLivro>>autorLivro>>editoraLivro;
			
			funcionario->adicionarLivro(acervo,nomeLivro,autorLivro,editoraLivro);
			}
			
		
		if(operacao == 2){
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer remover"<endl;
			
			cin>>nomeLivro>>autorLivro>>editoraLivro;
			
			funcionario->removerLivro(acervo,nomeLivro,autorLivro,editoraLivro);
			}	
		
		
		if(operacao == 3){
			
			cout<<"Digite o titulo e o autor da multimidia que voce quer adicionar"<endl;
			
			cin>>nomeMultimidia>>autorMultimidia;
			
			funcionario->adicionarMultimidia(acervo,nomeMultimidia,autorMultimidia);
			}	

		if(operacao == 4){
			
			cout<<"Digite o titulo e o autor da multimidia que voce quer remover"<endl;
			
			cin>>nomeMultimidia>>autorMultimidia;
			
			funcionario->removerMultimidia(acervo,nomeMultimidia,autorMultimidia);
			}		
			
		
		if(operacao==5)
			cout<<"Digite o nome completo"<<endl;
			cin>>nomeUsuario;
			cout<<"Digite o login e uma nova senha para o usuario"<<endl;
			cin>>userUsuario>>senhaUsuario;

			funcionario->cadastrarUsuario(administrador, nomeUsuario, senhaUsuario, userUsuario);
		
		if(operacao==6)
			cout<<"Digite o nome completo"<<endl;
			cin>>nomeFuncionario;
			cout<<"Digite o login e uma nova senha para o funcionario"<<endl;
			cin>>userFuncionario>>senhaFuncionario;

			funcionario->cadastrarFuncionario(administrador, nomeFuncionario, senhaFuncionario, userFuncionario);	
			
		if(operacao == 7)	
			acervo->listarLivros();
			
		if(operacao == 8)				
			acervo->listarMultimidia();
		
		if(operacao == 9)
			menu=0;
	}	
}

void Biblioteca::desalocaDados(){
	
}
