# FloripaScript (FLS)

O FloripaScript (FLS) tem como propósito atuar como uma linguagem interpretada em C++ com sintaxe similar ao Node.JS.

### Variáveis
Essas são os tipos variáveis disponíveis:

| Parâmetro   | Tipo       | Descrição                           |
| :---------- | :--------- | :---------------------------------- |
| `let` | `string` | Somente texto |
| `string` | `string` | Somente texto |
| `int` | `int` | Somente números inteiros |
| `auto` | `auto` | Somente funções LAMBDA |
| `json` | `JSON` | Somente JSON |

Exemplo:
```
let foo = "bar";
```

### Funções

As funções são declaradas somente via variáveis LAMBDA, dessa forma:

```
auto ola_mundo = []() { 
    console.log("Olá mundo!");
    return 0;
};
``` 

Todas as funções precisam ter um retorno.

Caso a função tenha um parâmetro, é necessário que ele e seu tipo sejam passados entre os parenteses, exemplo:

```
auto ola_mundo = [](string oi) { 
    console.log(oi);
    return oi;
};
```

### Métodos

A seguir, uma lista com os métodos disponíveis no FloripaScript:

#### console
| Método   | Função       | Uso                           |
| :------- | :----------- | :---------------------------------- |
| `log` | `Print no console` | ```console.log("Olá mundo!")``` |

#### network

| Método   | Função       | Uso                           |
| :------- | :----------- | :---------------------------------- |
| `get` | `Requisição HTTP GET` | ```network.get("https://google.com");``` |

#### json

| Método   | Função       | Uso                           |
| :------- | :----------- | :---------------------------------- |
| `parse` | `Transformar JSON em string em objeto` | ```JSON.parse(data);``` |

#### variables

| Método   | Função       | Uso                           |
| :------- | :----------- | :---------------------------------- |
| `replace` | `Substituir texto` | ```variables.replace(variavel, "ola_mundo", "mundo_ola");``` |
| `concat` | `Concatenar texto` | ```variables.concat("ola","mundo");``` |

### Exemplo

```
let url = "https://bar-do-jeiz.onrender.com/data";
let response = network.get(url);
json data = JSON.parse(response);
auto carlos = [](json data) { 
        console.log("Exibindo o primeiro post do Bar do Jeiz");
        console.log(variables.concat("Username: ", data["data"][0]["USERNAME"]));
        console.log(variables.concat("Postagem: ", data["data"][0]["POST_DESC"]));
};
carlos(data);
```

### Execução

Para executar um script em FLS, é necessário compilar e executar o arquivo ```/modules/compiler/main.cpp``` e depois o arquivo ```/out/comipled.cpp```.

### Extensão VSCODE

* [FloripaScript Extension](https://marketplace.visualstudio.com/items?itemName=GuilhermeFloriano.floripascript-extension)

