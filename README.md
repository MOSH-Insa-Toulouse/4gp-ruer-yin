# 22-23 4gp-ruer-yin

Ce projet s'inscrit dans l'UF **"I4GPMH21 - du capteur au banc de test en open source hardware"** en 4eme année département d'INSA Toulouse.
***

Ce projet sert à caractériser la résistance des capteurs graphites sous différentes conditions de déformation. Une application de déformation change la distance moyenne des particules de graphite. En effet, la conductivité de la couche graphite dépende vachement de cette distance moyenne et donc la déformation. En pratique, on applique un contraint et déposer le capteur sur les semis sphères pour caractériser les diffèrent déformation. L’ordre de grandeur de ce capteur est 100Mohm. Il n’est pas usuel. Par exemple il est hors la gamme de mesure des multimètres commerciaux. Donc il est essentiel dans ce projet de planifier et de fabriquer un circuit PCB qu’il nous permettre de mesurer cette résistance. De plus, il est aussi intéressant d’élaborer un système de communication pour communiquer les données avec notre téléphone Android avec Bluetooth. 
***  
![344179273_975800936927518_5341503790366510260_n](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/9c72dcec-b65c-47d8-bfe3-1c6ddb006259)
![344186423_743219774252609_5498657226306865498_n](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/fc572568-e9a5-4f5a-8190-813ba75efc62)
## Table de matière
* [1. Liverables et matériels](#PremiereSection)
* [2. Simulation LTSPICE](#SixiemeSection)
* [3. Réalisation Kicad et PCB](#DeuxiemeSection)
* [4. Code Arduino](#TroisemeSection)
* [5. (Application MIT app inventor)](#QuartiemeSection)
* [6. (Banc de test)](#CinqiemeSection)
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
## 2. Simulation LTSpice
La capteur graphite a une l'ordre de grandeur de 100MOhm. Le voltage maximun d'Arduino est 5V. Il est donc difficile de mesure la valeur de capteur si on n'arrive pas à amplifier la signal. On a donc designé un circuit d'amplification pour avoir un facteur 100 du signal. Ensuite on peut calculer le valeur précise de la résistance. Voici l'image du circuit de LTSpice:
![Annotation 2023-05-12 131215](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/64b885d9-98c8-4771-98be-362f1aee6683)

## 3. Réalisation Kicad et PCB <a id="DeuxiemeSection"></a>
Pour designer un carte PCB où on peut intégrer les matériels mentionnés au dessus, il est nécessaire de utiliser kicad pour designer un circuit de conductant de cuivre et les composants soudés au dessus. Les détailes de ces composants et de la cirtuit sont visibles dans les images au dessous.  
* L'image des symboles:
![Annotation 2023-05-12 135257](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/63dd5577-8d7b-423c-ab9e-3f131a618269)
![Annotation 2023-05-12 135336](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/ec4c70d7-c459-4969-9239-408fdcd7102a)
![Annotation 2023-05-12 135337](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/2ed6888f-1b2c-45c6-ae54-6d47ec804c43)


* L'image du PCB et son image 3D
 ![Annotation 2023-05-12 135534](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/d6525599-a3b9-4469-bc31-dcbc922b1e3d)

Après les vérifications electroniques, nous avons envoyé le fichier d'imprimant à Madame Catherine Crouzet pour poursuivre un impression de PCB avec elle. Ce PCB est réalisé sur un plaquette epoxy. A la fin des procédés de photolitographie et de gravure chimique, l'impression du circuit est réalisé sur l'un de cette plaquette. Nous avons poursuive les perçages des trous pour intégrer les matériels et le soudage de ces matériels. Les trous on les 2 différents diamètres. Pour les trous du module Arduino Uno, le diametre est 1mm. Les trous de reste ont de diametre 0.8mm selon la consigne de Madame Catherine Crouzet.

## 4. Code Arduino <a id="TroisemeSection"></a>
Les objetifs de script d'arduino nommé [plz-work.ino](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/tree/main/Arduino/plz-work/plz-work) sont:
* mesurer le voltage en temp relle de la sortie du circuit (VA0)
* En déduire la valeur de résistance R du capteur graphite.
* Envoyer la valeur de tension mesuré sous 1 octect par le module de bluetooth.
* Afficher la valeur de résistance sur l'écran OLED.
Le code essentielle est effctivement les code de mesure et de calcule de valeur de résistance. Selon les simulations de LTSpice, on peut en deduit la resistance exact que nous aimerions de mesurer.

## 5. Application (MIT app inventor) <a id="QuartiemeSection"></a>
Les objetifs de cet application est de communiquer en temp relle avec le module d'Arduino des valeurs de resistance et les afficher. 
La connection de bluetooth se réalise par trois bloc de "when". On affiche le liste d'adresse de bluetooth dans le mémoire de téléphone. Puis on pourra sélectionner un adresse. Le téléphone est ensuite connecté à bluetooth. 
![MIT App Inventor 2 - Google Chrome 2023_5_12 16_01_11](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/8262ee69-ab9a-41b2-8d50-958a2497ad3e)![MIT App Inventor 2 - Google Chrome 2023_5_11 22_43_18](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/09f62442-8b15-4392-89e2-818eae6ac4fa)

Le Bouton "Reception_bluetooth" sert à lancer le chronologe. Ensuite, dans le blocs orange fait le calcule depuis un octet envoyé par le Bluetooth HC-05 en utilisant la formule  1.1. Dans le graphe, le fonciton en bloc violet trace le graphe en tracant tous les lignes entre tous les 2 point.  
![MIT App Inventor 2 - Google Chrome 2023_5_12 16_00_10](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/7f6833b9-780c-4e49-8b4b-d872e656306a)

## 6. Banc de test <a id="CinqiemeSection"></a>
![344287991_991684428512524_8927725149100369612_n](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/d1cc95a4-a901-4529-8e2c-b168caf000b8)

Nous avons testé notre capteur graphite dans les différent angle de déformation. Ce dernier est caractériser par un banc de test dans l'image au dessus. Le banc de test est composé par les différents semi sphère de diamètre 5cm, 4.5cm, 4cm, 3.5cm, 3cm, 2.5cm, 2cm. Pendant le test, on colle le côté où il y a pas de graphite aux différent semi shère du banc de test et on fait le mesure du résistance. Ensuite on cherche la relation entre le déformation définit comme par le formule ε=D/(2*R)(où ε est la déformation, D est l'épaisseur du papier, R est la rayon de courbure) et la variation relative de (ΔR/R0).  
Nous avons décidé de faire les tests sur un graphite de 2H en applicant la seulement la tension. Il y a pas de mesure sous condition de compression car on a réalisé pendant les mesure que la forme de capteur graphite n'est pas réversible. Premièrement, on peut très facilement dépasser le limite élastique du papier. Deuxièmement, même si on ne change pas la forme de ce papier, la résistance n'est souvent pas réversible. En conséquence, on a choisit de faire le mesure seulment sur la tension pour chaque échantillon. Les résultat sont montré dans le fichier Datasheet.pdf.
Le résultat montre une relation linéaire entre la déformation et la variation relative de la résistance de capteur. On peut déduit l'angle de déformation  depuis un résistance mesurée. 
![image](https://github.com/MOSH-Insa-Toulouse/4gp-ruer-yin/assets/55764097/346b7e8b-7683-4ca2-b882-7b08e4dff0c5)

