#include "doctest.h"

#include "Pessoa.hpp"

TEST_CASE("Testa Gets e Sets"){

	Pessoa nova;
	nova.setNome("Admin");
	nova.setSenha("0000");
	nova.setId(0000);

	if(nova.getNome() == "Admin" && nova.getSenha() == "0000"){
		CHECK(nova.getId() == 0000);
	}

}

TEST_CASE("Testa Construtor"){

	Pessoa nova("Admin", "0000", 0000);

	if(nova.getId() == 0000){
		CHECK(nova.getNome() == "Admin");
		CHECK(nova.getSenha() == "0000");
	}

}