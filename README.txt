************Instruction avant téléversement************ 

##Compilation et exécution
Les instructions qui suivent doivent être suivies préalablement au téléversement du fichier myAlarm.ino
myAlarm.ino est d'autant plus le seul fichier destiné à être compilé/téléversé
La compilation ne requiert pas d'instruction particulière, elle peut être faite dès l'ouverture du fichier

##Moniteur série
Ouvrir le moniteur série avant le téléversement, il affichera l'état du système et donnera les premières indications

##Borne Wi-Fi
Le programme envoie des mails et nécessite donc une connexion Wi-Fi. Nous vous recommandons d'offrir un point d'accès à la carte avant toute chose. 
Une fois la mise en place effectuée, il est nécessaire de modifier les paramètres de la fonction WiFi.begin() située dans le fichier moduleWIFI.cpp ("nom_du_point_d_acces","mot_de_passe")

##Destinataire mail
Toujours dans le fichier moduleWIFI.cpp, remplacez le champ "orned@outlook.fr" par l'adresse de votre messagerie personnelle afin que les mails envoyés par le système arrivent à bon port.

************Interaction avec le programme pendant l'exécution************ 

##Au démarrage
Dès que le programme s'exécute, et après connexion au Wi-Fi, le message suivant apparaît : "Positionnez le capteur à un emplacement fixe..."
C'est le signal qui vous indique que vous avez très exactement 5 secondes pour que le capteur soit fixé. 
Il doit l'être de manière à prendre la mesure du passage que vous souhaitez mettre sous surveillance (exemple : fixé à l'extrémité de votre portail)
Si l'endroit est susceptible de voir passer une voiture, il est conseillé de placer le capteur à environ 1 mètre de hauteur.

IL EST VIVEMENT CONSEILLÉ DE FIXER LE CAPTEUR AVANT L'EXÉCUTION
Si toutefois, le capteur n'est pas fixé après la disparition du message "Positionnez le capteur à un emplacement fixe...", fixez le capteur et redémarrez le téléversement.

##Activation, désactivation de l'alarme
Après la disparition du message "Positionnez le capteur à un emplacement fixe..." et l'établissement de la connexion Wi-Fi par la carte, l'alarme est de base désactivée (aucune LED active). 
Le protocole pour activer l'alarme et la désactiver est le même.
Claquez vos mains près de la carte, la LED auxiliaire s'allume, dès qu'elle s'éteint claquez à nouveau des mains (vous avez plus ou moins 2 secondes pour réagir). 
Si vous avez réussi, la LED principale s'allume, signe que votre alarme est effective. Dans le cas contraire, recommencez l'opération.
Lors de la désactivation, la LED principale doit passer d'allumée à éteinte.

##Test du programme
Pour constater du bon fonctionnement de votre système, vous pouvez procéder à un test. Si la LED principale est active, passez simplement devant le capteur. 
Vous devez recevoir un mail vous indiquant une intrusion dans la minute suivant votre passage.




