# ASK-Projekt-2

## Opis projektu

ASK zadanie semestralne 2 projekt Alarmu

Prosty system alarmowy oparty na mikrokontrolerze ATMega328P (Arduino), który monitoruje ruch za pomocą czujników PIR. Projekt umożliwia kontrolę statusu czujników, wyświetlanie informacji o stanie alarmu na panelu LED oraz rejestrację liczby wykrytych ruchów.

## Funkcjonalności

- **Jednostka sterująca:** ATMega328P (Arduino)
- **Obsługa minimum 5 czujników PIR**
  - Możliwość indywidualnego załączania/wyłączania czujników
  - Każdy czujnik wyposażony w diodę LED statusu (świecenie = aktywny, brak = nieaktywny)
- **Panel LED:**
  - Wyświetlanie statusu alarmu:
    - Aktywny: symbol górnej kreski (\_)
    - Nieaktywny: symbol dolnej kreski (-)
  - Licznik wykrytych ruchów od momentu aktywacji alarmu
- **Dokumentacja projektu w formacie PDF** (screeny, kody źródłowe, prezentacja działania)

## Wymagania sprzętowe

- ATMega328P (Arduino UNO lub kompatybilny)
- 5x czujnik PIR (np. HC-SR501)
- Panel LED (np. 7-segmentowy wyświetlacz lub inny kompatybilny)
- Przewody połączeniowe
- Dioda LED dla każdego czujnika PIR

## Wymagania programowe

- Arduino IDE
- Biblioteki: `Wire.h`, `LiquidCrystal.h` (jeśli panel LED to LCD)

## Instrukcja uruchomienia

1. Podłącz czujniki PIR oraz diody LED zgodnie ze schematem połączeń.
2. Wgraj kod źródłowy do ATMega328P za pomocą Arduino IDE.
3. Uruchom system i przetestuj działanie załączania/wyłączania czujników.

## Planowane funkcjonalności

-

## ...

-

## Autor

[Kacper Szponar]
[21306]

## Licencja

Projekt dostępny na licencji MIT.
