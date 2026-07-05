# b) Análisis de Tipos Abstractos de Datos

## Introducción

El análisis de Tipos Abstractos de Datos consiste en identificar los objetos presentes en la realidad del problema y modelarlos mediante TAD adecuados, sin considerar aún su implementación.

A continuación se presenta el análisis de la realidad propuesta.

---

# Academia

La academia administra toda la información del sistema, compuesta por:

- Asignaturas.
- Alumnos.
- Régimen de previaturas.

Estos elementos representan componentes diferentes de un mismo objeto, por lo que la academia se modela como un Producto Cartesiano.

Por lo tanto:

Academia = Producto Cartesiano(
    Asignaturas,
    Alumnos,
    Previaturas
)

---

# Asignatura

Cada asignatura posee la siguiente información:

- Número.
- Nombre.
- Cantidad de horas.
- Indica si es optativa.

Por tratarse de un único objeto compuesto por varios atributos, se modela mediante un Producto Cartesiano.

Por lo tanto:

Asignatura = Producto Cartesiano(
    Número,
    Nombre,
    CantidadHoras,
    EsOptativa
)

---

# Asignaturas

Las asignaturas se identifican mediante su número.

No pueden existir dos asignaturas con el mismo número.

Por lo tanto:

Asignaturas = Diccionario(Asignatura)

Clave: Número de asignatura.

---

# Fecha

Una fecha está compuesta por:

- Día.
- Mes.
- Año.

Por lo tanto:

Fecha = Producto Cartesiano(
    Día,
    Mes,
    Año
)

---

# Curso

Cada curso registra:

- Número de asignatura.
- Fecha de finalización.
- Calificación final.

Por tratarse de un único objeto compuesto por varios atributos, se modela mediante un Producto Cartesiano.

Por lo tanto:

Curso = Producto Cartesiano(
    NúmeroAsignatura,
    FechaFinalización,
    Calificación
)

---

# Escolaridad

La escolaridad representa el conjunto de cursos realizados por un alumno.

Los cursos deben mantenerse ordenados cronológicamente según su fecha de finalización.

Además, una misma asignatura puede aparecer varias veces debido a que un alumno puede recursarla hasta aprobarla.

Por lo tanto:

Escolaridad = Secuencia(Curso)

---

# Alumno

Cada alumno posee:

- Cédula.
- Nombre.
- Apellido.
- Teléfono.
- Escolaridad.

Por tratarse de un único objeto compuesto por varios atributos, se modela mediante un Producto Cartesiano.

Por lo tanto:

Alumno = Producto Cartesiano(
    Cédula,
    Nombre,
    Apellido,
    Teléfono,
    Escolaridad
)

---

# Alumnos

Los alumnos se identifican mediante su cédula.

No pueden existir dos alumnos con la misma cédula.

Por lo tanto:

Alumnos = Diccionario(Alumno)

Clave: Cédula.

---

# Previaturas

Las previaturas representan las relaciones existentes entre las asignaturas de la carrera.

Cada vértice representa una asignatura registrada.

Cada arista dirigida representa que una asignatura es previa directa de otra.

Debido a que no pueden existir dependencias circulares entre asignaturas, el grafo debe ser dirigido y acíclico.

Por lo tanto:

Previaturas = Grafo(Asignatura)