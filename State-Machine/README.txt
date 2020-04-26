
Notre main suit le schéma du png dans ce dossier.

Pour changer d'état il faut appuyer sur les inputs suivants:

A - De l'état 1 à 2 et inversement
U - De l'état 1 à son sous-état S1
Z - Du sous-état S1 au sous-état S2
E - Du sous-état S1 au sous-état S3
R - Du sous-état S2 au sous-état S3 et inversemment
T - Du sous-état S2 à l'état 1
Y - Du sous-état S3 à l'état 1
I - De l'état 1 ou 2 à l'état Any


Le Anystate sera toujours le premier vérifié lors du check
des transitions. Une fois dans le Anystate il repasse directement
dans l'état 1 ( car le trigger est un bool mis à 'true') ce qui
explique le changement entre 1 et AnyState en boucle quand on reste
appuyé sur la touche I



