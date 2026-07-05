# Programación III - Obligatorio 2026

Repositorio del trabajo obligatorio de Programación III.

---

# 📌 Tecnologías

- C++
- GNU g++
- Visual Studio Code
- Git / GitHub

Compatible con:

- macOS
- Windows

---

# 1️⃣ Instalación del Compilador

## 🍎 macOS

Verificar instalación:

```bash
g++ --version
```

Si no está instalado:

```bash
xcode-select --install
```

---

## 🪟 Windows

Instalar MinGW (o MSYS2) incluyendo:

```
mingw32-gcc-g++
```

Agregar la carpeta `bin` al PATH.

Verificar:

```bash
g++ --version
```

---

# 2️⃣ Compilación

Mientras el proyecto crece, la compilación dependerá de la cantidad de módulos.

Ejemplo:

```bash
g++ *.cpp -o main
```

o

```bash
g++ main.cpp src/*.cpp -o main
```

Luego ejecutar:

## macOS

```bash
./main
```

## Windows

```bash
main.exe
```

---

# 3️⃣ Visual Studio Code

Instalar la extensión:

**C/C++**

Autor: Microsoft

ID:

```
ms-vscode.cpptools
```

---

# 4️⃣ Formateo Automático

Abrir:

- macOS → `Cmd + Shift + P`
- Windows → `Ctrl + Shift + P`

Ir a:

```
Preferences: Open Settings (JSON)
```

Agregar:

```json
{
    "editor.formatOnSave": true,
    "[cpp]": {
        "editor.defaultFormatter": "ms-vscode.cpptools"
    }
}
```

---

# 5️⃣ Organización del Proyecto

La implementación estará modularizada.

Cada módulo deberá tener:

```
Modulo.h
Modulo.cpp
```

El archivo `.h` contendrá únicamente la interfaz pública.

El archivo `.cpp` contendrá la implementación.

Nunca incluir archivos `.cpp`.

---

# 6️⃣ Protección de Headers

Todos los headers deberán utilizar include guards.

Ejemplo:

```cpp
#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

// contenido

#endif
```

---

# 7️⃣ Git Flow

La rama principal del proyecto es:

```
develop
```

No trabajar directamente sobre ella.

Antes de comenzar una funcionalidad:

```bash
git pull origin develop
```

Crear una nueva rama:

```bash
git checkout -b feature/nombre-feature
```

Ejemplo:

```bash
git checkout -b feature/alumnos
```

---

# 8️⃣ Commits

Agregar cambios:

```bash
git add .
```

Crear commit:

```bash
git commit -m "Descripción clara del cambio"
```

Ejemplos:

```bash
git commit -m "Implementa módulo Alumno"

git commit -m "Agrega operaciones del Grafo"

git commit -m "Corrige inserción de Escolaridad"
```

Buenas prácticas:

- Un cambio lógico por commit.
- Mensajes descriptivos.
- No subir código que no compile.

---

# 9️⃣ Push

```bash
git push origin feature/nombre-feature
```

---

# 🔟 Pull Request

Una vez finalizada la funcionalidad:

- Crear Pull Request hacia `develop`.
- Verificar que el proyecto compile.
- Esperar revisión de otro integrante antes del merge.

---

# 1️⃣1️⃣ Convenciones

## Tipos

```cpp
Alumno
Asignatura
Curso
Fecha
```

## Funciones

```cpp
RegistrarAlumno()
AgregarPrevia()
ExisteAlumno()
```

## Variables

```cpp
cantAlumnos
fechaActual
primerNodo
```

## Constantes

```cpp
MAX_ASIGNATURAS
MAX_ALUMNOS
```

---

# 1️⃣2️⃣ Modularización

Cada módulo deberá ocultar completamente su implementación.

Los demás módulos solamente podrán interactuar mediante sus operaciones públicas.

No acceder directamente a estructuras internas de otro módulo.

---

# 1️⃣3️⃣ Orden sugerido de implementación

1. Boolean
2. Fecha
3. Curso
4. Asignatura
5. Grafo de Previaturas
6. Escolaridad
7. Alumno
8. Diccionario de Alumnos
9. Sistema
10. Main

---

# 📌 Reglas del Proyecto

- No trabajar directamente sobre `develop`.
- Una funcionalidad por branch.
- `develop` debe compilar siempre.
- Realizar `git pull` antes de comenzar una nueva tarea.
- No subir código incompleto o que no compile.
- Todo merge debe realizarse mediante Pull Request.
- Mantener el código correctamente formateado.

---

# 🎯 Objetivo

Mantener un proyecto ordenado, modular y fácil de mantener durante todo el desarrollo del obligatorio.
