# Tetr.io-4W-Helper
When you are playing 4W, it can help you get lots of combos and send lots of attacks.

Thanks [zengmaoyuan](https://github.com/zengmaoyuan) and [tanjiaqi](https://github.com/tanjiaqi) for helping calculating.

## How to use it

### Boards

Here are the the ids of the boards.To be understood, we use 'X' to mean a piece and 'O' to mean a blank.

|$\text{id}$|$\text{board}$|
|:--:|:--:|
|$0$|`XXXO`|
|$1$|`XXOX`|
|$2$|`XOXX`|
|$3$|`OXXX`|
|$4$|`OOXO` <br/> `OOXX`|
|$5$|`OOOX` <br/> `OOXX`|
|$6$|`OOXX` <br/> `OOOX`|
|$7$|`OOXX` <br/> `OOXO`|
|$8$|`OXOO` <br/> `XXOO`|
|$9$|`XOOO` <br/> `XXOO`|
|$10$|`XXOO` <br/> `XOOO`|
|$11$|`XXOO` <br/> `OXOO`|
|$12$|`OOOX` <br/> `OOOX` <br/> `OOOX`|
|$13$|`XOOO` <br/> `XOOO` <br/> `XOOO`|
|$14$|`XOOO` <br/> `XOXO`|
|$15$|`XOOO` <br/> `XOOX`|
|$16$|`OOOX` <br/> `OXOX`|
|$17$|`OOOX` <br/> `XOOX`|
|$18$|`XOOO` <br/> `OOXX`|
|$19$|`OOOX` <br/> `XXOO`|
|$20$|`XOOO` <br/> `OXOX`|
|$21$|`OOOX` <br/> `XOXO`|
|$22$|`OXOO` <br/> `XOOX`|
|$23$|`OOXO` <br/> `XOOX`|
|$24$|`OXXO` <br/> `OOOX`|
|$25$|`OXXO` <br/> `XOOO`|
|$26$|`XOOO` <br/> `OXXO`|
|$27$|`OOOX` <br/> `OXXO`|

### Input

When you start the program, it will let you `input with [board id] [hold piece] [current piece] [next 5 pieces]`.

For example, `3 L I SZOIT` is a good input.

If the holden piece is unable, you can put a `-` before the `[hold piece]` to mean that.

For example, `3 -L I SZOIT` is a good input.

When you want to end the program, you can input `exit` or press `Ctrl + C` to do that.

### Output

If the program puts "No solution.", the board is unable to make more than 4 combos. You should make a new board.

If the program puts "Holding piece.", you should hold the piece.

If the program puts "Move to x.", you should replace the piece to turn the board into the x-th board.

## updates

$2025-05-05 15:35$ UTC+$8$: Known issues fixed. Added more colors.
