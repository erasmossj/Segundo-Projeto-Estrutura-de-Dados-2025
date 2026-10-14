# Gerador de Oferta de Disciplinas do IC/UFAL

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

Requisitos: GCC e GNU Make. No Windows, use o WSL ou o MSYS2 (terminal UCRT64, com `make` ou `mingw32-make`); o Makefile usa comandos de shell POSIX, então não roda direto no `cmd` ou no PowerShell.

```bash
make         # compila src/*.c em obj/*.o e liga em bin/oferta
make run     # gera a oferta a partir dos arquivos de dados/
make test    # gera a oferta e compara com tests/oferta_esperada.txt
make clean   # remove obj/, bin/ e a oferta gerada
```

O programa lê os arquivos de entrada da pasta atual, por isso `make run` e `make test` o executam dentro de `dados/`. A oferta gerada é gravada em `dados/oferta.txt`, e a saída de referência fica em `tests/oferta_esperada.txt`. O `make test` falha se as duas forem diferentes em qualquer byte.

Esta versão corrige os erros que faziam o programa travar (estouro de buffer na leitura do histórico, structs alocadas sem zerar, buscas sem `return NULL` e leitura em modo texto no Windows), por isso a oferta de referência mudou em relação à versão anterior.

## Estrutura

| Arquivo | Responsabilidade |
| --- | --- |
| `src/main.c` | Fluxo principal e escrita da oferta |
| `include/estruturas.h`, `src/estruturas.c` | Estruturas de dados e busca na lista de disciplinas |
| `include/ler_dados_materias.h`, `src/ler_dados_materias.c` | Leitura das disciplinas e dos pré-requisitos |
| `include/ler_dados_aluno.h`, `src/ler_dados_aluno.c` | Leitura dos históricos e cálculo da demanda |
| `include/ler_dados_professores.h`, `src/ler_dados_professores.c` | Leitura dos professores |
| `include/ler_dados_salas.h`, `src/ler_dados_salas.c` | Leitura das salas |
| `include/optativas.h`, `src/optativas.c` | Optativas por ênfase |
| `include/conflito_horarios.h`, `src/conflito_horarios.c` | Verificação de conflito de horário |
| `include/alocacao_salas.h`, `src/alocacao_salas.c` | Alocação de salas |
| `include/alocacao_professores.h`, `src/alocacao_professores.c` | Atribuição de professores |
| `dados/` | Arquivos de entrada (`TESTE-*.txt` são versões antigas, não lidas pelo programa) |
| `tests/oferta_esperada.txt` | Oferta de referência usada pelo `make test` |
| `Makefile` | Build automático (`obj/` e `bin/` são gerados e ficam fora do Git) |

## Tecnologias

- C (GCC)
- GNU Make

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
