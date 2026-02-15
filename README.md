# Bucket Sort

In deze opdracht implementeren en analyseren we Bucket Sort. 

## Algoritme

Bucket Sort start met:
- een 1D array (of `vector`) van `n` getallen die gesorteerd moet worden;
- een 2D bucket-array met 10 rijen (0 t/m 9) en `n` kolommen (0 t/m `n-1`), waarbij elke rij een bucket voorstelt.

Per digit-positie werkt het algoritme als volgt:
1. **Distribution pass**: plaats elk getal in de bucket die hoort bij de huidige digit (bijv. eenheden: 97 -> bucket 7, 3 -> bucket 3, 100 -> bucket 0).
2. **Gathering pass**: lees de buckets in volgorde 0 t/m 9 uit en schrijf de waarden terug naar de originele array.
3. Herhaal dit voor de volgende digit-positie (tientallen, honderdtallen, etc.). Na de laatste gathering pass is de array gesorteerd.

## Build & Run (Ubuntu/WSL)

In deze repository staat de code in `src/main.cpp`.

### Compileren
```bash
g++ -O2 -std=c++20 -Wall -Wextra -pedantic src/main.cpp -o bucketsort
```

### Runnen
```bash
./bucketsort
```

### Debug-build (handig tijdens ontwikkelen)
```bash
g++ -O0 -g -std=c++20 -Wall -Wextra -pedantic src/main.cpp -o bucketsort
./bucketsort
```

## Quick Start

Clone de repository en voer de volgende commando’s uit:

```bash
git clone <repo-link>
cd <repo-naam>
g++ -O2 -std=c++20 -Wall -Wextra -pedantic src/main.cpp -o bucketsort
./bucketsort
```