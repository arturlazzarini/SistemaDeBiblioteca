#include "Biblioteca.hpp"

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

void Biblioteca::determinaInterface(){
	
	cout<<"Voce deseja acessar o sistema como:"<<endl;
	cout<<"Usuario da Biblioteca(1)"<<endl;
	cout<<"Funcionario da Biblioteca(2)"<<endl;
	
	cin>>int interface;
	
	interfaceUsuario(interface);
}

void Biblioteca::interfaceUsuario(int interfaceTipo){
	
	int execucao =1;
	int acesso=0;
	
	while(execucao){
		
		acesso=telaInicial();

		while(acesso){
			
			if(interface==1)
				menuUsuario(acesso);
			
			if(interface==2)
				menuFuncionario(acesso);
		}
	}
}

//Tela de inicio comum à interface do usuario e à interface do funcionario
int Biblioteca::telaInicial(){
	
	int telaInicio=1
	int acessoPermitido=0;
	
	while(telaInicio){
		
		try{	
			cout<<"Voce possui cadastro na biblioteca?(s/n)"<<endl;
			cin>>char c;
				
			if(c == 's'){
				
				acessoPermitido=login(usuario,administrador)
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

int Biblioteca::login(Pessoa *p, Gerencia *administracao,int tipoUsuario){
	
	cout<<"Digite O seu ID e sua senha"<<endl;
	
	cin>>p->nome>>p->senha;
	
	if(tipoUsuario == 1){
		
		if()
			return 1;
		
		else
			throw LoginInvalido();
	}
		
	if(tipoUsuario == 2){
		
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














