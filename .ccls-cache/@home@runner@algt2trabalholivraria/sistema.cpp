#include <iostream>
#include "sistema.hpp"

int dataEntrega, entrega;

void cadastrar_livro(Livraria *livros, int tamanho){
  string titulo;
  string autor;
  int ano;
  int nCopias;
  int livrosID;
  int nPegos;

  for (int i = 0; i < tamanho; i++){
    cout << endl;
    cout << "Título do Livro? " << endl;
    cin >> livros[i].titulo;
    cout << endl;
    cout << "Nome do autor? " << endl;
    cin >> livros[i].autor;
    cout << endl;
    cout << "Ano de publicação? " << endl;
    cin >> livros[i].ano;
    cout << endl;
    cout << "Número de cópias? " << endl;
    cin >> livros[i].nCopias;
    livros[i].livrosID = i;
    cout << endl;
    livros[i].nPegos = 0;
    cout << "Livro cadastrado com sucesso!" << endl;
    cout << "------------------------------------------" << endl;
  }
  cout << "Cadastrado completo!" << endl;
  cout << "------------------------------------------" << endl;
}

void cadastrar_usuario(Usuario *usuarios, int tamanho){
  string nome;
  int usuariosID;
  int emprestados;
  string livrosUsuario;

  for (int i = 0; i < tamanho; i++){
    cout << "Seu nome: " << endl;
    cin >> usuarios[i].nome;
    cout << endl;
    usuarios[i].usuariosID = i;
    usuarios[i].emprestados = 0;
  }
  cout << "------------------------------------------" << endl;
}

void emprestimos_livros(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario) {
    int op_idLivro, op_idUsuario, dataInical;

    cout << "Digite o ID do livro: ";
    cin >> op_idLivro;
    cout << endl;
    cout << "Digite o ID do usuário: ";
    cin >> op_idUsuario;
    cout << endl;
    
    do {
      cout << "Digite o dia de retirada: " << endl;
      cin >> dataInical;
    }while(entrega <= 0 && entrega > 31);
  
    dataEntrega = dataInical + 21;

    // Conferir a validade das IDs do livro e do usuário
    if (op_idLivro >= 0 && op_idLivro < tamanho_livraria && op_idUsuario >= 0 && op_idUsuario < tamanho_usuario) {
      
        //Alocando dinamicamente as escolhas aos vetores já criados
        Livraria &livro = livros[op_idLivro];
        Usuario &usuario = usuarios[op_idUsuario];

        // Ver se o livro está disponível
        if (livro.nCopias > 0) {
            usuario.emprestados++;
            livro.nCopias--;
            livro.nPegos++;
            usuario.livrosUsuario = livro.titulo;
            cout << "Livro emprestado com sucesso!" << endl;
            cout << endl;
        } else {
            cout << "O livro não disponível para empréstimo." << endl;
            cout << endl;
        }
    } else {
        cout << "ID do livro ou do usuário inválido." << endl;
        cout << endl;
    }
}

void devolucao_livros(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario) {
  int op_idLivro = 0, op_idUsuario = 0, dataInical;

  cout << "Digite o ID do livro: ";
  cin >> op_idLivro;
  cout << endl;
  cout << "Digite o ID do usuário: ";
  cin >> op_idUsuario;
  cout << endl;
  
  do {
      cout << "Digite o dia de entrega: " << endl;
      cin >> entrega;
    }while(entrega <= 0 && entrega > 31);
  
  if (op_idLivro >= 0 && op_idLivro < tamanho_livraria && op_idUsuario >= 0 && op_idUsuario < tamanho_usuario){
    Livraria &livro = livros[op_idLivro];
    Usuario &usuario = usuarios[op_idUsuario];

    if (livro.nCopias >= 0){
      usuario.emprestados--;
      livro.nCopias++;
      cout << "Livro devolvido com sucesso!";
    } else {
      cout << "O livro não disponível para empréstimo." << endl;
      cout << endl;
    }
  }
}

void lista_livros(Livraria *livros, int tamanho){
  for (int i = 0; i < tamanho; i++){
    Livraria livro = livros[i];
    cout << i << ". " << livro.titulo << endl; 
    cout << "Total de cópias disponíveis = " << livro.nCopias << endl;
    cout << endl;
  }
}

void pesquisa_livros(Livraria *livros, int tamanho){
  int op_idLivro, totalCopias;

  cout << "Digite o ID do livro que deseja pesquisar: ";
  cin >> op_idLivro;
  
  for (int i = 0; i < tamanho; i++){
    
    Livraria &livro = livros[op_idLivro];
    totalCopias = livro.nCopias;
    
    if (i == op_idLivro && livro.nCopias > 0){
      cout << "Livro disponível: " << livro.titulo << endl;
      cout << "Total de cópias disponíveis = " << totalCopias << endl;
    } else {
      cout << "O livro não disponível no momento, tente novamente outra hora." << endl;
      cout << endl;
    }
  }
}

void pesquisa_usuario_livros(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario) {
  int op_idLivro, op_idUsuario;

  cout << "Digite o ID do livro que deseja pesquisar: ";
  cin >> op_idLivro;
  cout << endl;
  cout << "Digite o ID do usuário que deseja pesquisar: ";
  cin >> op_idUsuario;
  cout << endl;

  for (int i = 0; i < tamanho_livraria && tamanho_usuario; i++){
    Livraria &livro = livros[op_idLivro];
    Usuario &usuario = usuarios[op_idUsuario];

    if (op_idLivro >= 0 && op_idLivro < tamanho_livraria && op_idUsuario >= 0 && op_idUsuario < tamanho_usuario){
      if (i == op_idUsuario) {
        cout << "Nome do Usuario: " << usuario.nome << endl;
        cout << "Livros em seu nome: " << usuario.livrosUsuario << endl;
      } 
    } else {
      cout << "Livro ou Usuario Errado!" << endl;
    }
  } 
}

void controle_multas(Usuario *usuario, int tamanho){
  
  if (entrega > dataEntrega) {
    cout << "Livro devolvido com atraso multa do valor de R$ 30.00" << endl;
  } else {
    cout << "Sem multas!!!" << endl;
  }
}

void relatorioDe_uso(Livraria *livros, Usuario *usuarios, int tamanho_livraria, int tamanho_usuario){
  
  int maisEmprestados = 0;
  
  cout << "Livros mais emprestados: ";
  for(int i = 0; i < tamanho_livraria; i++){
    // alocando dinamicamente minha nova var
    Livraria &livro = livros[i];
    if(livro.nPegos > maisEmprestados){
      cout << livro.titulo;
      cout << endl;
    }
    if(livro.nPegos == 0){
      cout << "Nunca foi emprestado!!!";
      cout << livro.titulo;
      cout << endl;
    }   
  } 
}