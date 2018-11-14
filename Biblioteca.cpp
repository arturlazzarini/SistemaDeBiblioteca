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
	
	while(interfacea<1||interface>2){
		
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
					
					acessoPermitido=login(usuario,administrador,tipoUsuario)
					return acessoPermitido;
				}
						
				if(c == 'n')
					throw LoginInvalido();
			}
		}
			
			catch(LoginInvalido& invalido){
					
				cout<<"Voce deseja realizar um cadastro na biblioteca?(s/n)"<<endl;
				cin>>char cadastrar;
					
				if(cadastrar == 's')
					funcionario->cadastrarUsuario(usuario);
					
				if(cadastrar == 'n')
					telaInicio=0;	
			}
	}
	
	return 0;	
}	

//login retorna 1 caso o acesso seja valido
int Biblioteca::login(Pessoa *p,int tipoUsuario){
	
	cout<<"Digite O seu ID e sua senha"<<endl;
	
	cin>>p->nome>>p->senha;
	
	if(tipoUsuario == pessoaUsuario){
		
		if()
			return 1;
		
		else
			throw LoginInvalido();
	}
		
	if(tipoUsuario == pessoaFuncionario){
		
		if()
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
		
		while(operacao<1||operacao>4){
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4)"<<endl;
			
			cout<<"Adicionar itens do acervo da bibliteca(1)"<<endl;
			cout<<"Remover itens do acervo da biblioteca(2)"<<endl;
			cout<<"Cadastrar novo usuario da biblioteca(3)"<<endl;
			cout<<"Sair do sistema(4)"<<endl;
			
			cin>>operacao;
		}
		
		if(operacao==1)
			funcionario->adicionarItens();
		
		if(operacao==2)	
			funcionario->removerItens();
		
		if(operacao==3)	
			funcionario->cadastrarUsuario();
		
		if(operacao==4)
			menu=0;
	}	
}

void Biblioteca::desalocaDados(){
	
}
