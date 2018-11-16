#ifndef GERENCIA_HPP
#define GERENCIA_HPP

#include "Pessoa.hpp"
#include "Usuario.hpp"
#include "funcionario.hpp"
#include "Acervo.hpp"
#include <vector>

using std::vector;
using std::cout;
using std::cin;

class Gerencia{
	
	private:
		vector <Usuarios> _usuariosCadastrados;
		vector <Funcionarios> _funcionariosCadastrados;
		
	public:
		Gerencia();
		void setUsuarioCadastrado(Usuario);
		void setFuncionarioCadastrado(Funcionario);
		int pesquisaFuncionario(int,string);
		int pesquisaUsuario(int,string);

};

#endif
