# Architektura systemów komputerowych Projekt-2

## Opis projektu

System alarmowy oparty na mikrokontrolerze ATMega328P (Arduino), który monitoruje ruch za pomocą czujników PIR. Projekt umożliwia kontrolę statusu czujników, wyświetlanie informacji o stanie alarmu na panelu LED oraz rejestrację liczby wykrytych ruchów.

## Funkcjonalności

- **Jednostka sterująca:** ATMega328P (Arduino)
- **Obsługa 5 czujników PIR**
  - Możliwość indywidualnego załączania/wyłączania czujników
  - Każdy czujnik wyposażony w diodę LED statusu (świecenie = aktywny, brak = nieaktywny)
- **Panel LED:**
  - Wyświetlanie statusu alarmu:
    - Aktywny: symbol górnej kreski (-)
    - Nieaktywny: symbol dolnej kreski (\_)
  - Licznik wykrytych ruchów od momentu aktywacji alarmu
  
## Wymagania sprzętowe

- ATMega328P (Arduino UNO lub kompatybilny)
- 5x czujnik PIR 
- Panel LED (7-segmentowy wyświetlacz LED)
- Przewody połączeniowe
- Dioda LED dla każdego czujnika PIR
- Rezystory
- Przyciski
- 8-bitowy rejestr przesuwny 74HC595

## Schemat

![](/alarmschemat.png)

## Link do projektu Tinkercad

[Projekt alarmu](
https://www.tinkercad.com/things/hQb4lW148Oe-ask-projekt-2-alarm?sharecode=8xqfxaY5XNDh9_qgL-9ZIHNmJORLkDzH7wIwF1iYf2Y)

## Opis działania



## Autor

Kacper Szponar
21306

## Licencja

Projekt dostępny na licencji MIT.
