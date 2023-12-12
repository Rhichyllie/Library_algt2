#ifndef SISTEMA_HPP
#define SISTEMA_HPP
#include <string>

using namespace std;

struct Livraria{
  string titulo;
  string autor;
  int ano;
  int nCopias;
  int livrosID;
  int nPegos;
};

struct Usuario{
  string nome;
  int usuariosID;
  int emprestados;
  string livrosUsuario;
};

void cadastrar_livro(Livraria *livros, int tamanho);

void cadastrar_usuario(Usuario *usuarios, int tamanho);

void emprestimos_livros(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario);

void devolucao_livros(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario);

void pesquisa_livros(Livraria *livros, int tamanho);

void pesquisa_usuario_livros(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario);

void lista_livros(Livraria *livros, int tamanho);

void controle_multas(Usuario *usuario, int tamanho);

void relatorioDe_uso(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario);

#endif