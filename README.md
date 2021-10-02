# SFML-Platformer
This project is a test to learn the SFML API. The overall goal of this project is to make a simple platformer.

## Outline
- [TODO List](#todo_id)
- [Compile instructions](#compile_instruction_id)
    - [Debug](#debug_instruction)
    - [Release](#release_instruction)

## <a name="todo_id"></a> TODO List
- [ ] Define Goals
- [ ] Make Better README
- [ ] Define better build chain

## <a name="compile_instruction_id"></a> Compile Instruction
This project uses the atom build package to build the project. If you don't want to use atom these are the compile instructions (**Requires the g++ compiler**).

### <a name="debug_instruction"></a> Debug
`g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o build/debug/main -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp`

### <a name="release_instruction"></a> Release
`g++ -c src/*.cpp -std=c++14 -m64 -O3 -g -Wall -I include && g++ *.o -o build/release/main -s -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp`
