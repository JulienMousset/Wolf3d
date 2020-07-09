# Wolf3d

Wolf3d is a project inspired by the world-famous eponymous 90's game, which was one of the first FPS ever. The project's goal is to explore ray-casting by making a dynamic view inside a maze.

This project was realised with [@pasosa-s](https://github.com/pasosa-s).

## Our project

Instead of Wolf3d, our program could be called TheBindingOfIsaac3d. By using sprites from "The Binding of Isaac: Rebirth" and re-drawing some from scratch that we couldn't use because of the change of perspective between the original game (top-down) and ours (first person), we tried to imagine what BOI would look like in 3d. Despite that, our game is not a copy of BOI since there is no animation, so no shooting or enemies. Therefore, we just kept the original spirit of the game and tried to make a little puzzle game with what we had.

## How to use

- Compile : `make`
- Remove object files : `make clean`
- Remove object files and program : `make fclean`
- Start fresh and re-compile : `make re`

## Executing

Execute the program with the map of your choice like this : `./wolf3d maps/level_1`

You can create your own map or play with one of our own three levels that are in the `maps` folder.

Press `H` to print the controls inside the program.

## Warning

This program is using the minilibx, a Mac OS graphic library developped at 42 school which we are using in our first graphic programming projects. Therefore, it won't compile if you are on a Linux OS.
