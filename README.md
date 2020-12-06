# FinalProjectSolitaire

Kate McCarthy, CSCI 2275 (Working Alone)

Summary:
This is a very rudimentary game of solitaire, with rules akin to to the "Easy" Mode on the Google solitaire game (https://www.google.com/search?q=play+solitaire), where a user can click a card, and if there is a viable move, it will move the card to that spot as opposed to having the user physically drag it around. The game functions by users typing in the card input to move a card or line of cards. The main components of the code are a linked list for the card lines, a stack for all the card piles, the algorithms to check if a move is viable, and a shuffle function for both the original deck and to reshuffle the discard pile. 


 H: [    ]   D: [    ]   C: [    ]   S: [    ]
 

|QH|   ||||  ||||   ||||   ||||   ||||   |||| 

       |KD|  ||||   ||||   ||||   ||||   ||||   
             |6C|   ||||   ||||   ||||   ||||   
                    |QS|   ||||   ||||   ||||
                           |8D|   ||||   ||||    
                                  |8S|   ||||  
                                         |7S|
                                         
||||   |4S|

Gameplay:
- Input "D" to draw, "S" to shuffle when the draw pile is empty, and "E" to Exit the game. Press enter after each input
- Otherwise, type in the card name WITHOUT BRACKETS (to move card [4H ], type in "4H" then press enter).
- D = Diamond, H = Heart, S = Spade, C = Club. Diamond and Heart are red suits, Spade and Club are black suits. 
- |||| means that the card is hidden and cannot yet be played
- The only divergence from traditional solitaire rules is that only one card is drawn from the draw pile at a time. 

Rules: 
- The object of the game is to complete all 4 card piles at the top of the board. These piles will start with the Ace of that given suit, and proceed through the values 2 to 10, then J, Q, K. Once all stacks are completed, you've won the game. 
- If a card t
- On the board, you can only move a card underneath a card of a greater rank of 1 and of an OPPOSITE COLOR suit. Ex: 3H can be moved under 4S, H is red, S is black. 
- K>Q>J>10>9....>2>A
- You may move any overturned card. If you move a card that has cards underneath it, all of the cards below it move too. So in a line of 5D-->4S-->3D, you may move any of those 3 cards, but if for example you move 5D, 4S and 3D will go with it. 
- Once a card is in one of the 4 final piles, it cannot be moved back to the board.
- If you move a card and its previous card in the line is hidden, it will overturn the previous card.


Largest current bug is occasionally when inserting an Ace, (and only an ace) into the 4 final piles, it will show up as overturned (||||). You can still play the next card on top of it and it does not hinder gameplay or winning. 

Code should have no dependencies and work on all operating systems, but the layout of the gameboard has not been tested in any compiler other than VSCode. Other compilers might have slightly different alignments of gameboard. 



