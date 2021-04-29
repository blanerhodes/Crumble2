# Settlers of Catan - CS Software Engineering Final Project
by Blane Rhodes & Johana Di Girolamo 


## How to play the game:

Settlers of Catan is a board game about claiming settlements, and eventually upgrading to cities, strategically located around different resources to continue growth in resources and ultimately have the highest score.
![Game Screen](https://github.com/blanerhodes/Crumble2/tree/master/images/GameScreen.png)

Upon startup of our game, each player will start with the proper amount of resources to place two roads and two settlements. They must strategically place these so that they can gain resources as they roll the dice.
// image of an example of placing the two houses and roads for both players
![Player placements](https://github.com/blanerhodes/Crumble2/tree/master/images/PlayerFirstMoves.png)

The numbers inside of each resource tile on the map represents the number they must roll to gain that resource. A settlement gains one of that resource, and a city gains two. 

Once a player's turn starts, they must roll their dice to gain resources, and then they are free to buy more structures and place them on the map, or simply end turn to continue racking up resources.
![Game Screen](https://github.com/blanerhodes/Crumble2/tree/master/images/GameScreen.png)


## How the game was made:

For our game, we worked on a fully custom and self-made game engine we call **Crumble**. With the help of online tutorials, we were able to create Crumble to fully control and host our game of Settlers of Catan.

Here are the steps we took:
1. Creation of crumble (Documentation for Crumble Engine found [HERE](https://github.com/blanerhodes/Crumble2/tree/master/Documentation "Documentation on GitHub"))
2. Created a **GameLayer** to hold most of our information for the game (Players, Dice Roll, and other functionalities). Additionally, created the **Players** class to keep track of all player information to be tracked in GameLayer.
3. Created the Textures for the Map and Cards using Adobe Photoshop
![Building Costs card - example texture](https://github.com/blanerhodes/Crumble2/tree/master/images/BuildingCostsCard.png)
4. Created **TileMap** to take the textures and properly print it on the screen
5. Created ActiveFrames on the **GameLayer** to track location of mouse clicks on the map and properly place the Structures on the map.
![ActiveFrames code](https://github.com/blanerhodes/Crumble2/tree/master/images/ActiveFrameCode.png)
6. Created **CardsLayer** to take the textures of the cards and properly print it on the screen - on both sides for each player.
7. Created **DiceAndScoreLayer** to print out the textures of the dice and the score of each player.
8. Updated ActiveFrames to keep track of all new information on the screen
9. Updated **GameLayer** to have the functionalities of the dice roll, keeping score of each player and more.
![Continued gameplay](https://github.com/blanerhodes/Crumble2/tree/master/images/ContinuedGameplay.png)
10. Game ends on a score of 10.