# Plank
Extensible Tabletop Game Server

States
* Set of transitions with logic to determine which transitions are available to which players
* Player Select Oracle: Determine which state machine a player will enter

Transition
* Actions players may take to ove between states. The only way to mutate the game state.
* Dependant transitions trigger when another player triggers a transition

Hierarchy of state machines with meta games


```
Machine {
  intial List<MachineState>
  end List<MachineState>
}

MachineState {
  List<Transition>
}

Oracle: Player x GameState -> MachineState

Transition: GameState x MachineState -> GameState x MachineState x List<Player>
                                                                     ^ players to take epsilon
Transition may also trigger epsilon transitions

GetValidTransitoins GameState x Player x MachiineState -> List<Transition>

VictoryCheck GameState -> bool (added to a transition)
```

Building Blocks
* Cards
* Dice
  - Can be used to implement spinners etc

Engine Architecture
* Players run in the automaton's gameplay loop blocking waiting for transitions to fire
* Network Dispatch loop listens for incoming connections from players to process requests

![Alt text](docs/arch.png?raw=true "Arch")

The architecture can really be broken into 3 broad categories. The engine, which handles all of the player interaction and synchronization. The automaton and components libraries that offer reusable parts. The game specific user code that uses those reusable parts from the components and automaton libraries to implement the game specific automaton and state. That automaton can then be run by the engine and the transitions on that automaton will mutate the game state as the game progresses.

* Engine: This component manages all of the network connections to the players as well as the player data. Any request to take a transition or a prompt for the user comes through the engine.
* Client Library: This component is tightly coupled to the engine as it is the communication mechanism with which the players interact with the engine. The client library provides an API so that the actual interface does not need to be coupled to the engine code.
* Auomaton Library: Thie library provides the game flow primitives necessary to implement the game logic.
* Components Library: This library provides common components that will be seen in many games and therefore it is worth generating a common framework both for consistency as well as for general reusability. Things like decks or cards, dice, cups of dice, etc are implemented here.
* Automaton: The game specific specificaiton of the nodes and transitions.
* Game State: THe game specific collection of state components that will be mutated by the transitions. The only persistent state in the game, with the exception of the current position in the automaton, should be stored in the game state. This can simplify serializing the state of the game and make for simpler rollbacks on error.
