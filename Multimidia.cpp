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

void Biblioteca::imprimeLinhas(){
	cout<<"\n--------------------------------------------------\n"<<endl;
}

void Biblioteca::interfacePrincipal(){
	
    usuario = new Usuario(); 
	funcionario = new Funcionario();
	administrador= new Gerencia();
	acervo= new Acervo();
	
	Usuario padrao("Padrao","1234",4567);
	
	Funcionario base("Base","0000",1234);
	
	administrador->setUsuarioCadastrado(padrao);
	
	administrador->setFuncionarioCadastrado(base);
	
	acervo->inicializarAcervo();
	
	interfaceUsuario();
	
	desalocaDados();
}

//identifica o tipo da pessoa que acessa o sistema para disponibilizar sua respectiva interface
int Biblioteca::determinaInterface(){
	
	int interface = 0;
	
	while(interface<pessoaUsuario||interface>pessoaFuncionario){
		
		cout<<"Voce deseja acessar o sistema como:\n"<<endl;
		cout<<"Usuario da Biblioteca(1)\n"<<endl;
		cout<<"Funcionario da Biblioteca(2)\n"<<endl;


		cin>>interface;
		imprimeLinhas();
	}
	
	return interface;

}

//interface com login/cadastro e menu para usuario/funcionario
void Biblioteca::interfaceUsuario(){
	
	int execucao =1;
	int acesso=0;
	char decisao=' ';
	int interfaceTipo=0;

	while(execucao){

		interfaceTipo=determinaInterface();

		acesso=telaInicial(interfaceTipo);

		while(acesso){
			
			if(interfaceTipo == pessoaUsuario){
				menuUsuario();
				acesso=0;
				
			}
			
			if(interfaceTipo == pessoaFuncionario){
				menuFuncionario();
				acesso=0;
			}		

		}
			
			while(decisao!= 's'&& decisao!= 'n'){
				
				cout<<"Deseja sair do sistema?(s/n)\n"<<endl;

				cin>>decisao;
				imprimeLinhas();
			}
			
			if(decisao == 's'){
				execucao=0;
			}
			if(decisao== 'n')
				decisao=' ';
			
	}
}

//Tela de inicio comum à interface do usuario e à interface do funcionario
int Biblioteca::telaInicial(int tipoUsuario){
	
	int telaCadastro=1;
	int telaCadastro2=1;
	int telaInicio = 1;
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
			
				cout<<"Voce possui cadastro na biblioteca?(s/n)\n"<<endl;
				cin>> cadastroExistente;
				imprimeLinhas();
			}
					
				if(cadastroExistente == 's'){
					
					acessoPermitido=login(tipoUsuario);
					return acessoPermitido;
				}
						
				if(cadastroExistente == 'n')
					throw LoginInvalido();
		}
			
			catch(LoginInvalido& invalido){
				
				if(tipoUsuario==pessoaUsuario){
					
					while(telaCadastro){
						
						while(cadastrar != 'n' && cadastrar != 's'){	
						
							cout<<"Voce deseja realizar um cadastro na biblioteca?(s/n)\n"<<endl;
							
							cin>> cadastrar;
							imprimeLinhas();
						}
						
						if(cadastrar == 's'){
							
							while(telaCadastro2){
								
								cout<<"Digite seu id (inteiro) e sua senha\n"<<endl;
								cin>>idCadastro >> senhaCadastro;
								imprimeLinhas();
								
								cin.ignore();
								
								cout<<"Digite seu nome completo\n"<<endl;
								getline(cin,nomeCadastro);
								
								
								if(administrador->pesquisaUsuario(idCadastro,senhaCadastro)){
									
									cout<<"Erro: O usuario com esse id ja esta cadastrado\n"<<endl;
															
									cout<<"Tentar novamente?(s/n)\n"<<endl;
									
									cin>>novaTentativa;
									imprimeLinhas();
									
									if(novaTentativa == 'n')
										return 0;
								}
					
								else
									administrador->setUsuarioCadastrado(funcionario->cadastrarUsuario(nomeCadastro,senhaCadastro,idCadastro));
									return 0;
							}
						}	
							
						if(cadastrar == 'n')
							return 0;	
					}
				}
				
				if(tipoUsuario == pessoaFuncionario){
					
					cout<<"Acesso negado: Confira seu id e senha ou realize um cadastro\n"<<endl;
					imprimeLinhas();
					return 0;
				}
			}
	}
	
		
}	

//login retorna 1 caso o acesso seja valido
int Biblioteca::login(int tipoUsuario){
	
	int idUsuario;
	string senhaUsuario;
	
	cout<<"Digite o seu ID e sua senha\n"<<endl;
	
	cin>>idUsuario>>senhaUsuario;
	imprimeLinhas();
	
	if(tipoUsuario == pessoaUsuario){
		
		if(administrador->pesquisaUsuario(idUsuario,senhaUsuario)){
			
			usuario->setId(idUsuario);
			usuario->setSenha(senhaUsuario);
			administrador->atribuiParametrosUsuario(usuario);
			return 1;
		}
	
		else
			cout<<"Acesso negado: Confira seu id e senha ou realize um cadastro\n"<<endl;
			imprimeLinhas();
			throw LoginInvalido();
	}
		
	if(tipoUsuario == pessoaFuncionario){

		if(administrador->pesquisaFuncionario(idUsuario,senhaUsuario)){
			
			funcionario->setId(idUsuario);
			funcionario->setSenha(senhaUsuario);
			administrador->atribuiParametrosFuncionario(funcionario);			
			return 1;
		}
		
		else
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
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4/5/6/7/8/9/10/11)\n"<<endl;
			
			cout<<"(1)Reservar Livro\n"<<endl;
			cout<<"(2)Alugar Livro\n"<<endl;
			cout<<"(3)Devolver Livro\n"<<endl;
			cout<<"(4)Reservar Multimidia\n"<<endl;
			cout<<"(5)Alugar Multimidia\n"<<endl;
			cout<<"(6)Devolver Multimidia\n"<<endl;
			cout<<"(7)Imprimir livros alugados\n"<<endl;
			cout<<"(8)Imprimir livros reservados\n"<<endl;
			cout<<"(9)Pesquisar por livro\n"<<endl;
			cout<<"(10)Pesquisar por multimidia\n"<<endl;
			cout<<"(11)Fazer logoff\n"<<endl;
			
			cin>>operacao;
			imprimeLinhas();
		}
		
		if(operacao==1){
			
			cin.ignore();
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer reservar\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);
			getline(cin,editoraLivro);
			imprimeLinhas();
						
			Livro livroReservado;
			
			livroReservado.setTitulo(nomeLivro);
			livroReservado.setAutor(autorLivro);
			livroReservado.setEditora(editoraLivro);
			
			if(acervo->pesquisaLivro(livroReservado)&&livroReservado.isDisponivel()){
				
				acervo->mudarDisponibilidadeLivro(livroReservado);
				usuario->reservarLivro(livroReservado);
				cout<<"Livro reservado com sucesso\n"<<endl;
				imprimeLinhas();
			}
			if(!acervo->pesquisaLivro(livroReservado))
				cout<<"Livro nao esta disponivel para reserva\n"<<endl;
				imprimeLinhas();
			operacao=0;
		}
			
		if(operacao==2){	
		
			cin.ignore();
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer alugar\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);
			getline(cin,editoraLivro);
			imprimeLinhas(); 
			
			Livro livroAlugado;
			
			livroAlugado.setTitulo(nomeLivro);
			livroAlugado.setAutor(autorLivro);
			livroAlugado.setEditora(editoraLivro);
			
			if(acervo->pesquisaLivro(livroAlugado)){
				
				acervo->mudarDisponibilidadeLivro(livroAlugado);
				usuario->alugarLivro(livroAlugado);
				cout<<"Livro alugado com sucesso\n"<<endl;
				imprimeLinhas();
			}
			if(!acervo->pesquisaLivro(livroAlugado))
				cout<<"Livro nao esta disponivel para aluguel\n"<<endl;
				imprimeLinhas();
			operacao=0;
						
		}
		
		if(operacao==3){
			
			cin.ignore();		
			cout<<"Digite o titulo e o autor do livro que voce quer devolver\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);
			imprimeLinhas();			
			
			usuario->devolverLivro(nomeLivro);
			
			Livro livroDevolvido;
			
			livroDevolvido.setTitulo(nomeLivro);
			livroDevolvido.setAutor(autorLivro);
			
			
			acervo->mudarDisponibilidadeLivro(livroDevolvido);
			operacao=0;
		}
		
		if(operacao==4){	
		
			cin.ignore();
			cout<<"Digite o titulo, o autor e o tipo da multimidia que voce quer reservar\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);

			cin>>tipoMultimidia;
			imprimeLinhas();
			
			Multimidia multimidiaReservado;
			
			multimidiaReservado.setTitulo(nomeMultimidia);
			multimidiaReservado.setAutor(autorMultimidia);
			multimidiaReservado.setTipo(tipoMultimidia);
			
			if(acervo->pesquisaMultimidia(multimidiaReservado)){			
				acervo->mudarDisponibilidadeMultimidia(multimidiaReservado);
				usuario->reservarMultimidia(multimidiaReservado);
				cout<<"Multimidia reservada com sucesso\n"<<endl;
				imprimeLinhas();
			}
			if(!acervo->pesquisaMultimidia(multimidiaReservado))
				cout<<"Multimidia nao esta disponivel para reserva\n"<<endl;
				imprimeLinhas();
			operacao=0;
		}
		
		if(operacao==5){
			
			cin.ignore();
			
			cout<<"Digite o titulo, o autor e o tipo da multimidia que voce quer alugar:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			cin>>tipoMultimidia;
			imprimeLinhas();
			
			Multimidia multimidiaAlugado;
			
			multimidiaAlugado.setTitulo(nomeMultimidia);
			multimidiaAlugado.setAutor(autorMultimidia);
			multimidiaAlugado.setTipo(tipoMultimidia);
				
			if(acervo->pesquisaMultimidia(multimidiaAlugado)){			
				acervo->mudarDisponibilidadeMultimidia(multimidiaAlugado);
				usuario->alugarMultimidia(multimidiaAlugado);
				cout<<"Multimidia alugada com sucesso\n"<<endl;
				imprimeLinhas();
			}
			if(!acervo->pesquisaMultimidia(multimidiaAlugado))
				cout<<"Multimidia nao esta disponivel para aluguel\n"<<endl;
				imprimeLinhas();
			
			operacao=0;
		}
		
		if(operacao==6){
			
			cin.ignore();
			
			cout<<"Digite o titulo e o autor da multimidia que voce quer devolver:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			imprimeLinhas();				
			
			usuario->devolverMultimidia(nomeMultimidia);
			
			Multimidia multimidiaDevolvido;
			
			multimidiaDevolvido.setTitulo(nomeMultimidia);
			multimidiaDevolvido.setAutor(autorMultimidia);
			
			acervo->mudarDisponibilidadeMultimidia(multimidiaDevolvido);
			operacao=0;
		}
		
		if(operacao==7){	
			usuario->imprimeLivrosAlugados();
			operacao=0;
		}
		
		if(operacao==8){	
			usuario->imprimeLivrosReservados();
			operacao=0;
		}
		
		if(operacao==9){
			
			while(tipoPesquisa<1||tipoPesquisa>3){
				
				cout<<"Voce deseja pesquisar por :\n"<<endl;
				cout<<"(1)Titulo do livro\n"<<endl;
				cout<<"(2)Nome do autor\n"<<endl;
				cout<<"(3)Nome da editora\n"<<endl;
				
				cin>>tipoPesquisa;
				imprimeLinhas();
			}
			if(tipoPesquisa==1){
				
				cin.ignore();
				
				cout<<"Digite o titulo do livro que voce deseja pesquisar:\n";
				
				getline(cin,nomeLivro);
				imprimeLinhas();
				
				acervo->procuraLivro(nomeLivro,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
				
			if(tipoPesquisa==2){
				
				cin.ignore();
				
				cout<<"Digite o autor do livro que voce deseja pesquisar:\n"<<endl;
				
				getline(cin,autorLivro);
				imprimeLinhas();
				
				acervo->procuraLivro(autorLivro,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
				
			if(tipoPesquisa==3){
				
				cout<<"Digite a editora do livro que voce deseja pesquisar:\n"<<endl;
				cin>>editoraLivro;
				imprimeLinhas();
				
				acervo->procuraLivro(editoraLivro,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}		
			
		}
		
		if(operacao==10){	
		
			while(tipoPesquisa<1||tipoPesquisa>2){
				
				cout<<"Voce deseja pesquisar por :\n"<<endl;
				cout<<"(1)Titulo da multimidia\n"<<endl;
				cout<<"(2)Nome do autor\n"<<endl;
				
				cin>>tipoPesquisa;
				imprimeLinhas();
			}
			
			if(tipoPesquisa==1){
				
				cin.ignore();
				
				cout<<"Digite o titulo da multimidia que voce deseja pesquisar:\n"<<endl;
				
				getline(cin,nomeMultimidia);
				imprimeLinhas();
				
				acervo->procuraMultimidia(nomeMultimidia,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
				
			if(tipoPesquisa==2){
				
				cin.ignore();
				
				cout<<"Digite o autor da multimidia que voce deseja pesquisar:\n"<<endl;
				
				getline(cin,autorMultimidia);
				imprimeLinhas();
				
				acervo->procuraLivro(autorMultimidia,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
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

		while(operacao<1||operacao>9){
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4/5/6/7/8/9)\n"<<endl;
			
			cout<<"(1)Adicionar livro ao acervo da bibliteca\n"<<endl;
			cout<<"(2)Remover livro do acervo da biblioteca\n"<<endl;
			cout<<"(3)Adicionar multimidia ao acervo da bibliteca\n"<<endl;
			cout<<"(4)Remover multimidia do acervo da biblioteca\n"<<endl;
			cout<<"(5)Cadastrar novo usuario da biblioteca\n"<<endl;
			cout<<"(6)Cadastrar novo funcionario da biblioteca\n"<<endl;
			cout<<"(7)Imprimir colecao de livros\n"<<endl;
			cout<<"(8)Imprimir colecao de multimidia\n"<<endl;
			cout<<"(9)Fazer logoff\n"<<endl;
			
			cin>>operacao;
			imprimeLinhas();
		}
		
		if(operacao == 1){
			
			cin.ignore();
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer adicionar:\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);		
			getline(cin,editoraLivro);
			imprimeLinhas();
					
			funcionario->adicionarLivros(acervo,nomeLivro,autorLivro,editoraLivro);
			std::cout<<"Livro adicionado com sucesso\n"<<std::endl;
			imprimeLinhas();
			operacao=0;
		}
			
		
		if(operacao == 2){
			
			cin.ignore();
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer remover:\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);			
			getline(cin,editoraLivro);
			imprimeLinhas();
			
			funcionario->removerLivros(acervo,nomeLivro,autorLivro,editoraLivro);
			operacao=0;
		}	
		
		
		if(operacao == 3){
			
			cin.ignore();
			
			cout<<"Digite o titulo, o autor,a produtora e o tipo da multimidia que voce quer adicionar:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			getline(cin,produtoraMultimidia);
			imprimeLinhas();
			
			cin>>tipoMultimidia;
			
			funcionario->adicionarMultimidias(acervo,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia);
			std::cout<<"Multimidia adicionada com sucesso\n"<<std::endl;	
			imprimeLinhas();
			operacao=0;
		}	

		if(operacao == 4){
			
			cin.ignore();
			
			cout<<"Digite o titulo, o autor,a produtora e o tipo da multimidia que voce quer remover:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			getline(cin,produtoraMultimidia);
			cin>>tipoMultimidia;
			imprimeLinhas();
			
			funcionario->removerMultimidias(acervo,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia);
			operacao=0;
		}			
		
		if(operacao==5){
			
			cin.ignore();
			
			cout<<"Digite o nome completo:\n"<<endl;
			
			getline(cin,nomeUsuario);
			imprimeLinhas();
			
			cout<<"Digite o id (numero inteiro) e uma nova senha para o usuario:\n"<<endl;
			cin>>userUsuario>>senhaUsuario;
			imprimeLinhas();
			
			if(administrador->pesquisaUsuario(userUsuario,senhaUsuario)){
				cout<<"Erro: esse usuario ja esta cadastrado\n"<<endl;
				imprimeLinhas();
				operacao=0;
			}
			else
				administrador->setUsuarioCadastrado(funcionario->cadastrarUsuario(nomeUsuario,senhaUsuario,userUsuario));
				operacao=0;
		}
		
		if(operacao==6){
			
			cin.ignore();
			
			cout<<"Digite o nome completo:\n"<<endl;
			getline(cin,nomeFuncionario);
			imprimeLinhas();
			
			cout<<"Digite o id (numero inteiro) e uma nova senha para o funcionario:\n"<<endl;
			cin>>userFuncionario>>senhaFuncionario;
			imprimeLinhas();
			
			if(administrador->pesquisaFuncionario(userFuncionario,senhaFuncionario)){
				cout<<"Erro: esse funcionario ja esta cadastrado\n"<<endl;
				imprimeLinhas();
				operacao=0;
			}
			else
				administrador->setFuncionarioCadastrado(funcionario->cadastrarFuncionario(nomeFuncionario,senhaFuncionario,userFuncionario));	
				operacao=0;
		}
		
		if(operacao == 7){	
			acervo->listarLivros();
			operacao=0;
		}
			
		if(operacao == 8){				
			acervo->listarMultimidia();
			operacao=0;
		}
		
		if(operacao == 9){
			menu=0;
		}
	}	
}

void Biblioteca::desalocaDados(){
	delete usuario;
	delete funcionario;
	delete administrador;
	delete acervo;
}
	
Biblioteca::~Biblioteca(){

}
