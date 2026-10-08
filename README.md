# Oferta de Disciplinas do IC/UFAL

Segundo projeto da disciplina de **Estrutura de Dados** do curso de Ciência da Computação do Instituto de Computação da UFAL (IC/UFAL), em 2025.

## Sobre

Programa em C que gera a oferta de disciplinas do IC — com salas, horários e professores — a partir dos dados das disciplinas, das salas, da disponibilidade dos professores e do histórico dos alunos. Todo o processamento usa **estruturas de dados dinâmicas** (listas encadeadas).

## Requisitos do problema

- Usar apenas estruturas dinâmicas.
- Cada professor pode ministrar no máximo 3 disciplinas por semestre.
- Uma disciplina pode ser dividida entre mais de um professor.
- O professor deve ser alocado no menor número de dias possível.
- As disciplinas obrigatórias têm a maior prioridade.

## Funcionalidades

- Lê as disciplinas (`materias.txt`), as salas (`salas.txt`) e os professores com as disciplinas que podem ministrar (`professores.txt`).
- Lê os históricos dos alunos em sequência (`historico_1.txt`, `historico_2.txt`, …) para considerar a demanda, incluindo as optativas de cada ênfase.
- Aloca as disciplinas nas salas, verificando conflitos de horário.
- Atribui os professores às disciplinas alocadas.
- Mostra a oferta no terminal e salva o resultado em `oferta.txt`.

## Como rodar

Na raiz do projeto, com o GCC instalado:

```bash
gcc main.c -o main
./main
```

Os arquivos de entrada são lidos da pasta atual, então execute o programa a partir da raiz do repositório. A oferta gerada é gravada em `oferta.txt`.

## Estrutura

| Arquivo | Responsabilidade |
| --- | --- |
| `main.c` | Fluxo principal e escrita da oferta |
| `estruturas_e_funcoes.h` | Estruturas de dados e funções auxiliares |
| `ler_dados_materias.h`, `ler_dados_aluno.h`, `ler_dados_professores.h` | Leitura das entradas |
| `optativas.h` | Optativas por ênfase |
| `atribuicao_salas.h`, `AlocarSalaNovo.h` | Alocação de salas |
| `AlocarProfessores.h` | Atribuição de professores |

## Tecnologias

- C (GCC)

## Autores

- **Erasmo da Silva Sá Junior** — [GitHub](https://github.com/erasmossj) · [LinkedIn](https://www.linkedin.com/in/erasmo-junior-883010309/)
- **Victor**

### Divisão de tarefas

- [x] Reaproveitar a função de input de dados e de histórico. (Erasmo)
- [x] Refazer as estruturas que serão reaproveitadas. (Erasmo)
- [x] Criar um .txt com os dados de todos professores ativos do IC. (Victor)
- [x] Criar um .txt com os dados das salas do IC. (Victor)
- [x] Criar uma função para ler os dados dos professores do IC. (Erasmo)
- [x] Criar uma estrutura, ou modificar uma já existente que aponte à disciplina aos professores. (Victor)
- [x] Criar uma estrutura que faça a ligação entre sala, professor e disciplina. (Erasmo)
- [x] Criar uma função de conflito de horário. (Erasmo)
- [x] Criar estruturas condicionais para a função de atribuição de salas. (Victor)
- [x] Criar o loop da função de atribuição de salas. (Erasmo)

## Licença

Distribuído sob a [Licença MIT](./LICENSE).
