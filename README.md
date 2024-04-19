# FloripaScript (FLS)

O FloripaScript (FLS) é uma linguagem de programação interpretada em C++, que tem como missão facilitar iniciantes na área de desenvolvimento de software.

### Variáveis

Essas são os tipos variáveis disponíveis:

| Parâmetro | Tipo     | Descrição                |
| :-------- | :------- | :----------------------- |
| `let`     | `string` | Somente texto            |
| `string`  | `string` | Somente texto            |
| `int`     | `int`    | Somente números inteiros |

Exemplo:

```
let foo = "bar"
```

### Funções

As funções são declaradas da seguinte forma:

```
function ola_mundo(){
    console.log("Olá mundo!")
};
```

Todas as funções precisam ter um retorno.

Caso a função tenha um parâmetro, é necessário que ele e seu tipo sejam passados entre os parenteses, exemplo:

```
function ola_mundo(string oi){
    console.log(oi)
};
```

### Métodos

A seguir, uma lista com os métodos disponíveis no FloripaScript:

#### console

| Método | Função             | Uso                   | Exemplo                      |
| :----- | :----------------- | :-------------------- | :--------------------------- |
| `log`  | `Print no console` | `console.log(string)` | `console.log("Olá mundo!")` |


#### variables

| Método    | Função             | Uso                                          | Exemplo                                   |
| :-------- | :----------------- | :------------------------------------------- | ----------------------------------------- |
| `replace` | `Substituir texto` | `variables.replace(string, string, string)` | `variables.replace(ola, "ola", "mundo")` |

### Exemplo

```
int i = 1
int dez = 10

while(i < dez){
    console.log(i)
    i++
}

```

### Execução

Para executar um script em FLS, é necessário compilar e executar o arquivo `/modules/compiler/main.cpp` e depois o arquivo `/out/comipled.cpp`.

Uma IDE está em desenvolvimento para facilitar ao máximo a execução.

### Extensão VSCODE

- [FloripaScript Extension](https://marketplace.visualstudio.com/items?itemName=GuilhermeFloriano.floripascript-extension)
