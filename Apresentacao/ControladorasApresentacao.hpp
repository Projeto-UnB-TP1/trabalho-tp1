#ifndef CONTROLADORASAPRESENTACAO_HPP
#define CONTROLADORASAPRESENTACAO_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "../Interfaces/Interfaces.hpp"

using namespace std;

/**
 * @file ControladorasApresentacao.hpp
 * @brief Declaração das classes da camada de apresentação.
 *
 * @details A camada de apresentação é responsável pela interação com o usuário, por
 * console (cin e cout), e pela validação dos dados de entrada, que é feita pelas
 * classes de domínio. Ela depende somente das interfaces IServico* da camada de
 * serviço. Cada controladora realiza uma interface IApresentacao*; a documentação de
 * cada método é a da interface realizada.
 */

/**
 * @brief Funções de apoio à interação com o usuário, compartilhadas pelas controladoras
 * de apresentação.
 *
 * @details Reúne a leitura de dados do teclado e a apresentação de entidades na tela.
 * Todos os métodos são estáticos e podem ser chamados sem criar um objeto,
 * por exemplo Tela::lerCampo("Nome: ").
 */
class Tela{
    public:
        /**
         * @brief Apresenta um rótulo e lê uma linha digitada pelo usuário.
         * @param rotulo Texto apresentado antes da leitura.
         * @return Texto digitado; vazio se o usuário apenas apertou Enter.
         */
        static string lerCampo(string rotulo);

        /**
         * @brief Lê a opção de um menu.
         * @return A opção, de 0 a 9; -1 se o texto digitado não é um único dígito; 0 se a
         *         entrada terminou, o que encerra os menus.
         */
        static int lerOpcao();

        /**
         * @brief Converte um texto de até 3 dígitos em número inteiro.
         * @param texto Texto com o número.
         * @return O número; 0 se o texto estiver vazio, for longo demais ou tiver algo que
         *         não seja dígito.
         */
        static int converterNumero(string texto);

        /**
         * @brief Lê um identificador e valida o seu formato.
         * @param rotulo Texto apresentado antes da leitura.
         * @param identificador Ponteiro que recebe o identificador lido.
         * @return true se o identificador é válido; false caso contrário, após mostrar o erro.
         */
        static bool lerIdentificador(string rotulo, Identificador *identificador);

        /**
         * @brief Verifica se a pessoa com o e-mail informado tem papel GESTOR.
         * @param cntr Serviço de pessoas usado na consulta.
         * @param email E-mail da pessoa.
         * @return true se a pessoa existe e é GESTOR; false caso contrário.
         */
        static bool ehGestor(IServicoPessoas *cntr, Email email);

        /**
         * @brief Substitui um texto vazio por um traço, para apresentação.
         * @param valor Texto a ser apresentado.
         * @return O próprio texto; "-" se ele estiver vazio.
         */
        static string valorOuTraco(string valor);

        /**
         * @brief Apresenta um tempo em dias, horas e minutos.
         * @param rotulo Texto apresentado antes do tempo.
         * @param minutos Tempo em minutos.
         */
        static void mostrarTempo(string rotulo, int minutos);

        /**
         * @brief Apresenta todos os dados de um projeto.
         * @param projeto Projeto a ser apresentado.
         */
        static void mostrarProjeto(Projeto projeto);

        /**
         * @brief Apresenta todos os dados de um quadro.
         * @param quadro Quadro a ser apresentado.
         */
        static void mostrarQuadro(Quadro quadro);

        /**
         * @brief Apresenta todos os dados de um cartão de atividade.
         * @param cartao Cartão a ser apresentado.
         */
        static void mostrarCartao(CartaoDeAtividade cartao);

        /**
         * @brief Apresenta uma lista de identificadores, um por linha.
         * @param identificadores Lista a ser apresentada.
         * @param vazio Mensagem apresentada se a lista estiver vazia.
         */
        static void listarIdentificadores(list<Identificador> identificadores, string vazio);
};

/**
 * @brief Controladora de apresentação que coordena o sistema.
 *
 * @details Apresenta a tela inicial (entrar, cadastrar pessoa ou encerrar) e, depois da
 * autenticação, o menu principal, que encaminha o usuário para os módulos de pessoas,
 * projetos, quadros e cartões de atividade. A sessão termina quando o usuário sai ou
 * exclui a própria conta.
 */
class CntrApresentacaoControle{
    private:
        Email email;
        IApresentacaoPessoas *cntrApresentacaoPessoas;
        IApresentacaoProjetos *cntrApresentacaoProjetos;
        IApresentacaoQuadros *cntrApresentacaoQuadros;
        IApresentacaoCartoes *cntrApresentacaoCartoes;
        IServicoPessoas *cntrServicoPessoas;
        void executarSessao();
    public:
        /**
         * @brief Apresenta a tela inicial até o usuário escolher encerrar.
         */
        void executar();

        /**
         * @brief Define o módulo de apresentação de pessoas.
         * @param cntr Ponteiro para o módulo.
         */
        void setCntrApresentacaoPessoas(IApresentacaoPessoas *cntr);

        /**
         * @brief Define o módulo de apresentação de projetos.
         * @param cntr Ponteiro para o módulo.
         */
        void setCntrApresentacaoProjetos(IApresentacaoProjetos *cntr);

        /**
         * @brief Define o módulo de apresentação de quadros.
         * @param cntr Ponteiro para o módulo.
         */
        void setCntrApresentacaoQuadros(IApresentacaoQuadros *cntr);

        /**
         * @brief Define o módulo de apresentação de cartões de atividade.
         * @param cntr Ponteiro para o módulo.
         */
        void setCntrApresentacaoCartoes(IApresentacaoCartoes *cntr);

        /**
         * @brief Define o módulo de serviço de pessoas, usado para ler os dados do usuário logado.
         * @param cntr Ponteiro para o módulo.
         */
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

/**
 * @brief Controladora de apresentação do módulo de pessoas.
 *
 * @details Realiza IApresentacaoPessoas. No menu de pessoas, o usuário pode ler os dados
 * de qualquer pessoa (sem a senha), listar as pessoas e atualizar ou excluir a própria
 * conta. Na atualização só o nome e a senha podem ser alterados; o e-mail e o papel não
 * mudam.
 */
class CntrApresentacaoPessoas:public IApresentacaoPessoas{
    private:
        IServicoPessoas *cntr;
        void ler();
        void atualizar(Email email);
        bool excluir(Email email);
        void listar();
    public:
        bool autenticar(Email *email);
        void cadastrar();
        void executar(Email email);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

/**
 * @brief Controladora de apresentação do módulo de projetos.
 *
 * @details Realiza IApresentacaoProjetos. Ler e listar estão disponíveis para todos; criar,
 * atualizar e excluir aparecem somente para usuários com papel GESTOR. O gestor de um
 * projeto criado é o usuário logado.
 */
class CntrApresentacaoProjetos:public IApresentacaoProjetos{
    private:
        IServicoProjetos *cntr;
        IServicoPessoas *cntrServicoPessoas;
        void criar(Email email);
        void ler();
        void atualizar();
        void excluir();
        void listar();
    public:
        void executar(Email email);
        void setCntrServicoProjetos(IServicoProjetos *cntr);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

/**
 * @brief Controladora de apresentação do módulo de quadros.
 *
 * @details Realiza IApresentacaoQuadros. Ler e listar os quadros de um projeto estão
 * disponíveis para todos; criar, atualizar e excluir aparecem somente para usuários com
 * papel GESTOR.
 */
class CntrApresentacaoQuadros:public IApresentacaoQuadros{
    private:
        IServicoQuadros *cntr;
        IServicoPessoas *cntrServicoPessoas;
        void criar();
        void ler();
        void atualizar();
        void excluir();
        void listar();
    public:
        void executar(Email email);
        void setCntrServicoQuadros(IServicoQuadros *cntr);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

/**
 * @brief Controladora de apresentação do módulo de cartões de atividade.
 *
 * @details Realiza IApresentacaoCartoes. Ler, listar, mover e o submenu de métricas
 * (tempo de ciclo, lead time, médias e WIP) estão disponíveis para todos; criar, atualizar
 * e excluir aparecem somente para usuários com papel GESTOR. Os tempos são apresentados
 * em dias, horas e minutos.
 */
class CntrApresentacaoCartoes:public IApresentacaoCartoes{
    private:
        IServicoCartoes *cntr;
        IServicoPessoas *cntrServicoPessoas;
        void criar();
        void ler();
        void atualizar();
        void excluir();
        void listar();
        void mover();
        void executarMetricas();
        void lerTempoCiclo();
        void lerTempoCicloMedio();
        void lerLeadTime();
        void lerLeadTimeMedio();
        void lerWIP();
    public:
        void executar(Email email);
        void setCntrServicoCartoes(IServicoCartoes *cntr);
        void setCntrServicoPessoas(IServicoPessoas *cntr);
};

#endif
