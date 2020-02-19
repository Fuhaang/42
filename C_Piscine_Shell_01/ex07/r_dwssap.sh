#!/bin/bash

#Affiche la sortie d'un cat /etc/passwd, en retirant les commentairesm une ligne sur deux en partant de la seconde
cat /etc/passwd | sed -e '/^#.*$/d' | sed -n 'n;p'

#Reste a faire :
# inverser chaque login
# trier par ordre alphabethique inverse
# ne conserver aue les logins compris entre FT_LINE1 et FT_LINE2 inclus
# les separer par des "," (sans les guillemets)
# termines par un ".".
