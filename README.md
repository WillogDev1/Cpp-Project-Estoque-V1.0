Controle de estoque e NoSQL em Cpp<br>
Contendo<br>
* Menu com teclas                   <- Finalizado
* Cadastrar produto         (Create)<- Finalizado
* Ler Produtos cadastrados (Read  )<-Finalizado
* Atualizar produto         (Update)<- Em processo
* Deletar produto           (Delete)<- Em processo<br>

<h1>Menu</h1>

Alterar Cor de letras e fundo do Menu( CMD )
* Usar seta para navegar pelo Menu podendo acessar Sub-menus que contem outras funções<br>
* Futuras implementações:<br>
  * Criar teclas de escapes para navegar pelo menu exemplo:<br>
    * [F1] - Sair / [F2] - Criar Produto / [F3] - Atualizar / [F4] - Faz alguma coisa<br>

<h1>Cadastrar Produto</h1>

* Sub-menu cadastrar produto
  * Cadastrar produto "Nome"
  * Cadastrar "Quantidade"
    * Salvar como nome.txt
    * Dentro do txt salvar quantidade
    * Salvar na pasta C:\db_NoSQL\produtos
  * Futuras implementações:
    * Salvar em forma de JSON

<h1>Ler produtos cadastrados & Atualizar produto</h1>

* Sub-menu para ver produtos cadastrador
  * Listar diretorio C:\db_NoSQL\produtos
  * Listar arquivos e indexar
  * Permitir a navegação pelos arquivos com a seta<br>
  
    * Futuras implementações:
      * Selecionar o arquivo pelo ENTER
      * Visiualizar Quantidade
      * Alterar Quantidade

<h1>Deletar Produto</h1>

* Criar Sub-menu "Deletar"
  * Listar diretorio C:\db_NoSQL\produtos
  * Permitir a navegação pelos arquivos com a seta
  * Selecionar o arquivo pelo ENTER
  * Perguntar Excluir [S/N]?
  
