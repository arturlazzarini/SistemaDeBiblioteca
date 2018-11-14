#include "Biblioteca.hpp"

//os numeros que representam e diferenciam usuarios e funcionarios no sistema
const int pessoaUsuario = 1;
const int pessoaFuncionario = 2;

Biblioteca::Biblioteca(){
		
	usuario = nullptr;
	funcionario = nullptr;
	administrador = nullptr;
}
	
Biblioteca::~Biblioteca(){
	
	delete usuario;
	delete funcionario;
	delete administrador;
}

void Biblioteca::interfacePrincipal(){
	
    usuario = new Usuario(); 
	funcionario = new Funcionario();
	administrador= new Gerencia();
	
	determinaInterface();
}

//identifica o tipo da pessoa que acessa o sistema para disponibilizar sua respectiva interface
void Biblioteca::determinaInterface(){
	
	cout<<"Voce deseja acessar o sistema como:"<<endl;
	cout<<"Usuario da Biblioteca(1)"<<endl;
	cout<<"Funcionario da Biblioteca(2)"<<endl;
	
	cin>>int interface;
	
	interfaceUsuario(interface);
}

//interface com login/cadastro e menu para usuario/funcionario
void Biblioteca::interfaceUsuario(int interfaceTipo){
	
	int execucao =1;
	int acesso=0;
	
	while(execucao){
		
		acesso=telaInicial(interfaceTipo);
		
		if(acesso==0)
			cout<<"Acesso Negado"<<endl;

		while(acesso){
			
			if(interface == pessoaUsuario)
				menuUsuario(acesso);
			
			if(interface == pessoaUsuario)
				menuFuncionario;
		}
	}
}

//Tela de inicio comum à interface do usuario e à interface do funcionario
int Biblioteca::telaInicial(int tipoUsuario){
	
	int telaInicio=1
	int acessoPermitido=0;
	
	while(telaInicio){
		
		try{	
			cout<<"Voce possui cadastro na biblioteca?(s/n)"<<endl;
			cin>>char c;
				
			if(c == 's'){
				
				acessoPermitido=login(usuario,administrador,tipoUsuario)
				return acessoPermitido;
			}
					
			if(c == 'n')
				throw LoginInvalido();
			}
			
			catch(LoginInvalido& invalido){
					
				cout<<"Voce deseja realizar um cadastro na biblioteca?(s/n)"<<endl;
				cin>>char cadastrar;
					
				if(cadastrar == 's')
					funcionario.cadastrarUsuario(usuario);
					
				if(cadastrar == 'n')
					telaInicio=0;	
			}
	}
	
	return 0;	
}	

//login retorna 1 caso o acesso seja valido
int Biblioteca::login(Pessoa *p, Gerencia *administracao,int tipoUsuario){
	
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
	
}

void Biblioteca::menuFuncionario(){
	
}

void Biblioteca::desalocaDados(){
	
}
