Projeto: Central de Operações Autônomas — Setor VX27

IDEIA –  
Uma empresa de monitoramento industrial chamada Orbytec Sistemas Integrados iniciou  
recentemente a automação parcial de seus centros logísticos. Parte da operação agora depende de  
pequenos módulos computacionais responsáveis por registrar movimentações, controlar operadores e  
acompanhar eventos críticos do ambiente.

Entretanto, durante os últimos meses, diversos problemas começaram a surgir:  
• registros operacionais inconsistentes;  
• perda de informações durante trocas de turno;  
• equipamentos associados a setores incorretos;  
• operadores executando ações simultâneas incompatíveis;  
• falhas no rastreamento de eventos críticos;• relatórios divergentes entre departamentos.  

A empresa decidiu então contratar uma equipe de engenharia para desenvolver um protótipo  
operacional em linguagem C capaz de auxiliar no gerenciamento interno do setor VX27.  
Porém, os documentos recebidos pelas equipes apresentam lacunas, ambiguidades e regras  
parcialmente conflitantes, pois os próprios supervisores da empresa discordam sobre alguns  
comportamentos do sistema.  

Assim, além de programar, será necessário interpretar cenários, modelar estruturas adequadamente e
justificar decisões técnicas.

PROJETO  
Desenvolver, em linguagem C, um sistema para controle operacional de um setor automatizado  
Os Times deverão interpretar as necessidades da empresa, conversar com a empresa (representada pela  
professora), decidir e justificar suas decisões de implementação.

Considere que a empresa possui 150 equipamentos e 50 operadores  

O sistema deverá ser funcional tendo um fluxo contínuo de operação e execução com um menu principal
e as funcionalidades mínimas obrigatórias serão:

• Cadastro de Operadores  
  Permite a inserção de operadores, que devem possuir as seguintes informações:  
    • ID do operador (constituído de 4 dígitos)  
    • Nome do Operador (máximo 70 caracteres)  
    • Setor (constituído de duas letras e dois dígitos, nessa ordem)  
    • Nível Operacional - representa a experiencia do profissional, podendo ser: básico,  
      intermediário ou supervisor técnico  
    • Status - indica a disponibilidade do operador: ativo (disponível), ocupado, inativo(fora de  
      operação) e bloqueado(impedido temporariamente)  
    • Quantidade de operações realizadas  
    
• Cadastro do Equipamento / Módulo  
  Permite a inserção dos Equipamentos e/ou Módulos, que devem possuir as seguintes informações:  
    • ID do Equipamento/Módulo (constituído de 1 letra e 2 dígitos, nessa ordem)  
    • Tipo - é a categoria operacional, o Time pode definir seus próprios tipos, como por exemplo:  
      Drone, Sensor, Scanner, Braço Robótico, etc  
    • Setor Associado (constituído de duas letras e dois dígitos, nessa ordem)  
    • Estado Operacional – é a situação atual do equipamento:  
         Ativo – operando normalmente  
         Inativo – desligado, apto a se tornar ativo  
         Manutenção – indisponível temporariamente  
    • ID do Operador (constituído de 4 dígitos)  
    • Nível de Prioridade – é a importância operacional do equipamento, ajuda o sistema a decidir  
      quais equipamentos / módulos devem receber maior atenção:  
         Baixa – operação simples  
         Média – importante  
         Alta – Operação Crítica  
        
• Atualização  
  Permitirá que o sistema:  
    • Altere o Estado Operacional do Equipamento  
    • Atualize a disponibilidade dos Operadores  
    • Mover equipamentos entre Setores  
    • Registrar ocorrências  
    • Desativar Registros  
    
• Consulta Registros, como:    
    • Pesquisar se um operador está livre pelo nome e /ou pelo ID  
    • Pesquisar o estado operacional de um equipamento  
    • Pesquisar quais os operadores livres para operar um determinado equipamento em um  
      determinado setor  
      
• Relatórios Operacionais  
  O sistema deverá gerar relatórios simples contendo informações como:  
    • Listar todos os operadores e suas respectivas informações  
    • Listar o ID, nome e status dos operadores de um específico setor  
    • Listar todos os equipamentos (ID, TIPO e ESTADO OPERACIONAL) de um determinado Setor  
    • Listar o ID, Nome dos Operadores e Equipamento (ID e TIPO) de um determinado setor  
    • Listar os operadores, de cada setor, com o maior número de operações realizadas  
    
O Time deverá construir o sistema não permitindo duplicidade de operadores. Avaliar e decidir se um  
operador pode controlar simultaneamente vários equipamentos, se as prioridades alteram  
automaticamente o processamento.  
      
Essas decisões tomadas pelo time devem ser conversadas com a empresa (professora) e justificadas  
no relatório a ser entregue  
