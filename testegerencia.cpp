#define CATCH_CONFIG_ALL_PARTS
#include "catch.hpp"

#include "Gerencia.hpp"
#include "Pessoa.hpp"
#include "Usuario.hpp"
#include "Funcionario.hpp"

TEST_CASE("Testa cadastro e pesquisa de usuarios"){

	Gerencia atual;

	Usuario novo("Admin", "0000", 0000);

	if(atual.pesquisaUsuario(0000, "0000") == 0){
		atual.setUsuarioCadastrado(novo);
		CHECK(atual.pesquisaUsuario(0000, "0000") == 1);
	}
}

TEST_CASE("Testa cadastro e pesquisa de funcionario"){

	Gerencia atual;

	Funcionario novo("Admin", "0000", 0000);

	if(atual.pesquisaFuncionario(0000, "0000") == 0){
		atual.setFuncionarioCadastrado(novo);
		CHECK(atual.pesquisaFuncionario(0000, "0000") == 1);
	}

}
