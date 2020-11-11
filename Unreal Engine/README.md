This is a collection of projects and creations within Unreal Engine 4 that I developed.

1) Assets_Demo showcases the basic gameplay, weapons, and AI within my game as well as a frost trap from R6 Siege in a controlled environment.
2) Demo_Compressed will show the level in the game that I constructed along with structures and environments that I developed myself.
However, I had to compress it due to file restraints within github, so the quality of the video is quite poor compared to the
actual quality of the game.
3) Ela_GrzmotMine showcases Ela's Grzmot mine from R6 Siege. The Grzmot mine applies a stun and slow effect for about 6 seconds when a player moves within a certain radius of the mine.
4) EDD Mine demos Kapkan's tripwire mine. A laser is shown at first, but it fades away similar to the actual in-game mine.
These go on doorways and can be set off by either the player, which damages their armor and health, or the zombie AI I developed
5) Banshee_NoModel shows Melusi's Banshee gadget without a 3D model (currently a white cube) that will be imported from blender and updated when I have the time to model it.
The Banshee gadget slows down players when they are within a certain radius of the gadget. It cannot be shot, only destroyed by a melee hit or explosives.
6) GuMine_NoModel displays Lesion's Gu Mine without a 3D model (currently a dark sphere) that will be imported from blender and updated when I have the time to model it.
The Gu mine activates when a player steps on the gu. It will slow the player down and apply 5 damage every 3 seconds after the player steps on it as long as the player does not take the gu mine out. If the player presses a button (in this case "V"), then the action to take the gu mine out occurs, which takes 3 seconds. The player can stop pushing the button, but the gu mine will remain until the player holds it down for the 3 seconds.
7) DestructibleWall showcases a wooden wall that the player can shoot through, making small bullet holes. The player can also carve the wall with bullets, allowing them to take out chunks. Grenades can be used to destroy the wall completely, depending on if it is in its blast radius, or large portions. There are two parts to this video. The first half is where the wall has simulated physics, meaning it will fall over when shot or blown up. The second half shows it without simulated physics on the original wall, allowing for a better perspective on the destruction and possibilities on the implementation of barricaded doorways and windows.
8) JagerADS is a video of Jager's Active Defense System which targets throwables, such as grenades, flashbangs, smokes, etc. and destroys up to three of them in a radius around itself. Currently its model is a yellow box and the trail is a grey line that goes from the ADS to where the grenade was hit within the area of effect that the ADS has. I had to use 3D trigonometry and discrete math to calculate where the grenade was within the sphere and move the lines position and rotation accordingly.
9) Soon to be added: Deployable shield, poisonous gas smoke canister, barbed wire, drone

I am also by myself and I am not attempting to construct a complete game to sell, but rather show what I have learned and now know.
Regardless, I have learned a lot by myself within Unreal Engine and this folder supports that.
