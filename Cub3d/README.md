# Cub3D

Un proyecto de raycasting 3D inspirado en Wolfenstein 3D, implementado en C usando MiniLibX.

## Descripción

Cub3D es un proyecto de la escuela 42 que implementa un motor de renderizado 3D básico utilizando la técnica de raycasting. El jugador puede moverse por un laberinto y ver el mundo en perspectiva 3D.

## Características

- **Raycasting**: Renderizado 3D en tiempo real usando técnicas de raycasting
- **Texturas**: Diferentes texturas para cada pared (Norte, Sur, Este, Oeste)
- **Movimiento del jugador**: WASD para moverse, flechas para rotar
- **Colisiones**: El jugador no puede atravesar paredes
- **Archivo de configuración**: Mapas y texturas definidos en archivos `.cub`

## Compilación

```bash
make
```

## Uso

```bash
./cub3D maps/test.cub
```

## Controles

- **W**: Mover hacia adelante
- **S**: Mover hacia atrás  
- **A**: Mover hacia la izquierda
- **D**: Mover hacia la derecha
- **←**: Rotar hacia la izquierda
- **→**: Rotar hacia la derecha
- **ESC**: Salir del juego

## Formato del archivo .cub

El archivo de configuración debe contener:

1. **Texturas de paredes**:
   - `NO ./path/to/north_texture.xpm`
   - `SO ./path/to/south_texture.xpm`
   - `WE ./path/to/west_texture.xpm`
   - `EA ./path/to/east_texture.xpm`

2. **Colores de suelo y techo**:
   - `F R,G,B` (Floor/Suelo)
   - `C R,G,B` (Ceiling/Techo)

3. **Mapa**:
   - `0`: Espacio vacío
   - `1`: Pared
   - `N/S/E/W`: Posición inicial del jugador (Norte/Sur/Este/Oeste)
   - Espacios: Área fuera del mapa

### Ejemplo de archivo .cub

```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Estructura del proyecto

```
Cub3d/
├── Makefile
├── inc/
│   └── cub3d.h
├── src/
│   ├── main.c
│   ├── init.c
│   ├── parser.c
│   ├── parser_utils.c
│   ├── map_validation.c
│   ├── raycasting.c
│   ├── raycasting_utils.c
│   ├── render.c
│   ├── events.c
│   ├── utils.c
│   └── cleanup.c
├── maps/
│   └── test.cub
└── textures/
    ├── north_wall.xpm
    ├── south_wall.xpm
    ├── east_wall.xpm
    └── west_wall.xpm
```

## Dependencias

- **MiniLibX**: Biblioteca gráfica de 42
- **Libft**: Biblioteca personalizada de funciones C
- **Math library**: Para funciones trigonométricas

## Instalación de dependencias en Ubuntu/Debian

```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

## Norma de 42

Este proyecto sigue estrictamente la norma de 42:

- Máximo 25 líneas por función
- Máximo 5 funciones por archivo
- Nombres de variables en snake_case
- Nombres de funciones descriptivos
- Header con información de autor y fecha
- Gestión adecuada de memoria
- Sin leaks de memoria

## Autor

Desarrollado por **sbenitez** para la escuela 42 Málaga.

## Licencia

Este proyecto es parte del curriculum de 42 y está destinado únicamente para fines educativos.
