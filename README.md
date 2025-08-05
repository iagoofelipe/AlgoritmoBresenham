# AlgoritmoBresenham
Para o desenvolvimento da atividade, utilizei a biblioteca OpenGL em conjunto com a linguagem de programação C++. Armazenei as coordenadas da imagem em uma matriz e dentro da função `display` iterei seus valores, aplicando o algoritmo de Bresenham para o desenho na tela, utilizando sempre o ponto anterior como início e o valor atual como destino. O desenho utilizou as coordenadas iniciais (`INITIAL_X`, `INITIAL_Y`) como referência de origem e somou com as coordenadas definidas, dessa forma, o desenho poderia ser projetado em qualquer lugar da tela, alterando apenas os valores iniciais. Os valores definidos na matriz de coordenadas foram coletados do [PDF de orientação](/ref/Atividade%20Ativa%20Orientações%20-%20Computação%20Gráfica%20e%20Processamento%20de%20Imagens.pdf).

# Janela da Aplicação
![Janela da Aplicação](/ref/janela.png)
