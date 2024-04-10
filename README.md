# FloripaScript (FLS)

O FloripaScript (FLS) é uma linguagem de programação que combina a simplicidade e flexibilidade de linguagens interpretadas com a robustez e desempenho do C++.

Em outras palavras, é como se você tivesse o poder do C++ com a facilidade de uso de linguagens como Python ou Javascript.

### Variáveis

Essas são os tipos variáveis disponíveis:

| Parâmetro | Tipo     | Descrição                |
| :-------- | :------- | :----------------------- |
| `let`     | `string` | Somente texto            |
| `string`  | `string` | Somente texto            |
| `int`     | `int`    | Somente números inteiros |
| `json`    | `JSON`   | Somente JSON             |

Exemplo:

```
let foo = "bar";
```

### Funções

As funções são declaradas da seguinte forma:

```
function ola_mundo = []() {
    console.log("Olá mundo!");
    return 0;
};
```

Todas as funções precisam ter um retorno.

Caso a função tenha um parâmetro, é necessário que ele e seu tipo sejam passados entre os parenteses, exemplo:

```
function ola_mundo = [](string oi) {
    console.log(oi);
    return oi;
};
```

### Métodos

A seguir, uma lista com os métodos disponíveis no FloripaScript:

#### console

| Método | Função             | Uso                   | Exemplo                      |
| :----- | :----------------- | :-------------------- | :--------------------------- |
| `log`  | `Print no console` | `console.log(string)` | `console.log("Olá mundo!");` |

#### network

| Método | Função                | Uso                    | Exemplo                              |
| :----- | :-------------------- | :--------------------- | ------------------------------------ |
| `get`  | `Requisição HTTP GET` | `network.get(string);` | `network.get("https://google.com");` |

#### json

| Método  | Função                                   | Uso                         | Exemplo                        |
| :------ | :--------------------------------------- | :-------------------------- | ------------------------------ |
| `parse` | `Transformar JSON em string em objeto`   | `JSON.parse(string);`       | `JSON.parse({"data": "ola"});` |
| `map`   | `Loop em cada elemento de um JSON Array` | `JSON.map(json, function);` | `JSON.map(data, funcao);`      |

#### variables

| Método    | Função             | Uso                                          | Exemplo                                   |
| :-------- | :----------------- | :------------------------------------------- | ----------------------------------------- |
| `replace` | `Substituir texto` | `variables.replace(string, string, string);` | `variables.replace(ola, "ola", "mundo");` |
| `concat`  | `Concatenar texto` | `variables.concat(string, string);`          | `variables.concat("ola", "mundo");`       |

### Exemplo

```
let url = "https://bar-do-jeiz.onrender.com/data";
let response = network.get(url);
json data = JSON.parse(response);

function carlos = [](json json_parsed, int i){
        console.log(variables.concat("Username: ", json_parsed[i]["USERNAME"]));
        console.log(variables.concat("Postagem: ", json_parsed[i]["POST_DESC"]));
        console.log("------------------------------------------------------------------------");
        console.log(" ");
};

JSON.map(data["data"], carlos);
```

### Execução

Para executar um script em FLS, é necessário compilar e executar o arquivo `/modules/compiler/main.cpp` e depois o arquivo `/out/comipled.cpp`.

### Extensão VSCODE

- [FloripaScript Extension](https://marketplace.visualstudio.com/items?itemName=GuilhermeFloriano.floripascript-extension)
