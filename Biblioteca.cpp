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
	
	acervo->inicializarAcervo();
	
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
	char decisao=' ';
	
	while(execucao){
		
		acesso=telaInicial(interfaceTipo);

		while(acesso){
			
			if(interface == pessoaUsuario)
				menuUsuario(acesso);
			
			if(interface == pessoaUsuario)
				menuFuncionario(acesso);
			
			while(decisao!= 's'&& decisao!= 'n'){
				
				cout<<"Deseja continuar sair do sistema?(s/n)"<<endl;
				
				cin>>decisao;
			}
			
			if(decisao == 's')
				execucao=0;
			
			if(decisao == 'n')
				acesso=0;
		}
	}
}

//Tela de inicio comum à interface do usuario e à interface do funcionario
int Biblioteca::telaInicial(int tipoUsuario){
	
	int telaCadastro=1;
	int telaCadastro2=1;
	int telaInicio = 1
	int acessoPermitido = 0;
	char cadastroExistente = ' ';
	char cadastrar = ' ';
	char novaTentativa = ' ';
	int idCadastro;
	string nomeCadastro;
	string senhaCadastro;
	
	while(telaInicio){
		
		try{
			while(cadastroExistente != 'n' && cadastroExistente != 's'){	
			
				cout<<"Voce possui cadastro na biblioteca?(s/n)"<<endl;
				cin>> cadastroExistente;
					
				if(cadastroExistente == 's'){
					
					acessoPermitido=login(tipoUsuario);
					return acessoPermitido;
				}
						
				if(cadastroExistente == 'n')
					throw LoginInvalido();
			}
		}
			
			catch(LoginInvalido& invalido){
				
				if(tipoUsuario==pessoaUsuario){
					
					while(telaCadastro){
						
						while(cadastrar != 'n' && cadastrar != 's'){	
						
							cout<<"Voce deseja realizar um cadastro na biblioteca?(s/n)"<<endl;
							
							cin>> cadastrar;
						}
						
						if(cadastrar == 's'){
							
							while(telaCadastro2){
								
								cout<<"Digite seu Nome, seu id e sua senha"<<endl;
								cin>>idCadastro >>nomeCadastro >> senhaCadastro;
								
								if(administrador->pesquisausuario(idCadastro,senhaCadastro)){
									
									cout<<"Erro: O usuario com esse id ja esta cadastrado"<<endl;
															
									cout<<"Tentar novamente?(s/n)"<<endl;
									
									cin>>novaTentativa;
									
									if(novaTentativa == 'n')
										return 0;
								}
					
								else
									funcionario->cadastrarUsuario(administrador,idCadastro,nomeCadastro,senhaCadastro);
									return 0;
							}
						}	
							
						if(cadastrar == 'n')
							return 0;	
					}
				}
				
				if(tipoUsuario == pessoaFuncionario){
					
					cout<<"Falha de Acesso: Esse funcionario nao possui cadastro"<<endl;
					return 0;
				}
			}
	}
	
		
}	

//login retorna 1 caso o acesso seja valido
int Biblioteca::login(int tipoUsuario){
	
	int idUsuario;
	string senhaUsuario;
	
	cout<<"Digite O seu ID e sua senha"<<endl;
	
	cin>>idUsuario>>senhaUsuario;
	
	if(tipoUsuario == pessoaUsuario){
		
		if(administrador->pesquisaUsuario(idUsuario,senhaUsuario)){
			
			usuario->setId(idUsuario);
			usuario->setSenha(senhaUsuario);
			return 1;
		}
	
		else
			cout<<"Acesso negado: Confira seu id e senha ou realize um cadastro"<<endl;
			throw LoginInvalido();
	}
		
	if(tipoUsuario == pessoaFuncionario){

		if(administrador->pesquisaFuncionario(idUsuario,senhaUsuario)){
			
			funcionario->setId(idUsuario);
			funcionario->setSenha(senhaUsuario);			
			return 1;
		}
		
		else
			cout<<"Acesso negado: Confira seu id e senha ou realize um cadastro"<<endl;
			throw LoginInvalido();
	}	
}

void Biblioteca::menuUsuario(){
	
	string nomeLivro;
	string autorLivro;
	string editoraLivro;
	string nomeMultimidia;
	string autorMultimidia;
	string tipoMultimidia;
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
			cout<<"Pesquisar por livro(9)"<<endl;
			cout<<"Pesquisar por multimidia(10)"<<endl;
			cout<<"Fazer logoff(11)"<<endl;
			
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
		
			cout<<"Digite o titulo, o autor e o tipo da multimidia que voce quer reservar"<endl;
			cin>>nomeMultimidia>>autorMultimidia>>tipoMultimidia;
			
			Multimidia multimidiaReservado;
			
			multimidiaReservado.setTitulo(nomeMultimidia);
			multimidiaReservado.setAutor(autorMultimidia);
			multimidiaReservado.setTipo(tipoMultimidia);
				
			acervo->mudarDisponibilidadeMultimidia(multimidiaReservado);
			usuario->reservarMultimidia(multimidiaReservado);
		}
		
		if(operacao==5){	
		
			cout<<"Digite o titulo, o autor e o tipo da multimidia que voce quer alugar"<endl;
			
			cin>>nomeMultimidia>>autorMultimidia>>tipoMultimidia;
			
			Multimidia multimidiaAlugado;
			
			multimidiaAlugado.setTitulo(nomeMultimidia);
			multimidiaAlugado.setAutor(autorMultimidia);
			multimidiaAlugado.setTipo(tipoMultimidia);
				
			usuario->alugarMultimidia(multimidiaAlugado);
			acervo->mudarDisponibilidadeMultimidia(MultimidiaAlugado);
		}
		
		if(operacao==6){
			
			cout<<"Digite o titulo e o autor da multimidia que voce quer devolver"<endl;
			
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
				
				acervo->procuraMultimidia(autorMultimidia,tipoPesquisa);
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
	string nomeLivro,autorLivro,editoraLivro,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia;
	string nomeUsuario,senhaUsuario,nomeFuncionario,senhaFuncionario;
	int userFuncionario,userUsuario;
	
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
			cout<<"Fazer logoff(9)"<<endl;
			
			cin>>operacao;
		}
		
		if(operacao == 1){
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer adicionar"<endl;
			
			cin>>nomeLivro>>autorLivro>>editoraLivro;
			
			funcionario->adicionarLivros(acervo,nomeLivro,autorLivro,editoraLivro);
		}
			
		
		if(operacao == 2){
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer remover"<endl;
			
			cin>>nomeLivro>>autorLivro>>editoraLivro;
			
			funcionario->removerLivros(acervo,nomeLivro,autorLivro,editoraLivro);
		}	
		
		
		if(operacao == 3){
			
			cout<<"Digite o titulo, o autor,a produtora e o tipo da multimidia que voce quer adicionar"<endl;
			
			cin>>nomeMultimidia>>autorMultimidia>>produtoraMultimidia>>tipoMultimidia;
			
			funcionario->adicionarMultimidias(acervo,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia);
		}	

		if(operacao == 4){
			
			cout<<"Digite o titulo, o autor,a produtora e o tipo da multimidia que voce quer remover"<endl;
			
			cin>>nomeMultimidia>>autorMultimidia>>produtoraMultimidia>>tipoMultimidia;
			
			funcionario->removerMultimidias(acervo,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia);
		}			
		
		if(operacao==5){
			cout<<"Digite o nome completo"<<endl;
			cin>>nomeUsuario;
			cout<<"Digite o login(numero inteiro) e uma nova senha para o usuario"<<endl;
			cin>>userUsuario>>senhaUsuario;
			
			if(administrador->pesquisausuario(userUsuario,senhaUsuario)){
				cout<<"Erro: esse usuario ja esta cadastrado"<<endl;
			}
			else
				funcionario->cadastrarUsuario(administrador, nomeUsuario, senhaUsuario, userUsuario);
		}
		
		if(operacao==6){
			cout<<"Digite o nome completo"<<endl;
			cin>>nomeFuncionario;
			cout<<"Digite o login(numero inteiro) e uma nova senha para o funcionario"<<endl;
			cin>>userFuncionario>>senhaFuncionario;
			
			if(administrador->pesquisaFuncionario(userFuncionario,senhaFuncionario)){
				cout<<"Erro: esse funcionario ja esta cadastrado"<<endl;
			}
			else
				funcionario->cadastrarFuncionario(administrador, nomeFuncionario, senhaFuncionario, userFuncionario);	
		}
		
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
