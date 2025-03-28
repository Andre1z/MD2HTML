Conversor de Markdown a HTML

Descripción general

Este sencillo conversor de Markdown a HTML está escrito en C++. Lee un archivo Markdown, convierte su sintaxis a HTML y guarda el resultado en un archivo HTML.

Características

Admite encabezados (#, ##, ###)

Convierte código en negrita, cursiva y en línea

Administra listas desordenadas (elemento -)

Uso

1. Compilación

Compila el programa con g++:

g++ markdowntohtml.cpp -o markdown_converter

2. Ejecuta el conversor

Ejecuta el programa con nombres de archivo personalizados opcionales:

./markdown_converter input.md output.html

Si no se proporcionan nombres de archivo, se usan por defecto input.md y output.html.

3. Salida

El archivo HTML convertido se guardará como output.html.

Ejemplo

Markdown (input.md)

# Título
## Subtítulo
**Texto en negrita** y *Texto en cursiva*
- Elemento de lista 1
- Elemento de lista 2

HTML (output.html)

<h1>Título</h1>
<h2>Subtítulo</h2>
<b>Texto en negrita</b> y <i>Texto en cursiva</i>
<ul><li>Elemento de lista 1</li></ul>
<ul><li>Elemento de lista 2</li></ul>

Licencia

¡Este proyecto es de código abierto y gratuito!