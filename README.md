Aufgabenstellung Klausur 2024:

Autos und deren Reichweite
Allgemeine Hinweise
	• Es sind alle Unterlagen (Foliensätze, Skripten) erlaubt, Sie dürfen auch Teile Ihrer eigenen Lösungen der Übungsblätter wiederverwenden.
	• Kommunikation mit anderen Studenten und/oder KIs (ChatGPT & Co.) ist in jeglicher Form verboten und führt zu einer negativen Beurteilung.
	• Lesen Sie die Aufgabe genau und vollständig durch, bevor Sie mit der Bearbeitung beginnen.
	• Zur Benotung wird die Funktionalität ihrer Lösung auf JupyterHub herangezogen.
	• Kommentieren Sie Ihren Code ausführlich (jede Funktion und auch jeden wichtigen Codeteil)
	• Kommentieren Sie am Anfang Ihrer Quelldatei, was an Ihrem abgegebenen Programm einwandfrei funktioniert, und was nicht funktioniert (und warum).
	• Wann immer von „zufälligen“ Werten gesprochen wird, grenzen Sie den möglichen Wertebereich sinnvoll ein.
	• Wenn keine konkreten Werte angegeben werden, dann wählen Sie selber einen sinnvollen Wert aus.

Aufgabe
Implementieren Sie ein Programm, welches für eine Liste von Autos ausgibt, welche Autos eine gegebene Mindestreichweite haben und in einer gegebenen Farbe verfügbar sind. 

Die Liste der Autos finden Sie in der Datei cars.csv im Ordner dieser Klausur. Darin enthalten ist eine Liste von 40
 Autos inklusive deren Automarke, des Modells, des Verbrauchs in Liter pro 100 km, die Größe des Tanks in Liter und einer Liste von Farben, die für das Auto verfügbar sind. So gibt zum Beispiel der Datensatz Porsche:911:11.5:70:silver,blue,red die Automarke (Porsche), das Modell (911), den Verbrauch (11.5 Liter pro 100 km), das Tankvolumen (70 Liter) und die möglichen Farben (silver, blue und red) an. Die Reichweite berechnet sich aus dem Verbrauch und dem Tankvolumen des vollen Tanks.

Benutzer:innen sollen als Kommandozeilenparameter die gewünschte Mindestreichweite und eine gewünschte Farbe angeben können. 
Es soll dann eine Liste von Autos ausgegeben werden, die die angegebene Mindestreichweite erfüllen und in der angebenen Farbe verfügbar sind. Diese Liste soll neben der Automarke und dem Modell auch die genaue Reichweite des Autos (mit genau 2 Nachkommastellen!) enthalten.
Hier ein beispielhafter Programmaufruf inklusive Ausgabe:
	• Aufruf:
./carrange 2300 silver.
	• Ausgabe:
Nissan Rogue: 2352.94 km
Chevrolet Malibu: 2352.94 km

Es gilt zu beachten:
	• Die Liste der Autos in der Datei cars.csv wurde von ChatGPT erstellt, daher alle Angaben ohne Gewähr.
	
	• Die Reihenfolge der Ausgabe soll der umgekehrten Reihenfolge der Liste in der Datei cars.csv entsprechen.
	
	• Sollte die Datei cars.csv plötzlich mehr oder weniger als 40 Datensätze beinhalten, dann darf Ihr Programm nicht abstürzen. Überzählige Zeilen können aber ignoriert werden.
	
	• Ihr Programm sollte auch bei ungültigen Zeilen (z.B. bei fehlenden Daten) nicht abstürzen. Ungültige Zeilen können auch ignoriert werden.
	
	• Wenn die Datei cars.csv nicht zum Lesen geöffnet werden kann, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Lesefehler" enthalten.
	
	• Werden keine oder zuwenig Kommandozeilenparameter angegeben, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Eingabefehler" enthalten.
	
	• Wird eine Mindestreichweite und eine Farbe angegeben, die kein Auto matchen, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Parameterfehler" enthalten.
	
Hilfestellung für eine mögliche Herangehensweise:
Hinweis: Sie müssen sich NICHT an diesen Ablauf halten - wichtig ist nur, dass Ihr Programm den oberhalb präsentierten Angaben gerecht wird. Sehen Sie den folgenden Abschnitt lediglich als Hilfestellung an, um die Aufgabe in kleinere Einheiten zerlegen zu können.
(1) Erstellen Sie zunächst die main()-Funktion, lesen sie die Kommandozeilenparameter ein und überprüfen Sie diese auf ihre Richtigkeit.
(2) Erstellen Sie eine Struktur mit passenden Feldern, um die Daten der Autos speichern zu können.
(3) Implementieren Sie eine Funktion, welche die Daten der Autos aus der Datei liest und in der zuvor erstellten Struktur speichert. Erzeugen Sie hierfür ein Array ausreichender Größe für 40 Datensätzen. Sie müssen die Array-Größe nicht dynamisch anpassen.
(4) Implementieren Sie eine Funktion, welche für eine gegebene Mindestreichweite und Farbe die passenden Autos ausgibt.
(5) Führen Sie die in den Schritten 1-4 erstellten Bestandteile zu einem funktionsfähigen Programm zusammen.

