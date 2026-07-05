# a) Modelado de las previaturas

## Descripción

- Cada vértice representa una asignatura.
- Cada arista A → B indica que A es previa de B.
- El grafo es dirigido.
- Es acíclico.
- No necesariamente es conexo.
- No es un árbol.

## Ejemplo

```mermaid
graph LR

Introduccion["Introducción al Diseño"]
Conceptos["Conceptos Básicos"]
Textil1["Diseño Textil I"]
Textil2["Diseño Textil II"]

Introduccion --> Textil1
Conceptos --> Textil1
Textil1 --> Textil2