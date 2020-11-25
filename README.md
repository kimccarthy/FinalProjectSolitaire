# FinalProjectSolitaire
/*
Kate McCarthy, CSCI 2275 (Working Alone)

I will be creating a simple game of solitaire with a simple graphic output (drawings made out of keyboard characters) in an output.txt file that would look something along the lines of 
 [    ]   [    ]   [    ]   [    ]

|QH|   ||||  ||||   ||||   ||||   ||||   |||| 

       |KD|  ||||   ||||   ||||   ||||   ||||   
             |6C|   ||||   ||||   ||||   ||||   
                    |QS|   ||||   ||||   ||||
                           |8D|   ||||   ||||    
                                  |8S|   ||||  
                                  
                                         |7S|
                                         
||||   |4S|

(I will need to figure out how to translate this into github^^ I know how to lay it out in VSCode)

Where the top 4 piles are for inserting stacks of suits starting with Ace, a discard and draw pile in the corner. D = Diamond, H = Heart...

My gameplay is inspired by the "Easy" Mode on the Google solitaire game (https://www.google.com/search?q=play+solitaire), where a user can click a card
and if there is a viable move, it will move the card to that spot as opposed to having the user physically drag it around. 
Users can select an overturned card to move by using their arrow keys, can draw by pressing D and create a new game by pressing N.

RULES: 
- A card will only move if it's new parent has a greater value of one and is of a different color suit. 
- You may only see/use the top card of the discard pile **(use of a stack)**
- An Ace is the only card that can start one of the 4 piles at the top. To win the game, you must fill these piles with cards in a suit from Ace to King
- The deck may be shuffled once empty by pressing "S"
- If you wish to move a line of cards, for example:
||||
||||
||||
[8D]
[7D]
[6D]

**(whole line of cards will be a Linked List**, where some members have a true boolean to show that they are overturned and others do not)
you may move any card and the cards below it to a new location.
- You may only move a card or line of cards to the last visible card in a line.






*/
