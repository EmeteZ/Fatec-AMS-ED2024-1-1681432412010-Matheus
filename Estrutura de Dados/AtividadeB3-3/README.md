Análise de Complexidade

--
Busca Linear

Pior Caso: A chave está no último elemento do array ou não está presente.

Tempo de Execução: No pior cenário, o loop for realiza n iterações.

Função Algébrica: T(n) = n
Notação Big O: O(n) - Complexidade linear

--

Busca Linear em Array Ordenado

Pior Caso: A chave é maior que todos os elementos do array ou não está presente.

Tempo de Execução: O loop for pode iterar até n vezes no pior caso.

Função Algébrica: T(n) = n

Notação Big O: O(n) - Embora o processo possa terminar mais cedo em alguns casos, o pior caso ainda é linear.

--

Busca Binária (em Array Ordenado)

Pior Caso: A chave não está presente no array, e o intervalo de busca é repetidamente dividido ao meio até restar apenas um elemento.

Tempo de Execução: O loop while reduz o intervalo de busca pela metade a cada iteração. No pior caso, o número de iterações é log₂(n).

Função Algébrica: T(n) = log₂(n)
Notação Big O: O(log n) - Complexidade logarítmica

--

Gráfico da Complexidade dos Algoritmos de Busca
Os gráficos apresentados demonstram a complexidade de tempo dos diferentes algoritmos de busca:

Escala Linear: Nesta escala, a diferença entre a busca linear (O(n)) e a busca binária (O(log n)) é clara. A busca linear aumenta de forma constante com o tamanho da entrada, enquanto a busca binária cresce a uma taxa muito mais lenta.

Escala Logarítmica: Na escala logarítmica, a busca binária se aproxima de uma linha reta, evidenciando seu crescimento logarítmico. Isso reforça a ideia de que a busca binária é significativamente mais eficiente para grandes volumes de dados comparada à busca linear, cujo crescimento continua exponencial mesmo quando representado em uma escala logarítmica.