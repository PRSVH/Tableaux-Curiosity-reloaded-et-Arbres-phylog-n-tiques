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


**Pour l'APP3**
Tester votre implémentation en C:
=================================

Vous trouverez dans le répertoire tests/ des fichiers vous permettant de
tester par vous-même vos fonctions en exécutant votre programme principal, par 
exemple ainsi :

> ./main tests/arbre-simple.test

Plusieurs programmes de test sont également fournis:
    acte1.c, acte2.c, acte3.c, acte3b.c et acte4.c
Ceux-ci ne doivent **pas** être modifiés.
Ils sont compilés automatiquement avec la commande 'make' et utilisent les 
fonctions déclarées dans les fichiers .h et remplies dans les .c
Ils utilisent pour leurs tests les répertoires tests_acte1, etc. correspondants.


Pour tester l'acte I vous pouvez ainsi :
- soit déclencher l'ensemble des tests :
  > make tests_acte1

- soit lancer manuellement un des tests ainsi (par exemple pendant le debug 
  d'un test en particulier) :
  > ./acte1 tests_acte1/acte1_arbre-simple.test

Les actes II, III-A, III-B et IV se testent de la même manière.
Pour information, le format des fichiers de tests est décrit en fin de ce 
fichier.



Tester votre implémentation en Python:
======================================

Vous trouverez dans le répertoire tests/ des fichiers vous permettant de
tester par vous-même vos fonctions en exécutant votre programme principal, par 
exemple ainsi :

> ./main.py tests/arbre-simple.test

Ou, si vous travailler sous Idle, modifiez les arguments directement au début 
du main.py


Plusieurs programmes sont également fournis :
    acte1.py, acte2.py, acte3.py, acte3b.py et acte4.py
Ceux-ci ne doivent **pas** être modifiés, sauf pour les variables de tests au 
début des fichiers si vous travaillez sous Idle (variables 'do_all_test' et 
'nomfichier').

Ces programmes utilisent les fonctions définies dans arbres.py et arbresphylo.py
Ils utilisent pour leurs tests les répertoires tests_acte1, etc. correspondants.

Pour tester l'acte I vous pouvez ainsi:
- soit déclencher l'ensemble des tests ainsi:
  > ./acte1.py -all

- soit utiliser manuellement un des fichiers de tests ainsi (par exemple 
  pendant le debug d'un test en particulier) :
  > ./acte1.py tests_acte1/acte1_arbre-simple.test

(Ou, si vous n'utilisez pas la ligne de commande, en modifiant les premières lignes de acte1.py)

Les actes II, III-A, III-B et IV se testent de la même manière.
Pour information, le format des fichiers de tests est décrit en fin de ce 
fichier.




Description des formats des fichiers de test
============================================

Format des tests de l'acte I :
------------------------------

Nom du fichier arbre
nombre d'especes
nombre de caracteristiques


Format des tests de l'acte II :
-------------------------------

Nom du fichier arbre
nom de l'espece à chercher
"present" ou "absent" selon que l'espece est presente ou pas
Si espece presente :
le nombre de caractéristiques
Les caractéristiques de l'espèce (sur une seule ligne, séparées par un seul espace)


Format des tests de l'acte III-A :
----------------------------------

Nom du fichier arbre
Nom espèce à ajouter
Nombre de caractéristiques de l'espèce à ajouter
"possible" si l'insertion est légale, impossible sinon
 -- série de tests sur l'arbre après insertion
 Nombre espèces dans l'arbre
 Nombre caractéristiques de l'arbre
 Nombre espèces à tester (peut être moins que le nombre d'espèces total)
 -- Pour chaque espèce
 Nom espèce
 Nombre caractéristiques de l'espèce
 Liste caractéristiques (sur une seule ligne, séparées par un seul espace)


Format des tests de l'acte III-B :
----------------------------------

Nom du fichier arbre
Liste des caractéristiques au niveau 1 (sur une seule ligne, séparées par un seul espace)
Liste des caractéristiques au niveau 2
Liste des caractéristiques au niveau 3
...



Format des tests de l'acte IV :
-------------------------------

Nom du fichier arbre

Nom de la caractéristique à ajouter

Nombre d'espèces possédant ces caractéristiques

Liste des espèces qui possèdent cette caractéristique

"possible" si l'insertion est légale, impossible sinon

-- série de tests sur l'arbre après insertion

Nombre espèces dans l'arbre

Nombre caractéristiques de l'arbre

Nombre espèces à tester (peut être moins que le nombre d'espèces total)

-- Pour chaque espèce

Nom espèce

Nombre caractéristiques de l'espèce

Liste caractéristiques (sur une seule ligne, séparées par un seul espace)
