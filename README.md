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

## Opis kodu

1. **Tablice pinów:**
   - `pirPins[]`, `buttonPins[]`, `ledPins[]` – przechowują numery pinów odpowiadających czujnikom PIR, przyciskom oraz diodom LED.
   
2. **Inicjalizacja:**
   - W funkcji `setup()` ustawiane są tryby pracy pinów jako wejścia (czujniki, przyciski) lub wyjścia (diody, rejestr przesuwny).
   - Włączany jest port szeregowy do monitorowania zdarzeń.

3. **Obsługa przycisków:**
   - W pętli `loop()` przyciski są odczytywane za pomocą `digitalRead()`.  
   - Naciśnięcie przycisku zmienia status czujnika (aktywny/nieaktywny).

4. **Wykrywanie ruchu:**
   - Czujniki PIR monitorują obecność ruchu. Jeśli ruch zostanie wykryty, zmienne `pirDetected[]` dla danego czujnika są ustawiane na `true`.

5. **Wyświetlanie na panelu LED:**
   - Funkcja `writeLED(byte data)` przesyła dane do rejestru przesuwnego (74HC595), który steruje 7-segmentowym wyświetlaczem LED.  
   - Wartości z tablicy `liczby[]` odpowiadają cyfrom od 1 do 5.

### Zmienne

- `sensorEnabled[]` – tablica przechowująca status każdego czujnika (aktywny/nieaktywny).
- `pirDetected[]` – tablica wskazująca, które czujniki wykryły ruch.
- `pirDetCount` – liczba aktywnych czujników, które zarejestrowały ruch.

## Autor

Kacper Szponar
21306

## Licencja

Projekt dostępny na licencji MIT.
