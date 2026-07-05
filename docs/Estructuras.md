# c) Elección de Estructuras de Datos

En esta sección se seleccionan las estructuras de datos más adecuadas para implementar los TAD identificados, justificando cada elección según cardinalidad, operaciones frecuentes y características de la información.

---

# Academia

## TAD

Producto Cartesiano.

## Estructura elegida

Registro (`struct`).

## Justificación

La academia agrupa los componentes principales del sistema:

- Asignaturas.
- Alumnos.
- Previaturas.

Por lo tanto, puede representarse como un registro que contiene esas tres partes.

---

# Asignatura

## TAD

Producto Cartesiano.

## Estructura elegida

Registro (`struct`).

## Justificación

Una asignatura posee un conjunto fijo de atributos:

- Número.
- Nombre.
- Cantidad de horas.
- Es optativa.

No representa una colección.

---

# Asignaturas

## TAD

Diccionario(Asignatura).

Clave: número de asignatura.

## Estructura elegida

Mapeo.

## Justificación

La carrera tiene una cantidad máxima de 30 asignaturas y sus números son consecutivos comenzando en 0.

Esto permite usar el número de asignatura como índice del mapeo, obteniendo acceso directo a cada asignatura.

---

# Fecha

## TAD

Producto Cartesiano.

## Estructura elegida

Registro (`struct`).

## Justificación

Una fecha está compuesta por día, mes y año. No representa una colección.

---

# Curso

## TAD

Producto Cartesiano.

## Estructura elegida

Registro (`struct`).

## Justificación

Un curso representa una instancia cursada por un alumno y contiene:

- Número de asignatura.
- Fecha de finalización.
- Calificación.

El nombre de la asignatura no se almacena en el curso, ya que puede obtenerse consultando el diccionario de asignaturas mediante el número de asignatura.

---

# Escolaridad

## TAD

Secuencia(Curso).

## Estructura elegida

Lista simplemente enlazada.

## Justificación

La escolaridad debe almacenarse en orden cronológico por fecha de finalización.

Además, un alumno puede recursar una misma asignatura varias veces, por lo que no corresponde usar Set ni Diccionario por número de asignatura.

La cantidad de cursos no tiene una cota fija, por lo que una lista enlazada es adecuada.

---

# Alumno

## TAD

Producto Cartesiano.

## Estructura elegida

Registro (`struct`).

## Justificación

Un alumno posee un conjunto fijo de atributos:

- Cédula.
- Nombre.
- Apellido.
- Teléfono.
- Escolaridad.

No representa una colección.

---

# Alumnos

## TAD

Diccionario(Alumno).

Clave: cédula.

## Estructura elegida

Hash.

## Justificación

Los alumnos se identifican por cédula y se requiere buscarlos frecuentemente para inscribirlos, registrar cursos y listar sus datos.

La academia tiene aproximadamente 100 alumnos, por lo que se puede estimar una cantidad adecuada de cubetas.

Por eso, Hash resulta adecuado para obtener búsquedas e inserciones eficientes en promedio.

---

# Previaturas

## TAD

Grafo dirigido acíclico.

## Estructura elegida

Matriz de adyacencia.

## Justificación

La cantidad máxima de asignaturas es 30, por lo que una matriz de 30 × 30 ocupa poca memoria.

Además, la cantidad de previaturas es elevada, por lo que conviene una estructura que permita consultar rápidamente si existe una previatura directa entre dos asignaturas.

La matriz de adyacencia permite consultar la existencia de una arista en tiempo constante.