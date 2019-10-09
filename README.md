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
