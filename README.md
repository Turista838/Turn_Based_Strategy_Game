# Turn_Based_Strategy_Game

### Project developed for 'Object Oriented Programming', a second year subject @ISEC

Made in collaboration with another student

#### Guide:

This is a singleplayer turn based strategy game where the main goal is to conquer every territory.

**The World**<br/>
The world where the game takes place is made up of territories located on continents and islands.

**The Empire**<br/>
The player's empire starts out as their starting territory. According to the player's decisions and the luck factor, the empire can be expanded to encompass more territories.
Each turn, the player's territories produce goods and gold, needed to maintain the empire and trigger certain actions. The empire includes a warehouse with a capacity of 3 units of products and a vault with a capacity of 3 gold units. Under certain circumstances, both the warehouse and the vault can be increased in capacity. Products and gold that are obtained but no longer fit in the warehouse or vault will be wasted. If the empire implements a trading system, it is possible to exchange products and gold, according to the player's strategy and needs.<br/>The empire has a military strength that varies between 0 and 3 units. Military strength can be increased up to a maximum value of 5 units.
There are specific types of military force units that may be needed to attack or defend under certain circumstances. Initially, the empire does not have any of this type of specialized military equipment, but it may acquire it.<br/>There are technologies that allow you to improve certain aspects of the empire. The player will be able to buy these technologies.

**Territories**<br/>
There are 3 categories of territory: Home Territory, Continent or Island. Islands are less accessible territories, they can only be targeted for attempted conquest if the empire has at least 5 territories and if it has the homing missile technology.

**Technologies**<br/>
There are several technologies that are tools of strategic value. It is always possible to buy any tech, as long as the player has the necessary gold to pay (ie the stock of tech on sale is infinite).
The existing technologies are as follows:
* Military drones: when acquired, this technology raises the maximum military strength limit to 5. This does not mean that you have 5 units: you only have up to 5. It costs 3 gold units.
* Guided Missiles: This technology is needed to conquer islands. It costs 4 gold units. It is a technology and not ammunition, that is, from the moment you have it, you can (try) to conquer the islands you want so that the missiles don't run out.
* Territorial defenses: it is a special defense equipment that adds 1 unit to the resistance of the invaded territory during an invasion event (same logic as homing missiles - they don't wear out). It costs 4 gold units.
* Stock exchange: trading system that makes exchanges between products and gold possible, as referred to in the description of phase 2 of the shift (collecting products and gold). It costs 2 gold units.
* Central Bank: when acquired, this technology increases the storage capacity of the warehouse and the empire's vault by two units: they can now store up to 5 products and 5 gold units, respectively. The Empire does not automatically acquire these products and gold - it can only accumulate up to these quantities. No matter how many times you buy this technology, it is not possible to exceed the maximum value of 5 - you can buy it but it has no effect.

The game is divided in 4 stages:

#### Stage 0:
Create territories using the command ```criar XXX Y``` where XXX can is the territory type () and Y the number of how many of that type you want to create.<br/>
Type ```avanca``` to start the game.

#### Stage 1:
Type ```conquista XXXX``` to conquer a territory. XXXX is the name of it.
Type ```passa``` to get to the next stage without conquering any territory.

#### Stage 2:
Game automatically collects products and gold from the owned territories.

#### Stage 3:
You can buy technologies int this stage using the command ```adquire XXXX```, where XXXX is the name of the tech you want to acquire.
Type ```avanca``` to get to the next stage without acquiring any technology.

#### Stage 4:
Event stage. where one of these can randomly happen:
* Abandoned Resource: An abandoned resource has been found and provides the empire with a unit of products or gold as found in the first year of the game (product) or the second (gold). If the maximum allowed value has already been reached, the resource found is wasted (and no other event occurs in its place).
* Invasion: any other competing empire, of which there is no record at all, is trying to conquer one of the player's territories. Choose the most recently conquered territory. A luck factor is randomly generated, number between 1 and 6 inclusive. This luck factor is added to the strength of the invasion, which has a value of 2 in the first year and 3 in the second year. If the result is less than the resistance of the territory, the invasion fails. Otherwise, the invasion takes place, and the territory ceases to be part of the empire, thus ceasing to contribute to creation and products and gold. In case the empire has the territorial defenses technology, 1 is added to the resistance level of the territory that is targeted by the invasion. If the empire is only constituted by the Initial Territory, the success of the invasion leads to the loss of the game.
* Diplomatic alliance: an alliance was signed with another empire of which there is also no record. As a result, the military strength increases by one unit, as long as the maximum number of possible units in the empire is not exceeded (otherwise, nothing is gained, but the event “counts” anyway).
* No event: nothing happens.

#### List of Commands:

#### List of Technologies:
