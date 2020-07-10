# Wolf3d

Wolf3d is a project inspired by the world-famous eponymous 90's game, which was one of the first FPS ever. The project's goal is to explore ray-casting by making a dynamic view inside a maze.

This project was realised with [pasosa-s](https://github.com/pasosa-s).

## Our project

Instead of Wolf3d, our program could be called TheBindingOfIsaac3d. By using some sprites from *The Binding of Isaac: Rebirth* game and re-drawing some other ones from scratch, we tried to envision what this top-down game, using two-dimensional sprites, would look like in 3d. Since we don't have an animation system yet, you won't have shooting and face enemies like you would in the original game. That's why we decided to just stick to the spirit of the game and ended up making a short puzzle game out of it.

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

This program is using the minilibx, a Mac OS graphic library developped at 42 school which we are using in our first graphic programming projects. Therefore, it won't compile if you are on a Linux OS. **No screenshot for this one. If you are interested in this project and want to see more, I suggest checking the final and more complete version (using SDL2 and Linux compatible) here :** [Doom-Nukem](https://github.com/JulienMousset/Doom-Nukem).
