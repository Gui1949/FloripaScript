# FloripaScript (FLS)

O FloripaScript (FLS) tem como propósito atuar como uma linguagem interpretada em C++ com sintaxe similar ao Node.JS.

Para executar um arquivo .fls, é necessário compilar e executar o arquivo ```/modules/compiler/main.cpp```.

É possível declarar uma variável com ```let``` e tambem fazer um HTTP GET (necessário ter o CURL instalado na máquina): ```main.fls```:

```
let url = "https://bar-do-jeiz.onrender.com/data";

let response = network.get(url);

//Requisição WEB GET!!

console.log(response);
```

Ao executar, o compiler e depois o arquivo em ```/out/compiled.cpp```, será exibida no console a resposta da requisição!
