# Projekt_Torsionspendel 
06.07.2019

Zielsetzung:

Das Ziel dieses Programmes ist es, ein Torsionspendel zu simulieren. Ein Torsionspendel ist eine an einem Draht waagerecht aufgehangene Stange,
welche aufgrund des Widerstandes, der beim Verdrillen des Drahtes entsteht, eine Schwingung ausführt. 
Auf der Stange können in einem beliebigen Abstand zur Drehachse zylindrische Gewichte befestigt werden, was einen Einfluss auf das Trägheitsmoment
der Konstruktion hat und damit auch auf die Kreisfrequenz der Schwingung.
Mit diesem Projekt kann man nun ein solches Torsionspendel erstellen, wobei man als Benutzer die Eigenschaften des Drahtes, der Stange 
und der Gewichte frei wählen kann. Das Programm ist dann in der Lage, das Trägheitsmoment, die Kreisfrequenz sowie die Auslenkung zu einem Zeitpunkt
zu berechnen. Außerdem kann ein Zeit-Auslenkungs-Graph sowie die Wertetabelle auf der er basiert erstellt werden.


Installation:

Das Repository zum Programm findet man durch folgenden Link:
https://github.com/NickJannis/Projekt_Torsionspendel
Dort muss man das Repository dann klonen.


Kompilieren und ausführen:

Zunächst muss man in Terminal in das Verzeichnis des Programms wechseln. Kompileren lässt sich das Projekt dann durch folgenden Befehl:
g++  -std=c++11 -o Pendel.out main.cxx Pendel.cpp Masse.cpp Draht.cpp gnuplot_i.hpp
Der Befehl '-std=c++11' ist notwendig, da ältere Versionen von C++ nicht den Datentyp 'array<double,2>' kennen, welchen wir verwendet haben.
Die Datei  'gnuplot_i.hpp' wird benötigt, damit man in C++ die Befehle von Gnuplot verwenden kann. Dies wurde zur Erstellung des Plots benötigt.
Ausführen lässt sich das Programm dann durch den Befehl  './Pendel.out' im Terminal.
Da wir auch ein Makefile erstellt haben, lässt sich das Programm im Terminal auch mit dem Befehl 'make' kompileren. 
Ausgeführt wird es  dann wieder mit './Pendel.out'.


Input:

Grundsätzlich kann man alle Eigenschaften des Pendels, sowie den Startwinkel, mit Fehler angegeben. Möchte man ohne Fehler rechnen, 
kann man als Fehler 0 angeben. Alle Größen werden in SI-Einheiten angegeben. Der Benutzer muss beachten, dass alle Dezimalzahlen mit einem Punkt 
statt einem Komma eingegeben werden müssen.

Zum Erstellen des Pendels:
-Material des Drahtes:
	1-Stahl
	2-Kupfer
	3-Aluminium
	4-beliebiges Material(der Benutzer kann selbst einen Wert für das Torsionsmodul angeben)

-effektive Länge des Drahtes
-Fehler der Länge
-Radius des Drahtes
-Fehler des Radius
-Masse der Stange
-Fehler der Masse
-Innenradius der Stange
-Fehler des Innenradius
-Außenradius der Stange
-Fehler des Außenradius
-Länge der Stange
-Fehler der Länge
-Masse der Massestücke
-Fehler der Masse
-Abstand der Massestücke zum Draht
-Fehler des Abstands
-Innenradius der verwendeten Massestücke
-Fehler des Innenradius
-Außenradius der Massestücke
-Fehler des Außenradius
-Länge der Massestücke
-Fehler der Länge
-Startwinkel des Pendels
-Fehler des Startwinkels

Pendel berechnen:
-neuen Startwinkel
-Fehler des neuen Startwinkels
-Zeit, zu der die Auslenkung berechnet werden soll

Plot erstellen:
-Intervall der Zeiten, zu denen die Auslenkung berechnet werden soll
-Zeitpunkt, bis zu dem die Auslenkung berechnet werden soll (Zeitpunkt, bis zu dem der Graph die Auslenkung in Abhängigkeit von der Zeit darstellt


Output:

Führt man das Programm im Terminal aus, so werden das Trägheitsmoment, die Kreisfrequenz und die Auslenkung im Terminal ausgegeben. 
Der Plot und die Daten zur Auslenkung werden im Programmverzeichnis gespeichert und müssen vom Benutzer selbst geöffnet werden.

-Gesamtträgheitsmoment der Stange mit den Gewichten
-Kreisfrequenz, mit der das Pendel schwingt
-Auslenkung zu einem bestimmten Zeitpunkt
-Auslenkung in Abhängigkeit der Zeit, die bis zu einem gewissen Wert in festen Intervallen läuft (wird in der Datei "DatenPendel.txt" gespeichert, 
diese befindet sich dann im Programmverzeichnis)
-Zeit-Auslenkung-Graph (wird als "a.png" im Programmverzeichnis gespeichert)


Beispiel:

Hier ein Beispiel, welche Werte man eingeben kann und welche Werte das Programm dann berechnet:
Zunächst '1' eingeben um das Pendel zu erstellen.
Dann wurden die folgenden Werte eingegeben:
Material des Drahtes: 1 (Stahl)
-effektive Länge des Drahtes:0.319
-Fehler der Länge:0.001
-Radius des Drahtes:0.00015
-Fehler des Radius:0.00001
-Masse der Stange:0.057
-Fehler der Masse:0.0001
-Innenradius der Stange:0.003
-Fehler des Innenradius:0.0005
-Außenradius der Stange:0.0037
-Fehler des Außenradius:0.0005
-Länge der Stange:0.3
-Fehler der Länge:0.001
-Masse der Massestücke:0.3522
-Fehler der Masse:0.0001
-Abstand der Massestücke zum Draht:0.05
-Fehler des Abstands:0.001
-Innenradius der verwendeten Massestücke:0.008
-Fehler des Innenradius:0.001
-Außenradius der Massestücke:0.04
-Fehler des Außenradius:0.001
-Länge der Massestücke:0.039
-Fehler der Länge:0.001
-Startwinkel des Pendels:6.28
-Fehler des Startwinkels:0

Dann wurde der Punkt 2 ausgewählt, um das Pendel zu berechnen. Berechnet wurde:
-Gesamtträgheitsmoment:0.00257114+/-7.20377e-05 kg*m^2
-Auslenkung bei t=10 Sekunden:-5.85779+/-0.102789 rad
-Kreisfrequenz: 0.277282+/-0.00454058 Hz

Schließlich wurde mit Hilfe von Punkt 3 der Plot erstellt, wobei als Zeitintervall 1 Sekunde gewählt wurden und als Dauer 50 Sekunden.
Der Plot und die Werte sind im Repository im Ordner images unter "Plot.png" und in der Präsentation zu finden.


Sonstiges:

Die verwendeten Torsionsmodule wurden von folgender Seite entnommen:
https://de.wikipedia.org/wiki/Schubmodul
Im Repository befindet sich auch ein Doxyfile, welches zur Code-Dokumentation dient.
Erstellt wurde das Projekt von Nick Jannis Schmeißer und Ronja van Luijt.






