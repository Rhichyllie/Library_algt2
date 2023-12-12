#include <iostream>
#include "sistema.hpp"

using namespace std;

int main() {
  int tamanho_livraria = 0;
  cout << "Quantos livros deseja cadastrar? " << endl;
  cin >> tamanho_livraria;
  cout << endl;
  Livraria *livros = new Livraria[tamanho_livraria];
  // Alocando dinamicamente os vetores para livros
  
  int tamanho_usuario = 0;
  cout << "Quantos usuários serão cadastrados? " << endl;
  cin >> tamanho_usuario;
  cout << endl;
  Usuario *usuarios = new Usuario[tamanho_usuario];
  // Alocando dinamicamente os vetores para usuários
  
int opcao;
  do {
    cout << "MENU:" << endl;
    cout << "1. Cadastro de Livro" << endl;
    cout << "2. Cadastro de Usuário" << endl;
    cout << "3. Empréstimo de Livro" << endl;
    cout << "4. Devolução de Livro" << endl;
    cout << "5. Pesquisa de Livro" << endl;
    cout << "6. Listagem de Livros" << endl;
    cout << "7. Pesquisa de Livros por Usuário" << endl;
    cout << "8. Controle de Multas" << endl;
    cout << "9. Relatório de Uso" << endl;
    cout << "0. Sair" << endl;
    cout << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    cout << endl;
    
    switch (opcao) {
      case 1:
        cadastrar_livro(livros, tamanho_livraria);
        cout << endl;
        break;
      case 2:
        cadastrar_usuario(usuarios, tamanho_usuario);
        cout << endl;
        break;
      case 3:
        emprestimos_livros(livros, usuarios, tamanho_livraria, tamanho_usuario);
        cout << endl;
        break;
      case 4:
        devolucao_livros(livros, usuarios, tamanho_livraria, tamanho_usuario);
        cout << endl;
        break;
      case 5:
        pesquisa_livros(livros, tamanho_livraria);
        cout << endl;
        break;
      case 6:
        lista_livros(livros, tamanho_livraria);
        cout << endl;
        break;
      case 7:
        pesquisa_usuario_livros(livros, usuarios, tamanho_livraria, tamanho_usuario);
        cout << endl;
        break;
      case 8:
        controle_multas(usuarios, tamanho_usuario);
        cout << endl;
        break;
      case 9:
        relatorioDe_uso(livros, usuarios, tamanho_livraria, tamanho_usuario);
        cout << endl;
        break;
      case 0:
        // Encerrar o programa
        break;
      default:
        cout << "Opção inválida." << endl;
    }
  } while (opcao != 0);
  return 0;
}