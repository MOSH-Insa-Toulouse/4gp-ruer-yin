# 22-23 4gp-ruer-yin

Ce projet s'inscrit dans l'UF **"I4GPMH21 - du capteur au banc de test en open source hardware"** en 4eme année département d'INSA Toulouse.
***

Ce projet sert à caractériser la résistance des capteurs graphites sous différentes conditions de déformation. Une application de déformation change la distance moyenne des particules de graphite. En effet, la conductivité de la couche graphite dépende vachement de cette distance moyenne et donc la déformation. En pratique, on applique un contraint et déposer le capteur sur les semis sphères pour caractériser les diffèrent déformation. L’ordre de grandeur de ce capteur est 100Mohm. Il n’est pas usuel. Par exemple il est hors la gamme de mesure des multimètres commerciaux. Donc il est essentiel dans ce projet de planifier et de fabriquer un circuit PCB qu’il nous permettre de mesurer cette résistance. De plus, il est aussi intéressant d’élaborer un système de communication pour communiquer les données avec notre téléphone Android avec Bluetooth. 
***  
## Sommaire
* [1. Description du projet et détail des livrables](#PremiereSection)
* [2. Matériel nécessaire](#DeuxiemeSection)
* [3. Arduino](#TroisiemeSection)
  * [3.1. Librairies utilisées](#TroisiemeSection1)
  * [3.2. Code Arduino](#TroisiemeSection1)
* [4. Application Android](#QuatriemeSection)
* [5. KiCad](#CinquiemeSection)
  * [5.1. Symboles et empreintes des composants](#CinquiemeSection1)
  * [5.2. Schématique](#)
  * [5.3. Placement des composants](#)
  * [5.4. Visualisation 3D](#)
* [6. Fabrication du shield](#)
  * [6.1. Réalisation du PCB](#)
  * [6.2. Perçage et soudure](#)
* [7. Simulation](#)
* [8. Tests et résultats](#)
  * [8.1. Banc de test](#)
  * [8.2. Résultats obtenus](#)
  * [8.3. Analyse des résultats ](#)
* [9. Datasheet](#)


