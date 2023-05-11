# 22-23 4gp-ruer-yin

Ce projet s'inscrit dans l'UF **"I4GPMH21 - du capteur au banc de test en open source hardware"** en 4eme année département d'INSA Toulouse.
***

Ce projet sert à caractériser la résistance des capteurs graphites sous différentes conditions de déformation. Une application de déformation change la distance moyenne des particules de graphite. En effet, la conductivité de la couche graphite dépende vachement de cette distance moyenne et donc la déformation. En pratique, on applique un contraint et déposer le capteur sur les semis sphères pour caractériser les diffèrent déformation. L’ordre de grandeur de ce capteur est 100Mohm. Il n’est pas usuel. Par exemple il est hors la gamme de mesure des multimètres commerciaux. Donc il est essentiel dans ce projet de planifier et de fabriquer un circuit PCB qu’il nous permettre de mesurer cette résistance. De plus, il est aussi intéressant d’élaborer un système de communication pour communiquer les données avec notre téléphone Android avec Bluetooth. 
***  
![344179273_975800936927518_5341503790366510260_n](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/9c72dcec-b65c-47d8-bfe3-1c6ddb006259)
![344186423_743219774252609_5498657226306865498_n](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/fc572568-e9a5-4f5a-8190-813ba75efc62)
## Table de matière
* [1. Liverables et matériels](#PremiereSection)
* [2. Réalisation Kicad et PCB](#DeuxiemeSection)
* [3. Code Arduino](#TroisemeSection)
## 1. Liverables et matériels <a id="PremiereSection"></a>
***
Les liverables principaux sont: 
* Un sheild PCB de module Arduino Uno au dessus on a intégré un circuit d'amplificateur, un OLED et un module Bluetooth.
* Un application Android exploré avec MIT app inventor. Cet app sert à communiquer en temp relle avec le module d'Arduino des valeurs de resistance et les afficher. 
* Un script d'Arduino permettant de calculer en temps relle du valeur de resistance, communiquer ce valeur avec l'application mentionné au dessus et l'afficher sur l'écran OLED
* Un datasheet contenant tous les caratérisation du capteur. 

Les matériels nécessaires sont:
* Un carte PCB de module Arduino Uno
* Un module Bluetooth HC-05
* Un écran OLED
* Un amplificateur opérationnel LTC1050  
* Deux condensateurs de 100 nF  
* Un condensateur de 100 µF 
* Deux résistances de 100 KOhms  
* Une résistance de 10 KOhms  
* Deux résistances de 1 KOhm  
* Un papier dessiné d'un trace de crayon imposé

## 2. Réalisation Kicad et PCB <a id="DeuxiemeSection"></a>
Pour designer un carte PCB où on peut intégrer les matériels mentionnés au dessus, il est nécessaire de utiliser kicad pour designer un circuit de conductant de cuivre et les composants soudés au dessus. Les détailes de ces composants et de la cirtuit sont visibles dans les images au dessous.  

Apres les vérifications electroniques, nous avons envoyé le fichier d'imprimant à Madame Catherine Crouzet pour poursuivre un impression de PCB avec elle. Ce PCB est réalisé sur un plaquette epoxy. A la fin des procédés de photolitographie et de gravure chimique, l'impression du circuit est réalisé sur l'un de cette plaquette. Nous avons poursuive les perçages des trous pour intégrer les matériels et le soudage de ces matériels. Les trous on les 2 différents diamètres. Pour les trous du module Arduino Uno, le diametre est 1mm. Les trous de reste ont de diametre 0.8mm selon la consigne de Madame Catherine Crouzet.

## 3. Code Arduino
L'objetif de script d'arduino sont
* mesurer le voltage en temp relle de la sortie du circuit
* En déduire la valeur de résistance mesuré.
* Envoyer la valeur de tension mesuré sous 1 octect par le module de bluetooth.
* Afficher la valeur de résistance sur l'écran OLED.
 
