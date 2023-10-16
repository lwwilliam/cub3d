# Raycasting 3d game

This is a simple raycasting program where you can move around and view a 2d map on a 3d plane

## Installation

Run the makefile.

```bash
make
```

## Usage

```bash
# format: ./cub3d {map directory}
example:
./cub3d maps/pdf.cub
```

## Map

First segment incudes the path for wall textures along with the direction of the wall texture.

Second segment is the color for the floor and ceiling.

Last segment is the 2d map itself. '1' representing a wall, '0' representing empty cell, 'N/S/E/W' depicting the player start position as well as the direction it faces.

## Contributors
image and map redering:
https://github.com/lwwilliam

game logic and raycasting:
https://github.com/sealw4ll

## Game preview
