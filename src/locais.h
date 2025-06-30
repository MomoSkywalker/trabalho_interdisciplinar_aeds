#ifndef LOCAIS_H
#define LOCAIS_H

#include "slem.h"

int buscarLocalPorNome(const char* nome, const Local locais[], int numLocais);
void cadastrarLocal(Local locais[], int &numLocais);
void listarLocais(const Local locais[], int numLocais);
void atualizarLocal(Local locais[], int numLocais);
void excluirLocal(Local locais[], int &numLocais);

#endif