# FloripaScript (FLS)

O FloripaScript (FLS) tem como propósito atuar como uma linguagem interpretada em C++ com sintaxe similar ao Node.JS.

Para executar um arquivo .fls, é necessário compilar e executar o arquivo ```/modules/compiler/main.cpp```.

É possível declarar uma variável com ```let``` e tambem fazer um HTTP GET (necessário ter o CURL instalado na máquina) e parsear as informações da response (no arquivo ```main.fls```):

```
let url = "https://bar-do-jeiz.onrender.com/data";
let response = network.get(url);
int i = 0;
json data = JSON.parse(response);
int tamanho = data["data"].size();

while (i < tamanho)
{
    console.log(data["data"][i]["POST_DESC"]);
    i++;
}
```

Ao executar, o compiler e depois o arquivo em ```/out/compiled.cpp```, será exibida a propriedade ```POST_DESC``` de cada linha da response.
