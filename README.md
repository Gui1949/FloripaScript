# FloripaScript (FLS)

O FloripaScript (FLS) é uma linguagem de programação interpretada em C++, que tem como missão facilitar iniciantes na área de desenvolvimento de software.

### Variáveis

Essas são os tipos variáveis disponíveis:

| Parâmetro  | Tipo     | Descrição                |
| :--------- | :------- | :----------------------- |
| `caracter` | `string` | Somente texto            |
| `inteiro`  | `int`    | Somente números inteiros |

Exemplo:

```
caracter foo = "bar"
```

### Funções

As funções são declaradas da seguinte forma:

```
funcao ola_mundo(){
    cmd.imprimir("Olá mundo!")
};
```

Todas as funções precisam ter um retorno.

Caso a função tenha um parâmetro, é necessário que ele e seu tipo sejam passados entre os parenteses, exemplo:

```
funcao ola_mundo(caracter oi){
    cmd.imprimir(oi)
};
```

### Métodos

A seguir, uma lista com os métodos disponíveis no FloripaScript:

#### console

| Método     | Função             | Uso                    | Exemplo                      |
| :--------- | :----------------- | :--------------------- | :--------------------------- |
| `imprimir` | `Print no console` | `cmd.imprimir(string)` | `cmd.imprimir("Olá mundo!")` |

#### variables

| Método    | Função             | Uso                                         | Exemplo                                  |
| :-------- | :----------------- | :------------------------------------------ | ---------------------------------------- |
| `replace` | `Substituir texto` | `variables.replace(string, string, string)` | `variables.replace(ola, "ola", "mundo")` |

### Exemplo

```
inteiro i = 1
inteiro dez = 10

enquanto(i <= dez){
    cmd.imprimir(i)
    i++
}

funcao contagem(int num1, int num2){
	inteiro final = num1 + num2
	cmd.imprimir(final)
}

contagem(10,20)

```

### Execução

Para executar um script em FLS, é necessário compilar e executar o arquivo `/modules/compiler/main.cpp` e depois o arquivo `/out/comipled.cpp`.

Uma IDE está em desenvolvimento para facilitar ao máximo a execução.

### Extensão VSCODE

- [FloripaScript Extension](https://marketplace.visualstudio.com/items?itemName=GuilhermeFloriano.floripascript-extension)
