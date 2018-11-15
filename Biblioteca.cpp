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
//------------------------------------------------------------------------------------------------------					
				if(cadastrar == 's')
					usuario->cadastrarUsuario(usuario);
					
				if(cadastrar == 'n')
					telaInicio=0;	
			}
	}
	
	return 0;	
}	

//login retorna 1 caso o acesso seja valido
int Biblioteca::login(Pessoa *p,int tipoUsuario){
	
	string nomeUsuario;
	string senhaUsuario
	
	cout<<"Digite O seu ID e sua senha"<<endl;
	
	cin>>nomeUsuario>>senhaUsuario;
	
	p->setNome(nomeUsuario);
	p->setSenha(senhaUsuario);
	
	if(tipoUsuario == pessoaUsuario){
		
		if(pesquisaUsuario())
			return 1;
		
		else
			throw LoginInvalido();
	}
		
	if(tipoUsuario == pessoaFuncionario){
		
		if(pesquisaFuncionario())
			return 1;
		
		else
			throw LoginInvalido();
	}	
}

void Biblioteca::menuUsuario(){
	
	int menu=1;
	int operacao=0;
	
	while(menu){
		
		while(operacao<1||operacao>4){
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4)"<<endl;
			
			cout<<"Reservar itens(1)"<<endl;
			cout<<"Alugar itens(2)"<<endl;
			cout<<"Devolver itens(3)"<<endl;
			cout<<"Sair do sistema(4)"<<endl;
			
			cin>>operacao;
		}
		
		if(operacao==1)
			usuario->reservarItens();
		
		if(operacao==2)	
			usuario->alugarItens();
		
		if(operacao==3)	
			usuario->devolverItens();
		
		if(operacao==4)
			menu=0;
	}	
}

void Biblioteca::menuFuncionario(){
	
		int menu=1;
		int operacao=0;
	
	while(menu){
		
		while(operacao<1||operacao>7){
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4/5/6/7)"<<endl;
			
			cout<<"Adicionar livro ao acervo da bibliteca(1)"<<endl;
			cout<<"Remover livro do acervo da biblioteca(2)"<<endl;
			cout<<"Adicionar multimidia do acervo da bibliteca(3)"<<endl;
			cout<<"Remover multimidia do acervo da biblioteca(4)"<<endl;
			cout<<"Cadastrar novo usuario da biblioteca(5)"<<endl;
			cout<<"Cadastrar novo funcionario da biblioteca(6)"<<endl;
			cout<<"Sair do sistema(7)"<<endl;
			
			cin>>operacao;
		}
		
		if(operacao==1)
			funcionario->adicionarLivro();
		
		if(operacao==2)	
			funcionario->removerLivro();
		
		if(operacao==3)
			funcionario->adicionarMultimidia();
		
		if(operacao==4)	
			funcionario->removerMultimidia();
		
		if(operacao==5)	
			funcionario->cadastrarUsuario();
		
		if(operacao==6)	
			funcionario->cadastrarFuncionario();
		
		if(operacao==7)
			menu=0;
	}	
}

void Biblioteca::desalocaDados(){
	
}
