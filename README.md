# Thomas-Was-Alone
# 🎮 Joc de Plataformes amb C++ i SFML

**Projecte de Programació Orientada a Objectes**  
*1r Curs - Grau Superior en Desenvolupament d'Aplicacions Multiplataforma*

---

## 📝 Descripció del Projecte

He creat un joc de plataformes 2D cooperatiu utilitzant C++ i la llibreria SFML. El joc requereix que dos jugadors (o un jugador controlant ambdós personatges) arribin junts a la meta mentre eviten enemics i superen obstacles.

### 🎯 Objectius del Projecte

Aquest projecte m'ha servit per aprendre i aplicar:
- Programació Orientada a Objectes (POO)
- Herència i polimorfisme
- Gestió dinàmica de memòria (punters)
- Lectura i escriptura de fitxers
- Estructures de dades (vectors)
- Arquitectura de videojocs

---

## 🕹️ Com Jugar

### Controls:

**Thomas (Personatge Verd):**
- `W` - Saltar
- `A` - Moure a l'esquerra
- `D` - Moure a la dreta

**Bob (Personatge Blau):**
- `↑` - Saltar
- `←` - Moure a l'esquerra
- `→` - Moure a la dreta

**Controls Generals:**
- `P` - Pausar/Reprendre el joc
- `ESC` - Sortir del joc

### Objectiu:

🎯 **Ambdós personatges han d'arribar a la meta groga (quadrat groc)**

⚠️ **Evita els enemics:**
- 🟠 **Enemics taronja** - Patrullen horitzontalment
- 🟣 **Enemics morats** - Volen verticalment

Si toques un enemic, tornes a la posició inicial del nivell!

### Sistema de Puntuació:

```
Puntuació = (Nivells completats × 100) - (Morts × 10)
```

- Completar un nivell: **+100 punts**
- Morir: **-10 punts**
- El teu rècord es guarda automàticament!

---

## 🏗️ Arquitectura del Projecte

### Estructura de Classes (POO)

He aplicat els principis de Programació Orientada a Objectes creant una jerarquia de classes:

```
GameObject (classe base abstracta)
    ├── Character (personatges jugables)
    │   ├── Thomas
    │   └── Bob
    ├── Platform (plataformes)
    └── Enemy (enemics)
        ├── PatrolEnemy (patrulla horitzontal)
        └── FlyingEnemy (vola vertical)
```

### 📂 Fitxers del Projecte

#### Fitxers principals:
- `MotorVideojocs.cpp` - Punt d'entrada (main)
- `Game.h` / `Game.cpp` - Classe principal del joc (bucle, lògica)

#### Classes base:
- `GameObject.h` / `GameObject.cpp` - Classe base per tots els objectes del joc
- `Character.h` / `Character.cpp` - Classe base per personatges jugables

#### Personatges:
- `Thomas.h` / `Thomas.cpp` - Personatge controlat amb WASD
- `Bob.h` / `Bob.cpp` - Personatge controlat amb fletxes

#### Enemics (amb punters!):
- `Enemy.h` / `Enemy.cpp` - Classe base per enemics
- `PatrolEnemy.h` / `PatrolEnemy.cpp` - Enemic que patrulla
- `FlyingEnemy.h` / `FlyingEnemy.cpp` - Enemic volador

#### Entorn:
- `Platform.h` / `Platform.cpp` - Plataformes i gestió de nivells

#### Persistència:
- `GameData.h` / `GameData.cpp` - Sistema de guardat de dades

#### Fitxers de dades:
- `level1.txt` / `level2.txt` - Nivells del joc
- `gamedata.txt` - Dades guardades (puntuació, progrés)
- `KOMIKAP_.ttf` - Font per als textos

---

## 🛠️ Com Compilar i Executar

### Requisits:

1. **Compilador C++** (MinGW, Visual Studio, g++, etc.)
2. **Llibreria SFML 2.5+** instal·lada
3. Tots els fitxers `.h` i `.cpp` del projecte

### Compilació amb Visual Studio:

1. Crear un projecte nou de C++
2. Afegir tots els fitxers `.h` i `.cpp` al projecte
3. Configurar SFML:
   - **Project Properties → C/C++ → General → Additional Include Directories**: Afegir la carpeta `include` d'SFML
   - **Project Properties → Linker → General → Additional Library Directories**: Afegir la carpeta `lib` d'SFML
   - **Project Properties → Linker → Input → Additional Dependencies**: Afegir:
     ```
     sfml-graphics.lib
     sfml-window.lib
     sfml-system.lib
     ```
4. Compilar i executar!

### Compilació per línia de comandes (Linux):

```bash
g++ -c *.cpp
g++ *.o -o JocPlataformes -lsfml-graphics -lsfml-window -lsfml-system
./JocPlataformes
```

### Compilació per línia de comandes (Windows MinGW):

```bash
g++ -c *.cpp -I"C:/SFML/include"
g++ *.o -o JocPlataformes.exe -L"C:/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system
JocPlataformes.exe
```

## 📚 Recursos Utilitzats

- **SFML Documentation**: https://www.sfml-dev.org/documentation/
- **Learn C++**: https://www.learncpp.com/
- **YouTube tutorials** sobre arquitectura de videojocs
- **StackOverflow** per resoldre errors específics
- **Documentació de Visual Studio**

---

**Data de creació:** Febrer 2026  
**Versió:** 1.0  
**Llenguatge:** C++17  
**Llibreries:** SFML 2.5+

---
