# ORCS VS HUMANS

## Description

ORCS VS HUMANS is a turn by turn fight game, opposing different fighters each owning weapons, armors and skills.

A weapon deals damage, an armor can take damage instead of the fighter, and a skill has a special behaviour, that can increase damage, heal the fighter, etc.

All skills have a cooldown ; that means you can't use a skill twice before the cooldown timer is down. They also have a hit rate. Note that a failed hit rate will trigger the cooldown too.

Every fight starts with an initiative roll. Each fighter roll a 100 faces dice, and the one with the higher score starts the fight.

A fighter win the fight when his oponnent dies.

## Technical description

This project is part of a technical test for a video game company.

Here is a description of the different important parts of the project :

### Design Patterns

The project mainly use two design patterns : Singleton and State Machine.

#### Singleton

Because some data are needed in different classes, there is a DataManager class that is a Singleton. This way, for example, when displaying the differents fighters to the player, a simple call to ``DataManager::GetInstance().GetFighters()`` allows to get all the loaded fighters. The same kind of method is available for the weapons, the armors and the skills.

The singleton also includes a copy of the fighter the player chose, and a copy of the enemy's fighter. In addition, there is a whole fight logs that is available, in a way to notify the player about the different actions he did and the enemy did.

#### State Machine

I used State Machine to structure the game in different states, each with a starting method and an ending method. This way, each state of the game is well framed from A to Z and adding content is simplier.

This game includes two different state machines. The first one, ``AppBehiavour``, concerns the global game behaviour. The different states are : 1. Loading the data ; 2. Main menu ; 3. How to play - Rules ; 4. Select a fighter ; 5. Fight part.

The second state machine, ``FightBehaviour``, concerns the fight part behaviour. The different states are : 1. Roll of the initiative ; 2. Player's turn ; 3. Enemy's turn (Really basic IA) ; 4. End fight (Depending on who dies, the game is won or lost)

In a way to structure the code, the master state machine and the state machine's states are inherited from base classes ``MState`` and ``StateMachine``.

### Loading Data

As explained previously, the important data (as the fighters, the weapons, etc.) are stored in the DataManager. But at each launch, all the data are loaded from json files. These files are MANDATORY to launch the game.

## External libraries

This project use only one external library : ``nlohmann/json`` (link: https://github.com/nlohmann/json) A special thanks to nlohmann thus!

It is used in the ``DataManager`` to read the different json files that contains all the game data.

## Other

Since I hadn't coded in C++ this way for a long time, the whole project took me about 20 hours to complete, spread over almost 3 weeks.

I hope you'll enjoy the game, because I enjoyed a lot to develop it !
