Quickstart :
============

Pour démarrer **l'APP1**, commencez par compiler le tout:
> make

Puis lancez le programme d'introduction.
> ./client-introduction

et suivez les consignes :-)



**Pour l'APP2**
Compilation
-----------
Pour compiler :
> make

ou

> clang -Wall -Wextra main.c -o main curiosity.c interprete.c listes.c
(Nous vous conseillons d'utiliser le compilateur clang plutôt que gcc.)


Lancer un test
--------------

Test complet
> ./main tests/<nom de test>.test

Test en mode "pas à pas" :
> ./main -d tests/<nom de test>.test

Test de performance :
  => mettre tous les affichages dans des blocs conditionnels
     avec 'if (! silent_mode)'
  => recompiler avec les options de performance
     (modifiez les CFLAGS comme indiqué dans le Makefile
      puis lancez 'make -B')

> ./main -silent tests/perfs/<nom de test de performance>.test


Lancer une suite de tests
-------------------------

Tests fonctionnels :
> ./tests/check.py c

Batterie de tests de performance (avec generation de courbes):
> ./tests/performance/perf.py c

