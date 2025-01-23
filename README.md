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
- Dioda LED dla każdego czujnika PIR
- Rezystory
- Przyciski
- 8-bitowy rejestr przesuwny 74HC595
- Przewody połączeniowe

## Schemat

![](/alarmschemat.png)

## Link do projektu Tinkercad

[Projekt alarmu](
https://www.tinkercad.com/things/hQb4lW148Oe-ask-projekt-2-alarm?sharecode=8xqfxaY5XNDh9_qgL-9ZIHNmJORLkDzH7wIwF1iYf2Y)

## Opis działania

1. **Stan początkowy:**  
   - Po uruchomieniu systemu alarmowego, alarm jest nieaktywny.  
   - Na panelu LED wyświetlana jest dolna kreska (_), co oznacza, że system jest w trybie czuwania.

2. **Aktywacja alarmu:**  
   - Alarm zostaje aktywowany poprzez naciśnięcie przycisku pierwszego czujnika.
   - Dioda led znajdująca się przy czujniku zacznie świecić oznacza to, że czujnik jest aktywny
   - Po aktywacji na panelu LED wyświetlana jest górna kreska (-), symbolizująca włączony alarm.  
   - System pozostaje w stanie aktywnym, dopóki przynajmniej jeden czujnik jest włączony.

3. **Wykrywanie ruchu:**  
   - Gdy którykolwiek z czujników PIR wykryje ruch, panel LED przestaje wyświetlać górną kreskę (-).  
   - Zamiast tego wyświetlana jest liczba aktywnych czujników które wykryły ruch (wartość od 1 do 5).  
   - Liczba ta reprezentuje ilość czujników, które zarejestrowały ruch.

4. **Wyłączanie czujników:**  
   - Jeśli którykolwiek z czujników, który wykrył ruch zostanie wyłączony, liczba wyświetlana na panelu LED zostaje odpowiednio zmniejszona.  
   - Proces ten trwa, aż wszystkie czujniki zostaną wyłączone.

5. **Dezaktywacja alarmu:**  
   - Po dezaktywacji wszystkich czujników, panel LED ponownie wyświetla dolną kreskę (_), sygnalizując powrót systemu do trybu czuwania.  
   - Wszystkie czujniki są nieaktywne - alarm zostaje wyłączony do momentu aż któryś czujnik zostanie ponownie włączony.

## Autor

Kacper Szponar
21306

## Licencja

Projekt dostępny na licencji MIT.
